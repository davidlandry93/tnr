#ifndef TNR_POINTCLOUD_H
#define TNR_POINTCLOUD_H

#include <string>

#include <json/json.h>

namespace tnr {
    class PointCloud {
    public:
        std::string name;

        PointCloud(const std::string& name);
        PointCloud(const PointCloud& pointcloud);
        Json::Value to_json() const;
    };
}

#endif
