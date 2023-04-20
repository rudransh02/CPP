#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newX, int newY, int size, vector<vector<int>> visited, vector<vector<int>> maze)
{
    // Function To Check If Its Possible To Move In The Chosen Direction Or Not
    if ((newX >= 0 && newX < size) && (newY >= 0 && newY < size) && visited[newX][newY] == 0 && maze[newX][newY] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int size, vector<vector<int>> maze, int sourceX, int sourceY, vector<vector<int>> &visited, string &direction, vector<string> &path)
{
    // Push The Set Of Directions In The Final Path And Then Return
    if ((sourceX == (size - 1)) && (sourceY == (size - 1)))
    {
        path.push_back(direction);
        return;
    }

    // Initialize The Final Direction With 1 When The Mouse Successfully Found The Way Out The Maze
    visited[sourceX][sourceY] = 1;

    // Code To Move Down The Maze
    int newX = sourceX + 1;
    int newY = sourceY;
    if (isSafe(newX, newY, size, visited, maze))
    {
        direction.push_back('D');
        solve(size, maze, newX, newY, visited, direction, path);
        // Backtracking
        direction.pop_back();
    }

    // Code To Move Left The Maze
    newX = sourceX;
    newY = sourceY - 1;
    if (isSafe(newX, newY, size, visited, maze))
    {
        direction.push_back('L');
        solve(size, maze, newX, newY, visited, direction, path);
        // Backtracking
        direction.pop_back();
    }

    // Code To Move Right The Maze
    newX = sourceX;
    newY = sourceY + 1;
    if (isSafe(newX, newY, size, visited, maze))
    {
        direction.push_back('R');
        solve(size, maze, newX, newY, visited, direction, path);
        // Backtracking
        direction.pop_back();
    }

    // Code To Move Up The Maze
    newX = sourceX - 1;
    newY = sourceY;
    if (isSafe(newX, newY, size, visited, maze))
    {
        direction.push_back('U');
        solve(size, maze, newX, newY, visited, direction, path);
        // Backtracking
        direction.pop_back();
    }

    // Initialize The Source Of Origin To Zero To Calculate Any New Path If Available: Backtracking
    visited[sourceX][sourceY] = 0;
}

vector<string> FindPath(int size, vector<vector<int>> maze)
{
    // Declaring A Vector Of Strings To Store The Final Paths
    vector<string> path;

    // If The Source Of The Maze Is Zero Return Empty Path As The Mouse Can't Move Anywhere
    if (maze[0][0] == 0)
    {
        return path;
    }

    // Declaring The Starting Index Of The Mouse In The Maze
    int sourceX = 0;
    int sourceY = 0;

    // Creating And Initializing A Vector Containing Visited Path By Zero At The Beginning
    vector<vector<int>> visited = maze;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            visited[i][j] = 0;
        }
    }

    // Creating A Temporary String Direction To Store A Single Move
    string direction = "";

    // Calling A Function Solve To Get The Actual Solution
    solve(size, maze, sourceX, sourceY, visited, direction, path);

    // Returning The Final Paths
    return path;
}

int main()
{
    // Defining The Dimensions Of Our Maze
    int size = 4;

    // Initializing The Maze
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};

    // Calling Find Path Function
    vector<string> path = FindPath(size, maze);

    // Printing The Vector Of Strings Returned By FindPath()
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
}