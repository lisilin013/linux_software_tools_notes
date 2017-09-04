# CMake 第一阶段学习总结

## 1 编译一个完整的STM32工程
这是一个完整的STM32F407工程，这是一个工程第一级目录下的CMakeLists.txt
```
# CMake minimum version
cmake_minimum_required (VERSION 3.1)

# Project Infomation
project( blinky )
# 使用汇编编译
enable_language(ASM)

# add sub进入到这个文件夹下执行它的CMakeLists.txt
add_subdirectory(Drivers)

# Reset output path
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# STDLIB
set (CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)

# 包含头文件路径
include_directories (Drivers/CMSIS/Device/Include )

# 包含源码文件
aux_source_directory (User/Source/ DIR_USER_SRCS)

# CC AR LD AS
set (CMAKE_C_COMPILER "arm-none-eabi-gcc")
set (CMAKE_C_AR "arm-none-eabi-ar")
set (CMAKE_ASM_COMPILER "arm-none-eabi-gcc")

# CFLAGS
set (CMAKE_C_FLAGS "-g -mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -Wall -std=gnu99 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "c compiler flags")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D USE_HAL_DRIVER -D STM32F407xx")

# CXXFLAGS
set (CMAKE_CXX_FLAGS "-g -mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -Wall -std=c++11 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "cxx compiler flags")

# ASMFLAGS

set (CMAKE_ASM_FLAGS "-g -mthumb -mcpu=cortex-m4 -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -x assembler-with-cpp" CACHE INTERNAL "asm compiler flags")

# LDFLAGS
set (CMAKE_EXE_LINKER_FLAGS "-g -Wl,--gc-sections -mthumb -mcpu=cortex-m4 -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -mabi=aapcs" CACHE INTERNAL "executable linker flags")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${CMAKE_SOURCE_DIR}/ldscripts/STM32F407VGTx_FLASH.ld")

# Load the the extern library
# add_library (STM32F4xx_HAL_Driver STATIC IMPORTED)
# set_property (TARGET STM32F4xx_HAL_Driver PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Drivers/Build/lib/libSTM32F4xx_HAL_Driver.a)
# 这句话和上面两句作用一样
link_directories(${CMAKE_SOURCE_DIR}/Drivers/Build/lib )

# Load the the extern freertos library
# add_library (STM32F4xx_FreeRTOS STATIC IMPORTED)
# set_property (TARGET STM32F4xx_FreeRTOS PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/FreeRTOS/Build/lib/libSTM32F4xx_FreeRTOS.a)
# 这句话和上面两句作用一样
link_directories(${CMAKE_SOURCE_DIR}/FreeRTOS/Build/lib )

# Generate the target 生成目标文件
add_executable (${CMAKE_PROJECT_NAME}.elf ${DIR_USER_SRCS} ${DIR_BSP_SRCS} ${DIR_CMSIS_SRCS} ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Device/Source/startup/startup_stm32f407xx.s)

# Link the library to the target 使用库
target_link_libraries (${CMAKE_PROJECT_NAME}.elf STM32F4xx_HAL_Driver STM32F4xx_FreeRTOS)

# Generate the binary file 生成二进制文件
add_custom_target (${CMAKE_PROJECT_NAME}.bin ALL arm-none-eabi-objcopy -Obinary "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf" "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.bin" DEPENDS ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf)
# Generate the hex file 生成十六进制文件
add_custom_target (${CMAKE_PROJECT_NAME}.hex ALL arm-none-eabi-objcopy -Oihex "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf" "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.hex" DEPENDS ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf)
# Echo the size Infomation
add_custom_target (size ALL arm-none-eabi-size "${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf" DEPENDS ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.elf)
# Make flash to the board by st-link
add_custom_target (flash COMMAND st-flash write ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME}.bin 0x8000000)
# Make clean-all 添加的自定义命令
add_custom_target (clean-all COMMAND rm -rf ${CMAKE_BINARY_DIR}/*)

```

## 2 生成静态库和动态库(共享库)

以生成stm32 官方库为例，部分内容展示了如何生成库的流程
```
# Reset output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Set include path
include_directories( CMSIS/Include )

# The need build source path and build all files
aux_source_directory (STM32F4xx_HAL_Driver/Src DIR_STM32F4xx_HAL_Driver_SRCS)

# CC AR
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_C_AR "arm-none-eabi-ar")

# CFLAGS
set (CMAKE_C_FLAGS "-g -mthumb -fno-builtin -mcpu=cortex-m4 -mfpu=fpv5-sp-d16 -mfloat-abi=softfp -Wall -std=gnu99 -ffunction-sections -fdata-sections -fomit-frame-pointer -mabi=aapcs -fno-unroll-loops -ffast-math -ftree-vectorize" CACHE INTERNAL "c compiler flags")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTM32F407xx -DUSE_HAL_DRIVER")

# Generate the target to the static library
add_library (STM32F4xx_HAL_Driver ${DIR_STM32F4xx_HAL_Driver_SRCS})
```

## 3 使用configure_file()自定义编译选项
```
# configure file
configure_file(
     "${PROJECT_SOURCE_DIR}/config.h.in"
     "${PROJECT_SOURCE_DIR}/config/config.h")

# use configure file
option(USE_CMAKEDEFINE "help string describing USE_CMAKEDEFINE" ON)
if(USE_CMAKEDEFINE)
    message(STATUS "use cmake define...")
endif(USE_CMAKEDEFINE)

# use cmake config file ,so include the config.h folder
include_directories (config)

```

在源文件中编写以下代码
```
/*use cmake config file*/
#include "config.h"
#ifdef USE_CMAKEDEFINE
#else
#endif
```
编译过程：
```
cmake ..
# 便于交互式的选择该变量的值，可以使用 ccmake 命令
ccmake .. # 回车键选择，c配置，g生成
make 
```

## 4 安装文件
安装分为以下几类

* FILES——普通文件安装
* DIRECTORY——文件夹安装
* PROGRAMS——非目标文件的可执行程序安装(比如脚本之类)
* TARGETS——目标文件安装，分为三类，ARCHIVE 特指静态库, LIBRARY 特指动态库, RUNTIME特指可执行目标二进制

安装的cmake代码写在生成该文件的CMakeLists.txt中。


```
# 普通文件的安装:
INSTALL(FILES COPYRIGHT README
	DESTINATION share/doc/cmake/usual-c)

# 目录的安装:
INSTALL(DIRECTORY doc/
	DESTINATION share/doc/cmake/usual-c)

# 非目标文件的可执行程序安装(比如脚本之类):
INSTALL(PROGRAMS runhello.sh
	DESTINATION bin)

# 目标文件的安装
# ARCHIVE 特指静态库, LIBRARY 特指动态库, RUNTIME特指可执行目标二进制
INSTALL(TARGETS hello
RUNTIME DESTINATION bin
)
	
# 安装共享库和头文件
# ARCHIVE 特指静态库, LIBRARY 特指动态库, RUNTIME特指可执行目标二进制
INSTALL(TARGETS hello hello_static
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)
INSTALL(FILES hello.h
	DESTINATION include/hello)

```

## 5 为工程添加测试
```
# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run Demo 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# 测试 5 的平方
add_test (test_5_2 Demo 5 2)
set_tests_properties (test_5_2
 PROPERTIES PASS_REGULAR_EXPRESSION "is 25")
```

```
# 定义一个宏，用来简化测试工作
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# 利用 do_test 宏，测试一系列数据
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")
```

## 6 增加GDB设置
指定 Debug 模式下开启 -g 选项

```
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

```

## 7 添加环境检查

在config.h.in 文件中，预定义相关的宏变量。
```
#cmakedefine HAVE_POW
```

在CMakeLists.txt中
```
# 检查系统是否支持 pow 函数，放在 configure_file 命令前
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否加入 MathFunctions 库
if (NOT HAVE_POW)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (NOT HAVE_POW)

```



## 8 为代码添加版本信息
在config.h.in中
```
// the configured options and settings for Tutorial
#define Demo_VERSION_MAJOR @Demo_VERSION_MAJOR@
#define Demo_VERSION_MINOR @Demo_VERSION_MINOR@

```
在CMakeLists.txt中，放在 configure_file 命令前
```
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)
```
在主程序中直接使用该宏
```
printf("%s Version %d.%d\n",
            argv[0],
            Demo_VERSION_MAJOR,
            Demo_VERSION_MINOR);
```

## 9 生成安装包
首先在顶层的 CMakeLists.txt 文件尾部添加下面几行：

```
# 构建一个 CPack 安装包
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
include (CPack)

```
上面的代码做了以下几个工作：

* 导入 InstallRequiredSystemLibraries 模块，以便之后导入 CPack 模块；
* 设置一些 CPack 相关变量，包括版权信息和版本信息，其中版本信息用了上一节定义的版本号；
* 导入 CPack 模块。

接下来的工作是像往常一样构建工程，并执行 cpack 命令。

```
# 生成二进制安装包：
cpack -C CPackConfig.cmake

# 或者生成源码安装包
cpack -C CPackSourceConfig.cmake
```
生成安装包的本质是把需要安装的文件打包成一个压缩包，最后解压到某个文件夹下。

