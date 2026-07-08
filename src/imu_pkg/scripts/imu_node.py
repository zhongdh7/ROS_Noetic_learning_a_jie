#!/usr/bin/env python3
#coding=utf-8
import rospy
from sensor_msgs.msg import Imu
from tf.transformations import euler_from_quaternion
import math
from geometry_msgs.msg import Twist

def imu_callback(msg: Imu):
    global vel_pub
    if msg.orientation_covariance[0]<0:
        rospy.logwarn("数据不存在")
        return
    quaternion =[
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w
    ]
    (roll,pitch,yaw)=euler_from_quaternion(quaternion)
    roll=roll*180/math.pi
    pitch=pitch*180/math.pi
    yaw=yaw*180/math.pi
    rospy.loginfo(f"滚转角:{round(roll,2)},俯仰角:{round(pitch,2)},偏航角:{round(yaw,2)}")

    target_angle=-90
    diff_angle=target_angle-yaw
    vel_cmd=Twist()
    vel_cmd.angular.z=diff_angle*0.01
    vel_cmd.linear.x=0.2
    vel_pub.publish(vel_cmd)

    return

if __name__=="__main__":
    rospy.init_node("imu_node")
    vel_pub=rospy.Publisher("/cmd_vel",Twist,queue_size=10)
    imu_sub=rospy.Subscriber("/imu/data",Imu,imu_callback,queue_size=100)
    rospy.spin()