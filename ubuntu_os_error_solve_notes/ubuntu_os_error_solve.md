# UBUNTU_OS_ERROR
## cannot link the wire internet
solve:<br/>
```
安装wicd网络管理器解决网卡驱动问题代码: sudo modprobe -r rtl8723be 
 sudo modprobe rtl8723be -v ips=0 fwlps=0 swenc=1   
新建文件 （注意使用touch） sudo touch /etc/modprobe.d/rtl8723be.conf
 用vim打开后添加以下文段 options rtl8723be ips=0 fwlps=0 swenc=1
```

## ubuntu source update

		sudo cp /etc/apt/sources.list /etc/apt/sources.list_backup
		sudo gedit /etc/apt/sources.list
		sudo apt-get update

## W: 无法下载 http://extras.ubuntu.com/ubuntu/dists/trusty/main/binary-i386/Packages  Hash 校验和不符
solve:

		replace the source with aliyun mentioned before.

## ubuntu中怎样添加或删除一个PPA源
		# 添加PPA源的命令为：
		sudo add-apt-repository ppa:user/ppa-name
		
		# 删除命令格式则为： 
		sudo add-apt-repository -r ppa:user/ppa-name 


## 搜狗不能用了之后，安装Google拼音
		sudo apt-get remove ibus
		sudo apt-get autoremove
		
		# 接着添加Fcitx PPA
		sudo add-apt-repository ppa:fcitx-team/nightly
		sudo apt-get update
		
		# 由于该PPA暂未支持Ubuntu 14.04，所以需要修改PPA源表
		sudo gedit /etc/apt/sources.list.d/fcitx-team-nightly-trusty.list
		
		sudo apt-get update
		sudo apt-get install fcitx-googlepinyin
		
		