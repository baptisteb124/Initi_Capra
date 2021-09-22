#include <ros/ros.h>
#include "projet_baptiste/file_class.h"

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

float distance3d(float x1,float y1, float z1, float x2, float y2, float z2)
{
    return pow((pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2)),0.5);
}

float aeratrig(float a, float b, float c)
{
    float s=(a+b+c)/2;
    //ROS_INFO("S : %f",(float) s);
    return pow((s*(s-a)*(s-b)*(s-c)),0.5);
}

bool air(projet_baptiste::file_class::Request &req,
        projet_baptiste::file_class::Response &res){
    float distA=distance3d(req.X1,req.Y1,req.Z1,req.X2,req.Y2,req.Z2);
    ROS_INFO("Distance AB: %f",(float) distA);
    float distB=distance3d(req.X2,req.Y2,req.Z2,req.X3,req.Y3,req.Z3);
    ROS_INFO("Distance BC: %f",(float) distB);
    float distC=distance3d(req.X3,req.Y3,req.Z3,req.X1,req.Y1,req.Z1);
    ROS_INFO("Distance CA: %f",(float) distC);

    float surface=aeratrig(distA,distB,distC);
    ROS_INFO("Surface calculed");
    res.surface=surface;
    ROS_INFO("Send to client ...");
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server_msg");
    ros::NodeHandle nl;

    ros::ServiceServer service = nl.advertiseService("Calculate_three_dots",air);
    ROS_INFO("Ready to calculate");
    ros::spin();

    return 0;
}