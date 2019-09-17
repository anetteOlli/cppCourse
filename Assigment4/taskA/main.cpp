#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> numbers = {3, 8, 9, 4, 6};

    int first_number = numbers.front();
    int last_number = numbers.back();

    cout << "first_number: " << first_number << endl;
    cout << "last_number: " << last_number << endl;
    numbers.emplace_back(30);

    int now_first = numbers.front();

    cout << "first number after emplace: " << now_first << endl;

    int start_search = 0;
    int end_search = 6;
    int search_for = 8;

    auto p = find(numbers.begin(), numbers.end(), search_for);
    if (p != end(numbers)){
        cout << "found the number" <<  p.base() <<endl;
    }else {
        cout << "could not find the number" << endl;
    }

    return 0;
}