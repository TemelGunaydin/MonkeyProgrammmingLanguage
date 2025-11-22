#include "token.h"
#include <string>

Token newToken(TokenType tokenType, char ch) {
  Token tok;
  tok.type = tokenType;
  tok.value = std::string(1, ch);
  return tok;
}
