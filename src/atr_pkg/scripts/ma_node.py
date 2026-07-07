#! /usr/bin/env python3
#coding=utf-8
import rospy
from std_msgs.msg import String

def chao_callback(msg: String):
    rospy.loginfo(msg.data)

def yao_callback(msg: String):
    rospy.logwarn(msg.data)


if __name__=="__main__":
    rospy.init_node("ma_node")

    sub=rospy.Subscriber("lets_go_to_play",String,chao_callback,queue_size=10)
    sub2=rospy.Subscriber("help_me_get_more_score",String,yao_callback,queue_size=10)

    rospy.spin()#这个保持节点在运行状态
