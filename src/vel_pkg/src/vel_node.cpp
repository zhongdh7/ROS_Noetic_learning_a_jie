#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

using geometry_msgs::Twist;
int main(int argc,char** argv)
{
    ros::init(argc,argv,"vel_node");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<Twist>("/cmd_vel",100);

    Twist vel_msgs;
    vel_msgs.linear.x=0;
    vel_msgs.linear.y=0;
    vel_msgs.linear.z=0;
    vel_msgs.angular.x=0;
    vel_msgs.angular.z=1;
    vel_msgs.angular.y=0;

    ros::Rate vel_rate(30);
    while(ros::ok())
    {
        pub.publish(vel_msgs);
        vel_rate.sleep();
    }
    return 0;
}