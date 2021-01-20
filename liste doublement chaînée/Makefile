CXX=g++
CXXFLAGS=-Wall -g
RM=rm -f

test : intlist.o main.o test.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

intlist.o : intlist.cpp intlist.h
main.o : main.cpp intlist.h
test.o : test.cpp test.h intlist.h

%.o:%.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean :
	$(RM) intlist.o main.o test.o test

