#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include <std_srvs/Trigger.h>
#include <geometry_msgs/Twist.h>

/******************************************************
Buttons:
 0: A
 1: B
 2: X
 3: Y
 4: LB
 5: RB
 6: BACK
 7: START
 8: Logitech*
 9: Left Stick
10: Right Stick

 ******************************************************/

class Teleoperator
{
public:
	Teleoperator();
	
private:
	void joyCB(const sensor_msgs::Joy::ConstPtr& msg);

	ros::NodeHandle mNode;
	ros::Publisher mCommandPublisher;
	ros::Subscriber mJoySubscriber;
	
	int mAxisVelocity;
	int mAxisDirection;
	int mButtonMode;
	int mButtonStop;
	
	bool mButtonPressed;
};

Teleoperator::Teleoperator()
{
	// Button and Axis configuration
	mAxisVelocity = 4;
	mAxisDirection = 3;

	mButtonMode = 5;
	mButtonStop = 1;
	
	mCommandPublisher = mNode.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
	mJoySubscriber = mNode.subscribe<sensor_msgs::Joy>("joy", 10, &Teleoperator::joyCB, this);
	
	mButtonPressed = false;
}

void Teleoperator::joyCB(const sensor_msgs::Joy::ConstPtr& msg)
{
	// Ignore Button-Release events
	if(mButtonPressed)
	{
		mButtonPressed = false;
	} else
	{	
		geometry_msgs::Twist twist;
		if(msg->buttons[mButtonMode] == 1) {
			twist.linear.x = 0.4 * msg->axes[mAxisVelocity];
			twist.linear.y = 0.4 * msg->axes[mAxisDirection];
			twist.linear.z = 0;
			twist.angular.x = 0;
			twist.angular.y = 0;
			twist.angular.z = 0;
		} else {
			twist.linear.x = 0.4 * msg->axes[mAxisVelocity];
			twist.linear.y = 0;
			twist.linear.z = 0;
			twist.angular.x = 0;
			twist.angular.y = 0;
			twist.angular.z = 0.6 * msg->axes[mAxisDirection];
		}
		mCommandPublisher.publish(twist);
	}

	if(msg->buttons[mButtonStop])
	{
		geometry_msgs::Twist twist;
		twist.linear.x = 0;
		twist.linear.y = 0;
		twist.linear.z = 0;
		twist.angular.x = 0;
		twist.angular.y = 0;
		twist.angular.z = 0;
		mCommandPublisher.publish(twist);
	}
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "holobot_teleoperator");
	Teleoperator tele_op;
	ros::spin();
}
