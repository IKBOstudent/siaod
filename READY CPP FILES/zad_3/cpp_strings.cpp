#include "../../header.h"

void cppfind_min_dist(string&);
// находит минимальное расстояние между парой слов

void cppoutput_pairs(int, string&);
// выводит пары слов с минимальным расстоянием между ними


void cppfind_min_dist(string& a) {
    int min_dist = 100000;
    int current_dist = 0;

    int i = 0;
    while (a[i] != '\0') {
        if (a[i] == ',' or a[i] == ' ') {
            ++current_dist;
        } else {
            if (current_dist > 0 and current_dist < min_dist)
                min_dist = current_dist;

            current_dist = 0;
        }

        ++i;
    }

    cppoutput_pairs(min_dist, a);
}

void cppoutput_pairs(int min_dist, string& a) {
    string prev_word;
    bool type_next = false;

    int current_dist = 0;

    int i = 0;
    while (a[i] != '\0') {
        if (a[i] == ',' or a[i] == ' ') {
            ++current_dist;
            if (type_next) {
                type_next = false;
                cout << endl;
            }
        } else {
            if (current_dist > 0) {
                if (current_dist == min_dist) {
                    type_next = true;
                    cout << prev_word;
                    cout << " ";
                }

                prev_word = "";
            }
            prev_word += a[i];

            if (type_next) {
                cout << a[i];
            }

            current_dist = 0;
        }

        ++i;
    }
}

int cpp_strings_f2() {
//    string a = "aa, cc dd,, asdf,    , ff, ff aa ff aa ff";
	string a;
	getline(cin, a);
	cout << "min dist:\n";
	cppfind_min_dist(a);
    cout << endl;

    return 0;
}