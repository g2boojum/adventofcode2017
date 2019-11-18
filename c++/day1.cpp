#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>



auto fname = "day1.txt";

inline auto next_idx(int i, int size) {
    return (i+1) % size;
}

inline auto next_idx2(int i, int size) {
    return (i+size/2) % size;
}

int main() {
    std::cout << fname << "\n";
    std::ifstream fs(fname);
    std::string data((std::istreambuf_iterator<char>(fs)),
                     (std::istreambuf_iterator<char>()));
    data.pop_back(); // kill linefeed
    std::vector<int> v;
    // convert chars to ints
    for (auto c : data) {
        v.push_back(int(c) - int('0'));
    }
    // part 1
    long sum = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] == v[next_idx(i, v.size())]) {
            sum += v[i];
        }
    }
    std::cout << "part 1: " << sum << "\n";
    // part 2
    long sum2 = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] == v[next_idx2(i, v.size())]) {
            sum2 += v[i];
        }
    }
    std::cout << "part 2: " << sum2 << "\n";
}


