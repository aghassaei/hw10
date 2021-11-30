/* Aliya Ghassaei and Nina Young
 * Main program, GA solution
 */
#include <iostream>
#include <fstream>
#include <cassert>


#include "chromosome.hh"
#include "deme.hh"

int main(int argc, char *argv[]){

  // Paramaters for the GA 
  unsigned pop_size = 100;
  double mut_rate = 0.5;
  int iterations = 100;

  // Make sure arguments passed in correctly
  assert(argc == 2);

  // Open file, throw error if no file
	std::ifstream cities_file;
	cities_file.open(argv[1]);
	if (!cities_file){
	    std::cerr << "No file was provided";
	}


  // Run the GA
	else {

    // Create cities object and pointer from file
		Cities cities_object = Cities();
		cities_file>>cities_object;
    Cities* const cities_ptr = *cities_object;

    // Create the population
    Deme::Deme deme = Deme(cities1_ptr, pop_size, mut_rate);

    while (iterations>0){
      //run the thing, confused on this?
      iterations--;
    }

    /*

    // Save results to file "shortest.tsv"
    int n = best_ordering.size();
    std::ofstream results_file;
    results_file.open("shortest.tsv");
    for (auto i=0; i<n-1; i += 2){
      results_file<<best_ordering[i] << '\t' << best_ordering[i+1]<<'\n';
    }
    results_file<<best_ordering.back()<<std::endl;
	*/
  }


   return 0;
}
