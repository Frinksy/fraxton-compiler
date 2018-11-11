// Separate source_code into words

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isspecialchar(char c) {

    string spchars = "&~\"#<>'{([-|`_\\@)]+}=*\%$!;";

    for (unsigned i = 0; i < spchars.size(); i++) {
        if (c == spchars[i]) {
            return true;
        }
    }

    return false;
}


vector<string> splitsymbols (string symbols) 
{   // Splits symbols up into the longest match ('++' stays '++' but '()' becomes '(' & ')' )
    vector<string> output;
    if (symbols.size() > 1)
    {
    for (unsigned i = 0; i < symbols.size(); i++) 
    {
        switch (symbols[i])
        {
            case '+':
                switch (symbols[i+1])
                {
                    case '+':
                        output.push_back("++");
                        i++;
                        break;
                    case '=':
                        output.push_back("+=");
                        i++;
                        break;
                    default:
                        output.push_back("+");
                        break;

                }
                break;
            case '-':
                switch (symbols[i+1])
                {
                    case '-':
                        output.push_back("--");
                        i++;
                        break;
                    case '=':
                        output.push_back("-=");
                        i++;
                        break;
                    default:
                        output.push_back("-");
                        break;
                }
                break;
            case '<':   
                switch (symbols[i+1])
                {
                    case '=':
                        output.push_back("<=");
                        i++;
                        break;
                
                    default:
                        string a = "";
                        a += '<';
                        output.push_back(a);
                }
            case '>':
                switch (symbols[i+1]) {
                    case '=':
                        output.push_back(">=");
                        i++;
                        break;
                    default:
                        string a = "";
                        a += '>';
                        output.push_back(a);
                }
            case '=':
                switch (symbols[i+1])
                {
                    case '=':
                        output.push_back("==");
                        i++;
                        break;
                    default:
                        output.push_back("=");
                        break;
                }
                break;
            case '*':   
                switch (symbols[i+1])
                {
                    case '*':
                        output.push_back("**");
                        i++;
                    case '=':
                        output.push_back("*=");
                        i++;
                        break;
                    default:
                        string a = "";
                        a += "*";
                        output.push_back(a);
                        break;
                }
            case '\\':
                switch (symbols[i+1])
                {
                    case '=':
                        output.push_back("/=");
                        i++;
                        break;
                    default:
                        string a = "";
                        a += "/";
                        output.push_back(a);
                        break;
                }
            case '&':
                switch (symbols[i+1])
                {
                    case '&':
                        output.push_back("&&");
                        i++;
                        break;
                    default:
                        output.push_back("&");
                        break;
                }
                break;
            case '|':
                switch (symbols[i+1])
                {
                    case '|':
                        output.push_back("||");
                        i++;
                        break;
                    default:
                        output.push_back("|");
                        break;
                }
                break;
            default:                
                string a = "";
                a += symbols[i];
                output.push_back(a);
                a = "";
                break;

        }
    }
    }
    else
    {
        output.push_back(symbols);
    }


    return output;


}



vector<string> word_separator (string code) {

    vector<string> output;

    // loop through input

    string holder = ""; // temporary buffer to hold the word being constructed

    bool issymbols = isspecialchar(code[0]); // are current chars in the holder symbols?
    bool isString = false; // are current chars part of a string?

    for (unsigned i = 0; i < code.size(); i++) 
    {   
        if (code[i] == '"')
        {
              // push holder and flush it, then push ' " '  
            
            if (holder != "") // check if holder is empty 
            {
                output.push_back(holder);
                holder = "";
                output.push_back("\"");
            }
            else
            {
                output.push_back("\"");
            }
            isString = !isString;
        }
        if (!isString && code[i] != '"')
        { 
            if (code[i] == ' ' && holder.size() > 0) 
            {
                if (!issymbols) 
                {
                    if (holder == " ")
                    {
                        holder = "";
                    }
                    else
                    {
                    output.push_back(holder); //  push holder to word list
                    }
                }
                else
                {   // split the symbols up into separate words
                    issymbols = false;
                    vector<string> split;
                    split = splitsymbols(holder);
                    for (unsigned i = 0; i < split.size(); i++)
                    {
                        output.push_back(split[i]);
                    }
                }

                holder = ""; // reset holder
            }
            else 
            {
                if (isspecialchar(code[i]) && !issymbols)
                { // change from alphanum to symbols
                    issymbols = true;
                    if (holder.size() > 0) 
                    {   // push and reset holder
                        output.push_back(holder);
                        holder = "";    // make sure holder is reset
                    }
                }else if (!isspecialchar(code[i]) && issymbols && holder.size() > 0) 
                {   // change from symbols to alphanum
                    issymbols = false;  
                    vector<string> split;   // split symbols 
                    split = splitsymbols(holder);
                    
                    for (unsigned i = 0; i < split.size(); i++) {
                        output.push_back(split[i]);     // push symbols to word list
                    }

                    holder = "";    // make sure holder is reset

                }
                holder += code[i]; // add the character
            }
        }
        else if (code[i]!='"')
        {
            holder += code[i];
        }

    }
    if (!issymbols && (holder.size() > 0 || holder != " "))
    {
        output.push_back(holder); // add last word that is left in holder
    }
    else
    {   // split symbols up and then add them
        vector<string> split;
        split = splitsymbols(holder);
            for (unsigned i = 0; i < split.size(); i++)
            {   
                output.push_back(split[i]);
            }
    }

    return output;
}
