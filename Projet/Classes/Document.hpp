#include <iostream>
#include "Word.hpp"
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
class Document
{
private:
    int id;
    string name;
    string content;
    int nb_words = 0;
    vector<Word> words;

public:
    int get_id();
    string get_name();
    string get_content();
    int get_number_words();
    int search(string arg_word);
    void display_words();
    void display_words_frequency();
    void display_k_words(int k);
    void split_content_words(string arg_content);
    Document(int arg_id, string arg_name, string arg_content);
    ~Document();
};

Document::Document(int arg_id, string arg_name, string arg_content)
{
    id = arg_id;
    name = arg_name;
    content = arg_content;
    split_content_words(content);
}
int Document::get_id()
{
    return id;
}

string Document::get_name()
{
    return name;
}

string Document::get_content()
{
    return content;
}

int Document::get_number_words()
{
    return nb_words;
}

bool word_exist(vector<Word> arg_words, string arg_word)
{
    for (int i = 0; i < arg_words.size(); i++)
    {
        if (arg_words[i].get_word() == arg_word)
        {
            return true;
        }
    }
    return false;
}
void update_word_number(vector<Word> arg_words, string arg_word)
{
    for (int i = 0; i < arg_words.size(); i++)
    {
        if (arg_words[i].get_word() == arg_word)
        {
            arg_words[i].add_occurence();
        }
    }
}
void Document::split_content_words(string arg_content)
{
    stringstream ss(arg_content);
    string word;

    int id_word = 0;
    while (ss >> word)
    {
        //cout << word << endl;

        if (word_exist(words, word))
        {
            update_word_number(words, word);
        }
        else
        {
            id_word++;
            Word new_word(id_word, word);
            nb_words++;
            words.push_back(new_word);
        }
    }
}

void Document::display_words()
{
    printf("\e[35m");
    cout << "\n-----------------------------------------" << endl;
    cout << "       List Of Words" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| #      | Word" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < words.size(); i++)
    {
        cout << "| #" << words[i].get_id() << "     |    " << words[i].get_word() << endl;
        cout << "-----------------------------------------" << endl;
    }
    printf("\e[0m \n");
}

void Document::display_words_frequency()
{
    printf("\e[35m");
    cout << "\n-----------------------------------------" << endl;
    cout << "       List Of Words With Frequency " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| #      | Word       | Frequency" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < words.size(); i++)
    {
        cout << "| #" << words[i].get_id() << "     |    " << words[i].get_word() << "     |    " << words[i].get_occurence() << endl;
        cout << "-----------------------------------------" << endl;
    }
    printf("\e[0m \n");
}

void Document::display_k_words(int k)
{
    sort(words.begin(), words.end());
    printf("\e[35m");
    cout << "\n-----------------------------------------" << endl;
    cout << "       List Of Words With Frequency " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| #      | Word       | Frequency" << endl;
    cout << "-----------------------------------------" << endl;
    for (int i = 0; i < k; i++)
    {
        cout << "| #" << words[i].get_id() << "     |    " << words[i].get_word() << "     |    " << words[i].get_occurence() << endl;
        cout << "-----------------------------------------" << endl;
    }
    printf("\e[0m \n");
}
int Document::search(string arg_word)
{
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i].get_word() == arg_word)
        {
            return id;
        }
    }
    return -1;
}

Document::~Document()
{
}
