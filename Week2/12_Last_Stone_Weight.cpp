class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for_each(stones.begin(), stones.end(), [&pq](const int& stone){
            pq.push(stone);
        });
        
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x - y > 0) {
                pq.push(x - y);
            }
        }
        
        return pq.empty()? 0 : pq.top();
    }
};