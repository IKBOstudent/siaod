#include "../../header.h"

#define d 256

int search(string pattern, string txt, int q) {
	int count = 0;
	int M = pattern.size();
	int N = txt.size();
	int i, j;
	int p_hash = 0; // hash value for pattern
	int t_hash = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	for (i = 0; i < M; i++) {
		p_hash = (d * p_hash + pattern[i]) % q;
		t_hash = (d * t_hash + txt[i]) % q;
	}

	for (i = 0; i <= N - M; i++) {
		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p_hash == t_hash) {
			// Check for characters one by one
			for (j = 0; j < M; j++) {
				if (txt[i+j] != pattern[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

			if (j == M) {
				count++;
			}
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if ( i < N-M )
		{
			t_hash = (d*(t_hash - txt[i]*h) + txt[i+M])%q;
			if (t_hash < 0)
				t_hash = (t_hash + q);
		}
	}
	return count;
}


int str_search_f1() {
	string txt = "AB CA BCA ABC ABBC ABBABAB";
	cout << "Text is:\n";
	cout << txt << endl;

	vector<string> patterns {"AB", "CA", "BCA", "ABC"};
	vector<int> count(4);

	cout << "Patterns to find: ";
	for (auto i : patterns){
		cout << i << " ";
	}
	cout << endl;


	// A prime number
	int q = 101;
	cout << "Search result:\n";
	for (int i = 0; i < 4; ++i) {
		int c = search(patterns[i], txt, q);

		if (c > 0)
			count[i] += c;
	}

	for (int i = 0; i < 4; ++i) {
		cout << patterns[i] << ": ";
		cout << count[i] << endl;
	}

	return 0;
}