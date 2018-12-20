## gdb learning

| 命令 | 简写形式 | 说明 |
| ---- | :------: | ---- |
| list | l | 查看源码 |
| backtrace | bt、where | 打印函数栈信息 |
| next | n | 执行下一行 |
| step | s | 一次执行一行，遇到函数会进入 |
| finish |  | 运行到函数结束 |
| continue | c | 继续运行 |
| break | b | 设置断点 |
| info  breakpoints |  | 显示断点信息 |
| delete | d | 删除断点 |
| print | p | 打印表达式的值 |
| run | r | 启动程序 |
| until | u | 执行到指定行 |
| info | i | 显示信息 |
| help | h | 帮助信息 |



```
gdb exe.file

# breakpoingts
b file:linenum 
b func_name
info breakpoints
d #delet all breakpoints
enable once b_num
enable delete b_Num
disable b_num


r #run eg: r argv
s #step
n #next
c #continue
u #until line
finish #run to the end

i #info 
info locals #print local var
l #list content


################UNKNOWN#############
backtrace #func stack 


set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}  -g ")
set (CMAKE_VERBOSE_MAKEFILE ON)

＄gdb ./example2_sam


```
