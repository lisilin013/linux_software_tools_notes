```
# 1. 安装zsh
sudo apt-get install zsh

# 2. 安装oh-my-zsh
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"

# 3. 如果自动安装没有成功切换到oh-my-zsh，手动切换
chsh -s /bin/zsh

# 4. bash转zsh善后处理
把.bashrc 后面追加的东西放到.zshrc里面，并且内容中后缀为bash的换为zsh
eg:
echo "source /opt/ros/indigo/setup.zsh" >> ~/.zshrc

# 5. 安装autojump
sudo apt-get install autojump
echo "source /usr/share/autojump/autojump.zsh" >> ~/.zshrc

# 6. 简化命令配置，加入到.zshrc里面

#########################################
# open file configure
#########################################
alias -s py='vim'      # 在命令行直接输入 python 文件，会用 vim 中打开，以下类似
alias -s c='vim'
alias -s cpp='vim'
alias -s txt='gedit'

alias -s gz='tar -xzvf' # 在命令行直接输入后缀为 gz 的文件名，会自动解压打开
alias -s tgz='tar -xzvf'
alias -s zip='unzip'
alias -s bz2='tar -xjvf'
alias -s md='remarkable'
#########################################
# sh cmd configure
#########################################
alias cls='clear'
alias ll='ls -l'
alias la='ls -a'
#########################################
# git cmd configure
#########################################
alias gpush='git push origin master'
alias gstatus='git status'
alias gcommit='git commit -m'
alias gadd='git add'

# 6. source更新文件
source ~/.zshrc


```