#include "Config.h"

Config::Config():
    m_dataReader("assets/config.txt")
{
    // key, default value
    m_map.insert(std::pair<std::string, std::string>("difficulty", "normal"));
    m_map.insert(std::pair<std::string, std::string>("volume", "0"));

    Lines dataLines = m_dataReader.GetLines();
    for (int index = 0; index < dataLines.size(); index += 1) {
        std::string line = dataLines[index];
        if (!line.empty()) {
            size_t colonLocation = line.find_first_of(":");
            std::string value = line.substr(colonLocation+ 1);
            std::string key = line.substr(0, colonLocation);
            if (m_map.find(key) != m_map.end()) {
                m_map[key] = value;
            }
        }
    }
}

Config::~Config() { }

std::string Config::GetValue(std::string key) { return m_map[key]; }

int Config::GetIntValue(std::string key) {
    std::string stringValue = m_map[key];
    return std::stoi(stringValue);
}
