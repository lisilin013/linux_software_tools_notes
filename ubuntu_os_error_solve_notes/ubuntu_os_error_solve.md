# UBUNTU_OS_ERROR
## cannot link the wire internet
solve:<br/>
sudo ethtool -s eth0 autoneg off speed 100 duplex full<br/>
sudo ethtool -s eth0 speed 10 duplex half<br/>

notes:<br/>
Now, I have just tried the first cmd, and it is already beginning to work.<br/>

## ubuntu source update
sudo cp /etc/apt/sources.list /etc/apt/sources.list_backup<br/>
sudo gedit /etc/apt/sources.list<br/>


sudo apt-get update<br/>

## W: 无法下载 http://extras.ubuntu.com/ubuntu/dists/trusty/main/binary-i386/Packages  Hash 校验和不符
solve:<br/>
replace the source with aliyun mentioned before.<br/>

## ubuntu中怎样添加或删除一个PPA源
添加PPA源的命令为：<br/>
sudo add-apt-repository ppa:user/ppa-name<br/>
删除命令格式则为：<br/>
sudo add-apt-repository -r ppa:user/ppa-name<br/>



