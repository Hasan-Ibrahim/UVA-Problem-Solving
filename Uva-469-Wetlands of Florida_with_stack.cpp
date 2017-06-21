#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int testCase;
string line;
bool matrix[101][101];
bool visited[101][101];
string firstNumberString, secondNumberString;

struct position {
	int x;
	int y;
};
position stack[100000];
int stackTop = 0;

void push(position value) {
	stack[stackTop++] = value;
}

position pop() {
	return stack[--stackTop];
}

int calculate(int x, int y) {
	int area = 0;
	if (matrix[x][y]) {
		push({ x,y });
		visited[x][y] = true;
	}

	while (stackTop) {
		position pos = pop();
		area++;
		if (matrix[pos.x + 1][pos.y] && !visited[pos.x + 1][pos.y]) {
			push({ pos.x + 1,pos.y });
			visited[pos.x + 1][pos.y] = true;
		}
		if (matrix[pos.x + 1][pos.y + 1] && !visited[pos.x + 1][pos.y + 1]) {
			push({ pos.x + 1,pos.y + 1 });
			visited[pos.x + 1][pos.y + 1] = true;
		}
		if (matrix[pos.x + 1][pos.y - 1] && !visited[pos.x + 1][pos.y - 1] && pos.y > 0) {
			push({ pos.x + 1,pos.y - 1 });
			visited[pos.x + 1][pos.y - 1] = true;
		}
		if (matrix[pos.x][pos.y + 1] && !visited[pos.x][pos.y + 1]) {
			push({ pos.x,pos.y + 1 });
			visited[pos.x][pos.y + 1] = true;
		}
		if (matrix[pos.x][pos.y - 1] && !visited[pos.x][pos.y - 1] && pos.y > 0) {
			push({ pos.x,pos.y - 1 });
			visited[pos.x][pos.y - 1] = true;
		}
		if (matrix[pos.x - 1][pos.y + 1] && !visited[pos.x - 1][pos.y + 1] && pos.x > 0) {
			push({ pos.x - 1,pos.y + 1 });
			visited[pos.x - 1][pos.y + 1] = true;
		}
		if (matrix[pos.x - 1][pos.y - 1] && !visited[pos.x - 1][pos.y - 1] && pos.y > 0 && pos.x > 0) {
			push({ pos.x - 1,pos.y - 1 });
			visited[pos.x - 1][pos.y - 1] = true;
		}
		if (matrix[pos.x - 1][pos.y] && !visited[pos.x - 1][pos.y] && pos.x > 0) {
			push({ pos.x - 1,pos.y });
			visited[pos.x - 1][pos.y] = true;
		}
	}
	return area;
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
					firstNumber = stoi(firstNumberString);
					secondNumber = stoi(secondNumberString);

					for (int k = 0; k < 101; k++) {
						for (int l = 0; l < 101; l++) {
							visited[k][l] = false;
						}
					}

					int result = calculate(firstNumber - 1, secondNumber - 1);
					cout << result << endl;
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