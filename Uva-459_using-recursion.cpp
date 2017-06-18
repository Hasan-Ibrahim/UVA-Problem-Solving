
#include<iostream>

using namespace std;

int testCase;
bool graph[26][26];
bool visited[26][26];
int graphSize;
char character;


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

void floodFill(int row) {

	for (int x = 0; x < graphSize; x++) {
		if (!visited[row][x] && graph[row][x]) {
			visited[row][x] = true;
			floodFill(x);
		}
	}
}

int main() {
	

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
					floodFill(j);					
					numberOfConnectedGraph++;
				}
			}
		}
		cout << numberOfConnectedGraph << endl;
		if (testCase) cout << endl;
	}
}
