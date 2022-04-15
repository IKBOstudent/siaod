#include "../../header.h"

struct TNode {
    short Val;
    TNode *Next;

    TNode(short val) : Val(val), Next(nullptr) {}
};


struct TList {
    TNode *Head;

    TList() : Head(nullptr) {}

    ~TList() {
        while (!Empty())
            Pop();
    }

    bool Empty() const {
        return Head == nullptr;
    }

    void Push(short val) {
        TNode *new_head = new TNode(val);
        if (Empty()) {
            Head = new_head;
            return;
        }
        new_head->Next = Head;
        Head = new_head;
    }

    void Pop() {
        if (!Empty()) {
            TNode *head_next = Head->Next;
            delete Head;
            Head = head_next;
        }
    }

    void EmplaceBack(short val) {
        TNode *new_tail = new TNode(val);
        if (Empty()) {
            Head = new_tail;
            return;
        }

        TNode *p = Head;
        while (p->Next) p = p->Next;
        // now p = tail
        p->Next = new_tail;
    }

    void Print() const {
        if (Empty())
            return;

        TNode *p = Head;
        while (p) {
            cout << p->Val << " ";
            p = p->Next;
        }
        cout << endl;
    }

    bool Inside(short val) const {
        TNode *p = Head;
        while (p) {
            if (p->Val == val)
                return true;

            p = p->Next;
        }
        return false;
    }

    void Insert(short find_val, short insert_val) {
        // adding pseudo-head
        Push(0);
        TNode *new_elem = new TNode(insert_val);

        TNode *prev = Head;
        TNode *p = Head->Next;
        while (p) {
            if (p->Val == find_val) {
                prev->Next = new_elem;
                new_elem->Next = p;
                break;
            }

            prev = p;
            p = p->Next;
        }

        if (!p) {
            prev->Next = new_elem;
        }

        // deleting pseudo-head
        Pop();
    }

};


TList* find_sequence(TList& list, short x, short y) {
    if (list.Inside(x) and list.Inside(y)) {
        TList *result = new TList();

        // adding pseudo-head
        list.Push(0);

        TNode *prev = list.Head;
        TNode *p = list.Head->Next;

        bool started = false;
        while (p) {
            short current = p->Val;
            if (!started and current == x)
                started = true;

            if (started) {
                result->EmplaceBack(current);
                prev->Next = p->Next;
                if (current == y) {
                    delete p;
                    break;
                }
            }

            if (!started) {
                prev = p;
            } else {
                delete p;
            }
            p = prev->Next;
        }

        // deleting pseudo-head
        list.Pop();
        return result;
    }
    return nullptr;
}

void del_all(TList& list, short x) {
    // adding pseudo-head
    list.Push(0);

    TNode *prev = list.Head;
    TNode *p = list.Head->Next;

    while (p) {
        if (p->Val == x) {
            prev->Next = p->Next;
            delete p;
        } else {
            prev = p;
        }
        p = prev->Next;
    }

    // deleting pseudo-head
    list.Pop();
}

int linked_list_f1() {
    TList list;

    for (short i = 0; i < 7; ++i)
        list.Push(i);

    list.Print();

    list.EmplaceBack(3);

    list.Print();

    TList *ans = find_sequence(list, 6, 3);
    if (ans) ans->Print();
    list.Print();

    del_all(list, 3);
    list.Print();

    list.Insert(1, 11);
    list.Print();

    list.Insert(32, 222);
    list.Print();

    return 0;
}
