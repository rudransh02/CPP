#include <bits/stdc++.h>
using namespace std;

void solve(string s, int index, vector<string> &answer)
{
    // Base Case: Push The Current String With Swapped Elements Into The Final Answer When Index Goes Out Of Scope
    if (index >= s.length())
    {
        answer.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        // Swapping Element On Index i With The Element On Current Index With Each
        swap(s[index], s[i]);
        // Recursive Call For The Element On The Next Index
        solve(s, index + 1, answer);
        // Using Backtracking To Get The Original String Back Before Firing The Recurive Function Again
        swap(s[index], s[i]);
    }
}

vector<string> Permutate(string s)
{
    // Creating A Vector To Store The Answer
    vector<string> answer;
    // Creating An Index Variable To Iterate Over The String
    int index = 0;
    // Calling The Solve Function
    solve(s, index, answer);
    // Returning The Answer Vector
    return answer;
}

int main()
{
    string s;
    cin >> s;
    vector<string> V = Permutate(s);
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << endl;
    }
}