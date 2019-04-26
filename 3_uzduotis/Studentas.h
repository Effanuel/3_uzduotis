#pragma once
#include "median.h"

#include <string>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <random>
#include <iomanip> 
#include <iostream>

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
	Student(string vardas, string pavarde, vector<double> balai, double egz) //copy constr
		: vardas_(vardas), pavarde_(pavarde), balai_(balai), egz_(egz) {}
	//Student(Student&& a) noexcept //move constr
	//	: vardas_(a.vardas_), pavarde_(a.pavarde_), balai_(std::move(a.balai_)), egz_(a.egz_) {}
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	double egz() const { return egz_; }
	vector<double> balai() const { return balai_; }
	double galBalas(double(*kriterijus) (vector<double>) = median) const;

	friend bool operator==(const Student&, const Student&);
	friend bool operator!=(const Student&, const Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
	
	void writeToFile(string file_name, std::ofstream& failas);
	void randomStudent();



};


double cin_and_checkFormat_in_interval(std::istream&);
string cin_and_checkFormat(std::istream&);
bool final_mark_sorting(const Student &, const Student &);//+
bool alphabetical_sorting(const Student &, const Student &);//+

template <typename T> void Sukurti_studenta(T&, string, string, vector<double>, double);

template <typename T> void Sukurti_studenta(T& Studentai, string vardas, string pavarde, vector<double> balai, double egz) { //&
	Studentai.emplace_back(vardas, pavarde, balai, egz);
}


