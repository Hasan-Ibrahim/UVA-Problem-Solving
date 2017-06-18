#include<iostream>

using namespace std;

int stackTop;
char line[3];
int testCase;
bool graph[26][26];
bool visited[26][26];
int graphSize;
char character;

struct position {
	int x;
	int y;
};

position stack[26 * 26];

void push(position value) {
	stack[stackTop++] = value;
}

position pop() {
	return stack[--stackTop];
}


void readTestCases() {

	character = getchar();

	graphSize = character - 'A' + 1;
	character = getchar();

	for (int i = 0; i < graphSize; i++) {
		for (int j = 0; j < graphSize; j++) {
			if (i == j) {
				graph[i][j] = true;
			}
			else {
				graph[i][j] = false;
			}

			visited[i][j] = false;
		}
	}

	while (true) {
		character = getchar();

		if (character == '\n' && testCase)break;
		if ((character < 65 || character> 91) && character != '\n' && !testCase) break;
		int x = character - 'A';


		character = getchar();
		int y = character - 'A';

		graph[x][y] = graph[y][x] = true;

		character = getchar();
	}
}

void traverse(int i, int j) {

	while (stackTop != 0) {
		position pos = pop();

		for (int x = 0; x < graphSize; x++) {
			if (graph[pos.y][x]) {
				if (!visited[pos.y][x] && graph[pos.y][x]) {
					visited[pos.y][x] = true;
					push({ pos.y,x });
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> testCase;
	character = getchar();
	character = getchar();

	while (testCase--) {
		readTestCases();
		int numberOfConnectedGraph = 0;
		for (int i = 0; i < graphSize; i++) {
			for (int j = 0; j < graphSize; j++) {
				if (graph[i][j] && !visited[i][j]) {
					visited[i][j] = true;
					push({ i,j });
					traverse(i, j);
					numberOfConnectedGraph++;
				}
			}
		}
		cout << numberOfConnectedGraph << endl;
		if (testCase) cout << endl;
	}
}
