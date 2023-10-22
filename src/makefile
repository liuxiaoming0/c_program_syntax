CC := g++
PATH_SRC := .
PATH_ROOT := ..
PATH_BIN := $(PATH_ROOT)/bin
PATH_OBJS := $(PATH_ROOT)/obj
PATH_COMM := $(PATH_ROOT)/comm

CFLAGS = -g -o0 -DNDEBUG -Wall -fpic -std=c++17 -Wno-unused-variable
CFLAGS += -fno-elide-constructors
LIBS = -lpthread -ldl -lrt -lz -lssl -lcrypto -lcurl
EXE = $(PATH_BIN)/pro_syntax

CFLAGS += -I$(PATH_ROOT)
LIBS += $(LIBYAML)
OBJS = $(patsubst $(PATH_COMM)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_COMM)/*.cpp))
OBJS += $(patsubst $(PATH_SRC)/%.cpp, $(PATH_OBJS)/%.o, $(wildcard $(PATH_SRC)/*.cpp))



$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $^ -Xlinker "-(" $(LIBS) -Xlinker "-)" -o $@

$(PATH_OBJS)/%.o : $(PATH_COMM)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(PATH_OBJS)/%.o : $(PATH_SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY clean:
	rm -f $(OBJS) $(EXE)
