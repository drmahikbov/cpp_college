//
//  main.cpp
//  vector_slices
//
//  Created by Dr Mahike on 18.12.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Vector2D;

int somme_consecutifs_max(vector<int> vec) {
    
    int sum = 0, temp = 0;
    for (auto v : vec) {
        if (v != 0) {
            sum += v;
        } else {
            temp = (sum > temp) ? sum : temp;
            sum = 0;
        }
    }

    return (temp > sum ? temp : sum);
}

vector<size_t> lignes_max(Vector2D vec) {
    
    vector<size_t> v;
    
    int sum = 0, max_sum = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        sum = somme_consecutifs_max(vec[i]);
        if (sum > max_sum) {
            v.clear();
            v.push_back(i);
            max_sum = sum;
        } else if (sum == max_sum) {
            v.push_back(i);
        }
    }
    
    return v;
}

Vector2D tranches_max(Vector2D vec) {
    Vector2D v;
    for (size_t i = 0; i < lignes_max(vec).size(); i++) {
        v.push_back(vec[lignes_max(vec)[i]]);
    }
    
    return v;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Vector2D vect({{2, 1, 0, 2},
                    {0, 1, 0, 3},
                    {1, 3, 0, 0},
                    {0, 2, 2, 0},
        {2 ,1 ,1 ,1 ,1 ,1 ,1} });
    
    Vector2D testvec({{2 ,1 ,0 ,2 ,0 ,3 ,2},
                       {0 ,1 ,0 ,7 ,0},
                       {1 ,0 ,1 ,3 ,2 ,0 ,3 ,0 ,4},
                       {5 ,0 ,5},
                       {1 ,1 ,1 ,1 ,1 ,1 ,1} });

    for (auto vec : tranches_max(testvec)) {
        for (auto v : vec) {
            cout << v << ", ";
        }
        cout << endl;
    }
    //cout << endl;
   // cout << somme_consecutifs_max({2 ,1 ,1 ,1 ,1 ,1 ,1}) << endl;

    return 0;
}
