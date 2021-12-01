/*
 * Tests for chromosome
 */

#include "chromosome.hh"

// Testing mutate
bool test_mutate(Chromosome chrom){
  assert(chrom.is_valid());

  // Save previous ordering
  Cities::permutation_t prev_order;
  copy(order_.begin(), order_.end(), back_inserter(prev_order));
  assert(not prev_order.empty());

  chrom.mutate();

  // Find a difference
  bool found_difference = false;
  for (auto i; i<chrom.order_.size(), i++){
    if prev_order[i] != chrom.order_[i]{
      found_difference = true;
    }
  }
  return found_difference;

int main(){
  Cities cities1 = Cities();
  Cities* cities1_ptr = *cities1;
  Chromosome chrom1 = Chromosome(cities1_ptr);
  assert(test_mutate(chrom1));
	return 0;
}
