//
//  UniquePermutation.h
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 11/30/17.
//  Copyright © 2017 Abdelrahaman Aly. All rights reserved.
//

#ifndef UniquePermutation_h
#define UniquePermutation_h

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Permutation
 * @brief
 * Class implementing excersice 1.2 Shows all the unique permutations of a string.
 * @details
 * Designed to find all unique permutations of input_. Implements generic methods of Permutation and reuses the implementation of the data accessors of input_. To find unique permutations it uses a tabu (tabu_) list such that once the permutation is printed, is blacklisted. Increase in complexty vs. SimplePermutation.

 * @author Abdelrahaman Aly
 * @date  2017/11/30
 * @version 0.0.1.1
 */
class UniquePermutation: public Permutation{
private:
    //private state
    std::vector<std::string> tabu_; //permutation blacklist, tabu list(queueing theory) . Increase in complexty vs. SimplePermutation
    
    //private functions
    /**
     * @brief
     * Validates whether an Input Permutation is Blacklisted
     * @details
     * validates whether a permutation is aready blacklisted. Increase of complexity vs. SimplePermutation. If not it adds the permutation to the blacklist and authorizes it to be printed
     * @param input number to be added
     * @return 0,1 value where 1 means input is blacklisted and 0 otherwise
     * @exception NA (could be added under request)
     */
    bool validate(const std::string input);

protected:
    //protected functions
    int permute(unsigned long start, std::string input); //calculates Permutation. Increase in complexty vs. SimplePermutation. See Permutation class and method implementation for details
    
public:
    //constructors and destructors
    UniquePermutation(std::string input);
    ~UniquePermutation();
    
    //public functions
    int doPermute();//execute permutation funcitonality. See Permutation class and method implementation for details
    
};

#endif /* UniquePermutation_h */
