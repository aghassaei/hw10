# HW10
Continuation of the traveling salesperson problem

Aliya Ghassaei and Nina Young

CS221 Fall 2021

## Overview

The traveling salesperson problem asks us to find the shortest route that takes us to each city in the given list once and return to the starting location. Since this problem is NP-hard, there is no efficient way to solve it. We are implementing a genetic algorithm approach to approximate the shortest path.

## Chromosome Class

A chromosome represents a permutation on the orders of the cities to visit. Note that this class does not permit default construction and copying to preserve polymorphism. The only way to create a Chromosome class is via the create() method, and the only way to copy one is via the clone() method. This class builds off of the Cities class.

## Deme Class

A deme is a population of individuals. Deme class will evolve a genetic algorithm for the traveling-salesperson problem.

## Running the Code

To compile, type `make` into the command line, then `./tsp challenge.tsv 1000 .1`. The program should generate the shortest path and print them on the screen. You can run the program with the algorithm by commenting out lines 130 and 131 in tsp.cc. Leaving
them in will result in a randomized run.

## Visualizations

To visualize our results we used `gnuplot`.

![](images/comparison.gif)
