CXX=g++
CPPFLAGS=-std=c++20 -g -Iinclude -Isrc

objects=src/main.o src/hello.o

slang: $(objects)
	$(CXX) $(CPPFLAGS) $(objects) -o $@
clean:
	rm -rf $(objects)
purge: clean
	rm slang