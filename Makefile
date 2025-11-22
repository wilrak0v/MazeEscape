CXX = g++
CXXFLAGS = -std=c++17 -I./src -Wall -Wextra -g
SRCS = $(shell find src -name '*.cpp')
OBJS = $(SRCS:.cpp=.o)
TARGET = MazeEscape

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	@echo "Cleaning object files and executable..."
	rm -f $(OBJS) $(TARGET)
