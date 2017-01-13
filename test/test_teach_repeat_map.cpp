
#include <iostream>
#include <fstream>

#include "gtest/gtest.h"
#include "teach_and_repeat_map.h"

namespace tnr {
    TEST(TeachRepeatMapTest, AllAnchorDeserialized) {
        std::ifstream testfile;
        testfile.open("teachrepeat.json");

        TeachAndRepeatMap tnrmap;
        testfile >> tnrmap;

        ASSERT_EQ(2, tnrmap.n_anchor_points());
    }

    TEST(TeachRepeatMapTest, FirstAnchorIsCorrect) {
        std::ifstream testfile;
        testfile.open("teachrepeat.json");

        TeachAndRepeatMap tnrmap;
        testfile >> tnrmap;

        ASSERT_EQ("0001.vtk", (*tnrmap.begin()).get_pointcloud().name);
        ASSERT_EQ(1.0, (*tnrmap.begin()).get_pose().position.y);
    }
}
