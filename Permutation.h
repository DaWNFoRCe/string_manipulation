//
//  Permutation.h
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 11/30/17.
//  Copyright © 2017 Abdelrahaman Aly. All rights reserved.
//

#ifndef Permutation_h
#define Permutation_h

#include <string>

/**
 * @class Permutation
 * @brief
 * Class containing generic function declarations and non-logic centric functionality (generic class properties).
 * @details 
 * Designed to avoid code repetition of generic code. This includes state variables and main declarations. It also implements the input property given that is non logic-centrinc. This makes this class an hybrid in between an Interface and an ordinary class.
 * @author Abdelrahaman Aly
 * @date  2017/11/30
 * @version 0.0.1.1
 */
class Permutation{
protected:
    //protected state
    std::string input_; //String to be permuted
    unsigned long counter_=1; //Permutation counter (per instance)
    
    //protected functions
    /**
     * @brief
     * Prints Input Permutation
     * @details
     Method receives an array position, and generates the permutation of all possible elements on that position of the elements allocated between the "start" index and the end of the string. For every permutation it executes a recursive call and moves the "start" index one position ahead, until there are no more elements to permute. This expansion takes form of a tree were the leaves are all possible permutations of the string. The function is written in such a way it optimizes memory use, just spanding one branch at the time, hence reducing the stack space needed, given its exponential nature.
     * @param start next array position to analyzed
     * @param input number to be added
     * @return 1 in case of success
     * @exception NA (could be added under request)
     */
    int permute(unsigned long start, std::string input);
    
public:
    //public constants
    static const int START_POSITION=0;//initial exploratory position of input string.
    
    //public functions
    
    /**
     * @brief
     * Launches permutation
     * @details
     Method exposed to launch permutation using state variables. Accesses the protected implementations of permute.
     * @return 1 in case of success
     * @exception NA (could be added under request)
     */
    int doPermute();
    
    //public standard properties
    
    //input string setter and getter
    void setInput(std::string input){
        this->input_=input;
    };
    std::string getInput(){
        return this->input_;
    };
};

#endif /* Permutation_h */
