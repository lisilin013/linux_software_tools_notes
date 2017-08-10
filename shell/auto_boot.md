## 1. 建立自己的脚本
```
#!/bin/bash
cd /home/ubuntu/undertow-server/
sudo mvn exec:java
```

## 2. 修改脚本权限
```
 sudo chmod 755 run_server.sh
```

## 3. 将脚本放置在启动路径下
```
sudo cp run_server.sh /etc/init.d/
```

## 4. 将脚本添加到启动脚本。
```
cd /etc/init.d/
sudo update-rc.d run_server defaults 90
```

## 如何移除该脚本
```
sudo update-rc.d -f run_server.sh remove

```