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
    for (unsigned i = 0; i < words.size(); i++) 
   {    
       token t;
       t.seq = words[i];
       // DEBUG : 
        cout << endl << "Token is : " << t.seq << endl;

        if (isInteger(words[i]))
        {
            t.type = "integer";
        }
        else if (isDefiner(words[i]))
        {
            t.type = "definer";
        }
        else 
        {
            t.type = "undefined";
        }
        cout << "Type is : " << t.type << endl;
        

    }



    return output;
}