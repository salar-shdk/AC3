# AC3
AC3 algorithm cpp implementation.


# Usage Example
Define your domains as vectors like the given example. Note that position in this vector maters.
``` cpp
// domains = {
//     'a': [0, 2, 4],
//     'b': [0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
// }
vector<vector<int>> variable_domain = {
    {0, 2, 4},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
};
```
Define your constraints as NdArray like the given example. You must have [NumCpp](https://github.com/dpilger26/NumCpp) library installed in your system.
* Only supports equation as constraints.
* You must define actions in relevant position like the given example.
``` cpp
// constraints:
//     a + b - 4 = 0
nc::NdArray<int> equation = {
    {1, 1, -4},
};

// actions:
// = -> 1
// > -> 2
// < -> 3
// >= -> 4
// <= -> 5
vector<int> action = {1};
```

Then Create AC3 object and call calculate. the result is in the same type of the input domains.
``` cpp
AC3 ac3(variable_domain, equation, action);
auto result = ac3.calculate();
```

# Dependencies
* I strongly recommend to check these two projects if you have not checked yet.

[NumCpp](https://github.com/dpilger26/NumCpp)

[CppItertools](https://github.com/ryanhaining/cppitertools#enumerate)
