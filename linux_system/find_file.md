## 搜索文件

find <指定目录> <指定条件> <指定动作>
　　- <指定目录>： 所要搜索的目录及其所有子目录。默认为当前目录。
　　- <指定条件>： 所要搜索的文件的特征。
　　- <指定动作>： 对搜索结果进行特定的处理。
  
  如果什么参数也不加，find默认搜索当前目录及其子目录，并且不过滤任何结果（也就是返回所有文件），将它们全都显示在屏幕上
  
 
 find的使用实例：
　　$ find . -name 'my*'
搜索当前目录（含子目录，以下同）中，所有文件名以my开头的文件。
　　$ find . -name 'my*' -ls
搜索当前目录中，所有文件名以my开头的文件，并显示它们的详细信息。



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


