//
//  main.cpp
//  arraySize
//
//  Created by Dr Mahike on 25.10.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

// The exercise is meant to find a way of measuring an array's size
// without using the array.length property

// Declare these variables to avoid passing them as parameters
// By the way, the array could be of any type. We're just filling in values to test it
int arr[] = {5, 7, 235, 352, 6, 642, 64, 6, 2, 46, 55, 235, 352, 6, 642, 64, 6, 2, 46, 55, 235, 352, 6, 642, 64, 6, 2, 46, 55};
int t;
int length;

int arraySize(int offset) {
    t = 1;
    length = sizeof(arr)/sizeof(arr[0]);
    
    while ((offset + t) < length) {
        t *= 2;
    }
    
//    cout << "value of t is: " << t << endl;
//    cout << "value of offset is: " << offset << endl;
//    cout << "" << endl;
    
    return (t == 1 ? offset + t : arraySize(offset + t/2));
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << arraySize(0) << endl;
    return 0;
}
