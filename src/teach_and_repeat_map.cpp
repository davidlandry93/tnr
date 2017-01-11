
#include <assert.h>
#include <iostream>
#include "teach_and_repeat_map.h"

namespace tnr {
    void TeachAndRepeatMap::from_json(const Json::Value& j) {
        assert(j.isArray());
        anchor_points.clear();

        for(auto item : j["anchors"]) {
            anchor_points.push_back(AnchorPoint::from_json(j));
        }
    }

    std::ostream& operator<<(std::ostream& os, const TeachAndRepeatMap& map) {

        return os;
    }

    std::istream& operator>>(std::istream& is, TeachAndRepeatMap& map) {
        Json::Value j;
        is >> j;

        std::cout << "Done parsing.";

        map.from_json(j);

        return is;
    }
}
