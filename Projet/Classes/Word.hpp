#include <iostream>
#include <limits>
using namespace std;

class Word
{
private:
    int id;
    string word;
    int occurence;

public:
    Word(int arg_id, string arg_word);
    void add_occurence();
    int get_occurence();
    string get_word();
    int get_id();
    ~Word();
};

Word::Word(int arg_id, string arg_word)
{
    id = arg_id;
    word = arg_word;
}
string Word::get_word()
{
    return word;
}

int Word::get_id()
{
    return id;
}
int Word::get_occurence()
{
    return occurence;
}
void Word::add_occurence()
{
    occurence++;
}

Word::~Word()
{
}
