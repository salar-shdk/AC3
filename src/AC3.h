#ifndef AC3_H_
#define AC3_H_

#include <vector>
#include <NumCpp.hpp>

class AC3{

public:

    AC3(
        std::vector<std::vector<int>> variable_domain,
        nc::NdArray<int> equation,
        std::vector<int> action
    );

    std::vector<std::vector<int>> calculate();

private:

    std::vector<std::vector<int>> variable_domain;
    nc::NdArray<int> equation;
    std::vector<int> action;

    std::vector<std::vector<int>> product (const std::vector<std::vector<int>>& domains);

    bool is_satisfied(std::vector<std::vector<int>> domain);

};

#endif