
#include <iostream>

#include "pose.h"

namespace tnr {
    Pose::Pose(const Vector3& position, const Quaternion& orientation) :
        position(position), orientation(orientation) {}

    Pose Pose::from_json(const Json::Value& j) {
        Vector3 position = Vector3::from_json(j["position"]);
        Quaternion orientation = Quaternion::from_json(j["orientation"]);

        return Pose(position, orientation);
    }

    Json::Value Pose::to_json() const {
        Json::Value j;
        j["position"] = position.to_json();
        j["orientation"] = orientation.to_json();

        return j;
    }
}
