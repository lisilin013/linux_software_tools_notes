	author : lisilin
	date   : 04/04/2017 
# basic define
## char define
| char | note |
|--|--|
^ |line head
$| line tail
1G| doc head
G | doc tail		
w| a word

## command define
| char | note |
|--|--|
d | delet
y | copy 
p | paste




# insert
| command| note |
|--|--|
|o| insert a new line after the current line|
O |insert a new line before the current line
a | edit after the cusor
i | edit after the cusor
A | edit the tail of the line
I | edit the head of the line

# save
| command| note |
|--|--|
:q!| back without saving
:wq| save and back forcely
:q |back
:wq!|
:x |save and back

# delet
| command| note |
|--|--|
x |del the char of the current cusor
X |del the pre char of the current cusor
dd| del the line
dw| del a word
D| del from the cusor to the tail of the line
d^ |del from the cusor to the head of the line
dG |del to the tail of the doc
d1G| del to the head of the doc
10dd | del 10 lines
10x | del 10 words


# 快速跳转
## 行间跳转
| command| note |
|--|--|
50G | move to the 50th line
gg | move to first line
 G | move to last line
 
## 行内跳转
 | command| note |
|--|--|
w|	到下一个单词的开头
b|	到前一个单词的开头
^|	到行头
$|	到行尾
f<字母>	|向后搜索<字母>并跳转到第一个匹配的位置(非常实用)
F<字母>	|向前搜索<字母>并跳转到第一个匹配的位置

# copy and paste
		y : copy
		p : paste
 | command| note |
|--|--|
yy|复制游标所在的整行（3yy表示复制3行）
y^| 
y$ |
yw |复制一个单词
d|删除命令就是剪切
ddp |交换上下行

# replace and undo
## replace
 | command| note |
|--|--|
r+<待替换字母>	|将游标所在字母替换为指定字母
R	|连续替换，直到按下Esc
cc	|替换整行，即删除游标所在行，并进入插入模式
cw	|替换一个单词，即删除一个单词，并进入插入模式
C(大写)|	替换游标以后至行末

## redo and undo
 | command| note |
|--|--|
u{n}	|撤销一次或n次操作
U(大写)	|撤销当前行的所有修改
Ctrl+r	|redo，即撤销undo的操作


# find
 | command| note |
|--|--|
/char| findnext char
?char |find pre char
n | find next char repeatly
N |find pre char repeatly
\\*|寻找游标所在处的单词向后（下）
\\#|向前（上）找

