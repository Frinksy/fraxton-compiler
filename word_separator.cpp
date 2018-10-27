// Separate source_code into words

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isspecialchar(char c) {

    string spchars = "&~\"#'{([-|`_\\@)]+}=*\%$!;";

    for (int i = 0; i < spchars.size(); i++) {
        if (c == spchars[i]) {
            return true;
        }
    }

    return false;
}


vector<string> splitsymbols (string symbols)
{
    vector<string> output;
    if (symbols.size() > 1)
    {
    for (int i = 0; i < symbols.size(); i++) 
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

    bool issymbols = isspecialchar(code[0]);

    for (int i = 0; i < code.size(); i++) 
    {
        if (code[i] == ' ' && holder.size() > 0) 
        {
            if (!issymbols) 
            {
                output.push_back(holder);
            }
            else
            {
                issymbols = false;
                vector<string> split;
                split = splitsymbols(holder);
                for (int i = 0; i < split.size(); i++)
                {
                    output.push_back(split[i]);
                }
            }

            holder = ""; // reset holder
        }else {

            if (isspecialchar(code[i]) && !issymbols) // if change from symbols to alpha
            {
                issymbols = true;
                if (holder.size() > 0) 
                {

                    output.push_back(holder);
                    holder = "";

                }
            }else if (!isspecialchar(code[i]) && issymbols && holder.size() > 0) 
            {
                issymbols = false;  
                vector<string> split;
                split = splitsymbols(holder);
                
                for (int i = 0; i < split.size(); i++) {
                    output.push_back(split[i]);
                }

                holder = "";

            }




            holder += code[i]; // add the character
        }


        
    }
    output.push_back(holder); // Add last word that is left in holder
    
    return output;
}
