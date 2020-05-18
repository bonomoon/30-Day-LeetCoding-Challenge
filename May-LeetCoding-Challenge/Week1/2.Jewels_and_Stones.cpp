class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int cnt = 0;
        unordered_set<char> jewel(J.begin(), J.end());

        for_each(S.begin(), S.end(), [&cnt, &jewel](const char& s) {
            if(jewel.count(s)) {
                ++cnt;
            }
        });
        
        return cnt;
    }
};