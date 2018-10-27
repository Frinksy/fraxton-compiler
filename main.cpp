#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stripper.cpp"
#include "word_separator.cpp"
#include "tokenizer.cpp"

using namespace std;

int main (int argc, char *argv[]) {
    string stripped;
    stripped = strip_comments(argv[1]);  
  
    vector<string> words;
    words = word_separator(stripped); 
    return 0;
}
