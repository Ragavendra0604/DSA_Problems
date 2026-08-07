class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> required;
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                required[tolower(ch)]++;
            }
        }

        string result;
        int minLen = INT_MAX;
        for (string& word : words) {
            unordered_map<char, int> count;
            for (char ch : word) {
                count[ch]++;
            }

            bool valid = true;
            for (auto& [c, freq] : required) {
                if (count[c] < freq) {
                    valid = false;
                    break;
                }
            }

            if (valid && word.size() < minLen) {
                minLen = word.size();
                result = word;
            }
        }

        return result;
    }
};
