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
            double aspect_ratio,
            double aperture,
            double focus_dist
    ) {
        auto theta = degrees_to_radians(vfov_degrees);
        auto h = tan(theta / 2.0);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;

        w = unit_vector(look_from - look_at);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        origin = look_from;
        horizontal = focus_dist * viewport_width * u;
        vertical = focus_dist * viewport_height * v;
        lower_left_corner = origin - (horizontal / 2.0) - (vertical / 2.0) - (focus_dist * w);

        lens_radius = aperture / 2.0;
    }

    ray get_ray(double s, double t) const {
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = (u * rd.x()) + (v * rd.y());
        return ray(
                (origin + offset),
                (lower_left_corner + (s * horizontal) + (t * vertical) - origin - offset)
        );
    }

private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    vec3 u, v, w;
    double lens_radius;
};

#endif //RAYTRACING_WEEKEND_CAMERA_H
