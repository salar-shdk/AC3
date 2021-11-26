#include "AC3.h"
#include <NumCpp.hpp>
#include <vector>

using namespace std;

void printvec(vector<vector<int>> &a){
    for (auto list : a){
        for(auto value : list){
            cout<<value<<", ";
        }
        cout<<"\n";
    }
}

int main(){
    // domains = {
    //     'a': [0, 2, 4],
    //     'b': [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
    // }
    vector<vector<int>> variable_domain = {
        {0, 2, 4},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    };
    
    // constraints:
    //     a + b - 4 = 0

    // actions:
    // = -> 1
    // > -> 2
    // < -> 3
    // >= -> 4
    // <= -> 5
    vector<int> action = {1};
    nc::NdArray<int> equation = {
        {1, 1, -4},
    };

    AC3 ac3(variable_domain, equation, action);
    auto result = ac3.calculate();
    printvec(result);
}