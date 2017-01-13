
#include <assert.h>
#include <string>
#include <iostream>
#include <sstream>

#include "pointcloud.h"
#include "anchor_point.h"
#include "teach_and_repeat_map.h"

namespace tnr {
    int TeachAndRepeatMap::n_anchor_points() const {
        return anchor_points.size();
    }

    std::vector<AnchorPoint>::const_iterator TeachAndRepeatMap::begin() const {
        return anchor_points.begin();
    }

    std::vector<AnchorPoint>::const_iterator TeachAndRepeatMap::end() const {
        return anchor_points.end();
    }

    void TeachAndRepeatMap::from_csv(std::istream& is) {
        anchor_points.clear();

        std::string line_buffer;
        while(std::getline(is, line_buffer)) {
            std::stringstream ss(line_buffer);
            std::string value_buffer;

            std::getline(ss, value_buffer, ',');
            PointCloud pointcloud(value_buffer);

            std::getline(ss, value_buffer, ',');
            float x = std::stof(value_buffer);

            std::getline(ss, value_buffer, ',');
            float y = std::stof(value_buffer);

            std::getline(ss, value_buffer, ',');
            float z = std::stof(value_buffer);

            Vector3 position(x,y,z);

            std::getline(ss, value_buffer, ',');
            float i = std::stof(value_buffer);

            std::getline(ss, value_buffer, ',');
            float j = std::stof(value_buffer);

            std::getline(ss, value_buffer, ',');
            float k = std::stof(value_buffer);

            std::getline(ss, value_buffer);
            float w = std::stof(value_buffer);

            Quaternion orientation(i,j,k,w);

            AnchorPoint anchor_point(pointcloud, Pose(position, orientation));
            anchor_points.push_back(anchor_point);
        }
    }

    void TeachAndRepeatMap::from_json(const Json::Value& j) {
        assert(j["anchors"].isArray());
        anchor_points.clear();

        for(Json::Value const& item : j["anchors"]) {
            anchor_points.push_back(AnchorPoint::from_json(item));
        }
    }

    Json::Value TeachAndRepeatMap::to_json() const {
        Json::Value j;

        for(int i = 0; i < anchor_points.size(); i++) {
            j["anchors"][i] = anchor_points[i].to_json();
        }

        return j;
    }

    std::ostream& operator<<(std::ostream& os, const TeachAndRepeatMap& map) {
        os << map.to_json();
        return os;
    }

    std::istream& operator>>(std::istream& is, TeachAndRepeatMap& map) {
        Json::Value j;
        is >> j;

        map.from_json(j);

        return is;
    }
}
