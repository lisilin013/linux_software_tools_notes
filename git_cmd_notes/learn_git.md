## 准备工作  
sudo apt-get install git 
ssh-keygen -t rsa -C "your_email@youremail.com"    
cat  ~/.ssh/id_rsa.pub  
ssh -T git@github.com  
config --global user.name "your name"   //配置用户名  
git config --global user.email "your email"    //配置email   

## 利用Git从本地上传到GitHub
git init  
git remote add origin git@github.com:yourName/yourRepo.git                       //github  
git remote add origin https://lisilin013@bitbucket.org/lisilin013/learn_git.git  //bitbucket  

git add xxx  
git commit -m "提交的说明信息”  
  
git push -u origin master //把本地仓库提交到远程的GitHub仓库   
git push -u origin +master  //强行更新

## 分支操作  
git checkout -b new_feature //创建并同时切换到你新建的分支  
  
git branch new_feature  
git checkout new_feature //先创建一个分支然后手动切换  
  
git branch  //看你现在项目下所有的分支 

git add .git commit -m "adds my new feature" //加载（stage）并且提交你的文件 
git checkout master                          //移到你的主干分支  
git merge new_feature                        //合并  
  
git add .git commit -m "feature to be discarded" //丢弃分支  
git checkout master                              //移到主分支  
  
git branch -d new_feature  //  
git branch -D new_feature  //强制删除分支  

## 从GitHub克隆项目到本地  
git clone https://github.com/PentonBin/Demo.git（例子）  

本地的版本不是最新的，可以使用命令  
git fetch origin  
把更新的内容合并到本地分支
git merge origin/master 

## Git回滚操作  
git diff filename  
git status  
git log  
git reset  --hard HEAD^  
git reset  --hard HEAD^^  
git reset  --hard head_id

