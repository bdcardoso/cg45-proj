.PHONY: default clean

OUTDIR := bin
INCDIR := include
SRCDIR := src
OBJDIR := .obj

BIN    := cg45-proj
SRCS   := $(wildcard $(SRCDIR)/*.cpp)
OBJS   := $(SRCS:%.cpp=%.o)

CXX      := g++
CXXFLAGS := -std=c++03 -Wall -Wextra -pedantic -g -I$(INCDIR)
LDFLAGS  := -lGL -lGLU -lglut

default: $(BIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -x c++ -c $< -o $@

$(BIN): $(OBJS)
	-mkdir -p $(OUTDIR)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(OUTDIR)/$(BIN)

clean:
	-rm -f $(OBJS) $(OUTDIR)/$(BIN)

