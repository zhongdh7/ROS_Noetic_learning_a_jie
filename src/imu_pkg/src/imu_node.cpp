#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include "tf/tf.h"
#include "geometry_msgs/Twist.h"

ros::Publisher vel_pub;

void imu_callback(const sensor_msgs::Imu msg)
{
    if (msg.orientation_covariance[0] == -1)
    {
        ROS_INFO("the data is not exist");
        return;
    }
    // 将四元素转化成欧拉角
    tf::Quaternion quaternion(
        msg.orientation.x,
        msg.orientation.y,
        msg.orientation.z,
        msg.orientation.w);
    double roll, pitch, yaw; // 对应的是xyz方向上的转动的转向角度
    tf::Matrix3x3(quaternion).getRPY(roll, pitch, yaw);
    roll = roll * 180 / M_PI;
    pitch = pitch * 180 / M_PI;
    yaw = yaw * 180 / M_PI;
    ROS_INFO("滚转角:%.2f,俯仰角:%.2f,偏航角:%.2f", roll, pitch, yaw);

    double target_yaw = 90;
    double diff_angle = target_yaw - yaw;
    geometry_msgs::Twist vel_cmd;
    vel_cmd.angular.z = diff_angle * 0.01;
    vel_cmd.linear.x = 1;
    vel_pub.publish(vel_cmd);
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "imu_node");
    ros::NodeHandle nh;
    vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    ros::Subscriber imu_sub = nh.subscribe("/imu/data", 50, imu_callback);
    ros::spin();
    return 0;
}