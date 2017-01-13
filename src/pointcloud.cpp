
#include "pointcloud.h"

namespace tnr {
    PointCloud::PointCloud(const std::string& name) : name(name) {}

    Json::Value PointCloud::to_json() const {
        return name;
    }
}
