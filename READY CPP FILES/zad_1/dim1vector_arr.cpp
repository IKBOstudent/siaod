#include "../../header.h"
#include <vector>
using std::vector;

int n_input_vector();
vector<int> array_input_vector(int n);
void array_output_vector(vector<int>& a);
Seq_index array_find_seq_vector(vector<int>& a);
void array_push_front_seq_vector(vector<int>& a, int elem0, int &start_index, int &end_index);
void array_delete_seq_vector(vector<int>& a, int start_index, int end_index);

int n_input_vector() {
    int n;
    cout << "Array size:\n";
    cin >> n;
    while (n <= 0) {
        cout << "Array size must be > 0\n";
        cin >> n;
    }
    return n;
}

vector<int> array_input_vector(int n) {
    /* на вход: массив a и число элементов n
     * ввод массива
     */
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    return a;
}

void array_output_vector(vector<int>& a){
    /* на вход: массив a и число элементов n
     * выводит массив
     */
    cout << "n = " << a.size() << endl;
    for (int i : a)
        cout << i << endl;
    cout << endl;
}

Seq_index array_find_seq_vector(vector<int>& a) {
    /* на вход: массив a, число элементов n
     * Находит индексы (начальный и конечный) самой длинной,
     * упорядоченной по возрастанию подпоследовательности.
     */
    int n = a.size();

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

void array_push_front_seq_vector(vector<int>& a, int elem0, int &start_index, int &end_index) {
    /* на вход: массив a, число элементов n, число для вставки, индексы подпоследовательности
     * вставляет число перед началом подпоследовательности
     */
    a.insert(a.begin() + start_index, elem0);
    ++start_index; ++end_index;
}

void array_delete_seq_vector(vector<int>& a, int start_index, int end_index) {
    /* на вход: массив a, число элементов n, индексы подпоследовательности
     * удаляет подпоследовательность из массива
     */
    int n = a.size();

    if (end_index == n-1)
        a.resize(start_index);
    else {
        for (int i = 0; i < n - end_index - 1; ++i) {
            a[start_index + i] = a[end_index + i + 1];
        } a.resize(start_index + (n - end_index - 1));
    }
}

int dim1_vector_f3() {
    int n = n_input_vector();

    vector<int> a = array_input_vector(n);
    // вывод массива
    array_output_vector(a);

    // поиск подпоследовательности
    auto res = array_find_seq_vector(a);
    cout << "Start: " << res.start_i << " Finish: " << res.end_i << endl;

    int elem0;
    cout << "\nInsert element:\n";
    cin >> elem0;

    array_push_front_seq_vector(a, elem0, res.start_i, res.end_i);
    // вывод массива
    array_output_vector(a);

    // удаление подпоследовательности
    array_delete_seq_vector(a, res.start_i, res.end_i);
    // вывод массива
    array_output_vector(a);
    return 0;
}

