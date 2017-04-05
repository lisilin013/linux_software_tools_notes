# log

## 1 常见的日志
| **日志名称**	| **记录信息**|
| --------- | -----------|
| alternatives.log | 系统的一些更新替代信息记录
apport.log | 应用程序崩溃信息记录
apt/history.log	|使用apt-get安装卸载软件的信息记录
apt/term.log	|使用apt-get时的具体操作，如 package 的下载打开等
auth.log	|登录认证的信息记录
boot.log	|系统启动时的程序服务的日志信息
btmp	|错误登陆的信息记录
Consolekit/history|	控制台的信息记录
dist-upgrade	|dist-upgrade这种更新方式的信息记录
dmesg	|启动时，显示屏幕上内核缓冲信息,与硬件有关的信息
dpkg.log	|dpkg命令管理包的日志。
faillog	|用户登录失败详细信息记录
fontconfig.log	|与字体配置有关的信息记录
kern.log|	内核产生的信息记录，在自己修改内核时有很大帮助
lastlog	|用户的最近信息记录
wtmp	|登录信息的记录。wtmp可以找出谁正在登陆进入系统，谁使用命令显示这个文件或信息等
syslog	|系统信息记录

## 2 配置的日志
在早期的大部分 Linux 发行版都是内置 syslog，让其作为系统的默认日志收集工具，虽然时代的进步与发展，syslog 已经年老体衰跟不上时代的需求，所以他被 rsyslog 所代替了，较新的Ubuntu、Fedora 等等都是默认使用 rsyslog 作为系统的日志收集工具

rsyslog的全称是 rocket-fast system for log，它提供了高性能，高安全功能和模块化设计. 能实时收集日志信息的程序都会有其守护进程如 rsyslog 的守护进程便是 rsyslogd


		sudo service rsyslog start
		ps aux | grep syslog

rsyslog 的配置文件有两个
* /etc/rsyslog.conf 配置的环境，也就是 rsyslog 的加载什么模块，文件的所属者
* /etc/rsyslog.d/50-default.conf 配置的 Filter Conditions

## 3 转储的日志
/etc/logrotate.conf 中找到其配置文件
 /etc/logrotate.d/ 中有各项应用的 logrotate 配置

