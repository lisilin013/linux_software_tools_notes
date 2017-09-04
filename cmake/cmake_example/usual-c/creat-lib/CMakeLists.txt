PROJECT(NEWHELLO)

# ADD_SUBDIRECTORY(source_dir [binary_dir] [EXCLUDE_FROM_ALL])
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(src)
# ADD_SUBDIRECTORY(src bin)

MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
MESSAGE(STATUS "install prefix dir ${CMAKE_INSTALL_PREFIX}")


#########################################
# install
#########################################
# 普通文件的安装:
INSTALL(FILES COPYRIGHT README
	DESTINATION share/doc/cmake/usual-c)

# 目录的安装:
INSTALL(DIRECTORY doc/
	DESTINATION share/doc/cmake/usual-c)

# 非目标文件的可执行程序安装(比如脚本之类):
INSTALL(PROGRAMS runhello.sh
	DESTINATION bin)
