CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
RM= rm -f

main : morse.o wav.o test.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f morse.o wav.o test.o main.o main test.wav

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

morse.o : morse.cpp morse.h

wav.o : wav.cpp wav.h

test.o : test.cpp morse.cpp morse.h wav.cpp wav.h

main.o : main.cpp morse.cpp morse.h wav.cpp wav.h
