#include "../../header.h"

void sort_f2(int* a, int n){
	bool sorted = false;
	int right = n-1;
	int left = 1;
	while (!sorted) {
		sorted = true;
		for (int i = left; i <= right; ++i) {
			if (a[i] < a[i-1]) {
				int tmp = a[i];
				a[i] = a[i-1];
				a[i-1] = tmp;
				sorted = false;
			}
		}
		for (int i = right; i >= left; --i) {
			if (a[i] < a[i-1]) {
				int tmp = a[i];
				a[i] = a[i-1];
				a[i-1] = tmp;
				sorted = false;
			}
		}
	}

}

void output_f2(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int shaker_sort_f2(){

	int n = 100;
	int a[n];

	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 10;
	}
//	output_f2(a, n);
	auto t1 = chrono::steady_clock::now();
	sort_f2(a, n);
	auto t2 = chrono::steady_clock::now();
//	output_f2(a, n);

	cout << "time: ";
	cout << (double) chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl;
	cout << endl;
	return(0);
}
