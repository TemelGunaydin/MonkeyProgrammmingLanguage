#include "lexer.h"
#include "token.h"
#include <iostream>
#include <string>
#include <vector>
int main(int argc, char *argv[]) {
  std::string input = "=(){};";

  struct TestCase {
    TokenType expectedType;
    std::string expectedLiteral;
  };

  std::vector<TestCase> tests = {
      {TokenType::ASSIGN, "="},    {TokenType::LPAREN, "("},
      {TokenType::RPAREN, ")"},    {TokenType::LBRACE, "{"},
      {TokenType::RBRACE, "}"},    {TokenType::SEMICOLON, ";"},
      {TokenType::END_OF_FILE, ""}};

  Lexer l(input);

  for (size_t i = 0; i < tests.size(); ++i) {
    Token tok = l.nextToken();

    if (tok.type != tests[i].expectedType) {
      std::cerr << "tests[" << i << "] - tokenType is wrong.expected="
                << static_cast<int>(tests[i].expectedType)
                << ", got=" << static_cast<int>(tok.type) << "\n";
      return 1;
    }

    if (tok.value != tests[i].expectedLiteral) {
      std::cerr << "tests[" << i << "] - literal wrong. expected=\""
                << tests[i].expectedLiteral << "\", got=\"" << tok.value
                << "\"\n";
      return 1;
    }
  }
  std::cout << "All tests are passed\n";
  return 0;
}
