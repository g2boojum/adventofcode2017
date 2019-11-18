#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>

using namespace std;

bool is_valid(string line) {
    stringstream iss(line);
    string word;
    set<string> words;
    while(iss >> word) {
        auto search = words.find(word);
        if (search != words.end())
            return false;
        words.insert(word);
    }
    return true;
}


int part1(istream& is) {
    int count = 0;;
    string line;
    while (getline(is, line)) {
        if (is_valid(line))
            count++;
    }
    return count;
}

auto word_to_counts(string word) {
    map<char,int> counter;
    for (auto c : word) {
        if (counter.find(c) == counter.end()) {
            // new character
            counter[c] = 1;
        } else {
            // existing character
            counter[c] += 1;
        }
    }
    return counter;
}

bool is_valid2(string line) {
    stringstream iss(line);
    string word;
    set<map<char,int>> counters;
    while(iss >> word) {
        auto cnt = word_to_counts(word);
        auto search = counters.find(cnt);
        if (search != counters.end())
            return false;
        counters.insert(cnt);
    }
    return true;
}

int part2(istream& is) {
    int count = 0;;
    string line;
    while (getline(is, line)) {
        if (is_valid2(line))
            count++;
    }
    return count;
}

vector<string> test_lines{"aa bb cc dd ee",
                          "aa bb cc dd aa",
                          "aa bb cc dd aaa"};

vector<string> test_lines2{"abcde fghij",
                           "abcde xyz ecdab",
                           "iiii oiii ooii oooi oooo",
                           "oiii ioii iioi iiio"};
int main() {
    for (auto ln : test_lines) {
        cout << ln << ": " << is_valid(ln) << "\n";
    }
    ifstream ifs("day4.txt");
    int count = part1(ifs);
    cout << "part1: " << count << " valid lines\n";
    map<char,int> cnt = word_to_counts("aabcda");
    for (auto const& kv : cnt) {
        cout << kv.first << ": " << kv.second << "\n";
    }
    cout << (word_to_counts("aabcda") == word_to_counts("bcdaaa")) << "\n";
    for (auto ln : test_lines2) {
        cout << ln << ": " << is_valid2(ln) << "\n";
    }
    ifstream ifs2("day4.txt");
    count = part2(ifs2);
    cout << "part2: " << count << " valid lines\n";
}
