SET(LIBHELLO_SRC hello.c)

# 要指定 libxx.xx 生成的位置
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# 建立共享库(动态库) .so
ADD_LIBRARY(hello
	SHARED ${LIBHELLO_SRC})
# 添加静态库 .a
ADD_LIBRARY(hello_static
	STATIC ${LIBHELLO_SRC})
# 以用来设置输出的名称,对于动态库,还可以用来指定动态库版本和 API 版本
SET_TARGET_PROPERTIES(hello_static
	PROPERTIES OUTPUT_NAME "hello")
# GET_TARGET_PROPERTY(VAR target property)
GET_TARGET_PROPERTY(OUTPUT_VALUE hello_static OUTPUT_NAME)
MESSAGE(STATUS "This is the hello_static OUTPUT_NAME: ${OUTPUT_VALUE}")

# 动态库版本号
# VERSION 指代动态库版本,SOVERSION 指代 API 版本
SET_TARGET_PROPERTIES(hello PROPERTIES VERSION 1.2 SOVERSION 1)


#########################################
# install
#########################################
# 安装共享库和头文件
# ARCHIVE 特指静态库, LIBRARY 特指动态库, RUNTIME特指可执行目标二进制
INSTALL(TARGETS hello hello_static
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

INSTALL(FILES hello.h
	DESTINATION include/hello)
