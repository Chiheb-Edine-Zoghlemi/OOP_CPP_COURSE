#include <iostream>
#include "Word.hpp"
#include <bits/stdc++.h>

using namespace std;
class Document
{
private:
    int id;
    string name;
    string content;
    int nb_words = 0;
    vector<Word> words;
    int get_id();
    string get_name();
    string get_content();
    int get_number_words();
    int search(string arg_word);
    void display_words();
    void display_words_frequency();
    void display_k_words(int k);
    void split_content_words(string arg_content);

public:
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

bool word_exist(vector<Word> arg_words, Word arg_word)
{
    return true;
}
void Document::split_content_words(string arg_content)
{

    stringstream ss(arg_content);
    string word;

    int id_word = 0;
    while (ss >> word)
    {
        //cout << word << endl;
        Word new_word(id_word, word);
        if (word_exist(words, new_word))
        {
        }
        else
        {
            nb_words++;
            words.push_back(new_word);
        }
    }
}

Document::~Document()
{
}

Document::~Document()
{
}

Document::~Document()
{
}

Document::~Document()
{
}
