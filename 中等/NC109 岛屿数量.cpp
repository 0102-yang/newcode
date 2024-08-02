#include "../common-header.hpp"

class Solution
{
public:
    int solve(const vector<vector<char>>& grid) {
        int res = 0;
        const int m = grid.size();
        const int n = grid[0].size();
        vector searched_grid(m, vector(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !searched_grid[i][j]) {
                    stack<pair<int, int>> search_stack;
                    search_stack.emplace(i, j);
                    ++res;

                    while (!search_stack.empty()) {
                        auto [x, y] = search_stack.top();
                        search_stack.pop();

                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && !searched_grid[x][y]) {
                            searched_grid[x][y] = true;
                            search_stack.emplace(x - 1, y);
                            search_stack.emplace(x + 1, y);
                            search_stack.emplace(x, y - 1);
                            search_stack.emplace(x, y + 1);
                        }
                    }
                }
            }
        }

        return res;
    }

};
