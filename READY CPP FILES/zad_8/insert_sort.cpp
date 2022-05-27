#include "../../header.h"


void sort_f1(int* a, int n){
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0 and a[j] < a[j-1]; --j) {
			int tmp = a[j];
			a[j] = a[j-1];
			a[j-1] = tmp;
		}
	}
}

void output_f1(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int insert_sort_f1(){

	int n = 100;
	int a[n];

	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 10;
	}
//	output_f1(a, n);
	auto t1 = chrono::steady_clock::now();
	sort_f1(a, n);
	auto t2 = chrono::steady_clock::now();
//	output_f1(a, n);

	cout << "time: ";
	cout << (double) chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl;
	cout << endl;
	return(0);
}
