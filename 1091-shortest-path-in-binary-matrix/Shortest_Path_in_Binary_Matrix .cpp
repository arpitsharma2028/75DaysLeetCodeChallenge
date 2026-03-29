/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.
*/

// BFS appraoch

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    if (grid[0][0] != 0)
        return -1;
    int m = grid.size(), n = grid[0].size();
    auto isSafe = [&](int x, int y)
    {
        return (x >= 0 && y >= 0 && x < m && y < n);
    };
    q.push({0, 0});
    grid[0][0] = 1;
    int level = 0;
    while (!q.empty())
    {
        int N = q.size();
        while (N--)
        {
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;

            if (x == m - 1 && y == n - 1)
                return level + 1; // as we need to tell how many zero we have to faced

            for (int i = 0; i < 8; i++)
            {
                int x_ = x + dir[i][0];
                int y_ = y + dir[i][1];

                if (isSafe(x_, y_) && !grid[x_][y_])
                {
                    q.push({x_, y_});
                    grid[x_][y_] = 1;
                }
            }
        }
        level++;
    }
    return -1;
}
// dijkstra approach
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>direction = {{0,1} , {1,0} , {-1,0} , {0,-1} , {1,1} , {-1,-1} , {1,-1} , {-1,1}};
        int m = grid.size() , n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1])return -1;
        typedef pair<int , pair<int,int>> P ;
        priority_queue<P , vector<P> , greater<P>>pq; // dist , {i,j};
        // queue<P>pq; // we can use queue too , as edge weight is same for all
        pq.push({0 , {0,0}});
        vector<vector<int>>dist(m , vector<int>(n , INT_MAX));
        dist[0][0] = 0;
        auto isSafe = [&](int x , int y){
            return (x >= 0 && y >= 0 && x < m && y < n); 
        };
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            // perform edge relaxation for neighbours;
            for( auto dir : direction){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(isSafe(x_ , y_) && !grid[x_][y_] && 1 + d < dist[x_][y_]){
                    dist[x_][y_] = 1 + d ;
                    pq.push({dist[x_][y_] , {x_ , y_}});
                }
            }

        }
        if(dist[m-1][n-1] == INT_MAX)
            return -1;
        
        return dist[m-1][n-1]+1;
    }
};

int main()
{
}