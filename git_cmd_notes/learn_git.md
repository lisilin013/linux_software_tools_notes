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


		git checkout master                          //移到你的主干分支  
		git merge new_feature                        //合并  
		  
		git add .git commit -m "feature to be discarded" //丢弃分支  
		git checkout master                              //移到主分支  
		  
		git branch -d new_feature  //  
		git branch -D new_feature  //强制删除分支  


## git分支操作经验
第一步，git clone远程

第二步，拉取远程分支eg: dev
在master下直接
		
		git fetch origin dev:dev
然后就可以git checkout dev到其分之下工作了

**或者**

在master下git checkout -b dev建立dev分支同时切换到dev下
		
		git fetch origin dev

或者
在master下git checkout -b dev建立dev分支同时切换到dev下
		
		git fetch origin dev:tmp #把remote端dev分支内容copy到本地tmp分支上，如果本地没有tmp则会自动创建
在dev分支下git merge tmp 会把tmp中的remote端dev内容融合到当前分支下


第三步，在所在分支下

		git push origin branch_name
		
注意，这个branch_name是remote端你想push到的分支名字，也是你现在所在分支的名字

如果remote端没有这个branch，则会自动创建并把你推送的内容放进去

在本地master下工作，搞完之后切换到git checkout dev
		
		git merge master 

然后提交dev即可


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

## git 删除远程文件
		git status #查看本地文件变更情况
		git rm --cached -r path/file