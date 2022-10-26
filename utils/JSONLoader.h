#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class JSONLoader {
    public:
        JSONLoader();
        ~JSONLoader();
        json LoadFile(std::string filePath);
};