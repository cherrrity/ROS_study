#include "ros/ros.h"
#include "message/Message1.h"
#include "message/Message2.h"

message::Message2 msg_node2;

class Node2
{
public:
    Node2(){
        // pub
        ros_node2_pub_ = nh_.advertise<message::Message2>("node2_msg",10);

        //sub
        ros_node2_sub_from1_ = nh_.subscribe("node1_msg", 10, &Node2::msgCallbackfrom1, this);
    }

    void msgCallbackfrom1(const message::Message1::ConstPtr& msg){
        // log
        ROS_INFO("recieve MSG1 seq = %d", msg->header.seq);
        ROS_INFO("recieve MGS1 stamp = %d", msg->header.stamp);
        ROS_INFO("recieve MSG1 from0 = %d", msg->from0);
        ROS_INFO("recieve MSG1 from3 = %d", msg->from3);

        // header
        msg_node2.header.seq = msg->header.seq;
        msg_node2.header.stamp = msg->header.stamp;
        msg_node2.header.frame_id = msg->header.frame_id;

        // data
        msg_node2.frandom2 = msg->from0 * 0.1;
        publish();
    }

    void publish(){
        ros::Rate loop_rate(10);

        // print msg
        ROS_INFO("MSG2 send seq = %d", msg_node2.header.seq);
        ROS_INFO("MSG2 send timestamp = %d", msg_node2.header.stamp);
        ROS_INFO("MSG2 send frandom2 = %lf", msg_node2.frandom2);

        ros_node2_pub_.publish(msg_node2);
        loop_rate.sleep();
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher ros_node2_pub_;
    ros::Subscriber ros_node2_sub_from1_;
};


int main(int argc, char **argv)
{
        ros::init(argc, argv, "node2");

        Node2 node2;

        ros::spin();

        return 0;
}
