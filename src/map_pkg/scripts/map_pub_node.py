#!/usr/bin/env python3
#coding=utf-8
import rospy
from nav_msgs.msg import OccupancyGrid

if __name__=="__main__":
    rospy.init_node("map_pub_node")
    pub=rospy.Publisher("/map",OccupancyGrid,queue_size=10)

    pub_rate=rospy.Rate(1)

    msg=OccupancyGrid()

    while not rospy.is_shutdown():
        msg.header.frame_id="map"
        msg.header.stamp=rospy.Time().now()
        
        msg.info.resolution=1
        msg.info.width=3
        msg.info.height=3
        msg.info.origin.position.x=-1
        msg.info.origin.position.z=1
        msg.info.origin.position.y=-1

        msg.data=[0 for i in range(msg.info.height*msg.info.width)]
        msg.data[0]=100
        msg.data[2]=-1
        msg.data[4]=100
        msg.data[6]=-1
        msg.data[8]=100

        pub.publish(msg)
        pub_rate.sleep()