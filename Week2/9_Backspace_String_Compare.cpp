class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string _S = "", _T = "";
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == '#') {
                if(!_S.empty()) {
                    _S.pop_back();                    
                }
            } else {
                _S.push_back(S[i]);
            }
        }
        
        for(int i = 0; i < T.size(); ++i) {
            if(T[i] == '#') {
                if(!_T.empty()) {
                    _T.pop_back();                    
                }
            } else {
                _T.push_back(T[i]);
            }
        }
        
        return _S == _T;
    }
};