#! /usr/bin/env python3
#coding=utf-8

import rospy
from std_msgs.msg import String

if __name__=="__main__":
    rospy.init_node("yao_node")
    rospy.logwarn("辅助上线")
    pub=rospy.Publisher("help_me_get_more_score",String,queue_size=10)
    rate=rospy.Rate(10)
    msg=String()
    while not rospy.is_shutdown():
        msg.data="带我飞我陪你睡"
        pub.publish(msg)
        rate.sleep()