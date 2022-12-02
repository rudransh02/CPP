#include <iostream>
using namespace std;

void SourceToDestinaton(int source, int destination)
{
    if (source == destination)
    {
        cout << "Arrived!" << endl;
        return;
    }
    cout << "Source: " << source << " Destination: " << destination << endl;
    SourceToDestinaton(++source, destination);
}

int Fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void SayDigit(int number)
{
    string array[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    if (number == 0)
    {
        return;
    }
    int digit = number % 10;
    number = number / 10;
    SayDigit(number);
    cout << array[digit] << " ";
}

int main()
{
    int number;
    int destination = 10;
    int term;
    int source = 1;
    SourceToDestinaton(source, destination);
    // cin >> term;
    // cout << Fibonacci(term);
    cin >> number;
    SayDigit(number);
    return 0;
}