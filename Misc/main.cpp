#include <iostream>
#include <vector>

using namespace std;

void quadratic(vector<char> &V, char C, int length) {
	for (int i = 1; i < length; i++) {
		char tmp = V[i];
		int j = i;

		if (V[i] == C)
			continue;

		while (j > 0 && V[j-1] == C ) {
			V[j] = V[j-1];
			j--;
		}
		V[j] = tmp;
	}
}

void linear(vector<char> &V, char C, int length) {
	int count(0);
	for (int i = 1; i < length; i++) {
		if (V[i-1] == C && V[i] != C) {
			V[i-1-count] = V[i];
			V[i] = C;
		} else if (V[i-1] == C) {
			count++;
		}
	}
}

int main() {
	int length(6);
	vector<char> V(length);
	char C('.');

	V[0] = '.';
	V[1] = '.';
	V[2] = 'c';
	V[3] = 'd';
	V[4] = 'e';
	V[5] = 'f';

	linear (V, C, length);

	for (int i = 0; i < length; i++) {
		cout << " " << V[i];
	}

	quadratic (V, C, length);

	for (int i = 0; i < length; i++) {
		cout << " " << V[i];
	}


	return 0;
}
