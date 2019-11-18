#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

string tst1 = "5 1 9 5\n7 5 3 \n2 4 6 8\n";
string tst2 = "5 9 2 8\n9 4 7 3\n3 8 6 5\n";

int line_check(string line) {
    // A line is a set of space-delimited integers.
    // Compute checksum = max(ints) - min(ints)
    stringstream iss(line);
    int num;
    vector<int> line_nums;
    while(iss >> num)
        line_nums.push_back(num);
    int min = *min_element(line_nums.begin(), line_nums.end());
    int max = *max_element(line_nums.begin(), line_nums.end());
    return (max - min);
}

int part1(istream& is) {
    vector<int> checksums;
    string line;
    while (getline(is, line)) {
        checksums.push_back(line_check(line));
    }
    return accumulate(checksums.begin(), checksums.end(), 0);
}

auto line_to_vec(string line) {
    stringstream iss(line);
    int num;
    vector<int> line_nums;
    while (iss >> num)
        line_nums.push_back(num);
    return line_nums;
}

auto find_and_divide_even_divisors(vector<int> v) {
    vector<int> results;
    int bigger;
    int smaller;
    for (int i=0; i<v.size(); i++) {
        int n1 = v[i];
        for (int j=i+1; j<v.size(); j++) {
            int n2 = v[j];
            bigger = max(n1, n2);
            smaller = min(n1, n2);
            if (bigger % smaller == 0)
                results.push_back(bigger / smaller);
        }
    }
    if (results.size() != 1)
        cout << "find_and_divide_even_divisors found multiples\n";
    return results[0];
}

int part2(istream& is) {
    vector<int> divisions;
    string line;
    while (getline(is, line)) {
        vector<int> v;
        v = line_to_vec(line);
        int d = find_and_divide_even_divisors(v);
        divisions.push_back(d);
    }
    return accumulate(divisions.begin(), divisions.end(), 0);
}



int main() {
    auto c = line_check("5 1 9 5\n");
    cout << "checksum: " << c << "\n";
    istringstream is1(tst1);
    int cksum = part1(is1);
    cout << "tst1 checksum = " << cksum << "\n";
    ifstream ifs("day2.txt");
    cksum = part1(ifs);
    cout << "part1 checksum = " << cksum << "\n";
    vector<int> vtst{5, 9, 2, 8};
    cout << find_and_divide_even_divisors(vtst) << "\n";
    istringstream is2(tst2);
    cout << "part2 test: " << part2(is2) << "\n";
    ifstream ifs2("day2.txt");
    cout << "part2: " << part2(ifs2) << "\n";
}
