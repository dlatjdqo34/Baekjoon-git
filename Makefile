CC := gcc
CXX := g++
CFLAGS := -Wall -g

SRCS := $(wildcard *.cpp) \
	$(wildcard */*.cpp) \
	$(wildcard */*/*.cpp)

OBJS := $(patsubst %.cpp,%.exe,$(SRCS))

.PHONY: all clean
all: $(OBJS)
%.exe: %.cpp
	$(CXX) -o $@ $^

clean:
	del /s /q *.exe