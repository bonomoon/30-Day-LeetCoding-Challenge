class Solution {
public:
    bool isHappy(long long n) {        
        vector<int> rets;
        int sum = 0;

        while(true) {
            sum += (int)pow((n%10), 2.0);
            n /= 10;
            if(n == 0) {
                if(sum != 1) {
                    // sum 결과 값들에 똑같은 값이 중복된다면 이 숫자는 happy number가 아님
                    if(binary_search(rets.begin(), rets.end(), sum)) {
                        return false;
                    } else {    // 중복이 안되면 sum을 push하고 값을 갱신해서 루프를 돌림
                      rets.push_back(sum);
                      n = sum, sum = 0;
                    }
                } else {    // 주어진 숫자는 happy number 임
                    return true;
                }
            }
        }
    }
};