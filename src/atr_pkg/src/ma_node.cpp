#include <ros/ros.h>
#include <iostream>
#include <std_msgs/String.h>

// 回调函数对接受的消息进行处理
void chao_callback(std_msgs::String msg)
{
    // std::cout << msg.data << std::endl;
    ROS_INFO("%s", msg.data.c_str()); // 这个用于输出日志这个必须用C语言的格式化输出来输出
}

void yao_callback(std_msgs::String msg)
{
    ROS_WARN("%s", msg.data.c_str());
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, ""); // 这个设置中文输出
    ros::init(argc, argv, "ma_node");
    std::cout << "马可上线了" << std::endl;
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("lets_go_to_play", 10, chao_callback);
    ros::Subscriber sub2 = nh.subscribe("help_me_get_more_score", 10, yao_callback);

    while (ros::ok())
    {
        ros::spinOnce(); // 用于不断检查之前的回调函数能不能继续调用
    }

    return 0;
}