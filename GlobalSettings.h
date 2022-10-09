#pragma once
#include <map>
#include <string>

class GlobalSettings
{
public:
    GlobalSettings();
    ~GlobalSettings();
    std::string GetValue(std::string key);
private:
    std::map<std::string, std::string> m_map;
};
