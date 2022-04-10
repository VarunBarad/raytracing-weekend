//
// Created by Varun Barad on 10/04/22.
//

#ifndef RAYTRACING_WEEKEND_COMMON_H
#define RAYTRACING_WEEKEND_COMMON_H

#include <cmath>
#include <limits>
#include <memory>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions
inline double degrees_to_radians(double degrees) {
    return ((degrees * pi) / 180.0);
}

// Common headers
#include "ray.h"
#include "vec3.h"

#endif //RAYTRACING_WEEKEND_COMMON_H
