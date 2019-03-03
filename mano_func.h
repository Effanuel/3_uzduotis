#pragma once


#include <iostream>
#include <algorithm> //sort
#include <numeric> //accumulate

#include <vector>
#include <list>
#include <deque>

#include <fstream>
#include <typeinfo>
#include <chrono>
#include <random>
#include <iomanip>
#include <string>

#include <istream>


using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::generate;
using std::vector;
using std::list;
using std::deque;
using std::string;


class Timer {
private:
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<long double>;
	std::chrono::time_point<hrClock> start;
public:
	Timer() : start{ hrClock::now() } {}
	void reset() {
		start = hrClock::now();
	}
	long double elapsed() const {
		return durationDouble(hrClock::now() - start).count();
	}
};



struct Items
{
	string vardas, pavarde;
	double final_med, final_vid;
	vector<int> balai;
	int egz;
};


namespace Custom {
	void sort(vector<Items>&);
	void sort(list<Items>&);
	void sort(deque<Items>&);
}




bool alphabetical_sorting(const Items &, const Items &);
bool final_mark_sorting(const Items &, const Items &);
bool find_split_mark(Items&);

int max_len(vector<string>);
double median(std::vector<int>, size_t, int);
double vidurkis(std::vector<int>, size_t, int);


int cin_and_checkFormat_in_interval(int, int);
void random_num_generator(vector<int>&, int&);

void Rankinis_ivedimas(vector<int>&, int&);







template <typename T> void Sukurti_studenta(T& Studentai, string vardas, string pavarde, vector<int> balai, int egz) { //&
	size_t dydis_balu = balai.size() ? balai.size() : 1;
	const double galutinis_vid = vidurkis(balai, dydis_balu, egz);
	const double galutinis_med = median(balai, dydis_balu, egz);

	Studentai.push_back({ vardas, pavarde, galutinis_med, galutinis_vid, balai, egz });
}


template <typename T> void writeToFile(T& Studentai, string file_name) {
	std::ofstream failas(file_name);
	for (auto& studentas : Studentai) {
		failas << studentas.vardas << ' ' << studentas.pavarde << '\t';
		for (auto& balas : studentas.balai) {
			failas << balas << '\t';
		}
		failas << std::setprecision(3) << studentas.final_med << '\n';
	}
	failas.close();
}


template <typename T> void generateFile(T& Studentai_kieti, T& Studentai_silpni) {
	writeToFile(Studentai_kieti, "OUTPUT_KIETI.txt");
	writeToFile(Studentai_silpni, "OUTPUT_SILPNI.txt");
}



template <typename T> void Failo_generavimas(unsigned const int n = 100) {
	//Studentai.reserve(n);
	T Studentai;
	T Studentai_KIETI{};
	T Studentai_LEVI{};
	
	
	//Studentai2.reserve(100);

	vector<int> temp_balai;

	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_real_distribution<double> distr(1, 10);

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < 5; ++j) {
			temp_balai.push_back(distr(gen)); //sugeneruojami 5 random balai
		}

		Sukurti_studenta(Studentai, "Vardas" + std::to_string(i), "Pavarde" + std::to_string(i), temp_balai, (int)(distr(gen))); //sukuriamas vienas studentas
		temp_balai.clear();
	}

	Custom::sort(Studentai); // sortina pagal galutinius pazymius

	//---------split_students()-------------

	//auto it = std::distance(Studentai.begin(), std::find_if(Studentai.begin(), Studentai.end(), find_split_mark));
	//v0.4 -- neveikia su std::list, std::deque
	//std::move(Studentai.begin(), Studentai.begin() + it, std::back_inserter(Studentai2));
	//Studentai.erase(Studentai.begin(), Studentai.begin() + it);


	//v0.5 -- veikia su visais STL container'iais
	unsigned a = std::count_if(Studentai.begin(), Studentai.end(), find_split_mark);
	Studentai_KIETI.resize(a);
	Studentai_LEVI.resize(Studentai.size() - a);

	std::partition_copy(Studentai.begin(), Studentai.end(), Studentai_KIETI.begin(), Studentai_LEVI.begin(), find_split_mark);
	//--------------------------------------



	//---------generateFile()---------------
	generateFile(Studentai_KIETI, Studentai_LEVI);
	//--------------------------------------
}





//void Failo_nuskaitymas(vector<Items>& Studentai, string file_name, vector<string>& vardai, vector<string>& pavardes) {
template <typename T> void Failo_nuskaitymas(string file_name) {
	T Studentai;
	string vardas{}, pavarde{};

	vector<string> vardai;
	vector<string> pavardes;

	vector<int> balai{};
	int egz; 
	double galutinis_vid{};
	double galutinis_med{};

	std::ifstream failas(file_name.c_str());

	//ignoruoja pirma eilute:
	//Pavarde	Vardas	ND1  ND2   ND3  ND4  ND5  Egzaminas
	failas.ignore(1000, '\n'); 

	if (failas.fail()) throw std::exception("Nera tokio failo."); //jei nera failo

	int balas_temp;
	while (!failas.eof()) {

		failas >> pavarde >> vardas; // skaitomi pavarde ir vardas
		for (int j = 0; j < 5; j++) { // skaitomi 5 namu darbu balai
			failas >> balas_temp;
			balai.push_back(balas_temp);
		}

		if ((!(failas >> egz) || failas.fail() || balai.size() != 5)) throw std::exception("Blogas failo formatas."); // paieskoma ar formatas failo yra geras

		Sukurti_studenta(Studentai, vardas, pavarde, balai, egz); //push back viena Studenta
		balai.clear();
		vardai.push_back(vardas); // for max_len
		pavardes.push_back(pavarde); // for max_len
	}
	//sort(Studentai.begin(), Studentai.end(), alphabetical_sorting);
	failas.close(); //nezinau ar butina


	// reikia max_len, kad formatuoti lentele butu lengviau
	Print_table(Studentai, max_len(vardai), max_len(pavardes));
}




template <typename T> void Duomenu_ivedimas() {
	//balai.reserve(2);
	T Studentai;

	int egz{};
	vector<int> balai;
	vector<string> vardai;
	vector<string> pavardes;

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


	Print_table(Studentai, max_len(vardai), max_len(pavardes));
}







template <typename T> void Print_table(T& Studentai, int max_vardas, int max_pavarde) {
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*s %s\n", -int(max_pavarde) - 7, "Pavarde", -int(max_vardas) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());

	for (auto& line : Studentai) {
		printf("%*s %*s %*.2f %.2f\n", -int(max_pavarde) - 7, line.pavarde.c_str(), -int(max_vardas) - 7, line.vardas.c_str(), -19, line.final_vid, line.final_med);
	}
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
}
