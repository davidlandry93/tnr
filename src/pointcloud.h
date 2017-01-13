#ifndef TNR_POINTCLOUD_H
#define TNR_POINTCLOUD_H

#include <string>

#include <json/json.h>

namespace tnr {
    class PointCloud {
    public:
        PointCloud(const std::string& name);
        Json::Value to_json() const;

    private:
        std::string name;
    };
}

#endif
