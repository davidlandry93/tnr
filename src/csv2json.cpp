
#include <fstream>

#include <gflags/gflags.h>

#include "teach_and_repeat_map.h"

using namespace tnr;

DEFINE_string(input, "", "Path to the old csv teach and repeat map.");
DEFINE_string(output, "", "Path where the json file should be saved.");

int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    std::string usage("Convert a csv teach and repeat map to the new json format.");
    usage += argv[0];
    usage += "-input anchorPoints.apd -outpu anchors.json";

    gflags::SetUsageMessage(usage);

    if(FLAGS_input.empty()) {
        std::cout << "No input file provided." << std::endl;
        return 0;
    }

    if(FLAGS_output.empty()) {
        std::cout << "No output destination provided." << std::endl;
        return 0;
    }

    std::ifstream input;
    input.open(FLAGS_input);

    TeachAndRepeatMap map;
    map.from_csv(input);
    input.close();

    std::ofstream output;
    output.open(FLAGS_output);
    output << map;
    output.close();

    return 0;
}

