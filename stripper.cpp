#include <iostream>
#include <fstream>

using namespace std;

string strip_comments (char *source_fname) {

ifstream source_file;

    source_file.open(source_fname);

    string code; 
    string line;

    string holder = "";

    while (getline(source_file, line)) {
        
        for (unsigned i = 0; i<line.size(); i++) {
            if (line[i] == '/' && line[i+1] == '/') {
                i+=line.size();
            }else {
                holder += line[i];
            }
        }

        code += holder + " ";
        holder = "";
    }

    string stripped;
    bool is_comment = false;
    for (unsigned i = 0; i < code.size(); i++) {

        
        switch (code[i])
        {
            case '/':
                if (code[i+1] == '*' && !is_comment) {
                    is_comment = true;
                    i+=2;
                }
                break;
        
            case '*':
                if (code[i+1] == '/' && is_comment) {
                    is_comment = false;
                    i+=2;
                }
                break;
            default:
                break;
        }
        if (!is_comment) {
            stripped += code[i];
        }


    }

    return stripped;
}
