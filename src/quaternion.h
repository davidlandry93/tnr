#ifndef TNR_QUATERNION_H
#define TNR_QUATERNION_H

#include <json/value.h>

namespace tnr {
    struct Quaternion {
        float i,j,k;
        float w;

        Quaternion() : i(0), j(0), k(0), w(0) {}
        Quaternion(float i, float j, float k, float w) : i(i), j(j), k(k), w(w) {}

        Json::Value to_json() const {
            Json::Value json;
            json["i"] = i;
            json["j"] = j;
            json["k"] = k;
            json["w"] = w;

            return json;
        }

        static Quaternion from_json(const Json::Value& j) {
            Quaternion q;
            q.i = j["i"].asFloat();
            q.j = j["j"].asFloat();
            q.k = j["k"].asFloat();
            q.w = j["w"].asFloat();

            return q;
        }
    };
}

#endif
