#! /usr/bin/env python3
#coding=utf-8
import rospy
from geometry_msgs.msg import Twist

if __name__=="__main__":
    rospy.init_node("vel_node")
    pub=rospy.Publisher("/cmd_vel",Twist,queue_size=10)
    vel_rate=rospy.Rate(30)
    msg=Twist()

    msg.linear.x=0.1
    msg.linear.y=0
    msg.linear.z=0
    msg.angular.z=0.6
    msg.angular.y=0
    msg.angular.x=0

    while not rospy.is_shutdown():
        pub.publish(msg)
        vel_rate.sleep()