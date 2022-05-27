#include "../../header.h"

int n_input_static();
void array_input_static(int *a, int n);
void array_output_static(const int *a, int n);
Seq_index array_find_seq_static(const int *a, int n);
void array_push_front_seq_static(int *a, int &n, int elem0, int &start_index, int &end_index);
void array_delete_seq_static(int *a, int &n, int start_index, int end_index);

int n_input_static() {
    int n;
    cout << "Array size (<= 1000):\n";
    cin >> n;
    while (n > 1000 or n <= 0) {
        cout << "Array size must be > 0 and <= 1000\n";
        cin >> n;
    }
    return n;
}

void array_input_static(int *a, int n) {
    /* на вход: массив a и число элементов n
     * ввод массива
     */
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void array_output_static(const int *a, int n){
    /* на вход: массив a и число элементов n
     * выводит массив
     */
    cout << "n = " << n << endl;
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

Seq_index array_find_seq_static(const int *a, int n) {
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

void array_push_front_seq_static(int *a, int &n, int elem0, int &start_index, int &end_index) {
    /* на вход: массив a, число элементов n, число для вставки, индексы подпоследовательности
     * вставляет число перед началом подпоследовательности
     */
    if (n == 1000) {
        cout << "Array size to big to push element\n";
    } else {
        for (int i = n; i > start_index; --i) {
            a[i] = a[i - 1];
        }
        a[start_index] = elem0;
        ++n;
        ++start_index; ++end_index;
    }
}

void array_delete_seq_static(int *a, int &n, int start_index, int end_index) {
    /* на вход: массив a, число элементов n, индексы подпоследовательности
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

int dim1_static_f1() {
    int a[1000];

    // считывем массив размера n <= 1000
    int n = n_input_static();

    array_input_static(a, n);
    // вывод массива
    array_output_static(a, n);

    // поиск подпоследовательности
    auto res = array_find_seq_static(a, n);
    cout << "Start: " << res.start_i << " Finish: " << res.end_i << endl;

    int elem0;
    cout << "\nInsert element:\n";
    cin >> elem0;

    array_push_front_seq_static(a, n, elem0, res.start_i, res.end_i);
    // вывод массива
    array_output_static(a, n);

    // удаление подпоследовательности
    array_delete_seq_static(a, n, res.start_i, res.end_i);
    // вывод массива
    array_output_static(a, n);
    return 0;
}

