//
// Created by Varun Barad on 14/04/22.
//

#ifndef RAYTRACING_WEEKEND_CAMERA_H
#define RAYTRACING_WEEKEND_CAMERA_H

#include "common.h"

class camera {
public:
    camera(
            point3 look_from,
            point3 look_at,
            vec3 vup,
            double vfov_degrees, // vertical field-of-view in degrees
            double aspect_ratio
    ) {
        auto theta = degrees_to_radians(vfov_degrees);
        auto h = tan(theta / 2.0);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;

        auto w = unit_vector(look_from - look_at);
        auto u = unit_vector(cross(vup, w));
        auto v = cross(w, u);

        origin = look_from;
        horizontal = viewport_width * u;
        vertical = viewport_height * v;
        lower_left_corner = origin - (horizontal / 2.0) - (vertical / 2.0) - w;
    }

    ray get_ray(double s, double t) const {
        return ray(origin, (lower_left_corner + (s * horizontal) + (t * vertical) - origin));
    }

private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};

#endif //RAYTRACING_WEEKEND_CAMERA_H
