#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include <cstring>

using namespace std;

void FillArray(int **array, int a, int b);

void PrintArray(int **array, int a, int b);

void ChangeElements(int **array, int a, int b);

void BigNumber(char num[]);

void SwapArray(char sentence[]);

int main()
{
	int operation;

	int N = 0;
	int M = 0;

	char num[50];

	cout << "Choose operation: 1 - 2d array operations, 2 - big number repeated digits, 3 - swap sentence" << endl;

	cin >> operation;
	if (operation == 1) {
		cout << "Enter array size: " << endl;
		cin >> N;
		cin >> M;

		int** array = new int*[N];
		for (int i = 0; i < N; i++) {
			array[i] = new int[M];
		}

		FillArray(array, N, M);
		ChangeElements(array, N, M);
		PrintArray(array, N, M);

	}

	if (operation == 2) {
		cout << "Enter a big number (between 20 and 50 digits): " << endl;
		cin >> num;

		BigNumber(num);
	}

	if (operation == 3) {
		char * words = new char[1000];

		cout << "Enter a sentence to reverse it: " << endl;

		cin.get(words, 999);

		SwapArray(words);
	}
	system("PAUSE");
    return 0;
}

void FillArray(int **array, int a, int b) {
	srand(time(NULL));

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			array[i][j] = (rand()%319)- 94;
		}
	}
}

void PrintArray(int **array, int a, int b) {
	for (int i = 0; i < a; i++) {
		cout << "{";
		for (int j = 0; j < b; j++)  {
			cout << "|" << array[i][j] << "|" << " ";
		}
		cout << "}" << " , ";
	}
}

void ChangeElements(int **array, int a, int b) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				pow(array[i][j], 2);
			}
			else {
				int ab = abs(array[i][j]);
			}
		}
	}
}

void BigNumber(char num[]) {
	int len = strlen(num);
	int sum = 0;
	int j = 0;
	int temp;

	for (int i = 0; i < len; i++) {
		num[j++] = num[i];

		while (i + 1 < len && num[i] == num[i + 1]) {
			sum += num[i];
			i++;
		}
	}
	num[j] = '\0';
	
	cout << num << endl;
	cout << "The sum of the repeating numbers is: " << sum << endl;

	for (int x = 0; x < len; x++) {
		for (int z = x + 1; z < len; z++) {
			if (num[x] < num[z]) {
				temp = num[x];
				num[x] = num[z];
				num[z] = temp;
			}
		}
	}
	cout << "The number in descending order is: " << num << endl;
}

void SwapArray(char sentence[]) {
	bool inword = false, isletter = true;
	size_t length = 0; 
	size_t size = strlen(sentence);

	for (int i = 0; i < size; i++) {
		isletter = (sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z');

		if (isletter) {
			inword = true;
			length++;
		}
		if (!isletter || i == size - 1) {
			if (inword) {
				if (i == size - 1 && isletter) i = size;
				inword = false;
				for (int j = i - length, k = 0; j < i - (length / 2); j++, k++) {
					char tmp = sentence[j];
					sentence[j] = sentence[i - k - 1];
					sentence[i - k - 1] = tmp;
				}
			}
			length = 0;
		}
	}
	cout << sentence << endl;
}
