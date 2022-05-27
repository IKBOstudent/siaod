#include "../../header.h"

struct Patient{
	int card_id;
	string name;
};

int bf_search_f1(vector<Patient> a, int card_id) {
	int index = -1;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i].card_id == card_id) {
			index = i;
			break;
		}
	}
	return index;
}

int barrier_search_f1(vector<Patient> a, int card_id) {
	int len = a.size();
	if (len > 0) {
		int last = a[len-1].card_id;
		a[len-1].card_id = card_id;

		int i;
		for (i = 0; a[i].card_id != card_id; ++i) {}

		a[len-1].card_id = last;

		if (i != len-1 or card_id == last){
			return i;
		}
	}
	return -1;
}

struct THashTable{
	struct Node{
		Patient val;
		bool state = true;
	};

	Node** arr;
	int cap = 1000000;
	int size = 0;

	THashTable() {
		size = 0;
		arr = new Node*[cap];
		for (int i = 0; i < cap; ++i)
			arr[i] = nullptr; // заполняем nullptr - то есть если значение отсутствует, и никто раньше по этому адресу не обращался
	}
	~THashTable() {
		for (int i = 0; i < cap; ++i)
			if (arr[i])
				delete arr[i];
		delete[] arr;
	}

	int HashFunc(int key) {
		return key % cap;
	}

	string Find(int find_key) {
		int h1 = HashFunc(find_key);
		int i = 0;
		while (arr[h1] != nullptr && i < cap)
		{
			if (arr[h1]->val.card_id == find_key && arr[h1]->state)
				return arr[h1]->val.name;
			h1 = h1 % cap;
			++i;
		}
		return "";
	}

	bool Add(int new_key, string new_name)
	{
		int h1 = HashFunc(new_key);
		int i = 0;
		int first_deleted = -1;
		while (arr[h1] != nullptr && i < cap)
		{
			if (arr[h1]->val.card_id == new_key && arr[h1]->state)
				return false;
			if (!arr[h1]->state && first_deleted == -1)
				first_deleted = h1;

			h1 = h1 % cap;
			++i;
		}

		if (first_deleted == -1) // если не нашлось подходящего места, создаем новый Node
		{
			arr[h1] = new Node;
			arr[h1]->val.card_id = new_key;
			arr[h1]->val.name = new_name;
		}
		else
		{
			arr[first_deleted]->val.card_id = new_key;
			arr[first_deleted]->val.name = new_name;
			arr[first_deleted]->state = true;
		}
		++size;
		return true;
	}

};

int search1_f1() {
	int n = 100;
	vector<Patient> a;
	for (int i = 0; i < n; ++i) {
		a.push_back({100 + i, "a" + std::to_string(i)});
	}
	int find_key = 167;
	auto t1 = chrono::steady_clock::now();
	cout << a[bf_search_f1(a, find_key)].name;
	auto t2 = chrono::steady_clock::now();

	cout << "    time: ";
	cout << (double) chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl;
	cout << endl;


	t1 = chrono::steady_clock::now();
	cout << a[barrier_search_f1(a, find_key)].name;
	t2 = chrono::steady_clock::now();

	cout << "    time: ";
	cout << (double) chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl;
	cout << endl;


	THashTable table;
	for (int i = 0; i < n; ++i){
		table.Add(a[i].card_id, a[i].name);
	}

	t1 = chrono::steady_clock::now();
	cout << table.Find(find_key);
	t2 = chrono::steady_clock::now();

	cout << "    time: ";
	cout << (double) chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl;
	cout << endl;



	return(0);
}