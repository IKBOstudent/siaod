#include "../../header.h"
#include <vector>
#include <cmath>
using std::vector;

void dim2_array_input_vector_custom(vector<vector<double>>& a, int n);
void dim2_array_input_vector_random(vector<vector<double>>& a, int n);
void dim2_array_output_vector(vector<vector<double>>& a, int n);

bool dim2_one_side_vector(vector<vector<double>>& a, int n);
bool find_intersection(Coord a, Coord b, Coord c, Coord d, Coord& inter);
bool point_inside_segment(Coord a, Coord b, Coord m);



void dim2_array_input_vector_custom(vector<vector<double>>& a, int n) {
    /* на вход: матрица a, число строк n и число столбцов m
     * ручной ввод матрицы
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[i][j];
        }
    }
}

void dim2_array_input_vector_random(vector<vector<double>>& a, int n) {
    /* на вход: матрица a, число строк n и число столбцов m
     * заполнение матрицы случайными числами
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = (-rand() + rand()) % 100;
        }
    }
}

void dim2_array_output_vector(vector<vector<double>>& a, int n){
    /* на вход: матрица a, число строк n и число столбцов m
     * вывод матрицы
     */
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

bool dim2_one_side_vector(vector<vector<double>>& a, int n) {
    /* на вход: матрица a, число строк n
     * изменяет матрицу на обратную методом Гаусса
     */
    bool for_each = true;
    for (int i = 0; i < n; ++i) {
        Coord main_a = {a[i][0], a[i][1]};

        bool found_b = false;
        for (int j = 0; j < n; ++j) {
            if (j == i)
                continue;

            Coord b = {a[j][0], a[j][1]};

            // find 3rd point
            int ff;
            Coord c{};
            for (ff = 0; ff < n; ++ff) {
                if (ff == i or ff == j)
                    continue;

                c = {a[ff][0], a[ff][1]};
                break;
            }

            bool all_on_one_side = true;

            for (int ch = 0; ch < n; ++ch) {
                if (ch == i or ch == j or ch == ff)
                    continue;

                Coord d = {a[ch][0], a[ch][1]};

                Coord inter{};
                bool res_intersect = find_intersection(main_a, b, c, d, inter);

                if (res_intersect) {
                    bool res_inside = point_inside_segment(c, d, inter);
                    if (res_inside) {
                        all_on_one_side = false;
                        break;
                    }
                }
            }
            if (all_on_one_side) {
                found_b = true;
                break;
            }
        }

        if (!found_b) {
            for_each = false;
            break;
        }
    }

    if (for_each)
        return true;
    return false;
}

bool find_intersection(Coord a, Coord b, Coord c, Coord d, Coord& inter) {
    Coord ab = {b.x - a.x, b.y - a.y};
    Coord cd = {d.x - c.x, d.y - c.y};
    Coord ca = {a.x - c.x, a.y - c.y};

    // ab*k + cd*p = ca

    double p;
    if (ab.y != 0) {
        double q = -ab.x / ab.y;
        if (cd.x + cd.y * q == 0)
            return false;

        p = (ca.x + ca.y * q) / (cd.x + cd.y * q);
    } else {
        if (cd.y == 0)
            return false;

        p = ca.y / cd.y;
    }

    inter.x = c.x + cd.x * p;
    inter.y = c.y + cd.y * p;
    return true;
}

bool point_inside_segment(Coord c, Coord d, Coord m) {
    double dist = sqrt(pow(c.x - d.x, 2) + pow(c.y - d.y, 2));
    double dist_a_m = sqrt(pow(m.x - c.x, 2) + pow(m.y - c.y, 2));
    double dist_b_m = sqrt(pow(m.x - d.x, 2) + pow(m.y - d.y, 2));

    if (fabs(dist - (dist_a_m + dist_b_m)) < 0.0001) {
        return true;
    } else {
        return false;
    }
}



int dim2_vector_f3() {
    srand(time(0));
    int n = 15;
    vector<vector<double>> a(n, vector<double>(2, 0));

    string ans;
    cout << "Custom input?\n";
    cin >> ans;
    if (ans == "yes")
        dim2_array_input_vector_custom(a, n);
    else
        dim2_array_input_vector_random(a, n);

    // вывод матрицы
    dim2_array_output_vector(a, n);

    // можно ли для любой точек найти такую,
    // что все остальные 13 точек остануться с одной стороны прямой,
    // проведенной через данные 2 точки
    bool res = dim2_one_side_vector(a, n);
    cout << "answer: " << (res ? "yes, we can" : "no") << endl;

    return 0;
}
