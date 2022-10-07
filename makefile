CC = g++ -std=c++17

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
DEBUG_FLAGS = -g -Wall
RELEASE_FLAGS = -Wall

# build target
TARGET = main
RELEASE_FOLDER = ./builds/release/
DEBUG_FOLDER = ./builds/debug/
ASSET_FOLDER = assets
LIBRARIES = -Iinclude -I/usr/local/include -L/usr/local/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

# -lsfml-graphics -lsfml-window -lsfml-system

CPP_FILES = $(TARGET).cpp Note.cpp Game.cpp Window.cpp DataReader.cpp

debug:
	@make debug-build
	@make debug-run
debug-build:
	@echo "-- Building Debug --"
	$(CC) $(DEBUG_FLAGS) -o $(DEBUG_FOLDER)$(TARGET)-debug $(CPP_FILES) $(LIBRARIES)
	@echo "-- Copying Resources --"
	cp -r ./$(ASSET_FOLDER) $(DEBUG_FOLDER)
debug-run:
	@echo "-- Running Debug --"
	$(DEBUG_FOLDER)$(TARGET)-debug

release:
	@make release-build
	@make release-run
release-build:
	@echo "-- Building Release --"
	$(CC) $(RELEASE_FLAGS) -o $(RELEASE_FOLDER)$(TARGET) $(CPP_FILES) $(LIBRARIES)
	@echo "-- Copying Resources --"
	cp -r ./$(ASSET_FOLDER) $(RELEASE_FOLDER)
release-run:
	@echo "-- Running Release --"
	$(RELEASE_FOLDER)$(TARGET)

clean:
	@echo "-- Cleaning Builds --"
	@rm -r -f $(DEBUG_FOLDER)*
	@echo "- Removed Debug"
	@rm -r -f $(RELEASE_FOLDER)*
	@echo "- Removed Release"
	@echo "-- Finished Cleaning --"