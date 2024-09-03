#ifndef PARSER_HPP
#define PARSER_HPP

#include "Tokenization.h"

namespace node
{
    struct NodeExpr
    {
        Token int_lit;
    };
    struct NodeExit
    {
        NodeExpr expr;
    };
}

class Parser
{
  public:
    inline explicit Parser(vector<Token>& tokens):
 ms_tokens(move(tokens))
     {}
    std::optional<node::NodeExit> ParseExpr()
    {

      }
    std::optional<node::NodeExit> Parse()
    {
        std::optional<node::NodeExit> exit_node;
      while(peak().has_value())
        {
        if(peak().value().type == Token_Type::_back_roll)
          {
          if(auto node_expr = ParseExpr())
          {

          }
          else
            {
            cerr << "Error parsing expression." << endl;
            }
        }

      }
    }
  private:
    [[nodiscard]] optional<Token> peak(int ahead = 1) const
    {
        if (m_index + 1 >ms_tokens.size()) {
            return{};
        }
        else {
            return ms_tokens.at(m_index);
        }
    }
    inline Token consume() {
        return ms_tokens.at(m_index++);
    }
  const vector<Token>& ms_tokens;
  size_t m_index;
};

#endif //PARSER_HPP
