#pragma once

#include <iostream>
#include <algorithm> //sort
#include <numeric> //accumulate
#include <vector>
#include <fstream>
#include <typeinfo>
#include <chrono>
#include <random>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::generate;
using std::vector;
using std::string;


class Timer {
private:
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	std::chrono::time_point<hrClock> start;
public:
	Timer() : start{ hrClock::now() } {}
	void reset() {
		start = hrClock::now();
	}
	double elapsed() const {
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



int max_len(vector<string>);
bool alphabetical_sorting(const Items &, const Items &);
double median(std::vector<int>, size_t, int);
double vidurkis(std::vector<int>, size_t, int);
bool final_mark_sorting(const Items &, const Items &);



void Sukurti_studenta(vector<Items>&, string, string, vector<int>, int); //&
vector<Items> generateStudents(unsigned int);
bool find_split_mark(Items&);

vector<Items> split_students(vector<Items>&);

void writeToFile(vector<Items>&, string);
void generateFile(vector<Items>&, vector<Items>&);

int cin_and_checkFormat();
void Rankinis_ivedimas(vector<int>&, int&);
void Failo_nuskaitymas(vector<Items>&, string, vector<string>&, vector<string>&);
void random_num_generator(vector<int>&, int&);
void Duomenu_ivedimas(vector<Items>&, vector<int>&, vector<string>&, vector<string>&);
void Print_table(vector<Items>, int, int);




bool final_mark_sorting(const Items &a, const Items &b)
{
	return a.final_med < b.final_med;
}

void Sukurti_studenta(vector<Items>& Studentai, string vardas, string pavarde, vector<int> balai, int egz) { //&
	size_t dydis_balu = balai.size() ? balai.size() : 1;
	const double galutinis_vid = vidurkis(balai, dydis_balu, egz);
	const double galutinis_med = median(balai, dydis_balu, egz);

	Studentai.push_back({ vardas, pavarde, galutinis_med, galutinis_vid, balai, egz });
}



vector<Items> generateStudents(unsigned int n) {
	vector<Items> Studentai;
	Studentai.reserve(n);

	vector<int> temp_balai;

	std::mt19937 gen;
	gen.seed(std::random_device()());
	std::uniform_real_distribution<double> distr(1, 10);

	for (int i = 0; i < n; ++i) {

		for (int j = 0; j < 5; ++j) {
			temp_balai.push_back(distr(gen));
		}

		Sukurti_studenta(Studentai, "Vardas" + std::to_string(i), "Pavarde" + std::to_string(i), temp_balai, (int)(distr(gen)));
		temp_balai.clear();
	}
	sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	return Studentai;
}

bool find_split_mark(Items& n) {
	return n.final_med >= 5.0;
}

vector<Items> split_students(vector<Items>& Studentai1) {
	vector<Items> Studentai2;
	Studentai2.reserve(100);
	auto it = std::distance(Studentai1.begin(), std::find_if(Studentai1.begin(), Studentai1.end(), find_split_mark));
	std::move(Studentai1.begin(), Studentai1.begin() + it, std::back_inserter(Studentai2));
	Studentai1.erase(Studentai1.begin(), Studentai1.begin() + it);
	return Studentai2;
}





void writeToFile(vector<Items>& Studentai, string file_name) {
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


void generateFile(vector<Items>& Studentai_kieti, vector<Items>& Studentai_silpni) {
	writeToFile(Studentai_kieti, "OUTPUT_KIETI.txt");
	writeToFile(Studentai_silpni, "OUTPUT_SILPNI.txt");
}



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
			if (cin.fail() || input > 10) throw 1;
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

	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	balai.resize(5); //5 namu darbai
	generate(balai.begin(), balai.end(), []() {
		return (int)(distr(gen));
	});
	egz = (int)distr(gen);
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
