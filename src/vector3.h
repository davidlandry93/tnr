#ifndef TNR_VECTOR_3_H
#define TNR_VECTOR_3_H

#include <json/value.h>

namespace tnr {
    struct Vector3 {
        float x,y,z;

        static Vector3 from_json(const Json::Value& j) {
            Vector3 vec;
            vec.x = j["x"].asFloat();
            vec.y = j["y"].asFloat();
            vec.z = j["z"].asFloat();

            return vec;
        }
    };
}

#endif
