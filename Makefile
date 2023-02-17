CXX=g++
LEX=flex
YACC=bison
YFLAGS=--defines=src/parser.tab.hpp -o src/parser.tab.cpp
CPPFLAGS=-std=c++20 -g -Iinclude -Isrc

objects=src/parser.tab.o src/scanner.o src/main.o src/hello.o src/tree.o

slang: $(objects) 
	$(CXX) $(CPPFLAGS) $(objects) -o $@
src/scanner.cpp: src/scanner.lpp
	flex -o src/scanner.cpp src/scanner.lpp
src/parser.tab.cpp: src/parser.ypp
	bison $(YFLAGS) src/parser.ypp
clean:
	rm -rf $(objects)
purge: clean
	rm slang src/scanner.cpp src/parser.tab.hpp src/parser.tab.cpp