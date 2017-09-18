## sublime cpp提示
[Sublime3支持C++智能提示](http://luodw.cc/2015/09/25/sublime/)
```
安装相关软件
sudo apt-get install cmake build-essential clang git
cd ~/.config/sublime-text-3/Packages
git clone --recursive https://github.com/quarnster/SublimeClang SublimeClang
cd SublimeClang
cp /usr/lib/x86_64-linux-gnu/libclang-3.4.so.1 internals/libclang.so   #这一步很重要，如果你的clang库不是3.4版本的话，请将对应版本的库拷贝到internals中
cd src
mkdir build
cd build
cmake ..
make
```
> 一切成功的话将会在SublimeClang/internals目录中生成libcache.so库文件。重启Sublime Text，然后按快捷键Ctrl + `(Esc下面那个键)打开自带的控制输出，看看有没有错误，如果没有错误就说明一切OK了


## sublime clang 设置支持C++
打开preference-->package settings-->sublimeclang-->settings default
搜索additional_language_options，修改成以下代码
```
    "additional_language_options":
    {
        // For example, you can use "c++": ["-std=c++11"] to enable C++11 features.
        "c++" : ["-std=c++11"],
        "c": [],
        "objc": [],
        "objc++": []
    },
```

## 编译cpp
[Sublime Text 3 化身为高大上的C/C++ IDE](https://xuanwo.org/2014/06/05/sublime-text-3-IDE/)


> 以Ubuntu为例，系统不同请自行修改终端参数。 建立新的编译系统 Tools –> Build System –> New Build System 在打开的页面中粘贴以下代码

>注意你的shell是bash还是zsh

```
{
    "cmd": ["g++", "${file}", "-std=c++11", "-o", "${file_path}/${file_base_name}"],
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c, source.c++",
    "variants":
    [
        {
            "name": "Run",
            "cmd":["gnome-terminal", "-x", "bash", "-c", "g++ '${file}' -o '${file_path}/${file_base_name}' && '${file_path}/${file_base_name}' ;read -n1 -p 'press any key to continue.'"]
        }
    ]
}
```


## 格式化代码
在packagecontrol中安装SublimeAStyleFormatter
```
ctr+alt+f 格式化本文件
```