cmake_minimum_required(VERSION 3.18)

project(Rhythm VERSION 0.1)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(Rhythm src/base/main.cpp src/base/config.cpp src/base/DataReader.cpp src/base/Game.cpp src/base/GlobalSettings.cpp src/base/Window.cpp)
# add_executable(Rhythm src/player/.cpp src/player/*.cpp)
add_executable(Rhythm src/utils/Debug.cpp src/utils/JSONLoader.cpp src/utils/MusicClip.cpp)
add_executable(Rhythm src/world/Location.cpp src/world/NoteBar.cpp src/world/NoteData.cpp src/world/Room.cpp src/world/Sequence.cpp src/world/Sequencer.cpp)

