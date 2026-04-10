CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

TARGET = textmex

SRCS = $(wildcard ./src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)