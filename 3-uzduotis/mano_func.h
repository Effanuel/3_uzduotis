#pragma once

#include <iostream>
#include <algorithm> //sort
#include <numeric> //accumulate
#include <exception> 

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


string cin_and_checkFormat();
template <typename T> T cin_and_checkFormat_in_interval(int, int);
void random_num_generator(vector<double>&, double&);
void Rankinis_ivedimas(vector<double>&, double&);
int max_len(vector<string>);//+



template <typename T> T cin_and_checkFormat_in_interval(int a, int b) {
	T input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}


template <typename T> void writeToFile(T& Studentai, string filename) {
	std::ofstream failas(filename);
	for (auto& studentas : Studentai) {
		failas << '\n' << studentas.vardas() << '\t' << studentas.pavarde() << '\t';
		for (auto& balas : studentas.balai()) {
			failas << balas << '\t';
		}
		failas << std::setprecision(3) << studentas.galBalas();
	}
	failas.close();
}



template <typename T> void writeToFile_egz(T& Studentai, string filename) {
	std::ofstream failas(filename);
	for (auto& Studentas : Studentai) {
		Studentas.writeToFile(filename, failas);
	}
	failas.close();
}



template <typename T> void generateFile(T& Studentai_kieti, T& Studentai_silpni) {
	writeToFile(Studentai_kieti, "OUTPUT_KIETI.txt");
	writeToFile(Studentai_silpni, "OUTPUT_SILPNI.txt");
}


template <typename T> void Failo_skirstymas(int strategija, T& Studentai) {
	if (strategija == 1) { //STRATEGY #1
		//Custom::sort(Studentai);
		T Studentai_kieti;
		T Studentai_levi;

		std::partition_copy(std::make_move_iterator(Studentai.begin()),
			std::make_move_iterator(Studentai.end()),
			std::back_inserter(Studentai_kieti), std::back_inserter(Studentai_levi),
			cool_students_sort
		);


		//---------generuoja failus-------------
		generateFile(Studentai_kieti, Studentai_levi);
	}
	else if (strategija == 2) {	//STRATEGY #2
		auto pivot = std::partition(Studentai.begin(), Studentai.end(), cool_students_sort);
		//T Studentai_levi(pivot, Studentai.end());
		T Studentai_levi(std::distance(pivot, Studentai.end()));

		std::copy(pivot, Studentai.end(), Studentai_levi.begin()); 
		Studentai.erase(pivot, Studentai.end()); // SUPAPRASTINTA

		//---------generuoja failus-------------
		generateFile(Studentai, Studentai_levi);
	}
	else if (strategija == 3) { //STRATEGY #3
		T Studentai_levi;
		auto it = Studentai.begin();
		while (it != Studentai.end()) {
			if (!cool_students_sort(*it)) {
				Studentai_levi.push_back(*it);
				it = Studentai.erase(it); 
			}
			else
				++it; 
		}

		generateFile(Studentai, Studentai_levi);
	}
}


template <typename T> void Failo_generavimas_v2(string filename, unsigned int n = 1000) { //sugeneruoja faila tiktais
	//Studentai.reserve(n);
	T Studentai;


	vector<double> temp_balai;
	double temp_egz;
	for (unsigned int i = 0; i < n; ++i) {

		random_num_generator(temp_balai, temp_egz);

		Sukurti_studenta(Studentai, "Vardas" + std::to_string(i), "Pavarde" + std::to_string(i), temp_balai, temp_egz); //sukuriamas vienas studentas
		temp_balai.clear();
	}

	writeToFile_egz(Studentai, filename);

}



template <typename T> void Failo_nuskaitymas(string file_name, string print = "print", string skirstymas = "neskirstyti", int strategija = 1) {
	T Studentai;
	string vardas{}, pavarde{};

	vector<string> vardai;
	vector<string> pavardes;

	vector<double> balai{};
	double egz; 

	std::ifstream failas(file_name.c_str());

	if (failas.fail()) throw std::runtime_error("Nera tokio failo."); //jei nera failo

	double balas_temp;
	while (!failas.eof()) { 

		failas >> pavarde >> vardas; // skaitomi pavarde ir vardas
		for (int j = 0; j < 5; j++) { // skaitomi 5 namu darbu balai
			failas >> balas_temp;
			balai.push_back(balas_temp);
		}

		if ((!(failas >> egz) || failas.fail() || balai.size() != 5)) throw std::runtime_error("Blogas failo formatas."); // paieskoma ar formatas failo yra geras
		Sukurti_studenta(Studentai, vardas, pavarde, balai, egz); //emplace back viena Studenta
		balai.clear();
		vardai.push_back(vardas); // for max_len
		pavardes.push_back(pavarde); // for max_len
	}
	failas.close();




	if (print == "print") {
		Print_table(Studentai, max_len(vardai), max_len(pavardes));
	}

	if (skirstymas == "skirstyti") {
		Failo_skirstymas(strategija, Studentai);
	}
	
}



template <typename T> void Duomenu_ivedimas() {
	//balai.reserve(2);
	T Studentai;

	double egz{};
	vector<double> balai;
	vector<string> vardai;
	vector<string> pavardes;

	string vardas{};
	string pavarde{};
	cout << "Iveskite mokinio varda ir pavarde: " << endl;
	vardas = cin_and_checkFormat();
	pavarde = cin_and_checkFormat();

	

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
//
template <typename T> void Print_table(T& Studentai, int max_vardas, int max_pavarde) {
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*s %s\n", -int(max_pavarde) - 7, "Pavarde", -int(max_vardas) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());

	for (auto& line : Studentai) {
		printf("%*s %*s %*.2f %.2f\n", -int(max_pavarde) - 7, line.pavarde().c_str(), -int(max_vardas) - 7, line.vardas().c_str(), -19, line.galBalas(), line.galBalas()); //add vidurkis
	}                                      
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
}
