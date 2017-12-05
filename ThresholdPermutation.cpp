//
//  ThresholdPermutation.cpp
//  string_manipulation
//
//  Created by Abdelrahaman Aly on 12/3/17.
//  Copyright © 2017 Abdelrahaman Aly. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <algorithm>
#include "Permutation.h"
#include "ThresholdPermutation.h"

//private functions

//added complexity:revises whether an input (a leaf of a current explored branch) is blacklisted and hence if its a valid. Item is blackliste if it has appeared more than threshold_ times. It returns 1 if its not blacklisted and 0 otherwise.
bool ThresholdPermutation::validate(const std::string input){
    std::pair<std::string, int> entry;
    if (tabu_.size()==0) { //add first entry in case blacklist is empty
        tabu_.insert(std::pair<std::string, int>(input,1));
        return 1;
        
    }
    unsigned long int  size= tabu_.count(input);//checks whether or not input is blacklisted (size, in this casem can only take 0, 1 values) the code is optimized such that no entry is included twice on the blacklist.
   
    if (size>0) {
        int repetition = tabu_[input]; //extracts number of repetitions from tabu_ list.
        if (repetition >= this->threshold_) { //checks whether the permutation has reached the threshold_
            //std::cout<<"Repeated over Threshold: "<<size<< " "<<input<<std::endl; //decomment if you want to print what permutations are invalid.
            return 0;
        }
        
        tabu_[input]=tabu_[input]+1; //in case the input is validated, it registers a new reptition
        
    }else{
        tabu_.insert(std::pair<std::string, int>(input,1)); //in case is the first time the input is added to the tabu_ list.
    }
    
    return 1;
};


//protected functions

//implements recursive permutation function to print unique permutations. See SimplePermutation for details on basic functioning. Increase in complexity: Added validate function, which validates whether an input was blacklisted up to a threshold
int ThresholdPermutation::permute(unsigned long start, std::string input){
    unsigned long size = input_.size();//initialize input size to verify position in the recursion
    if(start== size-1){
        if(!validate(input)){//added complexity vs. UniquePermutation: validates whether the input has been blacklisted.
            return 1;
        }
        std::cout<<this->counter_<<". "<<input<<std::endl; //prints the entry in case it was not blacklisted

        this->counter_++;
        return 1;
    }
    for (unsigned long i=start; i<size; i++) {
        std::swap(input[start], input[i]); //exhanges all posstions of the local copy of input, from index start to the end of the string, calling permute every time.
        this->permute(start+1, input);
        
        
    }
    return 1;
};

//constructors
ThresholdPermutation::ThresholdPermutation(std::string input, int threshold){
    this->setInput(input); //initialize input_ with local string using Permutation accessors.
    this->setThreshold(threshold);//added complexity vs. UniquePermutation: initialize threshold_ with local string using Permutation accessors.
};

ThresholdPermutation::~ThresholdPermutation(){
    return;
};

//public functions
int ThresholdPermutation::doPermute(){
    this->permute(Permutation::START_POSITION, this->input_);
    return 1;
};


//class properties
//added complexity (vs. UniquePermutation)
//threshold property access
void ThresholdPermutation::setThreshold(int threshold){
    this->threshold_= threshold;
    return;
};

int ThresholdPermutation::gethreshold(){
    return this->threshold_;
};


int main(int argc, const char * argv[]) {
    std::string s= ""; //"abcde";
    int threshold=0;
    std::cout<< "Welcome Nigel to Ex. 1.3 All Permutations up to a Repetition Threshold of a string "<<std::endl;
    std::cout<< "Enter your String: "<<std::endl;
    std::cin>>s;
    std::cout<< "Enter the Threshold: "<<std::endl;
    std::cin>>threshold;
    std::cout<< "size of the string is: "<< s.size()<<std::endl;
    ThresholdPermutation *local= new ThresholdPermutation(s,threshold);
    local->doPermute();
    std::cout<< "Thats all folks!"<<std::endl;
    return 0;
};
