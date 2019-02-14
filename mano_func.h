#pragma once

#include <iostream>
#include <algorithm> //sort
#include <numeric> //accumulate

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::generate;


int cin_and_checkFormat() {
	int input;
	while (true) {
		//!(cin >> input) && input != 0 && !int(input)
		cin >> input;
		if (cin.fail())
		{
			cout << "Netinkamas balo formatas. Iveskite is naujo:\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else {
			return input;
		}

	}
}


void ar_atsitiktinis(char a, int(*&nd), int& dydis, int& egz) {
	if (a == 'y') {
		//nd.resize(5); //5 namu darbai
		generate(nd, nd + dydis, []() {
			return rand() % 10 + 1;
		});
		egz = rand() % 10 + 1;
	}
	else {

		cout << "Iveskite penkis namu darbu rezultatus: " << endl;
		int i = 0;
		int ndbalai;
		for (int i = 0; i < dydis; i++) {
			ndbalai = cin_and_checkFormat();
			*(nd + i) = ndbalai;
		}
		cout << "Egzamino rezultatas: " << endl;
		egz = cin_and_checkFormat();

	}
}



double median(int arr[], int size) {
	sort(arr, arr + size);
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;
}

