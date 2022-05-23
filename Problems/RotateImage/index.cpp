//
//  main.cpp
//  ps
//
//  Created by Mohamed Fouad on 19/05/2022.
//

#include <iostream>

#include <vector>
#include <string>
#include "stdio.h"
#include <set>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
    
        int n = (int) matrix[0].size();
           
           for (int layer = 0; layer < n/2; layer ++) {
               
               
               
              for (int i=layer; i<n-layer-1; i++) {
                  
                  
                 //take back before swap
                 int temp = matrix[layer][i];

                 matrix[layer][i] = matrix[n-i-1][layer];
                 matrix[n-i-1][layer] = matrix[n-1-layer][n-i-1];
                 matrix[n-1-layer][n-i-1] = matrix[i][n-1-layer];
                 matrix[i][n-1-layer] = temp;
                  
                  
              }
                          
           }
        
    }
    
    void printMatrix(vector<vector<int>>& matrix) {
        
        for (int i = 0 ; i< matrix.size(); i++) {
            
            for (int j = 0; j< matrix[i].size(); j++) {
                
                cout << matrix[i][j];
            }
            
            cout << "\n";
        }
    }
};


int main(int argc, const char * argv[]) {
    
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    
     Solution* sl = new Solution();

    sl->rotate(matrix);
    sl->printMatrix(matrix);
    
    return 0;
}
