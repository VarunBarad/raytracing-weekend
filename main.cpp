#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {
    // Image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    std::cout << "P3" << std::endl << image_width << ' ' << image_height << std::endl << "255" << std::endl;

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_width - 1);
            auto b = 0.25;

            color pixel_color(r, g, b);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << std::endl << "Done." << std::endl;
    return 0;
}
