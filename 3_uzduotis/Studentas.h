#pragma once
#include "median.h"

#include <string>
//#include <vector> 'median'
#include <fstream>
#include <numeric>
#include <algorithm>
#include <random>
#include <iomanip> 

using std::string;
using std::vector;


class Student
{
private:
	string vardas_, pavarde_;
	vector<double> balai_;
	double egz_;
public:
	Student() : egz_(0) { }
	Student(string vardas, string pavarde, vector<double> balai, double egz)
		: vardas_(vardas), pavarde_(pavarde), balai_(balai), egz_(egz) {}
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	double egz() const { return egz_; }
	vector<double> balai() const { return balai_; }
	double galBalas(double(*kriterijus) (vector<double>) = median) const;


	void writeToFile(string file_name, std::ofstream& failas);
	void randomStudent();

};



template <typename T> void Sukurti_studenta(T&, string, string, vector<double>, double);

bool final_mark_sorting(const Student &, const Student &);//+
bool alphabetical_sorting(const Student &, const Student &);//+



template <typename T> void Sukurti_studenta(T& Studentai, string vardas, string pavarde, vector<double> balai, double egz) { //&
	Studentai.emplace_back(vardas, pavarde, balai, egz);
}


