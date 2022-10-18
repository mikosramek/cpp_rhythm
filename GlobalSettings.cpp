#include "GlobalSettings.h"

// THIS FILE IS AUTOCOMPILED AT BUILDTIME
// DO NOT EDIT DIRECTLY
// INSTEAD EDIT compilers/SettingsCompiler/settings.*.json
GlobalSettings::GlobalSettings() {
	m_map.insert(std::pair<std::string, std::string>("title", "Rhythm Game - Debug"));
	m_map.insert(std::pair<std::string, std::string>("version", "v0.0.1"));
}

GlobalSettings::~GlobalSettings() { }

std::string GlobalSettings::GetValue(std::string key) { return m_map[key]; }
