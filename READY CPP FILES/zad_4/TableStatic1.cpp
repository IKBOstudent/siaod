#include "TableStatic1.h"

Lesson make_lesson_f1(const int Group) {
    int group, d_code, wd, time, aud;
    cout << "\nEnter your group:\n";
    while (true) {
        cin >> group;
        if (group == Group)
            break;
        cout << "Type group " << Group << endl;
    }


    cout << "Enter discipline code:\n";
    for (int i = 0; i < 7; ++i) {
        cout << i << " - " << DISCIPLINES[i] << endl;
    }
    while (true) {
        cin >> d_code;
        if (d_code >= 0 and d_code < 7)
            break;
        cout << "INVALID! discipline code is [0, 6]\n";
    }

    cout << "Enter weekday:\n";
    for (int i = 0; i < 7; ++i) {
        cout << i << " - " << WEEKDAYS[i] << endl;
    }
    while (true) {
        cin >> wd;
        if (wd >= 0 and wd < 7)
            break;
        cout << "INVALID! weekday is [0, 6]\n";
    }

    cout << "Enter lesson number:\n";
    while (true) {
        cin >> time;
        if (time > 0)
            break;
        cout << "INVALID! lesson number is > 0\n";
    }

    cout << "Enter audience:\n";
    while (true) {
        cin >> aud;
        if (aud > 0)
            break;
        cout << "INVALID! audience is > 0\n";
    }
    return {group, d_code, wd, time, aud};
}

int table_static_f1() {
    TableStatic1 obj;
    const int Group = 123;

    obj.AddLesson({Group, 3, 1, 2, 22});
    obj.AddLesson({Group, 1, 1, 1, 225});
    obj.AddLesson({Group, 3, 2, 1, 2});
    obj.AddLesson({Group, 4, 3, 1, 11});
    obj.AddLesson({Group, 5, 5, 1, 2});
    obj.AddLesson({Group, 0, 1, 4, 27});


    cout << obj;

    obj.DeleteSubject(3);
    cout << obj;

    obj.AddLesson(make_lesson_f1(Group));
    cout << obj;

    return 0;
}
