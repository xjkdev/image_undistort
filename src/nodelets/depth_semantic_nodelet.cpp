#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>

#include "image_undistort/depth_semantic.h"

namespace image_undistort {

class DepthSemanticNodelet : public nodelet::Nodelet {
  virtual void onInit() {
    try {
      depth_ = std::make_shared<DepthSemantic>(getNodeHandle(), getPrivateNodeHandle());
    } catch (std::runtime_error e) {
      ROS_ERROR("%s", e.what());
    }
  }

  std::shared_ptr<DepthSemantic> depth_;
};
}  // namespace image_undistort

PLUGINLIB_EXPORT_CLASS(image_undistort::DepthSemanticNodelet, nodelet::Nodelet);
