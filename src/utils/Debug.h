#pragma once
#include <iostream>

class Debug
{
    public:
        Debug();
        ~Debug();
        void Log(std::string l_log);
        void Log(int l_log);
        void Log(float l_log);
};
