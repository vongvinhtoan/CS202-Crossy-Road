# Compiler
CC := .\compiler\mingw64\bin\g++
# Compiler flags
CFLAGS := -std=c++17
# Include directories
INCLUDES := -I".\libs\SFML-2.5.1\include" -I".\libs\jsoncpp" -I".\include"
# Library directories
LFLAGS := -L"./libs/SFML-2.5.1/lib"
# Libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lcomdlg32
# Source files
SRCS := $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
# Library cpp files
LIB_SRCS := $(wildcard libs/jsoncpp/*.cpp)
# Executable name
MAIN := .\bin\game.exe
# Object files directory
OBJ_DIR := .\bin\obj
# Object files
OBJS := $(patsubst src/%.cpp, $(OBJ_DIR)\\%.o, $(SRCS))
# Clean command
RM := del

# Build
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIB_SRCS) $(LFLAGS) $(LIBS)

# Object files
$(OBJ_DIR)\\%.o: src/%.cpp
	if not exist $(@D) mkdir $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Run
run:
	$(MAIN)

# Clean
clean:
	$(foreach file,$(subst /,\,$(OBJS)) $(MAIN),$(RM) $(file);)