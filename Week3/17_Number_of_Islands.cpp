class Solution {
public:    
    // using BFS
    int numIslands(vector<vector<char>>& grid) {
        int x_size = 0, y_size = grid.size(), cnt = 0;
        queue<pair<int, int>> q;
        int offset[] = {0, -1, 0, 1, 0};
        
        if(grid.size()) {
           x_size = grid[0].size();
        } else {
            return 0;
        }
        
        for(int i = 0; i < y_size; ++i) {
            for(int j = 0; j < x_size; ++j) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0', ++cnt;
                    q.push({i, j});
                    
                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        
                        int x = p.second, y = p.first;
                        for(int k = 0; k < 4; ++k) {
                            int tmp_x = x + offset[k], tmp_y = y + offset[k + 1];
                            
                            if((tmp_x >= 0 && tmp_x < x_size) && (tmp_y >= 0 && tmp_y < y_size)) {
                                if(grid[tmp_y][tmp_x] == '1') {
                                    grid[tmp_y][tmp_x] = '0';
                                    q.push({tmp_y, tmp_x});                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};