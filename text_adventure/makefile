CXX = clang++
CXXFLAGS = -std=c++17

txtAdventure: game_text_data.o text-adventure.o
	$(CXX) $(CXXFLAGS) game_text_data.o text-adventure.o -o txtAdventure

game_text_data.o: game_text_data.cpp
	$(CXX) $(CXXFLAGS) -c game_text_data.cpp

text-adventure.o: text-adventure.cpp
	$(CXX) $(CXXFLAGS) -c text-adventure.cpp

clean:
	rm *.o txtAdventure
