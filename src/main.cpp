#include "Tokenization.h"
using namespace std;
vector<Token> tokenize(const string& str) {

}
string token_to_asm(const vector<Token>& tokens) {
    stringstream output;
    output << "global _start\n_start:\n";
    for (int i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        if(token.type == Token_Type::_back_roll) {
            if(i + 1 < tokens.size() && tokens[i + 1].type == Token_Type::_integer) {
                if(i + 2 < tokens.size() && tokens[i + 2].type == Token_Type::semi) {
                    output<< "      mov rax, 60\n";
                    output<< "      mov rdi, " << tokens.at(i + 1).value.value() << "\n";
                    output<< "      syscall";
                }
            }
        }

    }
    return output.str();
}
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return EXIT_FAILURE;
    }
    string res;
    {
    stringstream ss;
    fstream file(argv[1], ios::in);
    ss << file.rdbuf();
    file.close();
        res = ss.str();
    }

    vector<Token> token = tokenize(res);
    {
        fstream out_file("out.asm", ios::out);
        out_file << token_to_asm(token);
    }
    system("nasm -felf64 out.asm");
    system("ld -o out out.o");
    return EXIT_FAILURE;

}

