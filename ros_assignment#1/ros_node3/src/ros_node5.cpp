#include "ros/ros.h"
#include "message/Message2.h"
#include "message/Message3.h"

message::Message3 msg_node5;

class Node5
{
public:
    Node5(){
        // pub
        ros_node5_pub_ = nh_.advertise<message::Message3>("node5_msg",10);

        //sub
        ros_node5_sub_from2_ = nh_.subscribe("node2_msg", 10, &Node5::msgCallbackfrom2, this);
    }

    void msgCallbackfrom2(const message::Message2::ConstPtr& msg){
        // log
        ROS_INFO("recieve MSG2 seq = %d", msg->header.seq);
        ROS_INFO("recieve MGS2 stamp = %d", msg->header.stamp);
        ROS_INFO("recieve MSG2 frandom2 = %lf", msg->frandom2);

        // header
        msg_node5.header.seq = msg->header.seq;
        msg_node5.header.stamp = msg->header.stamp;
        msg_node5.header.frame_id = msg->header.frame_id;

        // data
        msg_node5.frandom3 = msg->frandom2 * 1000;

        publish();
    }

    void publish(){
        ros::Rate loop_rate(10);

        // print msg
        ROS_INFO("MSG5 send seq = %d", msg_node5.header.seq);
        ROS_INFO("MSG5 send timestamp = %d", msg_node5.header.stamp);
        ROS_INFO("MSG5 send frandom3 = %lf", msg_node5.frandom3);

        ros_node5_pub_.publish(msg_node5);
        loop_rate.sleep();
    }

private:
    ros::NodeHandle nh_;
    ros::Publisher ros_node5_pub_;
    ros::Subscriber ros_node5_sub_from2_;
};


int main(int argc, char **argv)
{
        ros::init(argc, argv, "ros_node5");

        Node5 node5;

        ros::spin();

        return 0;
}
