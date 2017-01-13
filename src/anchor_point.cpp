
#include "anchor_point.h"

namespace tnr {
    AnchorPoint::AnchorPoint(const PointCloud& pointcloud, const Pose& pose) :
        position(pose), pointcloud(pointcloud) {}

    PointCloud AnchorPoint::get_pointcloud() const {
        return pointcloud;
    }

    Pose AnchorPoint::get_pose() const {
        return position;
    }

    Json::Value AnchorPoint::to_json() const {
        Json::Value j;
        j["pointcloud"] = pointcloud.to_json();
        j["pose"] = position.to_json();

        return j;
    }

    AnchorPoint AnchorPoint::from_json(const Json::Value& j) {
        PointCloud pointcloud = j["pointcloud"].asString();
        Pose pose = Pose::from_json(j["pose"]);

        return AnchorPoint(pointcloud, pose);
    }
}
