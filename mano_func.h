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
	string vardas{}, pavarde{};
	double final_med{}, final_vid{};
	vector<int> balai{};
	int egz{};


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
		try {
			cin >> input;
			if (cin.fail()) throw 1;
			return input;
		} catch (int err) {
			cout << "Netinkamas balo formatas. Iveskite is naujo:\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
		


	}
}


void Rankinis_ivedimas(vector<int>& balai,  int& egz) {

	cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << endl;
	int ndbalai{};
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



double median(std::vector<int> arr, size_t size, int egz) {
	sort(arr.begin(), arr.end());
	if (size == 0) return 0.6 * egz;
	const double med = size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;
	return 0.4 * med + 0.6 * egz;
}

double vidurkis(std::vector<int> arr, size_t size, int egz) {
	if (size == 0) return 0.6 * egz;
	const double vid = std::accumulate(arr.begin(), arr.end(), 0.0) / size;
	return 0.4 * vid + 0.6 * egz;
}



void Sukurti_studenta(vector<Items>& Studentai, string vardas, string pavarde, vector<int> balai, int egz) { //&
	size_t dydis_balu = balai.size() ? balai.size() : 1;
	const double galutinis_vid = vidurkis(balai, dydis_balu, egz);
	const double galutinis_med = median(balai, dydis_balu, egz);

	Studentai.push_back({ vardas, pavarde, galutinis_med, galutinis_vid, balai, egz });
}






void Failo_nuskaitymas(vector<Items>& Studentai, string file_name, vector<string>& vardai, vector<string>& pavardes) {
	string vardas{}, pavarde{};
	vector<int> balai{};
	int egz{};
	double galutinis_vid{};
	double galutinis_med{};

	std::ifstream failas(file_name.c_str());

	failas.ignore(1000, '\n');
	try {
		if (failas.fail()) throw "Error opening file";
	}
	catch (...) {
		cout << "klaida" << endl;
		exit(0);

	}



	int balas_temp;
	while (failas.good()) {

		failas >> pavarde >> vardas;
		Studentai.reserve(2);
		for (int j = 0; j < 5; j++) {
			failas >> balas_temp;
			balai.push_back(balas_temp);
		}
		try {
			if (((!(failas >> egz)) && (failas.fail()) || balai.size() != 5) && !failas.eof()) throw 1; // check if push_back was successful && failas >> egz && not end of line;
		}
		catch (int err) {
			cout << "Error blogas formatas: " << err << endl;
			exit(0);
		}
		Sukurti_studenta(Studentai, vardas, pavarde, balai, egz);
		balai.clear();
		vardai.push_back(vardas);
		pavardes.push_back(pavarde);
	}
	sort(Studentai.begin(), Studentai.end(), alphabetical_sorting);
	failas.close(); //nezinau ar butina
}

void random_num_generator(vector<int>& balai, int& egz) {
	srand(time(NULL));
	balai.resize(5); //5 namu darbai
	generate(balai.begin(), balai.end(), []() {
		return rand() % 10 + 1;
	});
	egz = rand() % 10 + 1;
}




void Duomenu_ivedimas(vector<Items>& Studentai, vector<int>& balai, vector<string>& vardai, vector<string>& pavardes) {
	//balai.reserve(2);
	int egz{};

	string vardas{};
	string pavarde{};
	cout << "Iveskite mokinio varda ir pavarde: " << endl;
	cin >> vardas >> pavarde;
	

	char is_random;
	cout << "Ar norite, kad balai butu generuojami atsitiktinai?(y/n)" << endl;
	cin >> is_random;

	switch (tolower(is_random)){
	case 'y':
		random_num_generator(balai, egz);
		break;
	default:
		Rankinis_ivedimas(balai, egz);
		break;
	}

	vardai.push_back(vardas);
	pavardes.push_back(pavarde);
	Sukurti_studenta(Studentai, vardas, pavarde, balai, egz);

}










void Print_table(vector<Items> Studentai, int max_vardas, int max_pavarde) {
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*s %s\n", -int(max_pavarde) - 7, "Pavarde", -int(max_vardas) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());

	for (auto& line : Studentai) {
		printf("%*s %*s %*.2f %.2f\n", -int(max_pavarde) - 7, line.pavarde.c_str(), -int(max_vardas) - 7, line.vardas.c_str(), -19, line.final_vid, line.final_med);
	}
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
}
