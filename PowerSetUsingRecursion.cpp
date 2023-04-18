#include <iostream>
#include <vector>
using namespace std;

void solve(int array[], vector <int> subset, int index, vector<vector <int>> &answer, int size)
{
    // Base Case: When Index Becomes Equal To The Size Of Array
    if (index >= size)
    {
        // Pushing The Temporary Subset To The Power Set Before Returning
        answer.push_back(subset);
        return;
    }
    // Recursive Call For Exclude Function
    solve(array, subset, index + 1, answer, size);
    // Storing The Current Element On Index In A Variable
    int element = array[index];
    // Push That Particular Element Into The Temporary Subset
    subset.push_back(element);
    // Recursive Call For Include Function
    solve(array, subset, index + 1, answer, size);
}

vector<vector <int>> powerSet(int array[], int size)
{
    // Creating A Vector Of Vector To Store The Final Subsests
    vector<vector <int>> answer;
    // Creating A Vector To Store The Current Subset
    vector <int> subset;
    // Creating An Index For Fucntion To Keep Track Of The Scope Of Array
    int index = 0;
    solve(array, subset, index, answer, size);
    return answer;
}

int main()
{
    int size;
    cout << "Enter The Number Of Elements : ";
    cin >> size;
    int array[size];
    cout << "Enter The Elements Seperated By Space : ";
    for (int i = 0; i < 3; i++)
    {
        cin >> array[i];
    }
    vector<vector <int>> V = powerSet(array, 3);
    for (int i = 0; i < V.size(); i++)
    {
        cout << '{';
        for (int j = 0; j < V[i].size(); j++)
        {
            cout << V[i][j];
        }
        cout << '}' << endl;
    }
}