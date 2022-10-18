#include "GlobalSettings.h"

// THIS FILE IS AUTOCOMPILED AT BUILDTIME
// DO NOT EDIT DIRECTLY
// INSTEAD EDIT compilers/SettingsCompiler/settings.*.json
GlobalSettings::GlobalSettings() {
//%%
}

GlobalSettings::~GlobalSettings() { }

std::string GlobalSettings::GetValue(std::string key) { return m_map[key]; }
