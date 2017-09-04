# Reset output path
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Set include path
include_directories( CMSIS/Include )
include_directories( CMSIS/Device/Include )
include_directories( STM32F4xx_HAL_Driver/Inc )

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
