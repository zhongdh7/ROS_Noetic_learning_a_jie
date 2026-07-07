#! /usr/bin/env python3
#coding=utf-8
import rospy
from sensor_msgs.msg import LaserScan

def lidar_callback(msg: LaserScan):
    rospy.loginfo(f"正前方物体的距离为:{msg.ranges[180]}m")

if __name__=="__main__":
    rospy.init_node("lidar_node")
    sub=rospy.Subscriber("/scan",LaserScan,lidar_callback,queue_size=100)
    rospy.spin()