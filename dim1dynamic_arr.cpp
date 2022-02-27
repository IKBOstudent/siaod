#include "header.h"

int* array_input_dynamic(int n);
void array_output_dynamic(const int *a, int n);
int* array_push_front_dynamic(int *a, int &n, int elem0);
Seq_index array_find_seq_dynamic(const int *a, int n);
int* array_delete_seq_dynamic(int *a, int &n, int start_index, int end_index);

// ввод массива
int* array_input_dynamic(int n) {
    /* на вход: массив a и число элементов n
     * ввод массива
     */
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    return a;
}

// вывод массива
void array_output_dynamic(const int *a, int n){
    /* на вход: массив a и число элементов n
     * выводит массив
     */
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;
    cout << endl;
}

// вставка в начало
int* array_push_front_dynamic(int *a, int &n, int elem0) {
    /* на вход: массив a, число элементов n, число для вставки
     * вставляет число в начало
     */
    int *temp = new int[n+1];
    for (int i = n; i >= 0; --i) {
        temp[i] = a[i-1];
    }
    temp[0] = elem0;
    ++n;
    delete[] a;
    a = temp;
    return a;
}

Seq_index array_find_seq_dynamic(const int *a, int n) {
    /* на вход: массив a, число элементов n
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

    return Seq_index{start_index, end_index};
}

int* array_delete_seq_dynamic(int *a, int &n, int start_index, int end_index) {
    /* на вход: массив a, число элементов n, индексы подпоследовательности
     * удаляет подпоследовательность из массива
     */
    int *temp = new int[start_index + (n-1 - end_index)];

    for (int i = 0; i < n; ++i) {
        if (i < start_index)
            temp[i] = a[i];
        else if (i > end_index)
            temp[start_index + i-1 - end_index] = a[i];
    }
    n = start_index + (n-1 - end_index);
    delete[] a;
    a = temp;
    return a;
}

void mass_f2() {
    int n;
    cout << "Array size:\n";
    cin >> n;

    int *a = array_input_dynamic(n);
    // вывод массива
    array_output_dynamic(a, n);

    int elem0;
    cout << "Insert element:\n";
    cin >> elem0;

    // вставка в начало
    a = array_push_front_dynamic(a, n, elem0);
    // вывод массива
    array_output_dynamic(a, n);

    // поиск подпоследовательности
    auto res = array_find_seq_dynamic(a, n);
    cout << "Start: " << res.start_i << " Finish: " << res.end_i << endl;

    // удаление подпоследовательности
    a = array_delete_seq_dynamic(a, n, res.start_i, res.end_i);
    // вывод массива
    array_output_dynamic(a, n);
}

