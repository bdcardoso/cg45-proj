.PHONY: default clean

OUTDIR := bin
INCDIR := include
SRCDIR := src
OBJDIR := .obj

BIN    := cg45-proj
SRCS   := $(shell ls $(SRCDIR)/*.cpp | sort -f)
OBJS   := $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

CXX      := g++
CXXFLAGS := -std=c++03 -Wall -Wextra -pedantic -g -I$(INCDIR)
LDFLAGS  := -lGL -lGLU -lglut

$(shell mkdir -p $(OBJDIR))

default: $(BIN)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -x c++ -c $< -o $@

$(BIN): $(OBJS)
	-mkdir -p $(OUTDIR)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(OUTDIR)/$(BIN)

clean:
	-rm -f $(OBJS) $(OUTDIR)/$(BIN)

