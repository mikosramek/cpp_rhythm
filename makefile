CC = clang++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
DEBUG_FLAGS = -g -Wall
RELEASE_FLAGS = -Wall

# build target
TARGET = main
RELEASE_FOLDER = ./builds/release/
DEBUG_FOLDER = ./builds/debug/
ASSET_FOLDER = resources
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system

CPP_FILES = $(TARGET).cpp Note.cpp

debug:
	@make debug-build
	@make debug-run
debug-build:
	@echo "-- Building Debug --"
	$(CC) $(DEBUG_FLAGS) -o $(DEBUG_FOLDER)$(TARGET)-debug $(CPP_FILES) $(LIBRARIES)
	@echo "-- Copying Resources --"
	cp -r ./$(ASSET_FOLDER) $(DEBUG_FOLDER)$(ASSET_FOLDER)
debug-run:
	@echo "-- Running Debug --"
	$(DEBUG_FOLDER)$(TARGET)-debug

release:
	@make release-build
	@make release-run
release-build:
	@echo "-- Building Release --"
	$(CC) $(RELEASE_FLAGS) -o $(RELEASE_FOLDER)$(TARGET) $(TARGET).cpp $(LIBRARIES)
	@echo "-- Copying Resources --"
	cp -r ./$(ASSET_FOLDER) $(RELEASE_FOLDER)$(ASSET_FOLDER)
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