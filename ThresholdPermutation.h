//
//  ThresholdPermutation.h
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 11/30/17.
//

#ifndef ThresholdPermutation_h
#define ThresholdPermutation_h
#include <iostream>
#include <string>
#include <map>

/**
 * @class Permutation
 * @brief
 * Class implementing excersice 1.3 Shows all the unique permutations of a string up to a threshld threhold_.
 * @details
 * Designed to find all unique permutations of input_ up to a threshold_. Implements generic methods of Permutation and reuses the implementation of the data accessors of input_ up to a threshold_. To find unique permutations it uses a tabu (tabu_) map such that once the permutation is printed, is added to the list and then subsequently blocked when it had reached the printing upper limit. When threshold_ is 1, its behavior is the same as UniquePermutation. Increase in complexty vs. SimplePermutation.
 
 * @author Abdelrahaman Aly
 * @date  2017/11/30
 * @version 0.0.1.1
 */
class ThresholdPermutation: public Permutation{
private:
    //private state
    int threshold_;// permutation threshold. Permutations are repetead as long as they have not appeared up to threshold_
    std::map<std::string, int> tabu_;//permutation blacklist, tabu list(queueing theory). Increase in complexty vs. UniquePermutation. Map (or any Dictionary) to store repeated permutations and the number of repetitions up to threshold_
    
    //private functions
    /**
     * @brief
     * Validates whether an Input Permutation is Blacklisted. To be blacklisted it can only be repeated up to a Threshold (threshold_).
     * @details
     * validates whether a permutation is already blacklisted. Increase of complexity vs. UniquePermutation. If not it adds the permutation to the blacklist and authorizes it to be printed. To be blacklisted it has to be repeated at least threshold_ times.
     * @param input number to be added
     * @return 0,1 value where 1 means input is blacklisted and 0 otherwise
     * @exception NA (could be added under request)
     */
    bool validate(const std::string input);
protected:
    //protected functions
    int permute(unsigned long start, std::string input); //implements Permutation. Increase in complexty vs. UniquePermutation. See Permutation class and method implementation for details
    
public:
    //constructor/destructor
    ThresholdPermutation(std::string input, int threshold);
    ~ThresholdPermutation();
    
    //public functions
    int doPermute();//execute permutation funcitonality. Increase in complexty vs. UniquePermutation. See Permutation class and method implementation for details
    
    //class properties
    //threshold property. Increase in complexty vs. UniquePermutation.
    void setThreshold(int threshold);
    int gethreshold();
};

#endif /* ThresholdPermutation_h */
