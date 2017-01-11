#ifndef TNR_ANCHOR_POINT_H
#define TNR_ANCHOR_POINT_H

#include <json/json.h>

#include "pose.h"
#include "pointcloud.h"

namespace tnr {
    class AnchorPoint {
    public:
        AnchorPoint(const PointCloud& pointcloud, const Pose& pose);

        static AnchorPoint from_json(const Json::Value& j);
    private:
        Pose position;
        PointCloud pointcloud;
    };
}

#endif
