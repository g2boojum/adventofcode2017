#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string fname = "day5.txt";

auto read_data() {
    ifstream is(fname);
    vector<int> v;
    int num;
    while (is >> num) 
        v.push_back(num);
    return v;
}

int part1(vector<int>& data) {
    vector<int>::iterator it = data.begin();
    int steps = 0;
    int max_steps = 1000000;
    while ((it >= data.begin()) && (it < data.end()) && (steps < max_steps)) {
        int offset = *it;
        (*it)++;
        it += offset;
        steps++;
    }
    return steps;
}

int part2(vector<int>& data) {
    vector<int>::iterator it = data.begin();
    int steps = 0;
    int max_steps = 100000000;
    while ((it >= data.begin()) && (it < data.end()) && (steps < max_steps)) {
        int offset = *it;
        if (offset >= 3) {
            (*it)--;
        } else {
            (*it)++;
        }
        it += offset;
        steps++;
    }
    return steps;
}
int main() {
    auto data = read_data();
    cout << "part1: " << part1(data) << " steps\n";
    auto data2 = read_data();
    cout << "part2: " << part2(data2) << " steps\n";
}
