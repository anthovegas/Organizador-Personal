CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SOURCES = main.cpp \
          item.cpp \
          task.cpp \
          note.cpp \
          goal.cpp \
          calendar.cpp \
          printer.cpp \
          console_printer.cpp \
          file_printer.cpp \
          memory_printer.cpp \
          date.cpp \
          habit.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = OrganizadorPersonal---

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
