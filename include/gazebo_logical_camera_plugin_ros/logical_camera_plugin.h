#pragma once

//Based on lucrezio_logical_camera plugin

#include <string>
#include <sstream>

#include <gazebo/common/Plugin.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/rendering/rendering.hh>
#include <gazebo/sensors/sensors.hh>
#include <ignition/math.hh>

#include <ros/ros.h>
#include <std_msgs/String.h>

//#include <gazebo_logical_camera_plugin_ros/LogicalImage.h>
#include <pose_selector/ObjectList.h>

namespace gazebo {
class LogicalCameraPlugin : public SensorPlugin{
public:
    LogicalCameraPlugin() : SensorPlugin(){}
    virtual ~LogicalCameraPlugin() {}

    virtual void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf);
protected:
    ros::NodeHandle *nh;
    ros::Publisher image_pub;
private:
    virtual void OnUpdate();
    std::string frameID;
    sensors::LogicalCameraSensorPtr parentSensor;
    event::ConnectionPtr updateConnection;
};
}
