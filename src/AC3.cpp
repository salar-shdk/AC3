#include <algorithm>
#include <cppitertools/itertools.hpp>

#include"AC3.h"

using namespace std;

AC3::AC3(
    vector<vector<int>> variable_domain,
    nc::NdArray<int> equation,
    vector<int> action
    ):  variable_domain(variable_domain),
        equation(equation),
        action(action)
    {}

bool AC3::is_satisfied(vector<vector<int>> domains){
    for (auto domain : domains){
        nc::NdArray<int> domain_array = nc::NdArray(domain);
        auto equation_result = nc::matmul(this->equation, domain_array.transpose());

        for (auto&& [i, element] : iter::enumerate(equation_result)){
            switch(this->action[i]){
                case 1:   // =
                    if (element == 0) return true;
                    break;
                case 2:   // >
                    if (element > 0) return true;
                    break;
                case 3:   // <
                    if (element < 0) return true;
                    break;
                case 4:  // >=
                    if (element >= 0) return true;
                    break;
                case 5:  // <=
                    if (element <= 0) return true;
                    break;
            }
        }
    }
    return false;
}

vector<vector<int>> AC3::calculate(){
    for (auto&& [i, domain] : iter::enumerate(this->variable_domain)){
        vector<int> tmp_domain = domain;
        vector<vector<int>> abstract_domains = this->variable_domain;
        abstract_domains.erase(abstract_domains.begin() + i);
        vector<vector<int>> abstract_domains_product = product(abstract_domains);
        for (auto domain_element : domain){
            vector<vector<int>> tmp_abstract_domains_product = abstract_domains_product;
            for (auto& abstract_domains_product_member : tmp_abstract_domains_product){
                abstract_domains_product_member.insert(abstract_domains_product_member.begin() + i, domain_element);
                abstract_domains_product_member.push_back(1);
            }            
            if (!is_satisfied(tmp_abstract_domains_product)){
                tmp_domain.erase(std::remove(tmp_domain.begin(), tmp_domain.end(), domain_element), tmp_domain.end());
            }
        }
        this->variable_domain[i] = tmp_domain;
    }
    return this->variable_domain;
}

vector<vector<int>> AC3::product (const vector<vector<int>>& domains) {
    vector<vector<int>> result = {{}};
    for (const auto& domain_member : domains) {
        vector<vector<int>> result_member;
        for (const auto& result_member_value : result) {
            for (const auto domain_member_value : domain_member) {
                result_member.push_back(result_member_value);
                result_member.back().push_back(domain_member_value);
            }
        }
        result = move(result_member);
    }
    return result;
}
