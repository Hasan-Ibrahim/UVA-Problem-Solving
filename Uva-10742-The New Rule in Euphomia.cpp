#include<iostream>
#include<math.h>

using namespace std;

const int SIZE = 1000001;
int allNumbers[SIZE];
int primeNumbers[SIZE];
int primeLength;

void preprocessPrimeNumbers() {
	int upperBound = sqrt(SIZE);
	for (int i = 2; i <= upperBound; i++) {
		for (int j = 2 * i; j < SIZE; j += i) {
			allNumbers[j] = 1;
		}
	}
	int j = 0;

	for (int i = 2; i < SIZE; i++) {
		if (allNumbers[i] == 0) {
			primeNumbers[j++] = i;
		}
	}
	primeLength = j;
}

int getResult(int number) {
	int result = 0;
	for (int i = 0; i < primeLength && number - primeNumbers[i]> primeNumbers[i]; i++) {
		int diff = number - primeNumbers[i];
		int startIndex = i + 1;
		int endIndex = primeLength - 1;
		int currentIndex = i;
		while (startIndex <= endIndex) {
			int midIndex = (startIndex + endIndex) / 2;
			if (primeNumbers[midIndex] <= diff) {
				startIndex = midIndex + 1;
				currentIndex = midIndex;
			}
			else {
				endIndex = midIndex - 1;
			}
		}
		result = result + currentIndex - i;
	}
	return result;
}

int main() {

	preprocessPrimeNumbers();
	int inputNumber;

	int caseNo = 0;

	while ((cin >> inputNumber)) {
		if (inputNumber != 0)
		{
			cout << "Case " << ++caseNo << ": " << getResult(inputNumber) << endl;
		}
		else break;
	}

	return 0;
}
