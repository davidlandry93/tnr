#ifndef TNR_POINTCLOUD_H
#define TNR_POINTCLOUD_H

#include <string>

namespace tnr {
    class PointCloud {
    public:
        PointCloud(const std::string& name);
    private:
        std::string name;
    };
}

#endif
