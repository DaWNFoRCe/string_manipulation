# string_manipulation
Implements the Task 1 (String permutation) and is designed to see how I manage increasing level of complexity

##Task 1: 

Here the implementation is to be in C++ using the STL.  The following
is three problems, each one builds on the first. For each subproblem
give me the code which does the subproblem (so we can see how
you build up the complexity of the answer)

For a given input string you want to

  - A generate all permutations of it


  - Now extend the solution to generate all unique permutations

  - Now given input the string and an integer t do the same but
    print up to `t` repetitions (so with input t=1 you get the same
    output as the previous subproblem)
## Resolution:
The solutions for the different subtasks are standalone implementations as requested. Furthermore, they can be accessed on the following cpp files:
      
       -SimplePermutation.cpp (1.1)
       -UniquePermutation.cpp (1.2)
       -ThresholdPermutation.cpp (1.3)
       
As requested, each cpp file contains its own main method and can be individually compiled and executed. Moreover, I have used an Object Oriented approach and complemented the cpp files with their corresponding header files (which contain class definitions).

Note that Permutation.h was also implemented from scratch, and contains a generic-non logic repetitive declarations and code such as properties common for all mechanisms. Is an hybrid in between an interface and an abstract class.

## Specification:
   
   -It only uses STL and every cpp is self-contained i.e. they do not require the other .cpp files to be compiled.
   
   -Increases in complexity are clearly marked throughout the code for easy identification.
   
   -Following the indications, I have opted for a cohesive approach (limited composition and coupling), because it would defeat the purpose of showcasing increasing complexity. cpps are self-conteined and increase of complexity can be better appreciated.
   
   -All the implementations represent the exact behavior described by the task at hand.
   
   -The use of more complex objects such as Hash related dictionaries was avoided to keep the code in line with STL.
   
   -I am aware of the existence of std::next_iteration but opted not to use it to fulfil with the spirit of the exercise. How I tackle complexity. 
   
   -The 2 implementations could print the excluded permutations. The code is commented, but it is clearly marked in case you decide to examine it.
   
## Instructions: 
    
    1. Compile the exercise: 
    
          .. `g++ SimplePermutation.cpp -o SimplePermutation`
    
    2. Run the executable:
        
          .. `./SimplePermutation`
    
    3. Follow the instructions:
    
        .. `Enter your String:`

        .. (for ThresholdPermutation only)
  
        .. `Enter the Threshold:`
        
You can reach me for questions at any time!
