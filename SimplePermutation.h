//
//  SimplePermutation.h
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 11/30/17.
//

#ifndef SimplePermutation_h
#define SimplePermutation_h
#include <iostream>
#include <string>
#include "Permutation.h"

/**
 * @class Permutation
 * @brief
 * Class implementing excersice 1.1 Shows all the permutation of a string.
 * @details
 * Designed to find all permutations of input_. Implements generic methods of Permutation and reuses the implementation of the data accessors of input_. Basic level of complexity
 * @author Abdelrahaman Aly
 * @date  2017/11/30
 * @version 0.0.1.1
 */
class SimplePermutation: public Permutation{
protected:
    //protected functions
    int permute(unsigned long start, std::string input);//implements Permutation. Basic level of complexity. See Permutation class and method implementation for details
    
public:
    //class constructor and destructor
    SimplePermutation(std::string input);
    ~SimplePermutation();
    
    //public functions
    int doPermute();//execute permutation funcitonality. Basic level of complexity. See Permutation class and method implementation for details
};


#endif /* SimplePermutation_h */
