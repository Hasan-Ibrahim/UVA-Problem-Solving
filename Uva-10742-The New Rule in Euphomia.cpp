#include<iostream>
#include<math.h>

using namespace std;

const int SIZE = 1000001;
int allNumbers[SIZE];
int primeNumbers[SIZE];
int sumOfTwoPrimes[SIZE];
int compressedSums[SIZE];
int sumArrayLength = 0;

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

	for (int i = 0; i < j; i++) {
		for (int k = i + 1; k < j; k++) {
			int sum = primeNumbers[i] + primeNumbers[k];
			if (sum >= SIZE - 1) {
				break;
			}
			sumOfTwoPrimes[sum]++;
		}
	}

	j = 0;
	for (int i = 2; i < SIZE; i++) {
		if (sumOfTwoPrimes[i] > 0) {
			compressedSums[j++] = i;
		}
	}
	sumArrayLength = j;
}

int getTotalNumberOfCombination(int index) {
	int total = 0;
	for (int i = 0; i <= index; i++) {
		total += sumOfTwoPrimes[i];
	}
	return total;
}

int main() {

	preprocessPrimeNumbers();
	int inputNumber;

	int caseNo = 0;

	while ((cin >> inputNumber)) {
		if (inputNumber != 0)
		{
			int startIndex = 0;
			int endIndex = sumArrayLength - 1;
			bool isItemFound = false;
			int midIndex;
			while (endIndex >= startIndex) {
				midIndex = (startIndex + endIndex) / 2;
				if (inputNumber > compressedSums[midIndex]) {
					startIndex = midIndex + 1;
				}
				else if (inputNumber < compressedSums[midIndex]) {
					endIndex = midIndex - 1;
				}
				else {
					isItemFound = true;
					break;
				}
			}
			if (isItemFound) {
				cout << "Case " << ++caseNo << ": " << getTotalNumberOfCombination(compressedSums[midIndex]) << endl;
			}
			else {
				cout << "Case " << ++caseNo << ": " << getTotalNumberOfCombination(compressedSums[endIndex]) << endl;
			}
		}
		else break;

	}

	return 0;
}
