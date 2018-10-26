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

/*
vector<string> word_separator (string code) {

    string holder;  // holds the current word
    vector<string> output; // holds the list of words

    bool issymbols = false;

    for (int i = 0; i < code.size(); i++) {

        if (code[i] == ' ' && !holder.empty()) {
            output.push_back(holder);
            holder = "";

        }else if (isspecialchar(code[i]) && !issymbols && !holder.empty()) {

            output.push_back(holder); // push holder to output
            
            holder = "";              // flush holder
            issymbols = true;
            
        }else if (!isspecialchar(code[i]) && issymbols && !holder.empty()) {

            output.push_back(holder); // push holder to output
            holder = "";              // flush holder
            issymbols = false;
            
        }

        if (code[i]!=' ') {
            holder += code[i];
        }
    }

    output.push_back(holder);



        for (int i = 0; i<output.size(); i++) {
            cout << "Word " << i << " is :" << output[i] << endl;
        }


    return output;
}
*/

vector<string> word_separator (string code) {

    vector<string> output;

    // loop through input

    string holder = ""; // temporary buffer to hold the word being constructed



    for (int i = 0; i < code.size(); i++) {
        if (code[i] == ' ' && holder.size() > 0) {

            output.push_back(holder);

            holder = ""; // reset holder
        }else {

            




            holder += code[i]; // add the character
        }


        
    }

    output.push_back(holder);

    for (int i = 0; i < output.size(); i++) {

        cout << output[i] << endl;
    }


    return output;
}