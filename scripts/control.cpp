#include<ros/ros.h>
#include<std_msgs/Float64.h>
#include<iostream>

#include<stdio.h>

int main ( int argc, char **argv)
{

    std::cout<<" KEYBOARD CONTROLLER FOR FOUR INDEPENDENT STEERABLE WHEEL ROBOT \n";
    std::cout<<"W: Move Forward \n";
    std::cout<<"S: Move Backward \n";
    std::cout<<"D: Turn right \n";
    std::cout<<"A: Turn left \n";
    
    

    std_msgs::Float64 speed,rot,nspeed,halt;

    ros::init(argc,argv,"control");
    ros::NodeHandle n;
    ros::Publisher pub_lf_vel=n.advertise<std_msgs::Float64>("/robo/lfwheel_velocity_controller/command",10);
    ros::Publisher pub_lb_vel=n.advertise<std_msgs::Float64>("/robo/lbwheel_velocity_controller/command",10);
    ros::Publisher pub_rf_vel=n.advertise<std_msgs::Float64>("/robo/rfwheel_velocity_controller/command",10);
    ros::Publisher pub_rb_vel=n.advertise<std_msgs::Float64>("/robo/rbwheel_velocity_controller/command",10);
    ros::Publisher pub_lf_pos=n.advertise<std_msgs::Float64>("/robo/lfswirl_position_controller/command",10);
    ros::Publisher pub_lb_pos=n.advertise<std_msgs::Float64>("/robo/lbswirl_position_controller/command",10);
    ros::Publisher pub_rf_pos=n.advertise<std_msgs::Float64>("/robo/rfswirl_position_controller/command",10);
    ros::Publisher pub_rb_pos=n.advertise<std_msgs::Float64>("/robo/rbswirl_position_controller/command",10);
    speed.data=10.0;
    rot.data=0.1;
    nspeed.data=-10.0;
    halt.data=0;
    ros::Rate rate(10);
  
    
    while(ros::ok())
    {
        char cmd;
        std::cin>>cmd;
        
        if(cmd=='w' || cmd=='W')
        {
            pub_lf_vel.publish(speed);
            pub_lb_vel.publish(speed);
            pub_rf_vel.publish(speed);
            pub_rb_vel.publish(speed);
        }
        else if(cmd=='S' || cmd=='s')
        {
            pub_lf_vel.publish(nspeed);
            pub_lb_vel.publish(nspeed);
            pub_rf_vel.publish(nspeed);
            pub_rb_vel.publish(nspeed);
        }
        else if(cmd=='d' || cmd=='D')
        {
            rot.data+=0.1;
            pub_lf_pos.publish(rot);
            pub_lb_pos.publish(rot);
            pub_rf_pos.publish(rot);
            pub_rb_pos.publish(rot);
        }
        else if(cmd=='a' || cmd=='A')
        {
            rot.data-=0.1;
            pub_lf_pos.publish(rot);
            pub_lb_pos.publish(rot);
            pub_rf_pos.publish(rot);
            pub_rb_pos.publish(rot);
        }
        else if(cmd=='q' || cmd=='Q')
        {
            pub_lf_vel.publish(halt);
            pub_lb_vel.publish(halt);
            pub_rf_vel.publish(halt);
            pub_rb_vel.publish(halt);
            return 0;
        }
        else
        {
            pub_lf_vel.publish(halt);
            pub_lb_vel.publish(halt);
            pub_rf_vel.publish(halt);
            pub_rb_vel.publish(halt);
        }
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}