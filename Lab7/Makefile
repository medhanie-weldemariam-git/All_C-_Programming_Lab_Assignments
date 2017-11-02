CXX = g++
CXXFLAGS = -Wall -Wextra -Weffc++ -Wold-style-cast \
	   -Woverloaded-virtual -std=c++11 -pedantic -g

main : main.o menu.o product.o database.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o : %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	\rm -f *~ *.o main menu

