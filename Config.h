#pragma once
#include <map>
#include <string>
#include "DataReader.h"

class Config
{
public:
    Config();
    ~Config();
    std::string GetValue(std::string key);
    int GetIntValue(std::string key);
private:
    std::map<std::string, std::string> m_map;
    DataReader m_dataReader;
};
