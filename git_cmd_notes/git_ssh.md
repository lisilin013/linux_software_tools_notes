## 准备工作
		# 1 安装git  
		sudo apt-get install git 
		
		# 2 首先需要检查你电脑是否已经有 SSH key 
		cd ~/.ssh
		
		# 3 创建一个 SSH key 
		ssh-keygen -t rsa -C "your_email@youremail.com" 
		
		# 运行上面那条命令后会让你输入一个文件名
		# 用于保存刚才生成的 SSH key 代码
		# 可以不输入文件名，使用默认文件名（推荐）
		# 会生成 id_rsa 和 id_rsa.pub 两个秘钥文件
		
		# 又会提示你输入两次密码
		#（该密码是你push文件的时候要输入的密码，而不是github管理者的密码），

		# 当然，你也可以不输入密码，直接按回车。
		# 那么push的时候就不需要输入密码，直接提交到github上了
		
		# 4 添加你的 SSH key 到 github上面去
		cat  ~/.ssh/id_rsa.pub 
		# 拷贝 id_rsa.pub 文件的内容
		
		# 5 登录github账号，从右上角的设置（ Account Settings ）进入
		# 然后点击菜单栏的 SSH key 进入页面添加 SSH key。
		
		# 6 测试一下该SSH key
		ssh -T git@github.com 
		config --global user.name "your name"   //配置用户名 
		git config --global user.email "your email"    //配置email 