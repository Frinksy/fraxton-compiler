// Separate source_code into words

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isspecialchar(char c) {

    string spchars = "&~\"#'{([-|`_\\ç@)]+}=*\%$!;";

    for (int i = 0; i < spchars.size(); i++) {
        if (c == spchars[i]) {
            return true;
        }
    }

    return false;
}


/*
TODO:
    make sure numbers are processed as one
    make sure correct operators/symbols are processed as one


    i++ --> i ++
    int hello=12; --> int hello = 12 ;

*/



vector<string> word_separator (string code) {

    vector<string> output;

    // loop through input

    string holder = ""; // temporary buffer to hold the word being constructed

    bool issymbols = isspecialchar(code[0]);

    for (int i = 0; i < code.size(); i++) {
        if (code[i] == ' ' && holder.size() > 0) {

            output.push_back(holder);

            holder = ""; // reset holder
        }else {

            if ((isspecialchar(code[i]) && !issymbols) || (!isspecialchar(code[i]) && issymbols)) {
                issymbols = !issymbols;
                if (holder.size() > 0) {

                    output.push_back(holder);
                    holder = "";

                }
            }




            holder += code[i]; // add the character
        }


        
    }

    output.push_back(holder);

    for (int i = 0; i < output.size(); i++) {

        cout << output[i] << endl;
    }


    return output;
}