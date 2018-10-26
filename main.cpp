#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stripper.cpp"
#include "word_separator.cpp"

/*


Tokens are:
    keyword --> int char float string bool
    identifier -->  any sequence of alphabetical characters that is not a keyword
    operator -->    operators.....
    constant -->    any number or string expressed inside quotation marks or true/false
    symbol -->  any symbol that is not an operator


Rules :



*/



string keywords[] = {"int", "bool", "float", "char", "string", "true"};


using namespace std;

int main (int argc, char *argv[]) {
    string stripped;
    stripped = strip_comments(argv[1]);  
    cout << stripped << endl;
  
    vector<string> words;
    words = word_separator(stripped); 
    return 0;
}