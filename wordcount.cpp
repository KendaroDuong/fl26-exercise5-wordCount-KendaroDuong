
// ECE 3574 Exercise: Word Count

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

int main() {

    std::ifstream file("mobydick.txt");

    std::unordered_map<std::string, int> counts;
    std::string word;

    // operator>> on a stream already splits on whitespace (space/tab/newline),
    // so this is all we need to pull out each "word".
    while (file >> word) {
        for (char& c : word) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        ++counts[word];
    }

    // Copy into a vector so we can sort by frequency (unordered_map has no order).
    std::vector<std::pair<std::string, int>> freq(counts.begin(), counts.end());

    const int topN = std::min<int>(10, freq.size());

    std::sort(freq.begin(), freq.end(),
              [](const std::pair<std::string, int>& a,
                 const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    for (int i = 0; i < topN; ++i) {
        std::cout << (i + 1) << ". " << freq[i].first << ": "
                  << freq[i].second << " times\n";
    }

    return EXIT_SUCCESS;
}
