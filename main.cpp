#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stripper.cpp"
#include "word_separator.cpp"
#include "tokenizer.cpp"

using namespace std;

int main (int argc, char *argv[]) {
    cout << endl << "hello" << endl;
    string stripped;
    stripped = strip_comments(argv[1]);  
  
    vector<string> words;
    words = word_separator(stripped); 

    vector<token> tokens;
    tokens = assign_tokens(words);



    cout << endl << "EXECUTION DONE" << endl;

    return 0;
}
