#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

geometry_msgs::Twist velUpdate;

void velCallback(const geometry_msgs::Twist::ConstPtr& vel)
{

	velUpdate.linear.x = vel->linear.x;
	velUpdate.linear.y = vel->linear.y;
	velUpdate.angular.z = vel->angular.z;

}

int main(int argc, char** argv) {
    ros::init(argc, argv, "state_publisher_tutorials");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
	ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 10);
	
    tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(20);

    const double degree = M_PI/180;

    // message declarations
    geometry_msgs::TransformStamped odom_trans;
    sensor_msgs::JointState joint_state;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_footprint";

	//velocity
	double vx = 0.0;
	double vy = 0.0;
	double vth = 0.0;
	
	//position
	double x = 0.0;
	double y = 0.0;
	double th = 0.0;

	ros::Time current_time;
	ros::Time last_time;
	current_time = ros::Time::now();
	last_time = ros::Time::now();

    while (ros::ok()) {
		
		current_time = ros::Time::now();
		
		double dt = (current_time - last_time).toSec();

		double delta_x = (vx * cos(th) - vy * sin(th)) * dt;
		double delta_y = (vx * sin(th) + vy * cos(th)) * dt;
		double delta_th = vth * dt;

		x += delta_x;
		y += delta_y;
		th += delta_th;

		geometry_msgs::Quaternion odom_quat;
		odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,th);
	
        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(7);
        joint_state.position.resize(7);
		joint_state.name[0] ="base_to_wheel1";
        joint_state.position[0] = 0;
		joint_state.name[1] ="base_to_wheel2";
        joint_state.position[1] = 0;
		joint_state.name[2] ="base_to_wheel3";
        joint_state.position[2] = 0;
		joint_state.name[3] ="base_to_wheel4";
        joint_state.position[3] = 0;
		joint_state.name[4] = "base_footprint_joint";
		joint_state.position[4] = 0;
	
		
        // update transform
        odom_trans.header.stamp = ros::Time::now();
        odom_trans.transform.translation.x = cos(th);
        odom_trans.transform.translation.y = sin(th);
        odom_trans.transform.translation.z = 0.0;
        odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(th);

		//filling odometry
		nav_msgs::Odometry odom;
		odom.header.stamp = current_time;
		odom.header.frame_id = "odom";
		odom.child_frame_id = "base_footprint";	

		//position
		odom.pose.pose.position.x = x;
		odom.pose.pose.position.y = y;
		odom.pose.pose.position.z = 0.0;
		odom.pose.pose.orientation = odom_quat;

		//velocity
		odom.twist.twist.linear.x = vx;
		odom.twist.twist.linear.y = vy;		
		odom.twist.twist.linear.z = 0.0;
		odom.twist.twist.angular.x = 0.0;
		odom.twist.twist.angular.y = 0.0;
		odom.twist.twist.angular.z = vth;

		last_time = current_time;

        //send the joint state and transform
        joint_pub.publish(joint_state);
        broadcaster.sendTransform(odom_trans);
		odom_pub.publish(odom);


        // This will adjust as needed per iteration
        loop_rate.sleep();
    }

    return 0;
}


