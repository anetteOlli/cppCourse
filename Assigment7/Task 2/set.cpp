#include "set.hpp"
#include <algorithm> // std::find
#include <vector>

Set::Set(const std::vector<int> &set_vector_) {
    for (int element : set_vector_) {
        set_new_element(element);
    }
}
void Set::set_new_element(const int new_element) {
    auto p = (std::find(this-> Set::set_vector.begin(), this-> Set::set_vector.end(), new_element ));
    if(p == this-> Set::set_vector.end()) set_vector.emplace_back(new_element);
}

Set Set::find_of_union_set(const Set &other_set) const {
    Set result;
    for (int element : this->Set::set_vector){
        result.set_new_element(element);
    }
    for(int element : other_set.set_vector){
        result.set_new_element(element);
    }
    return result;
}

void Set::replace_set(Set &new_set) {
    this->set_vector.clear();
    for(int element : new_set.set_vector){
        this->set_new_element(element);
    }
}
