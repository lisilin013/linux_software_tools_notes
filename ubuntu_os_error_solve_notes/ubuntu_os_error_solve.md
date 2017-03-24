## UBUNTU_OS_ERROR
### cannot link the wire internet
solve:<br/>
sudo ethtool -s eth0 autoneg off speed 100 duplex full<br/>
sudo ethtool -s eth0 speed 10 duplex half<br/>

notes:<br/>
Now, I have just tried the first cmd, and it is already beginning to work.<br/>