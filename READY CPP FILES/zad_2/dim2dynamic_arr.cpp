#include "../../header.h"

void dim2_array_input_dynamic_custom(double** a, int n, int m);
void dim2_array_input_dynamic_random(double** a, int n, int m);
void dim2_array_output_dynamic(double** a, int n, int m);

int dim2_array_invert_dynamic(double** a, int n);
int pr_hod_gauss_dynamic(double** a, int n);
void obr_hod_gauss_dynamic(double** a, int n);

void dim2_array_input_dynamic_custom(double** a, int n, int m) {
    /* на вход: матрица a, число строк n и число столбцов m
     * ручной ввод матрицы
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
}

void dim2_array_input_dynamic_random(double** a, int n, int m) {
    /* на вход: матрица a, число строк n и число столбцов m
     * заполнение матрицы случайными числами
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = (-rand() + rand()) % 100;
        }
    }
}

void dim2_array_output_dynamic(double** a, int n, int m){
    /* на вход: матрица a, число строк n и число столбцов m
     * вывод матрицы
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int dim2_array_invert_dynamic(double** a, int n) {
    /* на вход: матрица a, число строк n
     * изменяет матрицу на обратную методом Гаусса
     */

    // проверка на отсутсвие нулей на главной диагонали
    for (int i = 0; i < n; ++i) {
        if (a[i][i] == 0)
            return 3;
    }

    // приклеивание единичной матрицы справа к матрице
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2*n; ++j) {
            if (i == j-n)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }

    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int res = pr_hod_gauss_dynamic(a, n);
    if (res != 0)
        return res;
    obr_hod_gauss_dynamic(a, n);

    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2*n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

int pr_hod_gauss_dynamic(double** a, int n) {
    for (int rr = 0; rr < n; ++rr) {
        for (int i = rr; i < n; ++i) {
            double tmp_0 = a[i][rr];
            if (tmp_0 == 0)
                break;

            int counter = 0;
            for (int j = rr; j < 2 * n; ++j) {
                if (i == rr)
                    a[i][j] /= tmp_0;
                else {
                    a[i][j] -= a[rr][j] * tmp_0;
                    if (a[i][j] == 0) ++counter;
                }
            }
            if (counter == n){
                cout << "dim(a) = 0";
                return 4;
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void obr_hod_gauss_dynamic(double** a, int n) {
    for (int rr = n - 1; rr > 0; --rr) {
        for (int i = rr - 1; i >= 0; --i) {
            double tmp_n = a[i][rr];

            for (int j = 0; j < 2 * n; ++j) {
                a[i][j] -= a[rr][j] * tmp_n;
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2*n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


int dim2_dynamic_f2() {
    srand(time(0));
    double** a;

    int n, m;
    cin >> n;
    if (n <= 0) {
        cout << "Invalid n\n";
        return 1;
    }

    cin >> m;
    if (m <= 0) {
        cout << "Invalid m\n";
        return 1;
    }

    a = new double*[n];
    for (int i = 0; i < n; i++)
        a[i] = new double[2*m];

    string ans;
    cout << "Custom input?\n";
    cin >> ans;
    if (ans == "yes")
        dim2_array_input_dynamic_custom(a, n, m);
    else
        dim2_array_input_dynamic_random(a, n, m);

    // вывод матрицы
    dim2_array_output_dynamic(a, n, m);

    // нахождение обратной матрицы методом Гаусса
    if (n == m) {
        int res = dim2_array_invert_dynamic(a, n);
        if (res != 0)
            return 3;
    }
    else
        return 2;

    return 0;
}

