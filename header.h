#ifndef SIAOD_HEADER_H
#define SIAOD_HEADER_H

#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

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

// для задания 4
int table_static_f1();
int table_dynamic_f2();
int table_vector_f3();

// для задания 5
int linked_list_f1();

// для задания 6
int recursion_combs_f1();
int recursion_list_f2();

// для задания 7
int calc_f1();

// для задания 8
int insert_sort_f1();
int shaker_sort_f2();
int stooge_sort_f3();

// для задания 9
int search1_f1();
int search2_f2();

// для задания 10
int str_search_f1();
int str_match_f2();

#endif //SIAOD_HEADER_H
