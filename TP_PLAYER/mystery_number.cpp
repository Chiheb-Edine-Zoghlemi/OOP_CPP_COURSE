#include <iostream>
#include <cstring>
using namespace std;
int mystery_number()
{

    const int CORRECT_NUMBER = rand() % 100 + 1;
    cout << "*** Welcome to Mystery Number ***" << endl;
    cout << "** Rules **\n# Guess a number between 1 -- 100 \n# You have 6 attempts \n# With each attempt u will be indicated if the correct number is lower or higher" << endl;
    int choice;

    //cout<<CORRECT_NUMBER<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "-- Attemp " << i + 1 << " --" << endl;
        cin >> choice;
        if (choice == CORRECT_NUMBER)
        {
            cout << "You Guessed it !" << endl;
            return (6 - i);
        }
        else if (choice < CORRECT_NUMBER)
        {
            cout << "The correct number is higher " << endl;
        }
        else
        {
            cout << "The correct number is lower" << endl;
        }
        cin.clear();
    }
    return 0;
}

int main()
{
    int score = mystery_number();
    score ? cout << "You Won ! " << score << " " << endl : cout << "You Lost :( " << endl;
    return 0;
}