#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void findPath(unordered_map<string, double>& details) {
    while (true) {
        auto max_it = max_element(details.begin(), details.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });
        auto min_it = min_element(details.begin(), details.end(),
            [](const auto& a, const auto& b) { return a.second < b.second; });

        double max_value = max_it->second;
        double min_value = min_it->second;

        if (max_value == 0.0 && min_value == 0.0) break;

        double transaction = min(max_value, -min_value);

        cout << min_it->first << " needs to pay " << max_it->first << ": " << fabs(transaction) << endl;

        max_it->second -= transaction;
        min_it->second += transaction;
    }
}

int main() {
    unordered_map<string, double> details = {
        {"A", -5.0}, {"B", 25.0}, {"C", -20.0}, {"D", 25.0}, {"E", -20.0}, {"F", -5.0}
    };

    findPath(details);

    return 0;
}
