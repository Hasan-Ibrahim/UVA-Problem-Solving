#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<sstream>

using namespace std;
int testCase;
string line;
int matrix[101][101];
bool visited[101][101];
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
		if (matrix[pos.x + 1][pos.y - 1] && !visited[pos.x + 1][pos.y - 1] && y > 0) {
			push({ pos.x + 1,pos.y - 1 });
			visited[pos.x + 1][pos.y - 1] = true;
		}
		if (matrix[pos.x][pos.y + 1] && !visited[pos.x][pos.y + 1]) {
			push({ pos.x,pos.y + 1 });
			visited[pos.x][pos.y + 1] = true;
		}
		if (matrix[pos.x][pos.y - 1] && !visited[pos.x][pos.y - 1] && y > 0) {
			push({ pos.x,pos.y - 1 });
			visited[pos.x][pos.y - 1] = true;
		}
		if (matrix[pos.x - 1][pos.y + 1] && !visited[pos.x - 1][pos.y + 1] && x > 0) {
			push({ pos.x - 1,pos.y + 1 });
			visited[pos.x - 1][pos.y + 1] = true;
		}
		if (matrix[pos.x - 1][pos.y - 1] && !visited[pos.x - 1][pos.y - 1] && y > 0 && x > 0) {
			push({ pos.x - 1,pos.y - 1 });
			visited[pos.x - 1][pos.y - 1] = true;
		}
		if (matrix[pos.x - 1][pos.y] && !visited[pos.x - 1][pos.y] && x > 0) {
			push({ pos.x - 1,pos.y });
			visited[pos.x - 1][pos.y] = true;
		}
	}
	return area;
}

void readTestCase() {
	int rowIndex = 0;
	while (true) {
		getline(cin, line);
		if (line == "")break;
		int size = line.length();

		for (int i = 0; i < size; i++) {

			if (line[i] == 'L') {
				matrix[rowIndex][i] = 0;
			}
			else if (line[i] == 'W') {
				matrix[rowIndex][i] = 1;
			}
			
			else {
				char number1[2], number2[2];
				int number1Index = 0, number2Index = 0;

				bool isFound = false;
				for (int j = 0; ; j++) {

					i = j - 1;

					if (line[j] == ' ') {
						isFound = true;
						j++;
					}
					if (!(line[j] >= 48 && line[j] <= 57)) {
						break;
					}
					if (!isFound) {
						number1[number1Index++] = line[j];
					}
					else {
						number2[number2Index++] = line[j];
					}
				}
				int firstNumber = stoi(string(number1));
				int secondNumber = stoi(string(number2));
				for (int k = 0; k < 101; k++) {
					for (int l = 0; l < 101; l++) {
						visited[k][l] = false;
					}
				}
				//cout << "first: " << firstNumber << " Second: " << secondNumber << endl;
				cout << calculate(firstNumber - 1, secondNumber - 1) << endl;
			}
		}
		rowIndex++;
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> testCase;
	getline(cin, line);
	getline(cin, line);
	while (testCase--) {
		
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				matrix[i][j] = 0;
			}
		}
		readTestCase();
		if (testCase) {
			cout << endl;
		}
	}

	return 0;
}