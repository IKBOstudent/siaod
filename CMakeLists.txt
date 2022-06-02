cmake_minimum_required(VERSION 3.20)
project(siaod)

set(CMAKE_CXX_STANDARD 17)

add_executable(siaod main.cpp header.h
        "READY CPP FILES/zad_1/dim1static_arr.cpp" "READY CPP FILES/zad_1/dim1dynamic_arr.cpp" "READY CPP FILES/zad_1/dim1vector_arr.cpp"
        "READY CPP FILES/zad_2/dim2static_arr.cpp" "READY CPP FILES/zad_2/dim2dynamic_arr.cpp" "READY CPP FILES/zad_2/dim2vector_arr.cpp" "READY CPP FILES/zad_3/c_strings.cpp" "READY CPP FILES/zad_3/cpp_strings.cpp" "READY CPP FILES/zad_4/TableStatic1.cpp" "READY CPP FILES/zad_4/TableStatic1.h" "READY CPP FILES/zad_4/TableDynamic2.cpp" "READY CPP FILES/zad_4/TableDynamic2.h" "READY CPP FILES/zad_4/TableVector3.cpp" "READY CPP FILES/zad_4/TableVector3.h" "READY CPP FILES/zad_5/linked_list.cpp" "READY CPP FILES/zad_6/recursion_list.cpp" "READY CPP FILES/zad_6/recursion_combs.cpp" "READY CPP FILES/zad_7/calc.cpp" "READY CPP FILES/zad_8/insert_sort.cpp" "READY CPP FILES/zad_8/shaker_sort.cpp" "READY CPP FILES/zad_8/stooge_sort.cpp" "READY CPP FILES/zad_9/search1.cpp" "READY CPP FILES/zad_10/str_search.cpp" "READY CPP FILES/zad_10/str_match.cpp")
