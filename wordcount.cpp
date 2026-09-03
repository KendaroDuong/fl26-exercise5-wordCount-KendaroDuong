#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

bool compareByCount(const std::pair<std::string, int>& a,
                     const std::pair<std::string, int>& b) {
    return a.second > b.second;
}

int main() {

    std::ifstream file("mobydick.txt");

    std::unordered_map<std::string, int> counts;
    std::string word;

    while (file >> word) {
        for (char& c : word) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        ++counts[word];
    }

    std::vector<std::pair<std::string, int>> freq(counts.begin(), counts.end());

    std::sort(freq.begin(), freq.end(), compareByCount);

    const int topN = std::min<int>(10, freq.size());

    for (int i = 0; i < topN; ++i) {
        std::cout << (i + 1) << ". " << freq[i].first << ": "
                  << freq[i].second << " times\n";
    }

    return EXIT_SUCCESS;
}
