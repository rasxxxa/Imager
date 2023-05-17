#define STB_IMAGE_IMPLEMENTATION
#include "../STB/stb_image.h"
#include "RawImageHandler.h"

Image RawImageHandler::LoadImageFile(const std::string& path)
{
    // Image properties
    int width, height, channels;

    // Load the image using stb_image
    unsigned char* image = stbi_load(path.data(), &width, &height, &channels, 0);
    if (!image) 
    {
        std::cout << "Failed to load image, reason: " << stbi_failure_reason() << " \n";
        return Image{};
    }
    Image im;
    im.m_channels = channels;
    im.m_height = height;
    im.m_width = width;
    im.m_size = height * width * channels;
    im.m_imageData = std::vector<char>(image, image + im.m_size);

    stbi_image_free(image);
    return im;
}
