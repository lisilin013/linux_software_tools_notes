```
catkin_make
source devel/setup.zsh

Manifest (package.xml): 清单，是对软件包相关信息的描述,用于定义软件包相关元信息之间的依赖关系，这些信息包括版本、维护者和许可协议等。

# operate towards to rospack
rospack find [包名称]
roscd roscpp
rosls roscpp_tutorials

# catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
catkin_create_pkg beginner_tutorials std_msgs rospy roscpp

# 查看一级依赖包
rospack depends1 beginner_tutorials
# 递归检测出所有的依赖包
rospack depends beginner_tutorials

```

```
Nodes:节点,一个节点即为一个可执行文件，它可以通过ROS与其它节点进行通信。

Messages:消息，消息是一种ROS数据类型，用于订阅或发布到一个话题。

Topics:话题,节点可以发布消息到话题，也可以订阅话题以接收消息。

Master:节点管理器，ROS名称服务 (比如帮助节点找到彼此)。

rosout: ROS中相当于stdout/stderr。

roscore: 主机+ rosout + 参数服务器 (参数服务器会在后面介绍)。
```

```
rostopic echo	print messages to screen
rostopic list	list active topics
rostopic type	print topic type
rostopic pub	publish data to topic

# eg: 参数其实是按照YAML语法格式
# rostopic pub /topic type [args...]
rostopic pub  /turtle1/cmd_vel geometry_msgs/Twist -1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
1 rostopic list
2 rostopic type /topic
3 rostopic pub /topic topic_type [args...]
 
```

```
# ros service and parameters
rosservice
rossrv
rosparam

```
```
# 日志等级按以下优先顺序排列：
Fatal
Error
Warn
Info
Debug

# Fatal是最高优先级，Debug 是最低优先级。通过设置日志等级你可以获取该等级及其以上优先等级的所有日志消息。比如，将日志等级设为Warn时，你会得到 Warn、Error和 Fatal 这三个等级的所有日志消息。
```
```
# 使用roslaunch
roslaunch file.launch
```

```
# 使用 rosed

rosed [package_name] [filename]
rosed roscpp Logger.msg

```

```
# 创建ROS消息
1 package里定义新的消息msg/file.msg

2 modify package.xml
  <build_depend>message_generation</build_depend>
  <run_depend>message_runtime</run_depend>
3 modify CMakelists.txt

(1)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

(2)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
  CATKIN_DEPENDS message_runtime
#  DEPENDS system_lib
)

(3)
add_message_files(
  FILES
  Num.msg
)

(4)
generate_messages()

```

```
# 创建ROS服务
1 package里定义新的服务srv/file.srv

2 Modify CMakeLists.txt
(1)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

(2)
add_service_files(
  FILES
  AddTwoInts.srv
)

3 
```

```
# ros cmd summary
生成的C++头文件将会放置在~/catkin_ws/devel/include/beginner_tutorials/。 

Python脚本语言会在 ~/catkin_ws/devel/lib/python2.7/dist-packages/beginner_tutorials/msg 目录下创建。

```


```
# summary
rospack = ros+pack(age) : provides information related to ROS packages
rosstack = ros+stack : provides information related to ROS stacks
roscd = ros+cd : changes directory to a ROS package or stack
rosls = ros+ls : lists files in a ROS package
roscp = ros+cp : copies files from/to a ROS package
rosmsg = ros+msg : provides information related to ROS message definitions
rossrv = ros+srv : provides information related to ROS service definitions
rosmake = ros+make : makes (compiles) a ROS package
```












