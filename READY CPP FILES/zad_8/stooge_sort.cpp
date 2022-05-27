#include "../../header.h"
void sort_f3(int* a, int left, int right){
	if (a[right] < a[left]) {
		int tmp = a[right];
		a[right] = a[left];
		a[left] = tmp;
	}
	if (right - left + 1 < 3)
		return;

	int k = (int) (right - left + 1) / 3;

	sort_f3(a, left, right-k);
	sort_f3(a, left + k, right);
	sort_f3(a, left, right - k);
}

void output_f3(int *a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int stooge_sort_f3(){

	int n = 100;
	int a[n];

	for (int i = 0; i < n; ++i) {
		a[i] = rand() % 100;
	}
//	output_f3(a, n);
	auto t1 = chrono::steady_clock::now();
	sort_f3(a, 0, n-1);
	auto t2 = chrono::steady_clock::now();
//	output_f3(a, n);

	cout << "time: ";
	cout << (double) chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000000 << " seconds" << endl;
	cout << endl;
	return(0);
}
