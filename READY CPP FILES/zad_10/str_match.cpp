#include "../../header.h"
#include <regex>
#include <ostream>

using std::regex;


void search_pattern(string text, regex rgx) {
    if (std::regex_match(text, rgx)){
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}


int str_match_f2() {

    // f1 = [+\-]?[\d\w]+(\^\(?([+-]?[\d\w]+)([+\-*/]([+-]?[\d\w]+))*\)?)?
    // f2 = f1([+\-*/]f1)*=f1([+\-*/]f1)*

    regex rgx(R"([+\-]?[\d\w]+(\^\(?([+-]?[\d\w]+)([+\-*/]([+-]?[\d\w]+))*\)?)?([+\-*/][+\-]?[\d\w]+(\^\(?([+-]?[\d\w]+)([+\-*/]([+-]?[\d\w]+))*\)?)?)*=[+\-]?[\d\w]+(\^\(?([+-]?[\d\w]+)([+\-*/]([+-]?[\d\w]+))*\)?)?([+\-*/][+\-]?[\d\w]+(\^\(?([+-]?[\d\w]+)([+\-*/]([+-]?[\d\w]+))*\)?)?)*)");
    search_pattern("yxs+asf+3fff+asfd=y^x", rgx);
    search_pattern("x^3+x^(2-2xy)-2*s*asdf=y-xx-z/32+1", rgx);


    return 0;
}