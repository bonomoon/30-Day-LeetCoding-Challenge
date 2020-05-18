class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> letters;
        
        for(auto c: magazine) {
            ++letters[c];
        };
        
        for(auto c: ransomNote) {
            if((--letters[c]) < 0) {
                return false;
            }
        };
        
        return true;
    }
};