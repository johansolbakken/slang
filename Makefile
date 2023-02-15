CXX=g++
LEX=flex
CPPFLAGS=-std=c++20 -g -Iinclude -Isrc

objects=src/main.o src/hello.o src/scanner.o

slang: $(objects) 
	$(CXX) $(CPPFLAGS) $(objects) -o $@
src/scanner.cpp: src/scanner.lpp
	flex -o src/scanner.cpp src/scanner.lpp 
clean:
	rm -rf $(objects) src/scanner.cpp
purge: clean
	rm slang