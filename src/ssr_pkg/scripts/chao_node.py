#! /usr/bin/env python3
#coding=utf-8
#python的文件可以直接运行不用编译，前面两个选择编译器和编码方式
import rospy
from std_msgs.msg import String

if __name__=="__main__":
    rospy.init_node("chao_node")
    rospy.logwarn("国服马超上号")

    pub=rospy.Publisher("lets_go_to_play",String,queue_size=10)
    rate=rospy.Rate(10)
    while not rospy.is_shutdown():
        rospy.loginfo("开始发送消息")
        msg=String()
        msg.data="国服马超带飞"
        pub.publish(msg)
        rate.sleep()