#include <iostream>
#include "Player.hpp"
using namespace std;

void displayMenu()
{
    printf("\e[31m");
    cout << "\t\t\t===========================" << endl;
    cout << "\t\t\t\t     MENU" << endl;
    cout << "\t\t\t===========================" << endl;
    cout << "\t\t\t2 PLAYERS MODE          || 1" << endl;
    cout << "\t\t\tMULTI PLAYERS MODE      || 2" << endl;
    cout << "\t\t\tEXIT                    || 3" << endl;
    cout << "\t\t\t===========================" << endl;
    printf("\e[0m");
}
void Credit()
{

    cout << "====================================================================" << endl;
    cout << "This game is developed by CHiheb Edine Zoghlemi" << endl;
    cout << "====================================================================" << endl;
    cout << "CONTACTS" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "LINKDIN 📘 || https://www.linkedin.com/in/chihebedinezoghlemi/" << endl;
    cout << "GITHUB  📓 || https://github.com/Chiheb-Edine-Zoghlemi" << endl;
}
Player createPlayer(int i)
{
    Player p;
    cout << "\n\x1B[34mPlease Provide Player [" << i + 1 << "] Name" << endl;
    cout << "--> \033[0m ";
    cin >> p;
    return p;
}
bool isWinner(Player players[], int playersNumber)
{
    int deadPlayers = 0;
    for (int i = 0; i < playersNumber; i++)
    {
        if (players[i].isDead())
        {
            deadPlayers++;
        }
    }
    if (deadPlayers == playersNumber - 1)
    {
        return true;
    }
    return false;
}
void twoPlayers_Mode()
{
    Player p1, p2;
    system(" figlet -c -f bubble 'GAME STARTED'");
    p1 = createPlayer(0);

    p2 = createPlayer(1);
    p1.setEnemy(p2);
    p2.setEnemy(p1);
    cout << p1.getEnemy() << endl;
    int round = 1;
    while (true)
    {
        cout << "<< Round " << round << " >>" << endl;
        if (isWinner)
        {
            break;
        }
        round++;
    }
}
void displayPlayer(Player players[], int players_number)
{
    printf("\e[35m");
    cout << "\n-----------------------------------------" << endl;
    cout << "       Players Board" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| #Number | Score |         Name" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < players_number; i++)
    {
        if (players[i].isDead() == false)
        {
            cout << "| #" << i + 1 << "     |    " << players[i].getScore() << "    | " << players[i].getName() << endl;
            cout << "-----------------------------------------" << endl;
        }
    }
    printf("\e[0m \n");
}
void multiPlayers_Mode()
{
    system(" figlet -c -f bubble 'GAME STARTED'");
    printf("\n\x1B[34mPlease Provide The Number Of Users\n");
    int players_number;
    cout << "--> \033[0m ";
    // validate the that the user provided a valid number
    while (true)
    {
        cin >> players_number;
        if (players_number <= 0)
        {
            cout << "\e[33m Unvalid Choice ⚠️\e[0m" << endl;
        }
        else
        {
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Player players[players_number];
    for (int i = 0; i < players_number; i++)
    {
        players[i] = createPlayer(i);
    }
    int round = 1;
    while (true)
    {
        cout << "<< Round " << round << " >>" << endl;
        displayPlayer(players, players_number);
        if (isWinner(players, players_number))
        {
            break;
        }
        round++;
    }
}

int main()
{
    //printf('\e[31m');
    system(" sudo apt install figlet && figlet -c -f standard 'Death Match'");
    //printf('\e[0m');
    displayMenu();
    int choice;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 3:
            Credit();
            return 0;
            break;
        case 1:
            twoPlayers_Mode();
            displayMenu();
            break;
        case 2:
            multiPlayers_Mode();
            displayMenu();
            break;

        default:
            cout << "\e[33m Unvalid Choice ⚠️\e[0m" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}