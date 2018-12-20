#文件打包与解压缩

## 文件打包和压缩格式
```
**文件后缀名	说明**

*.zip	zip程序打包压缩的文件
*.rar	rar程序压缩的文件
*.7z	7zip程序压缩的文件
*.tar	tar程序打包，未压缩的文件
*.gz	gzip程序(GNU zip)压缩的文件
*.xz	xz程序压缩的文件
*.bz2	bzip2程序压缩的文件
*.tar.gz	tar打包，gzip程序压缩的文件
*.tar.xz	tar打包，xz程序压缩的文件
*tar.bz2	tar打包，bzip2程序压缩的文件
*.tar.7z	tar打包，7z程序压缩的文件
```

## 解压
>zip压缩打包
unzip命令解压缩zip文件
 unzip shiyanlou.zip

>rar和unrar工具分别创建和解压 rar 压缩包

>解压*.tar.gz文件：
> $ tar -xzf shiyanlou.tar.gz

```
压缩文件格式	参数
*.tar.gz	-z
*.tar.xz	-J
*tar.bz2	-j
```



