#include "ros/ros.h"
#include "message/Message0.h"
#include "message/Message1.h"
#include "message/Message3.h"

message::Message1 msg_node1;

class Node1
{
public:
    Node1(){

        msg_node1.from0 = 0;
        msg_node1.from3 = 0.0;

        // pub
        ros_node1_pub_ = nh_.advertise<message::Message1>("node1_msg",10);

        //sub
        ros_node1_sub_from0_ = nh_.subscribe("node0_msg", 10, &Node1::msgCallbackfrom0, this);
        ros_node1_sub_from3_ = nh_.subscribe("node3_msg", 10, &Node1::msgCallbackfrom3, this);
    }

    void msgCallbackfrom0(const message::Message0::ConstPtr& msg){
        // log
        ROS_INFO("recieve MSG0 seq = %d", msg->header.seq);
        ROS_INFO("recieve MGS0 stamp = %d", msg->header.stamp);
        ROS_INFO("recieve MSG0 random = %d", msg->random);

        // header
        msg_node1.header.seq = msg->header.seq;
        msg_node1.header.stamp = msg->header.stamp;
        msg_node1.header.frame_id = msg->header.frame_id;

        // data
        msg_node1.from0 = msg->random + 3;
        publish();
    }

    void msgCallbackfrom3(const message::Message3::ConstPtr& msg){
        // log
        ROS_INFO("recieve MSG3 seq = %d", msg->header.seq);
        ROS_INFO("recieve MGS3 stamp = %d", msg->header.stamp);
        ROS_INFO("recieve MSG3 frandom3 = %lf", msg->frandom3);

        // header
        msg_node1.header.seq = msg->header.seq;
        msg_node1.header.stamp = msg->header.stamp;
        msg_node1.header.frame_id = msg->header.frame_id;

        // data
        msg_node1.from3 = msg->frandom3 / 10;
        publish();
    }

    void publish(){
        ros::Rate loop_rate(10);

        msg_node1.random = 7;

        // print msg
        ROS_INFO("MSG1 send seq = %d", msg_node1.header.seq);
        ROS_INFO("MSG1 send timestamp = %d", msg_node1.header.stamp);
        ROS_INFO("MSG1 send random = %d", msg_node1.random);
        ROS_INFO("MSG1 send from0 = %d", msg_node1.from0);
        ROS_INFO("MSG1 send from3 = %d", msg_node1.from3);

        ros_node1_pub_.publish(msg_node1);
        loop_rate.sleep();
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher ros_node1_pub_;
    ros::Subscriber ros_node1_sub_from0_;
    ros::Subscriber ros_node1_sub_from3_;
};


int main(int argc, char **argv)
{
        ros::init(argc, argv, "node1");

        Node1 node1;

        ros::spin();

        return 0;
}
