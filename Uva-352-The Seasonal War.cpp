#include <iostream>
#define SIZE_M 25

using namespace std;

int n, matrix[SIZE_M][SIZE_M];
int visited[SIZE_M][SIZE_M];
int stack[SIZE_M * SIZE_M];
int warCount;

void readData()
{
	char c;
	for (int i = 0;i < n;i++) {
		cin.get(c);
		for (int j = 0;j < n;j++) {
			cin.get(c);
			matrix[i][j] = c - 48;
			visited[i][j] = 0;
		}

	}

}


void FloodFill(int x, int y)
{
	
	visited[x][y] = 1;

	if(x+1<n && matrix[x+1][y] == 1 && visited[x+1][y] == 0){
		FloodFill(x + 1, y);
	}
	if (x - 1>=0 && matrix[x - 1][y] == 1 && visited[x - 1][y] == 0) {
		FloodFill(x - 1, y);
	}

	if (y+1 <n && matrix[x][y+1] == 1 && visited[x][y+1] == 0) {
		FloodFill(x, y + 1);
	}

	if (y - 1 >=0 && matrix[x][y-1] == 1 && visited[x][y - 1] == 0) {
		FloodFill(x, y - 1);
	}
	
	if (x + 1 <n && y-1 >=0 && matrix[x + 1][y - 1] == 1 && visited[x + 1][y - 1] == 0) {
		FloodFill(x + 1, y - 1);
	}

	if (x - 1 >= 0 && y - 1 >= 0 && matrix[x - 1][y - 1] == 1 && visited[x - 1][y - 1] == 0)
	{
		FloodFill(x - 1, y - 1);
	}

	if (x + 1 < n && y + 1 < n && matrix[x + 1][y + 1] == 1 && visited[x + 1][y + 1] == 0)
	{
		FloodFill(x + 1, y + 1);
	}
	
	if (x - 1 >= 0 && y + 1 < n && matrix[x - 1][y + 1] == 1 && visited[x - 1][y + 1] == 0)
	{
		FloodFill(x - 1, y + 1);
	}
	
	
}

int main()
{

	int i = 1;
	while (cin >> n)
	{
		warCount = 0;
		readData();
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if (visited[i][j] != 1 && matrix[i][j] == 1) {
					FloodFill(i, j);
					warCount++;
				}
			}
		}

		cout << "Image number " << i << " contains " << warCount << " war eagles." << endl;
		i++;
	}
	return 0;
}