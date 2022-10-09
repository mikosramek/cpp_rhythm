#include "GlobalSettings.h"

GlobalSettings::GlobalSettings() {
	m_map.insert(std::pair<std::string, std::string>("title", "Rhythm Game - Debug"));
	m_map.insert(std::pair<std::string, std::string>("version", "v0.0.1"));
}

GlobalSettings::~GlobalSettings() { }

std::string GlobalSettings::GetValue(std::string key) { return m_map[key]; }
