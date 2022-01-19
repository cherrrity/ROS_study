#include "ros/ros.h"
#include "message/Message2.h"
#include "message/Message3.h"

message::Message3 msg_node3;

class Node3
{
public:
    Node3(){
        // pub
        ros_node3_pub_ = nh_.advertise<message::Message3>("node3_msg",10);

        //sub
        ros_node3_sub_from2_ = nh_.subscribe("node2_msg", 10, &Node3::msgCallbackfrom2, this);
    }

    void msgCallbackfrom2(const message::Message2::ConstPtr& msg){
        // log
        ROS_INFO("recieve MSG2 seq = %d", msg->header.seq);
        ROS_INFO("recieve MGS2 stamp = %d", msg->header.stamp);
        ROS_INFO("recieve MSG2 frandom2 = %lf", msg->frandom2);

        // header
        msg_node3.header.seq = msg->header.seq;
        msg_node3.header.stamp = msg->header.stamp;
        msg_node3.header.frame_id = msg->header.frame_id;

        // data
        msg_node3.frandom3 = msg->frandom2 * 1000;

        publish();
    }

    void publish(){
        ros::Rate loop_rate(10);

        // print msg
        ROS_INFO("MSG3 send seq = %d", msg_node3.header.seq);
        ROS_INFO("MSG3 send timestamp = %d", msg_node3.header.stamp);
        ROS_INFO("MSG3 send frandom3 = %lf", msg_node3.frandom3);

        ros_node3_pub_.publish(msg_node3);
        loop_rate.sleep();
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher ros_node3_pub_;
    ros::Subscriber ros_node3_sub_from2_;
};


int main(int argc, char **argv)
{
        ros::init(argc, argv, "node3");

        Node3 node3;

        ros::spin();

        return 0;
}
