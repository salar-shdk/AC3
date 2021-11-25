#include "AC3.h"
#include <NumCpp.hpp>
#include <vector>

using namespace std;

int main(){
    // domains = {
    //     'a': [2, 3, 4, 5, 6, 7],
    //     'b': [4, 5, 6, 7, 8, 9],
    //     'c': [1, 2, 3, 4, 5]
    // }
    vector<vector<int>> variable_domain = {
        {2, 3, 4, 5, 6, 7},
        {4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5}
    };
    
    // constraints:
    //     b - 2 * a  = 0
    //     a - c      = 0
    //     b - c + 2 <= 0
    //     b - c - 2 >= 0
    vector<string> action = {"=", "=", "<=", ">="};
    nc::NdArray<int> equation = {
        {-2, 1, 0, 0},
        {1, 0, -1, 0},
        {0, 1, -1, 2},
        {0, 1, -1, -2}
    };

    AC3 ac3(variable_domain, equation, action);
    ac3.print();
}