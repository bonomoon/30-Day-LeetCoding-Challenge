/**
 * @param {number[]} nums
 * @return {number}
 */
// using hashmap
var majorityElement = function(nums) {
    const size = nums.length;
    let map = new Map(), ret = 0;
    
    for(let n of nums) {
        if(map.has(n)) {
            map.set(n, map.get(n) + 1);
        } else {
            map.set(n, 1);
        }
        
        if(map.get(n) > size / 2) {
            ret = n;
            break;
        }
    }
    
    return ret;
};

// Boyer-Moore Voting Algorithm
var majorityElement = function(nums) {
    let cnt = 0, ret;
    
    for(let n of nums) {
        if(cnt === 0) {
            ret = n;
        }
        cnt += (ret === n)? 1 : -1;
    }
    
    return ret;
};