#ifndef SIAOD_TABLEDYNAMIC2_H
#define SIAOD_TABLEDYNAMIC2_H


#include <string>
#include <iostream>

using namespace std;

static string WEEKDAYS[7] {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

static string DISCIPLINES[7] {"MathLogic", "MathAnalysis", "Siaod", "PE", "Physics", "English", "OOP"};


struct Lesson {
    int group;
    int discipline_code;
    int weekday;
    int class_time;
    int audience;
};

struct TableDynamic2 {
    int capacity = 100;
    int size = 0;
    Lesson *table;

    TableDynamic2();
    ~TableDynamic2();

    bool AddLesson(Lesson new_lesson);
    bool DeleteSubject(int code);
};

TableDynamic2::TableDynamic2() {
    table = new Lesson[capacity];
}

TableDynamic2::~TableDynamic2() {
    delete[] table;
}

bool TableDynamic2::AddLesson(Lesson new_lesson) {
    if (size == capacity) {
        auto *tmp = new Lesson[capacity+100];
        capacity += 100;
        for (int i = 0; i < size; ++i) {
            tmp[i] = table[i];
        }
        delete[] table;
        table = tmp;
    }

    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            if (new_lesson.weekday == table[i].weekday) {
                if (table[i].class_time >= new_lesson.class_time) {
                    if (table[i].class_time == new_lesson.class_time and table[i].audience == new_lesson.audience)
                        return false;

                    for (int j = size - 1; j >= i; --j) {
                        table[j + 1] = table[j];
                    }

                    table[i] = new_lesson;
                    ++size;
                    return true;
                }
            } else if (new_lesson.weekday < table[i].weekday) {
                for (int j = size - 1; j >= i; --j) {
                    table[j + 1] = table[j];
                }

                table[i] = new_lesson;
                ++size;
                return true;
            }
        }
        table[size] = new_lesson;
        ++size;

    } else {
        table[0] = new_lesson;
        ++size;
    }

    return false;
}

bool TableDynamic2::DeleteSubject(int code) {
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            if (table[i].discipline_code == code) {
                for (int j = i; j < size; ++j) {
                    table[j] = table[j+1];
                }
                --i;
                --size;
            }
        }
        return true;
    }
    return false;
}

ostream& operator<<(ostream &os, const TableDynamic2& t) {
    string res;
    if (t.size > 0) {
        int prev_wd = -1;
        res += "GROUP " + to_string(t.table[0].group) + "\n";
        for (int i = 0; i < t.size; ++i) {
            if (t.table[i].weekday != prev_wd) {
                res += "\n" + WEEKDAYS[t.table[i].weekday] + ":\n";
                prev_wd = t.table[i].weekday;
            }
            res += to_string(t.table[i].class_time) + ". audience: " + to_string(t.table[i].audience) + " - " +
                   DISCIPLINES[t.table[i].discipline_code] + "\n";
        }
    } else {
        res = "NO TIMETABLE\n";
    }

    return os << res;
}


#endif //SIAOD_TABLEDYNAMIC2_H
