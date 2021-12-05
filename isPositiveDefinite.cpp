#include <bits/stdc++.h>

using namespace std;

double matrix[100][100];
double determinant = 0;
double ModifiedDeterminant(int n, double matrix[100][100])
{
	int c, subi, i, j, subj;
	double submat[100][100];
	if (n == 1) {
		return matrix[0][0];
	}
	else if (n == 2) {
		return ( (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	}
	else {
		for (c = 0; c < n; c++) {
			subi = 0;
			for (i = 1; i < n; i++) {
				subj = 0;
				for (j = 0; j < n; j++) {
					if (j == c) {
						continue;
					}
					submat[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			determinant = determinant + (pow(-1 , c) * matrix[0][c] * ModifiedDeterminant(n - 1 , submat));
		}
	}
	return determinant;
}

bool isPositiveDefinite(int n) {
	for (int i = 1; i <= n; i++) {
		if (ModifiedDeterminant(i, matrix) < 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}
	if (isPositiveDefinite(n)) {
		cout << "Given Matrix is Positive Definite" << endl;
	} else {
		cout << "Give Matrix is NOT Positive Definite" << endl;
	}

}