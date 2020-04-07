class Solution {
public:
    string makeKey(const string& str) {
        int alphabet[26] = { 0, };
        string key = "";
        
        if(str != "") {
            for(int j = 0; j < str.size(); ++j) {
                ++alphabet[str.at(j) - 'a'];
            }            
        }
        
        for(int j = 0; j < 26; ++j) {
            key += ("@" + to_string(alphabet[j]));
        }
        
        return key;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> strGroups;
        
        switch(strs.size()) {
            case 0:
                return strGroups;
            case 1:
                strGroups.push_back(strs);
                return strGroups;
            default:
                break;
        }

        map<string, vector<string>> groups;
        
        for_each(strs.begin(), strs.end(), [this, &groups](const string& value) {
            string key = this->makeKey(value);

            if(groups.find(key) != groups.end()) {
                groups[key].push_back(value);
            } else {
                vector<string> temp{value};
                groups.insert(make_pair(key, temp));
            } 
        });
            
        for_each(groups.begin(), groups.end(), [&strGroups](const auto& pair) {
            strGroups.push_back(pair.second);
        });
        
        return strGroups;
    }
};