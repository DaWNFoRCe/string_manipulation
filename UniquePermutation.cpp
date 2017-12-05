//
//  UniquePermutation.cpp
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 12/1/17.
//  Copyright © 2017 Abdelrahaman Aly. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <algorithm>
#include "Permutation.h"
#include "UniquePermutation.h"

//private functions
//added complexity:revises whether an input (a leaf of a current explored branch) is blacklisted and hence if its a valid (unique). It returns 1 if its not blacklisted and 0 otherwise.
bool UniquePermutation::validate(const std::string input){
    if (tabu_.size()==0) { //add first entry in case blacklist is empty
        tabu_.push_back(input);
        return 1;
        
    }
    unsigned long int  size=std::count(tabu_.begin(), tabu_.end(), input); //checks whether or not input is blacklisted (size, in this case can only take 0, 1 values) the code is optimized such that no entry is included twice on the blacklist.
    if (size) {
        //std::cout<<"Repeated: "<<size<< " "<<input<<std::endl; //decomment if you want to print what permutations are invalid.
        return 0;
    }else{
        tabu_.push_back(input); //blacklist fresh permutation
    }
    return 1;
};

//implements recursive permutation function to print unique permutations. See SimplePermutation for details on basic functioning. Increase in complexity: Added validate function, which validates whether an input was blacklisted
int UniquePermutation::permute(unsigned long start, std::string input){
    unsigned long size = input_.size(); //initialize input size to verify position in the recursion
    if(start== size-1){
        if(!validate(input)){ //added complexity: validates whether the input has been blacklisted.
            return 1;
        }
        
        std::cout<<this->counter_<<". "<<input<<std::endl; //prints the entry in case it was not blacklisted
        this->counter_++;
        return 1;
    }
          
    for (unsigned long i=start; i<size; i++) {
        std::swap(input[start], input[i]);//exhanges all posstions of the local copy of input, from index start to the end of the string, calling permute every time.
        this->permute(start+1, input);
        
    }
    return 1;
};
//constructor/destructor:

UniquePermutation::UniquePermutation(std::string input){
    this->setInput(input); //initialize input_ with local string using Permutation accessors.
};

UniquePermutation::~UniquePermutation(){
    return;
};

//public functions:

int UniquePermutation::doPermute(){
    this->permute(Permutation::START_POSITION, this->input_);
    return 1;
};

//main method
int main(int argc, const char * argv[]) {
    std::string s= ""; //"abcde";
    std::cout<< "Welcome Nigel to Ex. 1.2 All Unique Permutations of a string"<<std::endl;
    std::cout<< "Enter your String: "<<std::endl;
    std::cin>>s;
    std::cout<< "size of the string is: "<< s.size()<<std::endl;
    UniquePermutation *local= new UniquePermutation(s);
    local->doPermute();
    std::cout<< "Thats all folks!"<<std::endl;
    return 0;
};

