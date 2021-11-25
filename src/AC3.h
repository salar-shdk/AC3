#ifndef AC3_H_
#define AC3_H_

#include<vector>
#include <NumCpp.hpp>

class AC3{

public:

    AC3(
        std::vector<std::vector<int>> variable_domain,
        nc::NdArray<int> equation,
        std::vector<std::string> action
    );

    void print();

private:

    std::vector<std::vector<int>> variable_domain;
    nc::NdArray<int> equation;
    std::vector<std::string> action;

};

#endif