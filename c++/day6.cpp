#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

vector<int> data {14, 0, 15, 12, 11, 11, 3, 5, 1, 6, 8,
                  4, 9, 1, 8, 4};
vector<int> test_data {0, 2, 7, 0};

vector<int> redistribute(vector<int> v) {
    auto max_ele = max_element(v.begin(), v.end());
    int most = *max_ele;
    *max_ele = 0;
    int pos_max = max_ele - v.begin();
    for (int offset = 1; offset <= most; offset++) {
        int pos = (pos_max + offset) % v.size();
        v[pos] += 1;
    }
    return v;
}

int part1(vector<int> v) {
    set<vector<int>> patterns;
    int num = 0;
    while (patterns.find(v) == patterns.end()) {
        patterns.insert(v);
        v = redistribute(v);
        num++;
    }
    return num;
}

int part2(vector<int> v) {
    map<vector<int>,int> patterns;
    int num = 0;
    while (patterns.find(v) == patterns.end()) {
        patterns[v] = num;
        v = redistribute(v);
        num++;
    }
    return (num - patterns[v]);
}

int main() {
    auto num = part1(test_data);
    cout << "test_data: " << num << "\n";
    num = part1(data);
    cout << "data: " << num << "\n";
    num = part2(data);
    cout << "part2: " << num << "\n";
}

