
#include <iostream>
#include <fstream>

#include "gtest/gtest.h"
#include "teach_and_repeat_map.h"

namespace tnr {
    TEST(TeachRepeatMapTest, DeserializationTest) {
        std::ifstream testfile;
        testfile.open("teachrepeat.json");

        TeachAndRepeatMap tnrmap;
        testfile >> tnrmap;

        ASSERT_EQ(2, tnrmap.n_anchor_points());
    }
}
