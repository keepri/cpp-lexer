#include <algorithm>
#include <iostream>

#include "lib/dates/dates.h"
#include "lib/lexer/lexer.h"
#include "lib/logger/logger.h"

using namespace std;

int main(int argc, char *argv[]) {
    Log &log = Log::get().set_level(Log::SILLY);
    Lexer *lexer = new Lexer;

    Lexer::TokenVec token_vec;
    lexer->tokenize("\"\"ow! caca \"  hi, mark!  \"n function \"caca\" else", token_vec);

    for (Lexer::Token token : token_vec) {
        log.info("token type:", token.type, "value:", token.value != NULL ? token.value : "NULL");
    }

    return 0;
}
