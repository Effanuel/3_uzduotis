#pragma once

#include <iostream>
#include <algorithm> //sort
#include <numeric> //accumulate
#include <vector>
#include <fstream>
#include <typeinfo>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::generate;
using std::vector;
using std::string;


struct Items
{
	string vardas, pavarde;
	double final_med;
	double final_vid;
	int egz;


};


int max_len(vector<string> data) {

	auto func = [](const string &a, const string &b) {return a.size() < b.size(); };
	return (*std::max_element(data.begin(), data.end(), func)).size();
}



bool alphabetical_sorting(const Items &a, const Items &b)
{
	return a.pavarde < b.pavarde;
}


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


void ar_atsitiktinis(char a, vector<int>& balai,  int& egz) {
	if (a == 'y' || a == 'Y') {
		srand(time(NULL));
		balai.resize(5); //5 namu darbai
		generate(balai.begin(), balai.end(), []() {
			return rand() % 10 + 1;
		});
		egz = rand() % 10 + 1;
	}
	else {

		cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << endl;
		int ndbalai;
		while (cin >> ndbalai && ndbalai != 0) { //int(ndbalai)
			balai.push_back(ndbalai);
		}
		if (balai.empty()) { //error handling
			balai.resize(1);
		}
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Egzamino rezultatas: " << endl;
		egz = cin_and_checkFormat();
	}
}



double median(std::vector<int> arr, int size) {
	sort(arr.begin(), arr.end());
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;
}






vector<Items> fail_work(string file_name, vector<string>& vardai, vector<string>& pavardes) {
	vector<Items> it;
	string vardas, pavarde;
	vector<int> balai;
	int egz;
	double galutinis_vid;
	double galutinis_med;

	std::ifstream failas(file_name.c_str());

	failas.ignore(1000, '\n');


	if (failas.fail()) {
		std::cerr << "Error opening file" << endl;
		exit(1);
	}
	int balas;
	while (failas.good()) { //good
		failas >> pavarde >> vardas; //fix?
		it.reserve(2);
		for (int j = 0; j < 5; j++) {
			failas >> balas;
			if (failas.fail() && !failas.eof()) {
				std::cerr << "Error. Blogas failo formatas" << endl;
				exit(2);
			}
			else {
				balai.push_back(balas);
			}
				
		}
		failas >> egz;
		if (failas.fail() && !failas.eof()) {
			std::cerr << "Error. Blogas failo formatas" << endl;
			exit(2);
		}

		size_t dydis_balu = balai.size() ? balai.size() : 1;
		galutinis_vid = 0.4 * std::accumulate(balai.begin(), balai.end(), 0.0) / dydis_balu + 0.6 * egz;
		galutinis_med = 0.4 * median(balai, dydis_balu) + 0.6 * egz;

		it.push_back({ vardas, pavarde, galutinis_med, galutinis_vid, egz });
		vardai.push_back(vardas);
		pavardes.push_back(pavarde);
	}
	sort(it.begin(), it.end(), alphabetical_sorting);

	failas.close();
	return it;
}


