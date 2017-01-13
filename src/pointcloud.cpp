
#include "pointcloud.h"

namespace tnr {
    PointCloud::PointCloud(const std::string& name) : name(name) {}

    PointCloud::PointCloud(const PointCloud& pointcloud) : name(pointcloud.name) {}

    Json::Value PointCloud::to_json() const {
        return name;
    }
}
