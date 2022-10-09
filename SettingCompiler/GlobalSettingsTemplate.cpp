#include "GlobalSettings.h"

GlobalSettings::GlobalSettings() {
//%%
}

GlobalSettings::~GlobalSettings() { }

std::string GlobalSettings::GetValue(std::string key) { return m_map[key]; }
