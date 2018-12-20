# Linux 目录结构及文件基本操作

## FHS 标准
![](https://dn-anything-about-doc.qbox.me/linux_base/4-1.png/logoblackfont) 

> tree
pwd

## 路径
绝对路径
> /usr/local/bin

相对路径
> ../../usr/local/bin

## 文件的移动、复制、重命名、编辑等操作
> mkdir
touch
rm
mv
cp

<br/>
>\# 使用通配符批量创建 5 个文件
>$ touch file{1..5}.txt

>\# 批量将这 5 个后缀为 .txt 的文本文件重命名为以 .c 为后缀的文件
>$ rename 's/\.txt/\.c/' *.txt

>\# 批量将这 5 个文件，文件名改为大写
>$ rename 'y/a-z/A-Z/' *.c

## 查看文件
cat为正序显示
tac倒序显示

more和less命令分页查看文件
使用Enter键向下滚动一行
使用Space键向下滚动一屏
按下h显示帮助
q退出

使用head和tail命令查看文件
> tail -n 1 /etc/passwd
>head -n 10 filename

