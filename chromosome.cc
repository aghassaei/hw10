/*
 * Implementation for Chromosome class
 * QUESTIONS: 
 * arguments for constructor and destructor
 * mutate (see comments)
 * confused on in range
 * general info:
 *  left collumn can be multiple of num of individuals per generation
 *
 */

#include <algorithm>
#include <cassert>
#include <random>
#include <iterator>

#include "chromosome.hh"

//////////////////////////////////////////////////////////////////////////////
// Generate a completely random permutation from a list of cities
Chromosome::Chromosome(const Cities* cities_ptr)
  : cities_ptr_(cities_ptr),
    order_(random_permutation(cities_ptr->size())),
    generator_(rand())
{
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Clean up as necessary
Chromosome::~Chromosome()
{
  assert(is_valid());
  //not sure how to delete this if we cant do delete *this
}

//////////////////////////////////////////////////////////////////////////////
// Perform a single mutation on this chromosome
void
Chromosome::mutate()
{
  
  // Initialize two forward iterators instead???
  std::uniform_int_distribution<int> distribution(0, order_.size());
  auto i = distribution(generator_);
  auto j = distribution(generator_);

  // Swap 
  std::swap(order_[i], order_[j]);

  
  // Check that this new arrangement is valid
  assert(is_valid());
}

//////////////////////////////////////////////////////////////////////////////
// Return a pair of offsprings by recombining with another chromosome
// Note: this method allocates memory for the new offsprings
std::pair<Chromosome*, Chromosome*>
Chromosome::recombine(const Chromosome* other)
{
  // Check that both original and other are valid
  assert(is_valid()); 
  assert(other->is_valid());
 
  std::pair<Chromosome*, Chromosome*> ptr_pair;

  unsigned b = 0;
  unsigned e = order_.size();

  // Create crossover children
  ptr_pair.first = create_crossover_child(this, other, b, e);
  ptr_pair.first = create_crossover_child(other, this, b, e);
 
  // Allocate new memory? I think this is taken care of in create_crossover_child (?)

  return ptr_pair;
}

//////////////////////////////////////////////////////////////////////////////
// For an ordered set of parents, return a child using the ordered crossover.
// The child will have the same values as p1 in the range [b,e),
// and all the other values in the same order as in p2.
Chromosome*
Chromosome::create_crossover_child(const Chromosome* p1, const Chromosome* p2,
                                   unsigned b, unsigned e) const
{
  Chromosome* child = p1->clone();

  // We iterate over both parents separately, copying from parent1 if the
  // value is within [b,e) and from parent2 otherwise
  unsigned i = 0, j = 0;

  for ( ; i < p1->order_.size() && j < p2->order_.size(); ++i) {
    if (i >= b and i < e) {
      child->order_[i] = p1->order_[i];
    }
    else { // Increment j as long as its value is in the [b,e) range of p1
      while (p1->is_in_range(p2->order_[j], b, e)) {
        ++j;
      }
      assert(j < p2->order_.size());
      child->order_[i] = p2->order_[j];
      j++;
    }
  }

  assert(child->is_valid());
  return child;
}

// Return a positive fitness value, with higher numbers representing
// fitter solutions (shorter total-city traversal path).
// (?) We can totally find a better way to do this in the future
double
Chromosome::get_fitness() const
{
  auto score = cities_ptr_->total_path_distance(order_);
  auto fitness = score*-1 + offset_;
  return fitness;
}

// A chromsome is valid if it has no repeated values in its permutation,
// as well as no indices above the range (length) of the chromosome.
// We implement this check with a sort, which is a bit inefficient, but simple
bool
Chromosome::is_valid() const
{
  
  // Check that the permutation is not empty
  assert(not order_.empty()); 
  
  // Ensure there are no gaps
  for (unsigned i = 0; i<order_.size(); i++){
    assert(order_[i]);
  }
  // (?) can probably replace this loop with an stl function:
  //std::adjacent find (stl function that returns first pointer to duplicate) // Ensure there are no duplicates
  // or maybe we can just return this function: bool is_permutation
  return true;  
}

// Find whether a certain value appears in a given range of the chromosome.
// Returns true if value is within the specified the range specified
// [begin, end) and false otherwise.
bool
Chromosome::is_in_range(unsigned value, unsigned begin, unsigned end) const
{
  return (std::find(order_[begin], order_[end], value) != order_[end]);
}
