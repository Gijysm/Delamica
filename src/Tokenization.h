#ifndef TOKENIZATION_H
#define TOKENIZATION_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
enum class Token_Type {
  _back_roll,
  _integer,
  semi
};
struct Token {
  Token_Type type;
  optional<string> value {};
};
class Tokenizer
    {
  private:
  const string msr_c;
  int m_index;
  [[nodiscard]] optional<char> peak(int ahead = 1) const
  {
    if (m_index + 1 >msr_c.length()) {
      return{};
    }
    else {
      return msr_c.at(m_index);
    }
  }
  char consume() {
    return msr_c.at(m_index++);
  }
  public:
    inline Tokenizer(string str): msr_c(move(str)) {

    }
    inline vector<Token> tokenize(const string& str) {
      string buf;
      vector<Token> tokens;

      while(peak().has_value()) {
        if(isalpha(peak().value())) {
          buf += consume();
        }
        while(peak().has_value()) {
          buf += consume();
        }
      }
      for (int i = 0; i < str.length(); i++) {
        char a = str.at(i);
        if(isalpha(a)) {
          buf += a;
          i++;
          while(isalnum(str.at(i))) {
            buf.push_back(str.at(i));
            i++;
          }
          i--;
          if(buf == "backroll") {
            tokens.push_back({.type = Token_Type::_back_roll});
            buf.clear();
            continue;
          }
          else {
            cerr <<"Token type error" << ": 1" << a <<endl;
            exit(EXIT_FAILURE);
          }
        }
        else if (isdigit(a)) {


          while (isdigit(str.at(i))) {
            buf.push_back(str.at(i));
            i++;
          }
          i--;
          tokens.push_back({.type = Token_Type::_integer, .value = buf});
          buf.clear();
        }

        else if(a == ';') {
          tokens.push_back({.type = Token_Type::semi});
        }
        else if(isspace(a)) {
          continue;
        }
        else {
          cerr << "Token type error: 2, unexpected character: " << a << endl;
          exit(EXIT_FAILURE);
        }
      }
      return tokens;
    }
    ~Tokenizer();

  };
#endif //TOKENIZATION_H
