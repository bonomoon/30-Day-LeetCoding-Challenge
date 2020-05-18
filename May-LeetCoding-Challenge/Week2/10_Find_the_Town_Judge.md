### Cpp

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustCnt(N, 0);
        
        for(auto& t : trust) {
            --trustCnt[t[0] - 1], ++trustCnt[t[1] - 1];
        }
        
        for(int i = 0; i < N; ++i) {
            if(trustCnt[i] == N - 1) {
                return i + 1;
            }
        }
        
        return -1;
    }
};
```

### Javascript

```javascript
/**
 * @param {number} N
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(N, trust) {
    let trustCnt = new Array(N).fill(0);

    for(let t of trust) {
        --trustCnt[t[0] - 1], ++trustCnt[t[1] - 1];
    }
    
    for(let i in trustCnt) {
        if(trustCnt[i] === N - 1) {
            return Number(i) + 1;
        }
    }
    
    return -1;
};
```