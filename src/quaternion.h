#ifndef TNR_QUATERNION_H
#define TNR_QUATERNION_H

#include <json/value.h>

namespace tnr {
    struct Quaternion {
        float i,j,k;
        float w;

        static Quaternion from_json(const Json::Value& j) {
            Quaternion q;
            q.i = j['i'].asFloat();
            q.j = j['j'].asFloat();
            q.k = j['k'].asFloat();
            q.w = j['w'].asFloat();

            return q;
        }
    };
}

#endif
