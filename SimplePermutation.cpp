//
//  SimplePermutation.cpp
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 11/30/17.
//  Copyright © 2017 Abdelrahaman Aly. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "SimplePermutation.h"
#include "Permutation.h"

//protected functions
//implements recursive permutation function. It exhanges all elements of a string or substring onto a given position (start). Per each permutation it augments the index position start by one and calls permute. Keeps doing this until the depth of the tree equals the size of the string i.e. start==size-1. Expands one branch of the tree at the time to optimize memory consumption.
int SimplePermutation::permute(unsigned long start,  std::string input){
     unsigned long size = input.size(); //initialize input size to verify position in the recursion
     if(start== size-1){ //detects wheter or not it has finalized exploring the branch.
         std::cout<<this->counter_<<". "<<input<<std::endl;
         this->counter_++;
         return 1;
     }
     for (unsigned long i=start; i<size; i++) {//exhanges all posstions of the local copy of input, from index start to the end of the string, calling permute every time.
             std::swap(input[start], input[i]);
             this->permute(start+1,input);
         
     }
    return 1;
 };

//constructor/destructor
SimplePermutation::SimplePermutation(std::string input){
    this->setInput(input); //initialize input_ with local string using Permutation accessors.
};

SimplePermutation::~SimplePermutation(){
    return;
};

//public functions
int SimplePermutation::doPermute(){
       this->counter_=1;
    this->permute(Permutation::START_POSITION, this->input_); //calls permute using class state.
    return 1;
};

int main(int argc, const char * argv[]) {
    std::string s= ""; //"abcde";
    std::cout<< "Welcome Nigel to Ex. 1.1  All Permutations of a String "<<std::endl;
    std::cout<< "Enter your String: "<<std::endl;
    std::cin>>s;
    std::cout<< "size of the string is: "<< s.size()<<std::endl;
    SimplePermutation *local= new SimplePermutation(s);
    local->doPermute();
    std::cout<< "Thats all folks!"<<std::endl;
    return 0;
};
