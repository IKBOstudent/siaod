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

    void PrintCustom(TNode * p, TList* ans = nullptr) const {
        if (!ans) ans = new TList();

        if (p) {
            if (p->Val < 0) {
                cout << p->Val << " ";
            }
            else {
                ans->EmplaceBack(p->Val);
            }
            PrintCustom(p->Next, ans);
        }
        else {
            ans->Print();
        }
    }
};

int recursion_list_f2() {
    TList list;

    for (short i = 0; i < 7; ++i) {
        short v = i;
        if (i % 2) v -= 14;
        list.Push(v);
    }

	cout << "list:\n";
    list.Print();

	cout << "list with negative elements first\n";
    list.PrintCustom(list.Head);

    return 0;
}