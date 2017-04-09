# UBUNTU_OS_ERROR
## cannot link the wire internet
solve:<br/>

		sudo ethtool -s eth0 autoneg off speed 100 duplex full
		sudo ethtool -s eth0 speed 10 duplex half

notes:
Now, I have just tried the first cmd, and it is already beginning to work.

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
		
		