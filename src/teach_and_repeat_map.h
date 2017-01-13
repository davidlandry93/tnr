#ifndef TNR_TEACH_REPEAT_MAP_H
#define TNR_TEACH_REPEAT_MAP_H

#include <iostream>
#include <vector>

#include <json/value.h>

#include "anchor_point.h"

namespace tnr {
    class TeachAndRepeatMap {
    public:
        int n_anchor_points() const;

        std::vector<AnchorPoint>::const_iterator begin() const;
        std::vector<AnchorPoint>::const_iterator end() const;

        void from_json(const Json::Value& j);
        Json::Value to_json() const;
        void from_csv(std::istream& is);
        friend std::ostream& operator<<(std::ostream& os, const TeachAndRepeatMap& map);
        friend std::istream& operator>>(std::istream& is, TeachAndRepeatMap& map);
    private:
        std::vector<AnchorPoint> anchor_points;
    };
}

#endif
