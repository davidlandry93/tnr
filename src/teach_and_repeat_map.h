#ifndef TNR_TEACH_REPEAT_MAP_H
#define TNR_TEACH_REPEAT_MAP_H

#include <iostream>
#include <vector>

#include <json/value.h>

#include "anchor_point.h"

namespace tnr {
    class TeachAndRepeatMap {
    public:
        void from_json(const Json::Value& j);
        friend std::ostream& operator<<(std::ostream& os, const TeachAndRepeatMap& map);
        friend std::istream& operator>>(std::istream& is, TeachAndRepeatMap& map);
    private:
        std::vector<AnchorPoint> anchor_points;
    };
}

#endif