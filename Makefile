CXXFLAGS=-Wall -Wextra -ggdb -std=c++17 -frtti

PHONY: all build clean run

all: build

build: ./build/main

clean:
	rm -rf ./build

run: build
	./build/main

./build/main: \
	./build/Card.o \
	./build/Deck.o \
	./build/main.o \
	
	@mkdir -p $$(dirname $@)
	$(CXX) -o $@ $(CXXFLAGS) $^

./build/%.o: ./src/%.cpp
	@mkdir -p $$(dirname $@)
	$(CXX) -o $@ -c $(CXXFLAGS) $^