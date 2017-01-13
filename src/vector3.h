#ifndef TNR_VECTOR_3_H
#define TNR_VECTOR_3_H

#include <iostream>

#include <json/value.h>

namespace tnr {
    struct Vector3 {
        float x,y,z;

        Vector3() : x(0), y(0), z(0) {}
        Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

        Json::Value to_json() const {
            Json::Value j;
            j["x"] = x;
            j["y"] = y;
            j["z"] = z;

            return j;
        }

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
