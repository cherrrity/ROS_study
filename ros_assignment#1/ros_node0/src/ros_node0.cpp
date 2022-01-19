#include "ros/ros.h"
#include "message/Message0.h"
#include <string>

message::Message0 msg;

int main(int argc, char **argv)
{
        ros::init(argc, argv, "node0");
	ros::NodeHandle nh;
	

	// topic setting
        ros::Publisher ros_node0_pub = nh.advertise<message::Message0>("node0_msg",10);

	// loop setting
	ros::Rate loop_rate(10);
	
	int count = 0;

        while(ros::ok)
	{
		//header
                msg.header.seq = count;
                msg.header.stamp = ros::Time::now();
                msg.header.frame_id = "yejin";
		
		//msg
                msg.random = 97;

		// print msg
                ROS_INFO("MSG0 send seq = %d", msg.header.seq);
                ROS_INFO("MSG0 send timestamp = %d", msg.header.stamp);
                ROS_INFO("MSG0 send msg = %d", msg.random);

                ros_node0_pub.publish(msg);

		loop_rate.sleep();

		++count;
	}
	
        return 0;
}
