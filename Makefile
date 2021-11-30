CXX=clang++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

#including test_cities here in case we update the interface
all:  test_cities tsp_random tsp_ga

test_cities: cities.o test_cities.o 
	$(CXX) $(LDFLAGS) -o $@ $^

tsp_random: tsp_random.o chromosome.o deme.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

tsp_ga: tsp_ga.o chromosome.o deme.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_cities tsp

