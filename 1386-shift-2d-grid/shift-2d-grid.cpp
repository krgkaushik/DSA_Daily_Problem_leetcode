class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total_elements = m * n;
        
        // Optimize k to avoid unnecessary full rotations
        k = k % total_elements;
        
        // If k is 0 after modulo, the grid remains unchanged
        if (k == 0) return grid;
        
        // Initialize a new grid with the same dimensions
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Flatten 2D index to 1D
                int original_1d_index = i * n + j;
                
                // Calculate shifted 1D index
                int new_1d_index = (original_1d_index + k) % total_elements;
                
                // Convert shifted 1D index back to 2D coordinates
                int new_i = new_1d_index / n;
                int new_j = new_1d_index % n;
                
                // Place the element in the new grid
                result[new_i][new_j] = grid[i][j];
            }
        }
        
        return result;
        
    }
};