//
// Created by Varun Barad on 07/04/22.
//

#ifndef RAYTRACING_WEEKEND_COLOR_H
#define RAYTRACING_WEEKEND_COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0, 255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << std::endl;
}

#endif //RAYTRACING_WEEKEND_COLOR_H
