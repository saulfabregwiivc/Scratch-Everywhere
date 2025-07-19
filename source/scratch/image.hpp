#pragma once
#include <string>
#include <vector>
#include "miniz/miniz.h"

class Image{
public:
    struct ImageRGBA {
    std::string name;
    int width;
    int height;
    unsigned char* data;
    };

    static void loadAllImages(mz_zip_archive *zip);
    static bool loadImageFromCostume(mz_zip_archive *zip, const std::string& costumeId);
    static void loadImageFromFile(std::string filePath);
    static void freeImage(const std::string& costumeId);
    static void queueFreeImage(const std::string& costumeId);
    static void FlushImages();

    static std::vector<ImageRGBA> imageRGBAS;


};