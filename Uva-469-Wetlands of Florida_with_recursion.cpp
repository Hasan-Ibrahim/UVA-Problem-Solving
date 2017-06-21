#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int testCase;
string line;
bool matrix[101][101];
bool visited[101][101];
string firstNumberString, secondNumberString;

int stackTop = 0;
int area = 0;

void calculate(int x, int y) {

	area++;

	if (matrix[x + 1][y] && !visited[x + 1][y]) {
		visited[x + 1][y] = true;
		calculate(x + 1, y);
	}
	if (matrix[x + 1][y + 1] && !visited[x + 1][y + 1]) {
		visited[x + 1][y + 1] = true;
		calculate(x + 1, y + 1);
	}
	if (matrix[x + 1][y - 1] && !visited[x + 1][y - 1] && y > 0) {
		visited[x + 1][y - 1] = true;
		calculate(x + 1, y - 1);
	}
	if (matrix[x][y + 1] && !visited[x][y + 1]) {
		visited[x][y + 1] = true;
		calculate(x, y + 1);
	}
	if (matrix[x][y - 1] && !visited[x][y - 1] && y > 0) {
		visited[x][y - 1] = true;
		calculate(x, y - 1);
	}
	if (matrix[x - 1][y + 1] && !visited[x - 1][y + 1] && x > 0) {
		visited[x - 1][y + 1] = true;
		calculate(x - 1, y + 1);
	}
	if (matrix[x - 1][y - 1] && !visited[x - 1][y - 1] && y > 0 && x > 0) {
		visited[x - 1][y - 1] = true;
		calculate(x - 1, y - 1);
	}
	if (matrix[x - 1][y] && !visited[x - 1][y] && x > 0) {
		visited[x - 1][y] = true;
		calculate(x - 1, y);
	}
}


int main() {

	cin >> testCase;
	getline(cin, line);
	getline(cin, line);
	while (testCase--) {

		for (int n = 0; n < 101; n++) {
			for (int m = 0; m < 101; m++) {
				matrix[n][m] = false;
			}
		}

		int rowIndex = 0;
		while (true) {
			getline(cin, line);
			if (line == "") {
				break;
			}
			int lineLength = line.length();

			for (int i = 0; i < lineLength; i++) {
				if (line[i] == 'L') {
					matrix[rowIndex][i] = false;
				}
				else if (line[i] == 'W') {
					matrix[rowIndex][i] = true;
				}
				else {
					int j = 0;
					for (; j < lineLength; j++) {
						if (line[j] == ' ')break;
					}
					i = lineLength;
					int firstNumber, secondNumber;
					firstNumberString = line.substr(0, j);
					secondNumberString = line.substr(j + 1, lineLength - (j + 1));
					firstNumber = stoi(firstNumberString) - 1;
					secondNumber = stoi(secondNumberString) - 1;

					for (int k = 0; k < 101; k++) {
						for (int l = 0; l < 101; l++) {
							visited[k][l] = false;
						}
					}
					area = 0;

					if (matrix[firstNumber][secondNumber] && !visited[firstNumber][secondNumber]) {
						visited[firstNumber][secondNumber] = true;
						calculate(firstNumber, secondNumber);
					}
					cout << area << endl;
				}
			}
			rowIndex++;
		}
		if (testCase) {
			cout << endl;
		}
	}

	return 0;
}