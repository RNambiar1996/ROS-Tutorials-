#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>

ros::Publisher pub;

void cloud_cb (const pcl::PCLPointCloud2ConstPtr& input)
{

	pcl::PCLPointCloud2 cloud_filtered;
	pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
	sor.setInputCloud (input);
	sor.setLeafSize (0.01, 0.01, 0.01);
	sor.filter (cloud_filtered);
	// Publish the datasize
	pub.publish (cloud_filtered);

}

int main(int argc, char** argv)
{
	//Initialise ROS
	ros::init(argc,argv,"my_pcl_tutorials");
	ros::NodeHandle nh;
	ros::Subscriber sub = nh.subscribe("/camera/depth/points", 1, cloud_cb);
	pub = nh.advertise<sensor_msgs::PointCloud2> ("output",1);
	ros::spin();
}

