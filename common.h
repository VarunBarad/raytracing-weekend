//
// Created by Varun Barad on 10/04/22.
//

#ifndef RAYTRACING_WEEKEND_COMMON_H
#define RAYTRACING_WEEKEND_COMMON_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

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

inline double clamp(double x, double min, double max) {
    if (x < min) {
        return min;
    } else if (x > max) {
        return max;
    } else {
        return x;
    }
}

// Random-utility functions
inline double random_double() {
    // Returns a random real in [0, 1)
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min, max)
    return (min + ((max - min) * random_double()));
}

// Common headers
#include "ray.h"
#include "vec3.h"

#endif //RAYTRACING_WEEKEND_COMMON_H
