#include <iostream>
using namespace std;
// Recursion Basically Asks Us To Solve Just One Case Of The Problem And Then Solves The Rest By Itself

// When The Function Has Its Recursive Relation Below/After The Processing Part Then It Is Called Tail Recursion
// When The Function Has Its Recursive Relation Above/Before The Processing Part Then It Is Called Head Recursion

int Factorial(int n)
{
    // Every Recursive Function Includes A Base Case Which Should Include A Return Statement Which Will Tell The Compiler To Stop The Execution When The Base Case Becomes True
    if (n == 0)
    {
        return 1;
    }
    // Now We Divide A Big Problem Into Small Problems And The Make The Recursive Call In It To Solve The Small Problem And Rest Of The Problem Will Be Solved By Recusrion
    int SmallerProblem = Factorial(n - 1);
    int BiggerProblem = n * SmallerProblem;
    return BiggerProblem;
    // Or Instead Of Using The Above Bulky Code We Can Use The Code Given Below
    // return n * Factorial(n - 1);
}

int Power(int number, int raisedto)
{
    // Base Case
    if (raisedto == 0)
    {
        return 1;
    }
    // Recursive Call
    return number * Power(number, raisedto - 1);
}

void Counting(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }
    // Processing Block
    cout << n << " ";
    // Tail Recursive Call In Which The Function First Executes The Processing Block And Then Makes The Recursive Call
    return Counting(n - 1);
    // Counting(n - 1);
    // Head Recursive Call In Which The Function First Makes The Recursive Call And Then Executes The Processing Block
    // cout << n << " ";
}

int main()
{
    cout << Factorial(5);
    cout << endl;
    cout << Power(5, 3);
    cout << endl;
    Counting(10);
}