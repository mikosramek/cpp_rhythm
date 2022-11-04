#include "Debug.h"

Debug::Debug(){}
Debug::~Debug(){}

void Debug::Log(std::string l_log) {
    std::cout << l_log << std::endl;
}

void Debug::Log(int l_log) {
    std::cout << l_log << std::endl;
}

void Debug::Log(float l_log) {
    std::cout << l_log << std::endl;
}