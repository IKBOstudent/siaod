#ifndef SIAOD_HEADER_H
#define SIAOD_HEADER_H

#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

struct Seq_index {
    int start_i, end_i;
};

struct Coord {
    double x, y;
};

// для задания 1
int dim1_static_f1();
int dim1_dynamic_f2();
int dim1_vector_f3();

// для задания 2
int dim2_static_f1();
int dim2_dynamic_f2();
int dim2_vector_f3();

// для задания 3
int c_strings_f1();
int cpp_strings_f2();

#endif //SIAOD_HEADER_H
