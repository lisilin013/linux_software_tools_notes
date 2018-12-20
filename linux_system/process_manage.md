# process manage
##1 查看、后台运行、kill
###1.1 查看
> pstree 查看当前活跃进程的树形结构
pstree -up
参数选择：
-A  ：各程序树之间以 ASCII 字元來連接；
-p  ：同时列出每个 process 的 PID；
-u  ：同时列出每个 process 的所屬账户名称。

***
>**ps -fxo user,ppid,pid,stat,pri,ni,time,command 静态查看当前的进程信息 自定义我们所需要的参数显示**
**ps aux 罗列出所有的进程信息
ps aux | grep zsh**
ps axjf 连同部分的进程呈树状
ps -l 显示自己这次登陆的 bash 相关的进程信息罗列出来

***
>**top 动态实时的查看进程的状态**
**常用交互命令	解释**
q	退出程序
I	切换显示平均负载和启动时间的信息
**P	根据CPU使用百分比大小进行排序
M	根据驻留内存大小进行排序
i	忽略闲置和僵死的进程，这是一个开关式命令
k	终止一个进程，系统提示输入 PID 及发送的信号值。**一般终止进程用15信号，不能正常结束则使用9信号。安全模式下该命令被屏蔽。

###1.2 后台运行
>& 这个符号，让我们的命令**在后台中运行**
eg: ls &
[1] 236分别是该工作的 job number 与该进程的 PID
>****
>**ctrl + z 使我们的当前工作停止并丢到后台中去**
**jobs 查看后台工作**
**fg %jobnumber 将后台的工作拿到前台来**
**bg %jobnumber 让其在后台运作**
###1.3 kill
>**kill -signal %jobnumer 删除一个工作**
这个只能在job所在的终端内才能操作
想要在别的终端kill，可以执行
**kill -signal pid**
>
其中，**-signal常用的有**
**-1	重新读取参数运行，类似与restart
-2	如同 ctrl+c 的操作退出　
-9	强制终止该任务　　　
-15	正常的方式终止该任务**
>***
**eg: kill -9 %1 #kill jobnumber
kill -9 1 **

