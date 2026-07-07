#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>

using sensor_msgs::LaserScan;
void lidar_callback(const LaserScan msg)
{
    ROS_INFO("正前方的距离是:%fm", msg.ranges[180]);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "lidar_node");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/scan", 100, lidar_callback);
    ros::spin();//这个就是等价于之前的spinonce不断while循环这个时候只用一个就可以让程序一直回看之前的可以回调的函数
    return 0;
}