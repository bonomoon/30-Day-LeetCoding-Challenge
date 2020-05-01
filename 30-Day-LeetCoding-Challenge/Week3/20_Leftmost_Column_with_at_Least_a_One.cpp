/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

// using binary search O(nlogn)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int row = binaryMatrix.dimensions()[0], col = binaryMatrix.dimensions()[1];
        int left_x = 0, right_x = col - 1, idx = -1;
        
        while(left_x <= right_x) {
            int mid_x = left_x + (right_x - left_x) / 2;
            bool flag = true;
            
            for(int i = 0; i < row; ++i) {
                if(binaryMatrix.get(i, mid_x)) {
                    idx = mid_x, right_x = mid_x - 1, flag = false;
                    break;
                }
            }
            if(flag) {
                left_x = mid_x + 1;
            }
        }
        
        return idx;
    }
};

// simple solution O(N + M)
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int row = binaryMatrix.dimensions()[0], col = binaryMatrix.dimensions()[1];
        int x = col - 1, y = 0;
        
        while(x >= 0 && y < row) {
            if(binaryMatrix.get(y, x)) {
                --x;
            } else {
                ++y;
            }
        }
        
        return (x == col - 1)? -1: x + 1;
    }
};