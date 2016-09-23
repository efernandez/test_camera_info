
#include <ros/ros.h>
#include <camera_info_manager/camera_info_manager.h>
#include <sensor_msgs/CameraInfo.h>

#include <iostream>

void print(const sensor_msgs::CameraInfo& ci)
{
  std::cout << "header: " << std::endl;
  std::cout << "  " << ci.header << std::endl;

  std::cout << "height: " << ci.height << std::endl;

  std::cout << "width: " << ci.width << std::endl;

  std::cout << "distortion_model: " << ci.distortion_model << std::endl;

  std::cout << "D[" << ci.D.size() << "]" << std::endl;
  for (size_t i = 0; i < ci.D.size(); ++i)
  {
    std::cout << "  D[" << i << "]: " << ci.D[i] << std::endl;
  }

  std::cout << "K[" << ci.K.size() << "]" << std::endl;
  for (size_t i = 0; i < ci.K.size(); ++i)
  {
    std::cout << "  K[" << i << "]: " << ci.K[i] << std::endl;
  }

  std::cout << "R[" << ci.R.size() << "]" << std::endl;
  for (size_t i = 0; i < ci.R.size(); ++i)
  {
    std::cout << "  R[" << i << "]: " << ci.R[i] << std::endl;
  }

  std::cout << "P[" << ci.P.size() << "]" << std::endl;
  for (size_t i = 0; i < ci.P.size(); ++i)
  {
    std::cout << "  P[" << i << "]: " << ci.P[i] << std::endl;
  }

  std::cout << "binning_x: " << ci.binning_x << std::endl;

  std::cout << "binning_y: " << ci.binning_y << std::endl;

  std::cout << "roi: " << std::endl;
  std::cout << "  " << ci.roi << std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "test_camera_info");

  ros::NodeHandle nh;

  camera_info_manager::CameraInfoManager cim(nh, "camera", "/tmp");

  std::cout << "Empty: " << std::endl;
  sensor_msgs::CameraInfo ci_empty;

  std::cout << "Camera Info (print): "; print(ci_empty);
  std::cout << "Camera Info: " << ci_empty << std::endl;

  std::cout << "Empty assigned: " << std::endl;
  sensor_msgs::CameraInfo ci_empty_assigned = sensor_msgs::CameraInfo();

  std::cout << "Camera Info (print): "; print(ci_empty_assigned);
  std::cout << "Camera Info: " << ci_empty_assigned << std::endl;

  std::cout << "Before shutdown: " << std::endl;
  std::cout << (ros::ok() ? "OK" : "NO-OK") << std::endl;

  sensor_msgs::CameraInfo ci_before = cim.getCameraInfo();

  std::cout << "Camera Info (print): "; print(ci_before);
  std::cout << "Camera Info: " << ci_before << std::endl;

  ros::shutdown();

  std::cout << "After shutdown: " << std::endl;
  std::cout << (ros::ok() ? "OK" : "NO-OK") << std::endl;

  sensor_msgs::CameraInfo ci_after = cim.getCameraInfo();

  std::cout << "Camera Info (print): "; print(ci_after);
  std::cout << "Camera Info: " << ci_after << std::endl;

  std::cout << "DONE" << std::endl;

  return EXIT_SUCCESS;
}

