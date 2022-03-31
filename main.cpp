#include "header.h"

int main(){
    int res;
//    // модули для задачи на одномерный массив
//    res = dim1_static_f1();
//    if (res != 0) return res;
//
//    res = dim1_dynamic_f2();
//    if (res != 0) return res;
//
//    res = dim1_vector_f3();
//    if (res != 0) return res;
//
//
//    // модули для задачи на двумерный массив
//    res = dim2_static_f1();
//    if (res != 0) return res;
//
//    res = dim2_dynamic_f2();
//    if (res != 0) return res;
//
//    res = dim2_vector_f3();
//    if (res != 0) return res;
//
//    // модули для задачи строки
    res = c_strings_f1();
    if (res != 0) return res;

    res = cpp_strings_f2();
    if (res != 0) return res;

    return 0;
}