#include <iostream>
#include <limits>
using namespace std;

int mystery_number()
{
    const int CORRECT_NUMBER = rand() % 100 + 1;
    cout << "*** Welcome to Mystery Number Challenge ***" << endl;
    cout << "** Rules **\n# Guess a number between 1 -- 100 \n# You have 6 attempts \n# With each attempt u will be indicated if the correct number is lower or higher\n#Reaming tries will be added to your score" << endl;
    int choice;
    int i;
    //cout << CORRECT_NUMBER << endl;
    for (i = 0; i < 6; i++)
    {
        cout << "-- Attemp " << i + 1 << " --" << endl;
        cin >> choice;
        if (choice == CORRECT_NUMBER)
        {
            cout << "You Guessed it 🎉" << endl;
            return 6 - i + 1;
        }
        else if (choice < CORRECT_NUMBER)
        {
            cout << "The correct number is higher ⬆️" << endl;
        }
        else
        {
            cout << "The correct number is lower  ⬇️" << endl;
        }
    }
    return 0;
}

class Player
{
private:
    string name;
    int score;
    int damages;
    Player *enemy;

public:
    Player();
    Player(string arg_name);
    string getName();
    void setName(string arg_name);
    int getScore();
    void setScore(int arg_score);
    int getDamages();
    void setDamages(int arg_damages);
    void setEnemy(Player arg_enemy);
    Player *getEnemy();
    bool isDead();
    void displayDamages();
    void displayScore();
    bool attack();
    void chooseWeapon();
    void challenge();
    void chooseAction();
    friend ostream &operator<<(ostream &output, const Player &p)
    {
        output << "Player " << p.name << "it has score of " << p.score << "and damages of " << p.damages << endl;
        return output;
    }
    friend istream &operator>>(istream &input, Player &p)
    {
        input >> p.name;
        return input;
    }
    ~Player();
};

// Defining the Methode
//Constructor with no args
Player::Player()
{
    name = "UKNOWN";
    score = 5;
    damages = 1;
}
//Constructor with name arg
Player::Player(string arg_name)
{
    name = arg_name;
}
//get Name
string Player::getName()
{
    return name;
}
//set Name
void Player::setName(string arg_name)
{
    name = arg_name;
}
//get score
int Player::getScore()
{
    return score;
}
//set score
void Player::setScore(int arg_score)
{
    score = arg_score;
}
//get damage
int Player::getDamages()
{
    return damages;
}
//set enemy
void Player::setEnemy(Player arg_enemy)
{
    enemy = &arg_enemy;
}

//get enemy
Player *Player::getEnemy()
{
    return enemy;
}
//set damage
void Player::setDamages(int arg_damages)
{
    damages = arg_damages;
}

//is dead function
bool Player::isDead()
{
    if (score <= 0)
    {
        cout << "The Player " << name << " is Dead 👻" << endl;
        return true;
    }
    return false;
}
// display the name and the score of a player
void Player::displayScore()
{
    cout << "The score of the player " << name << " is " << score << endl;
}
//display the damage and the name of a player
void Player::displayDamages()
{
    cout << "The damages of the player " << name << " is " << damages << endl;
}
//attack function
bool Player::attack()
{

    setScore(getScore() - damages);

    if (isDead() == false)
    {
        displayScore();
        return false;
    }
    return true;
}
//chose weapon function
void Player::chooseWeapon()
{
    int choice;
    int choices[4];
    for (int i = 0; i < 4; i++)
    {
        choices[i] = rand() % 5 + 1;
    }
    cout << "*** Cose your weapon ***" << endl;
    cout << "#1 -- Knife 🔪" << endl;
    cout << "#2 -- Axe 🪓" << endl;
    cout << "#3 -- Bomb 💣" << endl;
    cout << "#4 -- Bow 🏹" << endl;
    while (!(cin >> choice))
    {

        if (choice == 1 or choice == 2 or choice == 3 or choice == 4)
        {
            damages = choices[choice];
            break;
        }
        else
        {
            cout << "\e[33m Unvalid Choice ⚠️\e[0m" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    this->displayDamages();
}
void Player::challenge()
{
    int bonus = mystery_number();
    score = score + bonus;
    this->displayScore();
}
void Player::chooseAction()
{
    cout << "-- Chose Your Action --" << endl;
    cout << "#1 | Attack an Enemy  💀" << endl;
    cout << "#2 | Take a Challange 💪" << endl;
    cout << "#3 | Change Weapon    🛠️" << endl;
    int choice;
    while (true)
    {
        cin >> choice;
        if (choice == 1)
        {
            this->attack();
            break;
        }
        else if (choice == 2)
        {
            this->challenge();
            break;
        }
        else if (choice == 3)
        {
            this->chooseWeapon();
            break;
        }

        else
        {
            cout << "\e[33m Unvalid Choice ⚠️\e[0m" << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
Player::~Player()
{
}
