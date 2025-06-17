EXE = Namespace
CXX = g++
CXXFLAGS = -Wall -Wextra -MMD -finput-charset=UTF-8 -fexec-charset=UTF-8 -std=c++17 -g
LDFLAGS = -lstdc++fs
SRC = main.cpp
BUILD_DIR = build
OBJ = $(BUILD_DIR)/main.o
DEP = $(OBJ:.o=.d)
RM = del /Q /F

.PHONY: all clean rebuild

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	$(RM) $(BUILD_DIR)\*.o $(BUILD_DIR)\*.d 2>nul
	rmdir /S /Q $(BUILD_DIR) 2>nul
	del /Q /F $(EXE).exe 2>nul

rebuild: clean all