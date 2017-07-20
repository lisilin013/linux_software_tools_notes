##################################################################
cmake_minimum_required(VERSION 3.1)  # CMake 版本要求
PROJECT(hello)                       # 项目名称

##################################################################
# 添加外部头文件查找目录
##################################################################
include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/beep/
 ${CMAKE_CURRENT_SOURCE_DIR}/led/
 ${CMAKE_CURRENT_SOURCE_DIR}/user/)



##################################################################
# 将当前目录所有文件添加到变量 PROGRAM_SOURCE 中
##################################################################
aux_source_directory(
	PROGRAM_SOURCE)



##################################################################
add_executable(
 hello
 ${PROGRAM_SOURCE}) # 指定目标可执行文件 hello 的源代码文件为 PROGRAM_SOURCE



##################################################################
# 添加外部链接库
##################################################################
# 通过以下代码可以添加外部链接库查找目录, 其中 CMAKE_CURRENT_SOURCE_DIR 是内置宏， 表示当前 CMakeLists.txt 所在目录：

# link_directories(
#     ${CMAKE_CURRENT_SOURCE_DIR}/../../lib
#     ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
# 通过以下代码可以添加链接的外部库，这里链接 libmylib1 和 libmylib2， 这里链接的库可以是静态库也可以是动态库：

# link_libraries(mylib1
#     mylib2)
# 如果是链接指定目录指定某个库，则可以用以下方式：

# target_link_libraries(hello ../mylib1.a
#     hello ../mylib2.so)
# 对于同一个工程中构建的库，则可以用以下方式，无需指定具体的库的位置：

# target_link_libraries(hello mylib1 mylib2)


# 如果是链接指定目录指定某个库
# target_link_libraries(hello ../mylib1.a
#     hello ../mylib2.so)




##################################################################
# 创建工程内的库
##################################################################
# 创建库和创建可执行文件的 CMakeLists.txt 区别不大，只是讲 add_executable 替换为：

# add_library(mylib STATIC ${SRC})
# STATIC表示创建静态库，目标文件为 libmylib.a，如果是 SHARED， 则为创建动态库.


##################################################################







