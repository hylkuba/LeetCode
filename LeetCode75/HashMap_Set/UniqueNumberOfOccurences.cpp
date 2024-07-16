#include <vector>
#include <map>
#include <set>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::map<int, int> occurences;

        int size = arr.size();
        for(int i = 0; i < size; i++) {
            occurences[arr[i]]++;
        }
        
        std::set<int> unique;
        for(const auto& it : occurences) {
            int cnt = it.second;
            if(unique.find(cnt) != unique.end()) {
                return false;
            }
            unique.insert(cnt);
        }
        
        return true;
    }
};