#pragma once
#include "Zmogus.h"
#include "median.h"

#include <fstream>
#include <numeric>
#include <algorithm>
#include <random>
#include <iomanip> 
#include <iostream>



/**
Studentas : Zmogus objektas
*/
class Student : public Zmogus
{
private:
	///Studento namu darbu balai (5)
	vector<double> balai_;
	///Studento egzamino balas
	double egz_;
public:
	///Konstruoja Studentas objekta
	Student() : Zmogus(), egz_(0) { }
	///Studento objeckto copy constructor'ius skirtas emplace_back
	Student(string vardas, string pavarde, vector<double> balai, double egz) //copy constr, called on emplace_back
		: Zmogus(vardas, pavarde), balai_(balai), egz_(egz) {}
	///Studento objeckto copy constructor'ius
	Student(const Student& v) //copy constr
		: Zmogus(v), balai_{ v.balai_ }, egz_{ v.egz_ } {}
	///Studento objeckto move constructor'ius
	Student(Student&& a) noexcept : Zmogus(a), balai_{ std::move(a.balai_) }, egz_{ std::move(a.egz_) } {} //VS19 warning about no except
	///Grazina egzamino bala
	double egz() const { return egz_; }
	///Grazina namu darbu balus
	vector<double> balai() const { return balai_; }
	///Skaiciuoja galutini bala pagal mediana arba vidurki (default mediana)
	double galBalas(double(*kriterijus) (vector<double>) = median) const;
	///Tikrina ar Studentu objektai sutampa
	friend bool operator==(const Student&, const Student&);
	///Tikrina ar Studentu objektai nesutampa
	friend bool operator!=(const Student&, const Student&);
	///Operatorius skirtas rankiniam Studento objekto ivedimui
	friend std::ostream& operator<<(std::ostream&, const Student&);
	///Operatorius skirtas rankiniam Studento objekto isvedimui
	friend std::istream& operator>>(std::istream&, Student&);
	///Studento priskyrimo operatorius (Rule of 5)
	Student& operator=(const Student&);
	///Iraso Studentas objekto duomenis i faila
	void writeToFile(string file_name, std::ofstream& failas);
	///Generuoja atsitiktini Studenta objekta
	void randomStudent();



};

///Patikrina ar ivestas skaicius yra tinkamas balo formatas (tarp 1 ir 10)
double cin_and_checkFormat_in_interval(std::istream&);
///Zodzio ivedimo ir formato patikrinimo funkcija
string cin_and_checkFormat(std::istream&);
///Pagalbine funkcija studentu sort'inimui i kietus ir levus
bool final_mark_sorting(const Student &, const Student &);//+
///Pagalbine funkcija studentu sort'inimui abeceles tvarka
bool alphabetical_sorting(const Student &, const Student &);//+
///Iskviecia copy constructor'iu ir sukuria viena studenta
template <typename T> void Sukurti_studenta(T&, string, string, vector<double>, double);
//--------------------
template <typename T> void Sukurti_studenta(T& Studentai, string vardas, string pavarde, vector<double> balai, double egz) { //&
	Studentai.emplace_back(vardas, pavarde, balai, egz);
}


