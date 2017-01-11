
#include "anchor_point.h"

namespace tnr {
    AnchorPoint::AnchorPoint(const PointCloud& pointcloud, const Pose& pose) :
        position(pose), pointcloud(pointcloud) {}

    AnchorPoint AnchorPoint::from_json(const Json::Value& j) {
        Pose pose = Pose::from_json(j["pose"]);
        PointCloud pointcloud = j["pointcloud"].asString();

        return AnchorPoint(pointcloud, pose);
    }

}
