#include "../../header.h"
#include "string.h"
#include "stdlib.h"


void cfind_min_dist(const char *);
// находит минимальное расстояние между парой слов

void coutput_pairs(int, const char *);
// выводит пары слов с минимальным расстоянием между ними


void cfind_min_dist(const char * a) {
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

    coutput_pairs(min_dist, a);
}

void coutput_pairs(int min_dist, const char * a) {
    char prev_word[100];
    int prev_n = 0;
    bool prev_finished = false;
    bool type_next = false;

    int n = 0;
    int current_dist = 0;

    int i = 0;
    while (a[i] != '\0') {
        if (a[i] == ',' or a[i] == ' ') {
            if (!prev_finished) {
                prev_finished = true;
                prev_n = n;
                n = 0;
            }
            ++current_dist;
            if (type_next) {
                type_next = false;
                cout << endl;
            }
        } else {
            if (current_dist > 0 and current_dist == min_dist) {
                type_next = true;
                for (int k = 0; k < prev_n; ++k) {
                    cout << prev_word[k];
                }
                n = 0;
                cout << " ";
            }
            prev_finished = false;
            prev_word[n] = a[i];
            ++n;

            if (type_next) {
                cout << a[i];
            }

            current_dist = 0;
        }

        ++i;
    }
}

int c_strings_f1() {
//    const char * a = "aa, cc dd,, asdf,    , ff, ff aa ff aa ff";
    char a[1024];

	gets(a);
	cout << "min dist:\n";
	cfind_min_dist(a);
    cout << endl;
    cout << endl;

    return 0;
}