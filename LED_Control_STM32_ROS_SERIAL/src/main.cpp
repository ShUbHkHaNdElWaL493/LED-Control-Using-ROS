#include <ros.h>
#include <std_msgs/Bool.h>

ros::NodeHandle nh;

void messageRead( const std_msgs::Bool& toggle_msg)
{
  if (toggle_msg.data)
  {
    digitalWrite(PC13, HIGH);
  } else
  {
    digitalWrite(PC13, LOW);
  }
}

ros::Subscriber<std_msgs::Bool> sub("toggleLED", &messageRead);

void setup()
{
  pinMode(PC13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}