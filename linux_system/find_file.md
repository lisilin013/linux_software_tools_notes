# 搜索文件


## whereis只能搜索二进制文件(-b)，man帮助文件(-m)和源代码文件(-s)
<br/>

## find
>find [path] [option] [action]

> sudo find /etc/ -name interfaces

<br/>
### 与时间相关的命令参数：

参数        说明
-atime	最后访问时间
-ctime	创建时间
-mtime	最后修改时间
下面以-mtime参数举例：

* -mtime n: n 为数字，表示为在n天之前的”一天之内“修改过的文件
* -mtime +n: 列出在n天之前（不包含n天本身）被修改过的文件
* -mtime -n: 列出在n天之内（包含n天本身）被修改过的文件
* newer file: file为一个已存在的文件，列出比file还要新的文件名
![](https://dn-anything-about-doc.qbox.me/linux_base/5-8.png)


