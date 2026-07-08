#! /usr/bin/env python3
#coding=utf-8
import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

n_count=0
def lidar_callback(msg: LaserScan):
    global vel_pub, n_count
    rospy.loginfo(f"正前方物体的距离为:{msg.ranges[180]}m")
    distance = msg.ranges[180]
    vel_cmd=Twist()
    if n_count>0:
        n_count-=1
        return 
    if distance<1.5:
        vel_cmd.angular.z=0.3
        n_count=50
    else:
        vel_cmd.linear.x=0.05
    vel_pub.publish(vel_cmd)


if __name__=="__main__":
    rospy.init_node("lidar_node")
    sub=rospy.Subscriber("/scan",LaserScan,lidar_callback,queue_size=100)
    vel_pub=rospy.Publisher("/cmd_vel",Twist,queue_size=100)
    rospy.spin()