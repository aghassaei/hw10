/* Aliya Ghassaei and Nina Young
 * Main program, GA solution
 */
#include <iostream>
#include <fstream>
#include <cassert>


#include "chromosome.hh"
#include "deme.hh"

int main(int argc, char *argv[]){

  // Make sure arguments passed in correctly
  assert(argc == 2);

  // Open file, throw error if no file
	std::ifstream cities_file;
	cities_file.open(argv[1]);
	if (!cities_file){
	    std::cerr << "No file was provided";
	}


	else{
		Cities cities_object = Cities();
		cities_file>>cities_object;
    
    //create a deme?
    // run ga thing
    // save somehow?

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
