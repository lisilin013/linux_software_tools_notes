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

\#aliyun<br/>
deb http://mirrors.aliyun.com/ubuntu/ trusty main restricted universe multiverse<br/>
deb http://mirrors.aliyun.com/ubuntu/ trusty-security main restricted universe multiverse<br/>
deb http://mirrors.aliyun.com/ubuntu/ trusty-updates main restricted universe multiverse<br/>
deb http://mirrors.aliyun.com/ubuntu/ trusty-proposed main restricted universe multiverse<br/>
deb http://mirrors.aliyun.com/ubuntu/ trusty-backports main restricted universe multiverse<br/>
deb-src http://mirrors.aliyun.com/ubuntu/ trusty main restricted universe multiverse<br/>
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-security main restricted universe multiverse<br/>
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-updates main restricted universe multiverse<br/>
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-proposed main restricted universe multiverse<br/>
deb-src http://mirrors.aliyun.com/ubuntu/ trusty-backports main restricted universe multiverse<br/>
<br/>
sudo gedit /etc/apt/sources.list<br/>

## W: 无法下载 http://extras.ubuntu.com/ubuntu/dists/trusty/main/binary-i386/Packages  Hash 校验和不符
solve:<br/>
replace the source with aliyun mentioned before.<br/>