#include "header.h"

struct Seq {
    int start_i, end_i;
    Seq(int x, int y){
        start_i = x;
        end_i = y;
    }
};

void array_input(int a[], int n);
void array_output(int a[], int n);
void array_push_front(int a[], int &n, int elem0);
Seq array_find_seq(const int a[], int n);
void array_delete_seq(int a[], int &n, int start_index, int end_index);

// ввод массива
void array_input(int a[], int n) {
    /* на вход: массив a[] и число элементов n
     * ввод массива
     */
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

// вывод массива
void array_output(int a[], int n){
    /* на вход: массив a[] и число элементов n
     * выводит массив
     */
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;
    cout << endl;
}

// вставка в начало
void array_push_front(int a[], int &n, int elem0) {
    /* на вход: массив a[], число элементов n, число для вставки
     * вставляет число в начало
     */
    for (int i = n; i >= 0; --i) {
        a[i] = a[i-1];
    }
    a[0] = elem0;
    ++n;
}

Seq array_find_seq(const int a[], int n) {
    /* на вход: массив a[], число элементов n
     * Находит индексы (начальный и конечный) самой длинной,
     * упорядоченной по возрастанию подпоследовательности.
     */
    int current_start_index = 0;
    bool flag_start = false;

    int start_index = 0;
    int end_index = 0;
    int max_length = 0;

    for (int i = 1; i < n; ++i){
        if (a[i] > a[i-1]) {
            if (!flag_start) {
                flag_start = true;
                current_start_index = i-1;
            } else if (i == n-1) {
                if (max_length < i - current_start_index) {
                    start_index = current_start_index;
                    end_index = i;
                }
            }
        } else {
            if (flag_start) {
                if (max_length < i - 1 - current_start_index) {
                    max_length = i - 1 - current_start_index;
                    start_index = current_start_index;
                    end_index = i - 1;
                }
            }
            flag_start = false;
        }
    }

    Seq s(start_index, end_index);
    return s;
}

void array_delete_seq(int a[], int &n, int start_index, int end_index) {
    /* на вход: массив a[], число элементов n, индексы подпоследовательности
     * удаляет подпоследовательность из массива
     */
    if (end_index == n-1) {
        n = start_index;
    } else {
        for (int i = 0; i < n - end_index - 1; ++i) {
            a[start_index + i] = a[end_index + i + 1];
        } n = start_index + (n - end_index - 1);
    }
}

void mass_f1() {
    int a[100];

    // считывем массив размера 10
    int n = 10;
    array_input(a, n);
    // вывод массива
    array_output(a, n);

    int elem0;
    cout << "Insert element:\n";
    cin >> elem0;

    // вставка в начало
    array_push_front(a, n, elem0);
    // вывод массива
    array_output(a, n);

    // поиск подпоследовательности
    auto res = array_find_seq(a, n);
    cout << "Start: " << res.start_i << " Finish: " << res.end_i << endl;

    // удаление подпоследовательности
    array_delete_seq(a, n, res.start_i, res.end_i);
    // вывод массива
    array_output(a, n);
}

