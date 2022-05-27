#include "../../header.h"
#include <cctype>

struct TStack {
	struct TNode {
		char Val;
		TNode *Next;

		TNode(char val) : Val(val), Next(nullptr) {}
	};
	TNode* Top = nullptr;

	~TStack() {
		while (!Empty())
			Pop();
	}

	bool Empty() const {
		return Top == nullptr;
	}

	void Push(char val) {
		auto *new_head = new TNode(val);
		if (Empty()) {
			Top = new_head;
			return;
		}
		new_head->Next = Top;
		Top = new_head;
	}

	char Pop() {
		char x = '\0';
		if (!Empty()) {
			TNode *head_next = Top->Next;
			x = Top->Val;
			delete Top;
			Top = head_next;
		}
		return x;
	}
};

int priority(char s){
	if (s == '+' or s == '-')
		return(0);
	else if (s == '*' or s == '/' or s == '%')
		return(1);

	return(2);
}

string get_prefix(string& ex) {
	TStack symbols;
	string result;
	string infix_rev;
	for (int i = ex.size()-1; i >= 0; --i){
		char a = ex[i];
		if (a == '(')
			a = ')';
		else if (a == ')')
			a = '(';
		infix_rev += a;
	}
//	cout << "reversed: " << infix_rev << endl;

	for (int i = 0; i < infix_rev.size(); ++i){
		if (isalnum(infix_rev[i]))
			result += infix_rev[i];

		else if (infix_rev[i] == '(')
			symbols.Push(infix_rev[i]);

		else if (infix_rev[i] == ')') {
			while(!symbols.Empty()) {
				char x = symbols.Pop();
				if (x == '(')
					break;
				result += x;
			}
		}
		else {
			while (!symbols.Empty() and symbols.Top->Val != '(' and priority(infix_rev[i]) <= priority(symbols.Top->Val)){
				result += symbols.Pop();
			}

			symbols.Push(infix_rev[i]);
		}

	}

	while (!symbols.Empty())
		result += symbols.Pop();

	string result_reversed;
	for (int i = result.size()-1; i >= 0; --i)
		result_reversed += result[i];

	return result_reversed;
}

int calc_f1(){
	string infix;
//	getline(cin, infix);
	infix = "f*g/e-(a*b*d+c)+h*k";
	cout << "Infix form:\n";
	cout << infix << endl;
	cout << "Prefix form:\n";
	cout << get_prefix(infix) << endl;
	return 0;


}