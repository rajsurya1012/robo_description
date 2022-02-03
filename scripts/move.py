#! /usr/bin/env python3
import rospy
from std_msgs.msg import Float64

def main():
    rospy.init_node("move")
    pub=rospy.Publisher("/robo/lbswirl_velocity_controller/command",Float64,queue_size=10)
    rate=rospy.Rate(10)
    while not rospy.is_shutdown():
        val=10
        rospy.loginfo(val)
        pub.publish(val)
        rate.sleep()

if __name__=='main':
    try:
        main()
    except rospy.ROSInterruptException:
        pass