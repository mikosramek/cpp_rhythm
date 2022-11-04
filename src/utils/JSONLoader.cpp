#include "JSONLoader.h"

JSONLoader::JSONLoader() {}

JSONLoader::~JSONLoader() {}

json JSONLoader::LoadFile(std::string filePath) {
    std::ifstream f(filePath);
    json data = json::parse(f);
    return data;
}