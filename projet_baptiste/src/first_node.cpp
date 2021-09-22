#include <ros/ros.h>
#include "projet_baptiste/file_class.h"

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "client_msg");
    if(argc !=10)
    {
        ROS_INFO("Usage inccorect, Entrez les coordonnées des trois points du triangle");
        return 1;
    }
    ros::NodeHandle nl;

    ros::ServiceClient client = nl.serviceClient<projet_baptiste::file_class>("Calculate_three_dots");
    projet_baptiste::file_class srv_point;
    
    srv_point.request.X1=atoll(argv[1]);
    srv_point.request.Y1=atoll(argv[2]);
    srv_point.request.Z1=atoll(argv[3]);
    ROS_INFO("Premier point A (%f,%f,%f)",srv_point.request.X1,srv_point.request.Y1,srv_point.request.Z1);

    srv_point.request.X2=atoll(argv[4]);
    srv_point.request.Y2=atoll(argv[5]);
    srv_point.request.Z2=atoll(argv[6]);
    ROS_INFO("Deuxième point B (%f,%f,%f)",srv_point.request.X2,srv_point.request.Y2,srv_point.request.Z2);
    
    srv_point.request.X3=atoll(argv[7]);
    srv_point.request.Y3=atoll(argv[8]);
    srv_point.request.Z3=atoll(argv[9]);
    ROS_INFO("Troisème point C (%f,%f,%f)",srv_point.request.X3,srv_point.request.Y3,srv_point.request.Z3);

    if(client.call(srv_point))
    {
        ROS_INFO("RESULTAT Aire triangle: %f",(float)srv_point.response.surface);
    }
    else
    {
        ROS_INFO("FAIL");
        return 1;
    }

    return 0; 
}
