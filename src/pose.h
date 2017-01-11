#ifndef TNR_POSE_H
#define TNR_POSE_H

#include <json/value.h>

#include "vector3.h"
#include "quaternion.h"

namespace tnr {
    class Pose {
    public:
        Vector3 position;
        Quaternion orientation;

        Pose(const Vector3& position, const Quaternion& orientation);
        static Pose from_json(const Json::Value& j);
    };
}

#endif
