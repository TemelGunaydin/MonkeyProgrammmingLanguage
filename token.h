#pragma once
#include <string>

enum class TokenType {
  ILLEGAL,
  END_OF_FILE,
  IDENT,
  INT,
  ASSIGN,
  PLUS,
  COMMA,
  SEMICOLON,
  LPAREN,
  RPAREN,
  LBRACE,
  RBRACE,
  FUNCTION,
  LET,
};

struct Token {
  TokenType type;
  std::string value;
};

Token newToken(TokenType tokenType, char ch);
