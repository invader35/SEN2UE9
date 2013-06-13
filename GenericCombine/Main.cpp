///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 27-05-2013
// Description : Combine if template
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include "GenericCombine.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "RandomGen.h"
#include <ostream>
#include <list>
#include <set>

using namespace std;

int RandNum () {
    return rgen::GetRandVal(1, 5);
}

int RandNumDobule () {
    return rgen::GetRandVal(1000, 5000) / 500;
}

template <typename T>
T ProductSquare(T const &a, T const &b){
    return static_cast<T>( (pow(a, 2) * pow(b,2)) );
}

template <typename T>
bool isPos(T const &a){
    return a > 0;
}

void testInt(ostream &os = cout){
    vector<int> myVec(5);
    vector<int> myVec2(5);
    vector<int> newVec(5);
    //vector<int> newVec;

    ostream_iterator<int> out_it (os, ", ");

    generate(myVec.begin(), myVec.end(), RandNum);

    generate(myVec2.begin(), myVec2.end(), RandNum);

    combine_if(myVec.begin(), myVec.end(), myVec2.begin(), newVec.begin(), ProductSquare<int>, isPos<int>);

    Print(myVec, "1. Original vector<int>");
    os << endl;
    Print(myVec2, "2. Original vector<int>");
    os << endl;
    Print(newVec, "Result vector<int>");
    os << endl << endl;
}

void testIntList(ostream &os = cout){
    list<int> myVec(5);
    list<int> myVec2(5);
    list<int> newVec(5);

    ostream_iterator<int> out_it (os, ", ");

    generate(myVec.begin(), myVec.end(), RandNum);

    generate(myVec2.begin(), myVec2.end(), RandNum);

    combine_if(myVec.begin(), myVec.end(), myVec2.begin(), newVec.begin(), ProductSquare<int>, isPos<int>);

    Print(myVec, "1. Original list<float>");
    os << endl;
    Print(myVec2, "2. Original list<float>");
    os << endl;
    Print(newVec, "Result list<float>");
    os << endl << endl;
}

void testFloat(ostream &os = cout){

    vector<float> myVec(5);
    vector<float> myVec2(5);
    vector<float> newVec(5);
    
    ostream_iterator<float> out_it (os, ", ");

    generate(myVec.begin(), myVec.end(), RandNumDobule);

    generate(myVec2.begin(), myVec2.end(), RandNumDobule);

    combine_if(myVec.begin(), myVec.end(), myVec2.begin(), newVec.begin(), ProductSquare<float>, isPos<float>);

    Print(myVec, "1. Original vector<float>");
    os << endl;
    Print(myVec2, "2. Original vector<float>");
    os << endl;
    Print(newVec, "Result vector<float>");
    os << endl << endl;
}

void testFloatList(ostream &os = cout){
    list<float> myVec(5);
    list<float> myVec2(5);
    list<float> newVec(5);

    ostream_iterator<float> out_it (os, ", ");

    generate(myVec.begin(), myVec.end(), RandNumDobule);

    generate(myVec2.begin(), myVec2.end(), RandNumDobule);

    combine_if(myVec.begin(), myVec.end(), myVec2.begin(), newVec.begin(), ProductSquare<float>, isPos<float>);

    Print(myVec, "1, Original list<float>");
    os << endl;
    Print(myVec2, "2. Original list<float>");
    os << endl;
    Print(newVec, "Result list<float>");
    os << endl << endl;
}

int main(){
    rgen::Init();

    ostream &os = cout;

    testInt(os);
    testIntList(os);
    
    testFloat(os);
    testFloatList(os);
    
    cin.get();
    return 0;
}