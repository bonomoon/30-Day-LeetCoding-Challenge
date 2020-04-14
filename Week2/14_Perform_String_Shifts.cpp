class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        int count = 0, size = s.size();
        for_each(shifts.begin(), shifts.end(), [&count](vector<int>& shift) {
            count += (shift[0]? shift[1]: -shift[1]);
        });
        // rotate(s.rbegin(), s.rbegin() + (count%size + size)%size, s.rend());
        if(count > 0) {     // right
            rotate(s.rbegin(), s.rbegin() + count%size, s.rend());
        } else if(count == 0) {
            return s;
        } else {        // left
            rotate(s.begin(), s.begin() - count%size, s.end());
        }
        return s;
    }
};