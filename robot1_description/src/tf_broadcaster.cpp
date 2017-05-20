#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robot_tf_publisher");
	ros::NodeHandle n;

	ros::Rate r(20);
	
	tf::TransformBroadcaster broadcaster;
	
	while (n.ok()){
		broadcaster.sendTransform(
			tf::StampedTransform(
				tf::Transform(tf::Quaternion(0,0,0,0), tf::Vector3(0,0,0.5)),
				ros::Time::now(), "base_link", "base_footprint"));
		r.sleep();
	}
}
