#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yao_node");
    std::cout << "辅助已经上号" << std::endl;
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("help_me_get_more_score", 10);

    ros::Rate loop_rate(10.0);
    std_msgs::String msg;
    while (ros::ok())
    {
        msg.data = "带我飞我陪你睡";
        pub.publish(msg);
        loop_rate.sleep();
    }

    return 0;
}