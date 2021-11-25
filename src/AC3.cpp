#include<iostream>
#include"AC3.h"

using namespace std;

AC3::AC3(
    std::vector<std::vector<int>> variable_domain,
    nc::NdArray<int> equation,
    std::vector<std::string> action
    ):  variable_domain(variable_domain),
        equation(equation),
        action(action)
    {
    }

    



void AC3::print(){
    cout<< this->equation;
}