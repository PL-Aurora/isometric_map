# makefile dla isometric_map, ale mozna generalizowac na wiekszosc projektow
# dosyc generalna postac makefile

CXX=g++
CXXFLAGS=-c -Wall -Wextra -pedantic -O2 -std=c++17
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

# nazwa programu
TARGET=isometric_map

#katalogi i rozszerzenia
SRC_DIR:=src
INC_DIR:=inc
OBJ_DIR:=obj

SRC_EXT:=cpp
OBJ_EXT:=o
INC_EXT:=hpp

MAIN_FILE = main.cpp

#-----------------------------
# NIE EDYTOWAC PONIZEJ LINII!!
#-----------------------------
SRC_FILES:=$(wildcard $(SRC_DIR)/*.$(SRC_EXT))
OBJ_FILES:=$(patsubst $(SRC_DIR)/%.$(SRC_EXT), $(OBJ_DIR)/%.$(OBJ_EXT), $(SRC_FILES))

$(TARGET): $(OBJ_FILES)
	$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.$(OBJ_EXT):$(SRC_DIR)/%.$(SRC_EXT) $(INC_DIR)/%.$(INC_EXT)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $< -o $@


all: $(TARGET)

clean:
	rm -f $(TARGET) $(OBJ_FILES)
	rmdir $(OBJ_DIR)