#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

void chao_callback(std_msgs::String msg)
{
    std::cout << msg.data << std::endl;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "ma_node");
    std::cout << "马可上线了" << std::endl;
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("lets_go_to_play", 10, chao_callback);

    while (ros::ok())
    {
        ros::spinOnce();//用于不断检查之前的回调函数能不能继续调用
    }

    return 0;
}