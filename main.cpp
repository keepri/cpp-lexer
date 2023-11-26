#include <algorithm>
#include <iostream>

#include "lib/dates/dates.h"
#include "lib/lexer/lexer.h"
#include "lib/logger/logger.h"

using namespace std;

int main(int argc, char *argv[]) {
    Log &log = Log::get().set_level(Log::DEBUG);
    Lexer *lexer = new Lexer;

    Lexer::VecToken token_vec =
        lexer->tokenize("\"\"ow! \"  hi, mark!  \"n function \"caca\" else");

    for (Lexer::Token token : token_vec) {
        log.debug("token type:", token.type);
        if (token.value != NULL) {
            log.debug("token value:", token.value);
        }
    }

    return 0;
}
