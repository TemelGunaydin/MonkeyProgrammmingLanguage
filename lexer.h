#include "token.h"
#include <string>

class Lexer {
public:
  Lexer(const std::string &input);
  void readChar();
  Token nextToken();

private:
  std::string input;
  size_t position = 0;
  size_t readPosition = 0;
  char ch = 0;
};
