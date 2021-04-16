#include <iostream>
#include <limits>
#include "Document.hpp"
using namespace std;
class Corpus
{
private:
    int id;
    string name;
    int nb_documents;
    vector<Document> documents;

public:
    Corpus(int arg_id, string arg_name);
    int get_id();
    string get_name();
    int get_number_documents();
    void add_document();
    void remove_docuement(int id);
    void display_document(int id);
    void search(string word);
    void get_distance(int id_doc1, int id_doc2);
    ~Corpus();
};

Corpus::Corpus(int arg_id, string arg_name)
{
}

int Corpus::get_id()
{
    return id;
}

string Corpus::get_name()
{
    return name;
}

Corpus::~Corpus()
{
}
