SRC_DIR := src/
INC_DIR := inc/
BIN_DIR := Bin/
BIN_SRC := $(BIN_DIR)src/
DEL := rm -rf
EXE := $(BIN_DIR)msort

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJ := $(SRCS:%=$(BIN_DIR)%.o)
DEPS := $(OBJ;.o=.d)

INCL := $(shell find $(INC_DIR) -type d)
INC_FLAGS := $(addprefix -I, $(INCL))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

FLAGOBJ := g++ -g -c -std=c++17 -Wall -Wextra -Wpedantic
FLAGEXE := g++ -g -std=c++17 -Wall -Wextra -Wpedantic

all: $(BIN_DIR) $(BIN_SRC) $(EXE)

$(EXE): $(OBJ)
	$(FLAGEXE) $(OBJ) -o $(EXE)

$(BIN_DIR):
	-@if [ ! -d "$(BIN_DIR)" ]; then mkdir "$(BIN_DIR)"; fi

$(BIN_SRC):
	-@if [ ! -d "$(BIN_SRC)" ]; then mkdir "$(BIN_SRC)"; fi

$(BIN_DIR)%.cpp.o: %.cpp
	$(FLAGOBJ) $(CPPFLAGS) -c $< -o $@

clean:
	$(DEL) $(EXE) $(BIN_DIR)$(SRC_DIR)

-include $(DEPS)
