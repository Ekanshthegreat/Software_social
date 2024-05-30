/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 *                    Its concrete data structure (CDT) is not expandable.  
 *                    This signifies that when this data collection becomes full,
 *                    you do not have to resize its data structure (not in this Assignment 1).  
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *
 * Author: AL and Ekansh Chawla
 * Last modified on: 23 May 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() {
   // cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
 
   /* Put your code here */
   //iterating till Max_alpha and setting the pointers to each of the array elements in "elements to nullptr"
   //and setting element count to 0 for each
   for(unsigned int i = 0; i < MyADT::MAX_ALPHA; i++){
      elements[i] = nullptr;
      elementCount[i] = 0;
   }

   
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   /* Put your code here */

   //Iterating over Max_alpha and coppying the values from rhs if rhs doesnt have a null pointer
   //and its element count at that index is not 0
   for(unsigned int index = 0; index<MyADT::MAX_ALPHA; index++){
      elements[index] = nullptr;
      elementCount[index] = rhs.elementCount[index];

      if (rhs.elements[index] != nullptr && rhs.elementCount[index] >  0) {
         // elements[index] = new Profile[capacity[index]];
         elements[index] = new Profile[MyADT::MAX_ELEMENTS];
         for (unsigned int element = 0; element < elementCount[index]; element++) {
            elements[index][element] = rhs.elements[index][element];
         }
      }
   }
}  

// Overloaded assignment operator - Covered in Lab 4
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) { }
	
// Destructor - Covered in Lab 3
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above cout to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
  
   /* Put your code here */
   for(unsigned int i = 0; i < MAX_ALPHA; i++) {
      // Check if elements[i] isn't nullptr. 
      if(elements[i]) {
         delete[] elements[i];
         elements[i] = nullptr; // setting to nullptr for safety
      }
   }
}  

// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {

   /* Put your code here */
   //simply incrementing through each element and the summation of the element counts gives us the total element count
   unsigned int totalElementCount = 0;
   for(unsigned int i = 0; i < MAX_ALPHA; i++){
      totalElementCount += elementCount[i];
   }

   return totalElementCount;

}


// Description: Inserts an element in the data collection MyADT.
//              Returns "true" when the insertion is successfull, otherwise "false".
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted, MyADT's class invariants are still true
//                and the appropriate elementCount has been incremented.
// Time Efficiency: O(m)
bool MyADT::insert(const Profile& newElement) {
    char searchKey = newElement.getSearchKey();
    int index = searchKey - 'a'; // Calculate index based on search key

    // Initialize array if not already done
    if (elements[index] == nullptr && elementCount[index] == 0) {
        elements[index] = new Profile[MyADT::MAX_ELEMENTS];
        if (elements[index] == nullptr) {
            return false; // Memory allocation failed
        }
        elements[index][elementCount[index]++] = newElement;
        return true;
    }

    // Check if array has space
    if (elementCount[index] < MyADT::MAX_ELEMENTS) {
        // Find the correct position to insert the new element
        unsigned int insertPos = 0;
        while (insertPos < elementCount[index] && elements[index][insertPos] < newElement) {
            insertPos++;
        }

        // Check for duplicate element
        if (insertPos < elementCount[index] && elements[index][insertPos] == newElement) {
            return false; // Duplicate found, do not insert
        }

        // Shift elements to the right to make space for the new element
        for (unsigned int shift = elementCount[index]; shift > insertPos; shift--) {
            elements[index][shift] = elements[index][shift - 1];
        }

        // Insert the new element
        elements[index][insertPos] = newElement;
        elementCount[index]++;
        return true;
    }

    return false; // No space left in the array
}

  

// Description: Removes an element from the data collection MyADT. 
//              Returns "true" when the removal is successfull, otherwise "false".    
// Precondition: The data collection MyADT is not empty.  
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency: O(m)
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */
   bool done = false;
   int index = -1;

   // Get index of array in which toBeRemoved may be found.
   index = toBeRemoved.getSearchKey() - 'a';
        
   // Make sure array for this letter exists
   if ( elements[index] != nullptr && elementCount[index] >  0) {

      for ( unsigned int each = 0; each < elementCount[index] && !done; each++) {
         if ( elements[index][each] == toBeRemoved ) {
            for ( unsigned int shift = each+1; shift < elementCount[index]; shift++ ) {
               // Shift elements left in order to overwrite toBeRemoved
               elements[index][each] = elements[index][shift];
               each = shift;
            }
            done = true;
            // Decrement element count    
            elementCount[index]--;
         }        
      }
   }     
              
   return done;

   
}  

// Description: Removes all elements from the data collection MyADT. 
// Precondition: The data collection MyADT is not empty. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
// Time Efficiency: O(m)
void MyADT::removeAll() {
    
    /* Put your code here */
    for(unsigned int i = 0; i < MAX_ALPHA; i++){
      // Check if "elements[i]" is not nullptr. 
      if(elements[i]){
         delete[] elements[i];
         elements[i] = nullptr; 
      }
      elementCount[i] = 0;
   }

}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency: O(m)
Profile* MyADT::search(const Profile& target) {
    
    /* Put your code here */
   //get searchkey of the target (first letter of username)
   Profile* result = nullptr;
   bool found = false;
   int index = -1;

   // Get index of array in which target may be found.
   index = target.getSearchKey() - 'a';
	
   // Go directly to array of elements with same first letter as target's and ...
   if ( elements[index] != nullptr && elementCount[index] > 0 ) {
      for (unsigned int eachMember = 0; eachMember < elementCount[index] && !found; eachMember++) {
        
         // ... search for target - see Profile class overloaded operator ==
         if ( elements[index][eachMember] == target ) {
            result = &elements[index][eachMember];
            found = true;
         }
      }
   }

   return result; 
}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
// Time Efficiency: O(n)
void MyADT::print() {
  
    /* Put your code here */  
    for(unsigned int i = 0; i < MAX_ALPHA; i++){
      // Check "elements[i]" is not nullptr before accessing Profile object(s) 
      if(elements[i]){
         for(unsigned int j = 0; j < elementCount[i]; j++){
            cout << elements[i][j];
         }
      }
    }


} 

//  End of implementation file
