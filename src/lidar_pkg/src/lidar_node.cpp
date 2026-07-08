#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

ros::Publisher vel_pub;
using sensor_msgs::LaserScan;
int n_count=0;
void lidar_callback(const LaserScan msg)
{
    ROS_INFO("正前方的距离是:%fm", msg.ranges[180]);
    if(n_count>0)
    {
        n_count--;
        return;
    }
    geometry_msgs::Twist vel_cmd;
    if(msg.ranges[180]<1.5)
    {
        vel_cmd.angular.z=0.3;
        n_count=50;
    }
    else
    {
        vel_cmd.linear.x=0.1;
    }
    vel_pub.publish(vel_cmd);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "lidar_node");
    ros::NodeHandle nh;
    //这个地方调用回调函数的频率是取决于激光雷达扫描的频率的,如果雷达是10hz那么这个回调函数就是10hz,如果雷达是20hz那么这个回调函数就是20hz
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
    ros::Subscriber sub = nh.subscribe("/scan", 100, lidar_callback);

    ros::spin();//这个就是等价于之前的spinonce不断while循环这个时候只用一个就可以让程序一直回看之前的可以回调的函数
    return 0;
}