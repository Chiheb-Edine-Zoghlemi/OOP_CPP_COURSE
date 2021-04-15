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
    int nb_words;
    vector<Word> words;

public:
    Document(/* args */);
    ~Document();
};

Document::Document(/* args */)
{
}

Document::~Document()
{
}
