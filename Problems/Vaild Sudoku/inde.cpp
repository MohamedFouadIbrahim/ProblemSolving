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

//[["5","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<set<int>> rows(9), cols(9), blocks(9);
        
        for (int i = 0; i < 9; i++) {
            
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.')
                {
                    continue;
                    
                }
                
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3)*3+j/3].count(curr))
                    return false;
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3)*3+j/3].insert(curr);
            }
            
        }
        
        return true;
    }
};




int main(int argc, const char * argv[]) {
    
    vector<vector<char>> matrix = {
            {'1', '2', '3' ,'4','5','6','7','8','9'},
            {'1', '2', '3' ,'4','5','6','7','8','9'},
            {'1', '2', '3' ,'4','5','6','7','8','9'},
    };
    
     Solution* sl = new Solution();


    cout << sl-> isValidSudoku(matrix);
    
//    cout << sl->isValidSudoku(matrix);
    return 0;
}
