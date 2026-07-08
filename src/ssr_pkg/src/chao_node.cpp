#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>
#include "qq_msgs/Carry.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "chao_node");
    std::cout << "国服马超带飞" << std::endl;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<qq_msgs::Carry>("lets_go_to_play", 10);
    ros::Rate loop_rate(10.0);

    qq_msgs::Carry msg;
    while (ros::ok())
    {
        // std::cout << "我要刷屏了" << std::endl;
        msg.grade="王者";
        msg.star=50;
        msg.data = "马超我带飞";
        pub.publish(msg);
        loop_rate.sleep(); // 这个地方到这里了之后程序会停住
    }
    return 0;
}