#pragma once
#include <vector>

//Assigment 7, task 2, set.hpp

class Set {
public:
    std::vector<int> set_vector;
    Set()= default;
    Set(const std::vector<int> &set_);
    void set_new_element(const int new_element);
    Set find_of_union_set(const Set &other_set) const;
    void replace_set(Set &new_set);

};