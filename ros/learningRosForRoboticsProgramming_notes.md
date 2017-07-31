### ros::spin() 和 ros::spinOnce() 区别及详解
ros::spin() 在调用后不会再返回，也就是你的主程序到这儿就不往下执行了，而 ros::spinOnce() 后者在调用后还可以继续执行之后的程序。

ros::spin()函数一般不会出现在循环中，因为程序执行到spin()后就不调用其他语句了，也就是说该循环没有任何意义，还有就是spin()函数后面一定不能有其他语句(return 0 除外)，有也是白搭，不会执行的。ros::spinOnce()的用法相对来说很灵活，但往往需要考虑调用消息的时机，调用频率，以及消息池的大小，这些都要根据现实情况协调好，不然会造成数据丢包或者延迟的错误。

### launch
```
<?xml version="1.0" encoding="UTF-8"?>

<launch>

  <!-- Example 1 调用节点写法-->
  <node name ="chap2_example1_a" pkg="chapter2_tutorials" type="chap2_example1_a"/>
  
  <!-- Example 1 调用节点、屏幕输出写法-->
  <node pkg="chapter3_tutorials" type="example1" name="example1"
        output="screen"/>
 
   <!-- Example 1 调用节点、gdb调试写法-->
  <node pkg="chapter3_tutorials" type="example1" name="example1"
        output="screen"/>      
        
   <!-- Example 1 调用节点、使用valgrind调试写法-->
  <node pkg="chapter3_tutorials" type="example1" name="example1"
        output="screen" launch-prefix="valgrind"/>      
        
</launch>
```
### launch文件调用launch传参数用arg
```
    <include file="$(find turtlebot_gazebo)/launch/turtlebot_world.launch" >
        <arg name="world_file"  value="$(find turtle_sim)/worlds/robot_simple.world"/>
    </include>
```

### launch文件调用节点传参数用parm或者args
```
  <node pkg="odom_node_pkg" type="odom_node_type" name="odom_node" output="screen">
    <param name="odom_param" value="param_value" />
  </node>
```

```
    <node name="rviz" pkg="rviz" type="rviz" args="-d $(find turtle_sim)/rviz/turtle.rviz" />
```
### 添加并使用msg

### 添加并使用srv

### 动态配置参数
1 编写cfg/filename.cfg文件
2 在cpp文件中使用
3 修改CMakelists.txt
4 rosrun rqt_reconfigure rqt_reconfigure

