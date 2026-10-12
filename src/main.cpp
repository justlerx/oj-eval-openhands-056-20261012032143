#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an interval
struct Interval {
    int start, end;
    
    Interval(int s, int e) : start(s), end(e) {}
    
    // For sorting and set operations
    bool operator<(const Interval& other) const {
        return start < other.start;
    }
};

// Function to check if two intervals overlap
bool overlap(const Interval& a, const Interval& b) {
    return max(a.start, b.start) <= min(a.end, b.end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<Interval> intervals;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            Interval new_interval(l, r);
            
            // Find all intervals that conflict with the new interval
            vector<Interval> to_remove;
            for (const auto& interval : intervals) {
                if (overlap(interval, new_interval)) {
                    to_remove.push_back(interval);
                }
            }
            
            // Remove conflicting intervals
            int count = 0;
            for (const auto& interval : to_remove) {
                intervals.erase(interval);
                count++;
            }
            
            // Add the new interval
            intervals.insert(new_interval);
            
            cout << count << '\n';
        } else if (op == 'B') {
            cout << intervals.size() << '\n';
        }
    }
    
    return 0;
}