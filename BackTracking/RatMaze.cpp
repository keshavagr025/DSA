#include <iostream>
#include <string>
#include <vector>
using namespace std;

void ratInMaze(int maze[][4], int x, int y, string sol, int n, vector<vector<bool>> vis){

    // base case
    if( x == n - 1 && y == n - 1){
        cout << sol << "\n";
        return;
    }

    // Up condition
    if( x - 1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1){
        vis[x][y] = true;
        ratInMaze(maze, x-1, y, sol + "U", n, vis);
        vis[x][y] = false;
    }

    // down condition
    if( x + 1 < n && !vis[x+1][y] && maze[x+1][y] == 1){
        vis[x][y] = true;
        ratInMaze(maze, x+1, y, sol + "D", n, vis);
        vis[x][y] = false;
    }

    // Left condition
    if( y - 1 >= 0 && !vis[x][y-1] && maze[x][y-1] == 1){
        vis[x][y] = true;
        ratInMaze(maze, x, y-1, sol + "R", n, vis);
        vis[x][y] = false;
    }

    // Rigth condition
    if( y + 1 < n && !vis[x][y+1] && maze[x][y+1] == 1){
        vis[x][y] = true;
        ratInMaze(maze, x, y+1, sol + "R", n, vis);
        vis[x][y] = false;
    }
}

void solveMaze(int maze[][4], int n){
    string sol = "";
    vector<vector<bool>>vis(n, vector<bool> (n, false));
    
    if(maze[0][0] == 1){
        ratInMaze(maze, 0, 0, sol, n, vis);
    }
   
}

int main(){
    int n = 4;
    int maze[4][4] = {{1,1,0,0},
                      {1,1,0,1},
                      {1,1,1,0},
                      {0,0,1,1}};

    solveMaze(maze, n);
   

}
