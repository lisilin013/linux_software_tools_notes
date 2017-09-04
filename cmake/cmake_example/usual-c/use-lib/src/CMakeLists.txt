# 换个地方保存目标二进制
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# 添加一个头文件搜索路径
include_directories(/tmp/hello-world-project/usr/include/hello)

aux_source_directory(. SRC_LST)

link_directories(/tmp/hello-world-project/usr/lib)

ADD_EXECUTABLE(main ${SRC_LST})

# 为 target 添加共享库
target_link_libraries(main hello)

