## 1. 支持C++11
* 最佳解决方案
```
add_executable(demo ${CPP_SRC})
# enable 引导使用C++标准
target_compile_features(demo PRIVATE cxx_range_for)
```
* 次佳解决方案
```
# enable c++ 11
set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

```

## 2. 使用pthread库
```
# enable both C++ and C
project(cpp_example VERSION 0.1.0 LANGUAGES CXX C)

# 多线程的pthread族函数
find_package(Threads)
add_executable(demo ${CPP_SRC})
target_link_libraries(demo ${CMAKE_THREAD_LIBS_INIT})
```

## 3 使用boost库
```
target_link_libraries(exe_name ${Boost_PROGRAM_OPTIONS_LIBRARY})
```

