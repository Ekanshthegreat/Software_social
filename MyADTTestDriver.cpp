/*
MyADTTestDriver.cpp

Description: Test Driver for data collection MyADT class

Author: Ekansh Chawla

Created on 21 May 2024
*/

#include <iostream>
#include "MyADT.h"
#include "Profile.h"

using std::cout;
using std::endl;

int main(){
    // Test 1:
    // Create a new instance of MyADT and verify that it is empty.
    cout << "Test 1:" << endl;
    cout << "Create a default MyADT -> testing constructor MyADT()." << endl;
    cout << "Expected results: 0" << endl; 
    MyADT test; 
    cout << endl;
    cout << "Actual results: " << test.getElementCount() << endl; 
    cout << endl;

    // Test 2:
    // Inserting a Profile into MyADT. 
     cout << "Test 2:" << endl;
    cout << "Insert a Profile object into MyADT." << endl;
    Profile p1("username1", "Name1", "email1.example.com", "01/01/2000"); 
    cout << "Expected results: Insertion successful." << endl;
    if(test.insert(p1)){
        cout << "Actual results: Insertion successful." << endl;
    }else{
        cout << "Actual results: Insertion failure." << endl;
    }
    cout << endl;

    // Test 3:
    // Inserting a Profile with duplicate searchKey. 
     cout << "Test 3:" << endl;
    cout << "Insert a Profile object into MyADT with duplicate searchKey as p1" << endl;
    Profile p2("username2", "Name2", "email2.example.com", "02/02/2000"); 
    cout << "Expected results: Insertion successul." << endl;
    if(test.insert(p2)){
        cout << "Actual results: Insertion successful." << endl;
    }else{
        cout << "Actual results: Insertion failure." << endl;
    }
    cout << endl;

    // Test 4:
    // Insert a Profile with maxed out elements corresponding to searchKey.
     cout << "Test 4:" << endl;
    cout << "Max out MyADT with Profile objects of searchKey 'u' then insert another Profile object of searchKey 'u'." << endl;
    cout << "Expected results: Insertion failure." << endl;
    Profile p3("username3", "Name3", "email3.example.com", "03/03/2000"); 
    Profile p4("username4", "Name4", "email4.example.com", "04/04/2000"); 
    Profile p5("username5", "Name5", "email5.example.com", "05/05/2000"); 
    Profile p6("username6", "Name6", "email6.example.com", "06/06/2000"); 
    test.insert(p3);
    test.insert(p4);
    test.insert(p5);
    if(!test.insert(p6)){
        cout << "Actual results: Insertion failure." << endl;
    }else{
        cout << "Actual results: Insertion success." << endl;
    }
    cout << endl;

    // Test 5:
    // Search for a Profile that exists in MyADT test.
     cout << "Test 5:" << endl;
    cout << "Search for p1 in MyADT." << endl;
    cout << "Expected results: Search a success." << endl;
    if(test.search(p1)){
        cout << "Actual results: Search a success." << endl;
    }else{
        cout << "Actual results: Search a failure." << endl;
    }
    cout << endl;

    // Test 6:
    // Search for Profile that does not exist in MyADT test.
     cout << "Test 6:" << endl;
    cout << "Search for a Profile object that does not exist in MyADT. " << endl;
    cout << "Expected results: Search a failure." << endl;
    Profile blah("blah", "blah", "blah", "blah"); 
    if(!test.search(blah)){
        cout << "Actual results: Search a failure." << endl;
    }else{
        cout << "Actual results: Search a success." << endl;
    }
    cout << endl;

    // Test 7:
    // Search for Profile in empty MyADT instance.
     cout << "Test 7:" << endl;
    cout << "Search for a Profile object in an empty MyADT" << endl;
    cout << "Expected results: Search a failure." << endl;
    MyADT test7; 
     if(!test7.search(blah)){
        cout << "Actual results: Search a failure." << endl;
    }else{
        cout << "Actual results: Search a success." << endl;
    }
    cout << endl;


    // Test 8:
    // Remove a Profile object that exists in MyADT.
     cout << "Test 8:" << endl;
    cout << "Remove a profile object that exists in MyADT." << endl;
    cout << "Expected Results: Element count before: 5" << endl;
    cout << "Expected Results: Removal a success."<< endl;
    cout << "Expected Results: Element count after: 4" << endl;
    cout << endl;
             cout << "Actual results: Element count before: "<< test.getElementCount() << endl;

    if(test.remove(p1)){
         cout << "Actual results: Removal a success." << endl;
         cout << "Actual Results: Element count after: " << test.getElementCount() << endl;
    }else{
        cout << "Actual results: Removal a failure." << endl;
        cout << "Actual Results: Element count after: " << test.getElementCount() << endl;
    }
    cout << endl; 

    // Test 9:
    // Attemping to remove a Profile object that does not exist in MyADT.
    cout << "Test 9:" << endl;
    cout << "Attemping to remove a Profile object that does not exist in MyADT." << endl;
    cout << "Expected Results: Removal a failure." << endl;
    if(!test.remove(blah)){
        cout << "Actual Results: Removal a failure" << endl;
    }else{
        cout << "Actual Results: Removal a failure" << endl;
    }
    cout << endl;

    // Test 10:
    // Making a copy of an instance of MyADT and then removing one of the Profile objects and printing out the results
    cout << "Test 10:" << endl;
    cout << "Making a copy of an instance of MyADT and then removing one of the Profile objects and printing out the results" << endl;
    cout << "Expected results: " << endl;
    cout << "MyADT instance:" << endl;
    cout << "abc, Adam, adam123@gmail.com, born on August 2 2003" << endl;
    cout << "xyz, Bob, bob999@gmail.ca, born on March 1 2020" << endl;
    cout << "MyADT instance copy:" << endl;
    cout << "abc, Adam, adam123@gmail.com, born on August 2 2003" << endl;
    cout << endl;

    cout << "Actual results:" << endl;
    Profile person1("abc", "Adam", "adam123@mail.com", "August 2 2003");
    Profile person2("xyz", "Bob", "bob999@mail.ca", "March 1 2020");
    MyADT test10;
    test10.insert(person1); 
    test10.insert(person2);
    MyADT test10Copy(test10);
    test10Copy.remove(person2);
    
    cout << "MyADT instance:" << endl;
    test10.print();
    cout << "MyADT instance copy:" << endl;
    test10Copy.print();

    cout << endl;

    // Test 11: 
    // Outputing same members as shown in SamplePrintResult.txt under Assignment 1 Step 1 - Problem Statement and Requirements.
    cout << "Test 11" << endl;
    cout << "Outputing same members as shown in SamplePrintResult.txt under Assignment 1 Step 1 - Problem Statement and Requirements." << endl;

    cout << "Expected results:" << endl;
    cout << "abcreally, Xiao Wong, xw123@coldmail.com, born on August 2 2003" << endl;
    cout << "ihatethis!, Louis Pace, louis@nowhere.com, born on May 25 2001" << endl;
    cout << "marieLower, Marie Lower, marie@somewhere.ca, born on July 21 1999" << endl;
    cout << "mrvropdgs56, Arwinder Singh, meow@telthem.com, born on December 17 1998" << endl;
    cout << endl;

    cout << "Actual results:" << endl;
    MyADT test11;    
    Profile mem1("abcreally", "Xiao Wong", "xw123@coldmail.com", "August 2 2003"); 
    Profile mem2("ihatethis!", "Louis Pace", "louis@nowhere.com", "May 25 2001"); 
    Profile mem3("marieLower", "Marie Lower", "marie@somewhere.com", "July 21 1999"); 
    Profile mem4("mrvropdgs56", "Arwinder Singh", "meow@telthem.com", "December 17 1998"); 
    test11.insert(mem1);
    test11.insert(mem2);
    test11.insert(mem3);
    test11.insert(mem4);

    test11.print();
    cout << endl;
    
    // Test 12:
    // Remove all Profiles.
    cout << "Test 12:" << endl;
    cout << "Remove all Profile objects from MyADT" << endl;
    cout << "Expected Results: MyADT now has an elementCount: 0" << endl;
    test.removeAll();
    cout << "Actual Results: MyADT now has an elementCount: " << test.getElementCount() << endl;

    
    // Expected results should be sorted by username

    MyADT sortedTest;
    Profile ps1("axxgh", "John Smith", "jsmith@example.com", "02/02/2000");
    Profile ps2("aNN", "Zucker Man", "zucker@example.com", "03/03/2000");
    Profile ps3("a12345", "Jane Doe", "jdoe@example.com", "01/01/2000");
    Profile ps4("mzuckerberg", "Mark Zuckerberg", "mzuck@example.com", "04/04/2000");

    cout << endl<< "Test 13: Inserting profiles and verifying the sorted order by username."<<endl;


    sortedTest.insert(ps1);
    sortedTest.insert(ps2);
    sortedTest.insert(ps3);
    sortedTest.insert(ps4);

    cout << "Expected results:"<<endl;
    cout <<"a12345, Jane Doe, jdoe@example.com, born on 01/01/2000"<<endl;
    cout <<"aNN, John Smith, jsmith@example.com, born on 02/02/2000"<<endl;
    cout << "axxgh, Mark Zuckerberg, mzuck@example.com, born on 04/04/2000"<<endl;
    cout << "mzuckerberg, Zucker Man, zucker@example.com, born on 03/03/2000" << endl;
    cout << endl<<"Actual Results:" << endl;
    sortedTest.print();
    return 0;
}