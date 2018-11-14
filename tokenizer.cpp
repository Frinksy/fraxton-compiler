#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*


    int bool char string array --> data types
    if else while for --> condition statements
    = == <= >= > <  + - * / ++ -- -= += --> operators
    { } ( ) [ ] -->

    reserved words are :


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

bool isControlChar (string word)
{
    string control_chars[] = {"(", ")", ";", "[", "]", "{", "}"};

    for (unsigned i = 0; i < sizeof(control_chars)/sizeof(control_chars[0]); i++)
    {
        if (word == control_chars[i])
        {
            return true;
        }
    }
    return false;
}

bool isOperator (string word)
{
    string ops[] = {"+", "+=", "++",
                    "-", "-=", "--",
                    "*", "*=",
                    "/", "/=",
                    "=", "==",
                    "<", "<=",
                    ">", ">=",
                    "!="};

    for (unsigned i = 0; i < sizeof(ops)/sizeof(ops[0]); i++)
    {
        if (word == ops[i])
        {
            return true;
        }
    }

    return false;

}

bool isKeyword (string word)
{
    string keywords[] = {"true", "false", "using", "NULL", "operator", "function"};

    for (unsigned i  = 0; i < sizeof(keywords)/sizeof(keywords[0]); i++)
    {
        if (word == keywords[i])
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
        else if (isOperator(words[i]))
        {
            t.type = "operator";
        }
        else if (isControlChar(words[i]))
        {
            t.type = "controlChar";
        }
        else if (isKeyword(words[i]))
        {
            t.type = "keyword";
        }
        else if (t.type.size() == 0)
        {
            t.type = "identifier";
        }
        cout << "Type is : " << t.type << endl;
        

    }



    return output;
}