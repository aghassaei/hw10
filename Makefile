CXX=clang++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++17 -O3 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

#including test_cities here in case we update the interface
all:  test_cities tsp tsp test_chromosome test_deme

test_cities: cities.o test_cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_chromosome: chromosome.o test_chromosome.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

test_deme: deme.o test_deme.o chromosome.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

tsp: tsp.o chromosome.o deme.o cities.o
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_cities test_chromosome test_deme tsp
