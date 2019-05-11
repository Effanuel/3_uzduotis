﻿#pragma once
#include "Studentas.h"
#include "median.h"

#include <exception> 

#include <list>
#include <deque>

#include <fstream>
#include <typeinfo>
#include <chrono>
#include <string>
#include <istream>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::generate;
//using std::list;
//using std::deque;
using std::string;




/**
Timer objektas laiko skaiciavimui
*/
class Timer {
private:
	///Auksto tikslumo laikrodi
	using hrClock = std::chrono::high_resolution_clock;
	///Double trukmes skaiciavimas
	using durationDouble = std::chrono::duration<long double>;
	std::chrono::time_point<hrClock> start;
public:
	///Sukuria Timer() objekta, pradeda skaiciuoti laika
	Timer() : start{ hrClock::now() } {}
	///Pradeda skaiciuoti laika is pradziu
	void reset() {
		start = hrClock::now();
	}
	///Grazina laika nuo Timer() sukurimo/reset() iki sios funkcijos call
	long double elapsed() const {
		return durationDouble(hrClock::now() - start).count();
	}
};

/**
Suranda dydziausio ilgio string std::vector'iuje
*/
int max_len(std::vector<string>);
/**
Pagalbine funckija atskirti kietus nuo levu studentu
*/
bool cool_students_sort(const Student &);
/**
Generuoja atsitiktinius 5 namu darbu balus ir 1 egzamino bala
*/
void random_num_generator(std::vector<double>&, double&);
/**
Antrine funkcija Studento duomenu ivedimui per console
*/
template <typename T> void Rankinis_ivedimas(T&, string&, string&, std::vector<string>&, std::vector<string>&);
/**
Skaiciaus ivedimo ir formato patikrinimo funkcija (tarp a ir b)
*/
template <typename T> T cin_and_checkFormat_in_interval(double, double);
/**
Isskirsto std::vector<Student> i kietus ir levus
*/
template <typename T> void Failo_skirstymas(int, T&);
/**
Pagalbine funkcija container'i irasyti i faila
*/
template <typename T> void writeToFile(T&, string);
/**
Pagalbine funkcija (std::vectoriu is Studentu) irasyti i faila call'inant member function
*/
template <typename T> void writeToFile_egz(T&, string);
/**
Sugeneruoja 2 atskirus failus is pateiktu container'iu
(default: SILPNI ir KIETI)
*/
template <typename T> void generateFile(T&, T&);
/**
Pilno Studento su vardu, pavarde, nd, egz sugeneravimas
*/
template <typename T> void StudentGenerator(T&, int, std::vector<string>&, std::vector<string>&);
/**
Atsitiktinai sugeneruoja faila is kazkokio kiekio Studentu
*/
template <typename T> void Failo_generavimas_v2(string, unsigned int);
/**
Pagrindine funkcija Studento duomenu ivedimui/generavimui per console
*/
template <typename T> void Duomenu_ivedimas();
/**
Nuskaito faila ir/arba print'ina/skirsto
*/
template <typename T> void Failo_nuskaitymas(string, string, string, int);
/**
Spausdina Studento duomenis lenteleje
*/
template <typename T> void Print_table(T&, int, int);



//--------------------
void random_num_generator(std::vector<double>& balai, double& egz) {
	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	balai.resize(5); //5 namu darbai
	generate(balai.begin(), balai.end(), []() {
		return distr(gen);
	});
	egz = distr(gen);
}
//--------------------
bool cool_students_sort(const Student &n) {
	return n.galBalas() >= 5.0;
}
//--------------------
template <typename T> T cin_and_checkFormat_in_interval(double a, double b) {
	T input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}
//--------------------
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
//--------------------
template <typename T> void writeToFile_egz(T& Studentai, string filename) {
	std::ofstream failas(filename);
	for (auto& Studentas : Studentai) {
		Studentas.writeToFile(filename, failas);
	}
	failas.close();
}
//--------------------
template <typename T> void generateFile(T& Studentai_kieti, T& Studentai_silpni) {
	writeToFile(Studentai_kieti, "OUTPUT_KIETI.txt");
	writeToFile(Studentai_silpni, "OUTPUT_SILPNI.txt");
}
//--------------------
template <typename T> void Failo_generavimas_v2(string filename, unsigned int n) { //sugeneruoja faila tiktais
	
	T Studentai;
	//Studentai.reserve(n); //tik std::vector'iui

	std::vector<double> temp_balai;
	double temp_egz;
	for (unsigned int i = 0; i < n; ++i) {

		random_num_generator(temp_balai, temp_egz);

		Sukurti_studenta(Studentai, "Vardas" + std::to_string(i), "Pavarde" + std::to_string(i), temp_balai, temp_egz); //sukuriamas vienas studentas
		temp_balai.clear();
	}

	writeToFile_egz(Studentai, filename);

}
//--------------------
template <typename T> void Failo_nuskaitymas(string file_name, string print, string skirstymas, int strategija) {
	T Studentai;
	string vardas{}, pavarde{};

	std::vector<string> vardai;
	std::vector<string> pavardes;

	std::vector<double> balai{};
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
//--------------------
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
	//else if (strategija == 2) {	//STRATEGY #2
	//	auto pivot = std::partition(Studentai.begin(), Studentai.end(), cool_students_sort);
	//	//T Studentai_levi(pivot, Studentai.end());
	//	T Studentai_levi(std::distance(pivot, Studentai.end()));

	//	std::copy(pivot, Studentai.end(), Studentai_levi.begin());
	//	Studentai.erase(pivot, Studentai.end()); // SUPAPRASTINTA

	//	//---------generuoja failus-------------
	//	generateFile(Studentai, Studentai_levi);
	//}
	//else if (strategija == 3) { //STRATEGY #3
	//	T Studentai_levi;
	//	auto it = Studentai.begin();
	//	while (it != Studentai.end()) {
	//		if (!cool_students_sort(*it)) {
	//			Studentai_levi.push_back(*it);
	//			it = Studentai.erase(it);
	//		}
	//		else
	//			++it;
	//	}
	//	generateFile(Studentai, Studentai_levi);
	//}
}
//--------------------
template <typename T> void StudentGenerator(T& Studentai, int stud_skaicius, std::vector<string>& vardai, std::vector<string>& pavardes) {

	Studentai.resize(stud_skaicius);
	for (auto& Studentas : Studentai) {
		Studentas.randomStudent();
		vardai.push_back(Studentas.vardas());
		pavardes.push_back(Studentas.pavarde());
	}
}
//--------------------
template <typename T> void Rankinis_ivedimas(T& Studentai, string& vardas, string& pavarde, std::vector<string>& vardai, std::vector<string>& pavardes) {

	double egz{};
	std::vector<double> balai;

	cout << "Iveskite mokinio varda ir pavarde: " << endl;
	vardas = cin_and_checkFormat(cin);
	pavarde = cin_and_checkFormat(cin);

	vardai.push_back(vardas);
	pavardes.push_back(pavarde);

	cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << endl;
	double ndbalai;
	while (cin >> ndbalai && ndbalai != 0 && ndbalai < 10 && ndbalai > 0) { //int(ndbalai)
		balai.push_back(ndbalai);
	}
	if (balai.empty()) { //error handling
		balai.resize(1);
	}
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Egzamino rezultatas(1-10): " << endl;
	egz = cin_and_checkFormat_in_interval<double>(1, 10);

	Sukurti_studenta(Studentai, vardas, pavarde, balai, egz);


}
//--------------------
template <typename T> void Duomenu_ivedimas() {
	//balai.reserve(2);
	T Studentai;

	std::vector<string> vardai;
	std::vector<string> pavardes;

	char is_random;
	cout << "Ar norite, kad studentai butu generuojami atsitiktinai?(y/n)" << endl;
	cin >> is_random;
	switch (tolower(is_random)) {
	case 'y':	
		int stud_skaicius;
		cout << "Kiek norite studentu?(1-1000)" << endl;
		stud_skaicius = cin_and_checkFormat_in_interval<int>(1, 1000);

		StudentGenerator(Studentai, stud_skaicius, vardai, pavardes);
		break;
	default:
		char more;
		do {
			string vardas{};
			string pavarde{};
			Rankinis_ivedimas(Studentai, vardas, pavarde, vardai, pavardes);
			
			cout << "Ar norite ivesti dar viena studenta?(y/n)" << endl;
			cin >> more;
		} while (more == 'y');
		break;
	}
	Print_table(Studentai, max_len(vardai), max_len(pavardes));
}
//--------------------
template <typename T> void Print_table(T& Studentai, int max_vardas, int max_pavarde) {
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*s %s\n", -int(max_pavarde) - 7, "Pavarde", -int(max_vardas) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());

	for (const auto& line : Studentai) {
		printf("%*s %*s %*.2f %.2f\n", -int(max_pavarde) - 7, line.pavarde().c_str(), -int(max_vardas) - 7, line.vardas().c_str(), -19, line.galBalas(vidurkis), line.galBalas()); //add vidurkis
	}
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
}
