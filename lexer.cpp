#include "lexer.h"
#include "token.h"

Lexer::Lexer(const std::string &input) : input(input) { readChar(); }

void Lexer::readChar() {
  if (readPosition >= input.size()) {
    ch = 0;
  } else {
    ch = input[readPosition];
  }

  position = readPosition;
  readPosition += 1;
}

Token Lexer::nextToken() {
  Token tok;

  switch (ch) {
  case '=':
    tok = newToken(TokenType::ASSIGN, ch);
    break;
  case ';':
    tok = newToken(TokenType::SEMICOLON, ch);
    break;
  case '(':
    tok = newToken(TokenType::LPAREN, ch);
    break;
  case ')':
    tok = newToken(TokenType::RPAREN, ch);
    break;
  case '{':
    tok = newToken(TokenType::LBRACE, ch);
    break;
  case '}':
    tok = newToken(TokenType::RBRACE, ch);
    break;
  case 0:
    tok.value = "";
    tok.type = TokenType::END_OF_FILE;
    break;
  }

  readChar();
  return tok;
}
