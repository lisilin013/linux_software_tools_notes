## 基本操作
(1)创建
mkdir -p ~/test/src

(2)删除test及其子目录和子文件
rm -rf ~/test
删除test的子目录和子文件
rm -rf ~/test/*

-r 就是向下递归，不管有多少级目录，一并删除
-f 就是直接强行删除，不作任何提示的意思

(3)复制文件夹A及其子目录和子文件 到 B下
copy -rf ～/A ～/B
复制文件夹A的子目录和子文件 到 B下
copy -rf ～/A/* ～/B

(5)剪切文件夹A及其子目录和子文件 到 B下
mv ～/A ～/B
剪切文件夹A的子目录和子文件 到 B下
mv ～/A/* ～/B

(6)重命名，其实也就是剪切一个文件夹命名成其他的名字而已

## 批量复制文件/文件夹
```
echo /home/aaronkilik/test/ /home/aaronkilik/tmp | xargs -n 1 cp -v /home/aaronkilik/bin/sys_info.sh
```
上面的命令中，目录的路径（dir1、dir2、dir3...dirN）被管道作为输入到 xargs 命令中，含义是：

-n 1 - 告诉 xargs 命令每个命令行最多使用一个参数，并发送到 cp 命令中。
cp – 用于复制文件。
-v – 启用详细模式来显示更多复制细节。