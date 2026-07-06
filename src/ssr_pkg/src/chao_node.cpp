#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "chao_node");
    std::cout << "国服马超带飞" << std::endl;

    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("lets_go_to_play", 10);
    ros::Rate loop_rate(10.0);

    std_msgs::String msg;
    while (ros::ok())
    {
        // std::cout << "我要刷屏了" << std::endl;
        msg.data = "mao chao to carry fly";
        pub.publish(msg);
        loop_rate.sleep();
    }
    return 0;
}