#include <iostream>
using namespace std;

#define QueueLength 10

class Queue
{
public:
    string SeatNumber[QueueLength] = {""};
    int AvailableSeats()
    {
        int count = 0;
        for (int i = 0; i < QueueLength; i++)
        {
            if (SeatNumber[i] == "")
            {
                count++;
            }
        }
        return count;
    }
    int BookSeat(string name)
    {
        if (AvailableSeats() != 0)
        {
            int SeatIndex;
            for (SeatIndex = 0; SeatIndex < QueueLength; SeatIndex++)
            {
                if (SeatNumber[SeatIndex] == "")
                {
                    break;
                }
            }
            SeatNumber[SeatIndex] = name;
            return SeatIndex;
        }
        else
        {
            cout << "The House For This Show Is Full!" << endl;
            return -1;
        }
    }
    int CancelSeat(string name)
    {
        if (AvailableSeats() != 0)
        {
            int SeatIndex;
            for (SeatIndex = 0; SeatIndex < QueueLength; SeatIndex++)
            {
                if (SeatNumber[SeatIndex] == name)
                {
                    break;
                }
            }
            SeatNumber[SeatIndex] = "";
            return SeatIndex;
        }
        else
        {
            cout << "No Seats Available To Cancel!" << endl;
            return -1;
        }
    }
    void DispaySeat()
    {
        for (int i = 0; i < QueueLength; i++)
        {
            if (SeatNumber[i] != "")
            {
                cout << i << " : " << SeatNumber[i] << endl;
            }
        }
    }
};

int main()
{
    Queue MovieQueue;
    MovieQueue.BookSeat("Rudransh Rajpurohit");
    MovieQueue.BookSeat("Devika Solanki");
    MovieQueue.BookSeat("Rohan Sankhla");
    MovieQueue.BookSeat("Chaitya Khanna");
    MovieQueue.BookSeat("Prince Poonia");
    MovieQueue.BookSeat("Samriddhi Srivastava");
    MovieQueue.CancelSeat("Rohan Sankhla");
    MovieQueue.BookSeat("Rohan Sankhla");
    MovieQueue.DispaySeat();
    cout << MovieQueue.AvailableSeats();
}