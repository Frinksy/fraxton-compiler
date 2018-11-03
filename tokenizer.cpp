#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*


    int bool char string array --> data types
    if else while for --> condition statements
    = == <= >= > <  + - * / ++ -- -= += --> operators
    { } ( ) [ ] -->


*/

bool isInteger (string word)
{
    for (unsigned i = 0; i < word.size(); i++)
    {
        if (!isdigit(word[i]))
        {
            return false;
        }
    }
    return true;
}

bool isFloat (string word)
{
    for (unsigned i = 0; i < word.size(); i++)
    {
        if (!isdigit(word[i]) && word[i]!='.')
        {
            return false;
        }
    }
    return true;
}

bool isDefiner (string word)
{
    string definers[] = {"int", "char", "string", "bool", "array", "float"};

    for (int i = 0; i < 6; i++)
    {
        if (word == definers[i])
        {
            return true;
        }
    }
    return false;
}

struct token
{
    string seq;
    string type;
};


vector<token> assign_tokens (vector<string> words) 
{
    vector<token> output;

    bool isString = false;
    for (unsigned i = 0; i < words.size(); i++) 
   {    
       token t;
       t.seq = words[i];
       // DEBUG : 
        cout << endl << "Token is : " << t.seq << endl;
        if (t.seq == "\"")
        {
            isString = !isString;
            t.type = "strDelim";
        }

        if (isString && t.seq !="\"")
        {
            t.type = "string";
        }
        else if (isInteger(words[i]))
        {
            t.type = "integer";
        }
        else if (isDefiner(words[i]))
        {
            t.type = "definer";
        }
        else if (isFloat(words[i]))
        {
            t.type = "float";
        }
        else if (t.type.size() == 0)
        {
            t.type = "undefined";
        }
        cout << "Type is : " << t.type << endl;
        

    }



    return output;
}