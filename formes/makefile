CXX=g++
CXXFLAGS=-std=c++11
RM= rm -f

main : main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f  shape.o test.o main.o main a.out

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

main.o : main.cpp test.o test.h

test.o : test.cpp shape.h

