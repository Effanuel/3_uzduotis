#pragma once
#include "Zmogus.h"
#include "median.h"

#include <fstream>
#include <numeric>
#include <algorithm>
#include <random>
#include <iomanip> 
#include <iostream>

using std::vector;


class Student : public Zmogus
{
private:
	vector<double> balai_;
	double egz_;
public:
	Student() : Zmogus(), egz_(0) { }
	Student(string vardas, string pavarde, vector<double> balai, double egz) //copy constr, called on emplace_back
		: Zmogus(vardas, pavarde), balai_(balai), egz_(egz) {}

	Student(const Student& v) //copy constr
		: Zmogus(v), balai_{ v.balai_ }, egz_{ v.egz_ } {}

	//Student(Student&& a) : Zmogus(a), balai_{ std::move(a.balai_) }, egz_{ std::move(a.egz_) } {}
	
	double egz() const { return egz_; }
	vector<double> balai() const { return balai_; }
	double galBalas(double(*kriterijus) (vector<double>) = median) const;

	friend bool operator==(const Student&, const Student&);
	friend bool operator!=(const Student&, const Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
	
	Student& operator=(const Student&);

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


