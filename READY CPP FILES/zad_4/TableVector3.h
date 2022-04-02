#ifndef SIAOD_TABLEVECTOR3_H
#define SIAOD_TABLEVECTOR3_H

#include <string>
#include <iostream>
#include <vector>

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

struct TableVector3 {
    vector<Lesson> table;

    bool AddLesson(Lesson new_lesson);
    bool DeleteSubject(int code);
};

bool TableVector3::AddLesson(Lesson new_lesson) {
    int size = table.size();

    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            if (new_lesson.weekday == table[i].weekday) {
                if (table[i].class_time >= new_lesson.class_time) {
                    if (table[i].class_time == new_lesson.class_time and table[i].audience == new_lesson.audience)
                        return false;

                    table.push_back({});

                    for (int j = size - 1; j >= i; --j) {
                        table[j + 1] = table[j];
                    }

                    table[i] = new_lesson;
                    return true;
                }
            } else if (new_lesson.weekday < table[i].weekday) {
                table.push_back({});

                for (int j = size - 1; j >= i; --j) {
                    table[j + 1] = table[j];
                }

                table[i] = new_lesson;
                return true;
            }
        }
        table.push_back(new_lesson);

    } else {
        table.push_back(new_lesson);
    }

    return false;
}

bool TableVector3::DeleteSubject(int code) {
    if (!table.empty()) {
        for (int i = 0; i < table.size(); ++i) {
            if (table[i].discipline_code == code) {
                table.erase(table.begin() + i);
            }
        }
        return true;
    }
    return false;
}

ostream& operator<<(ostream &os, const TableVector3& t) {

    string res;
    if (!t.table.empty()) {
        int prev_wd = -1;
        res += "GROUP " + to_string(t.table[0].group) + "\n";
        for (int i = 0; i < t.table.size(); ++i) {
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
#endif //SIAOD_TABLEVECTOR3_H
