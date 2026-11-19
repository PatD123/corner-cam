#include <iostream>
#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "extern/stb_image.h"
#include "extern/stb_image_write.h"

int main() {

    std::string input_fn = "calibration/test.jpeg";
    std::string output_fn = "calibration/test_out.png";
    int height = 426;
    int width = 564;
    int pixel_step = 12;
    int num_channels = 3;
    unsigned char *data = stbi_load(input_fn.c_str(), &width, &height, &pixel_step, num_channels);

    if(data == nullptr) throw std::runtime_error("Error loading file");

    int err = stbi_write_png(output_fn.c_str(), width, height, num_channels, data, pixel_step * width);
    
    if (!err) throw std::runtime_error("Error writing file");

    return 0;
}

