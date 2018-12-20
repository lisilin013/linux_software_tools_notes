# 换个地方保存目标二进制
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
ADD_EXECUTABLE(hello main.c)

#########################################
# install
#########################################
# 目标文件的安装
# ARCHIVE 特指静态库, LIBRARY 特指动态库, RUNTIME特指可执行目标二进制
INSTALL(TARGETS hello
RUNTIME DESTINATION bin
)
