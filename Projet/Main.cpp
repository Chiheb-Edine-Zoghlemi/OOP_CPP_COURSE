#include <iostream>
#include "./Classes/Corpus.hpp"
#include <cstring>
using namespace std;

void displayMenu()
{
    printf("\e[31m");
    cout << "\t\t\t================================" << endl;
    cout << "\t\t\t\t     MENU" << endl;
    cout << "\t\t\t================================" << endl;
    cout << "\t\t\tDisplay Corpus List        || 1" << endl;
    cout << "\t\t\tSelect Corpus              || 2" << endl;
    cout << "\t\t\tEXIT                       || 3" << endl;
    cout << "\t\t\t================================" << endl;
    printf("\e[0m");
}
void Credit()
{

    cout << "====================================================================" << endl;
    cout << "This Software is developed by CHiheb Edine Zoghlemi" << endl;
    cout << "====================================================================" << endl;
    cout << "CONTACTS" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "LINKDIN 📘 || https://www.linkedin.com/in/chihebedinezoghlemi/" << endl;
    cout << "GITHUB  📓 || https://github.com/Chiheb-Edine-Zoghlemi" << endl;
}

int main()
{
    try
    {
        system("  figlet -c -f standard 'Corpus Manager'");
    }
    catch (...)
    {
        cout << "******* CORPUS MANAGER *******" << endl;
    }

    displayMenu();
    int choice;
    while (true)
    {
        cout << "\n\x1B[34m--> \033[0m ";
        cin >> choice;
        switch (choice)
        {
        case 3:
            Credit();
            return 0;
            break;
        case 1:
            displayMenu();
            break;
        case 2:
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