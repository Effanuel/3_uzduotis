#pragma once
#include <string>
#include <utility>

using std::string;

/**
Zmogus base objektas
*/
class Zmogus {
protected:
	///Studento vardas
	string vardas_;
	///Studento pavarde
	string pavarde_;
	
public:
	///Konstruoja Zmogus objekta
	Zmogus(string v = "", string p = "") : vardas_(v), pavarde_(p) {}
	///Zmogus objeckto copy constructor'ius
	Zmogus(const Zmogus& p) : vardas_{ p.vardas_ }, pavarde_{ p.pavarde_ } {}
	///Zmogus objeckto move constructor'ius
	Zmogus(Zmogus&& a) noexcept : vardas_{ std::move(a.vardas_) }, pavarde_{ std::move(a.pavarde_) } {} //VS19 warning about no except
	///Zmogus priskyrimo operatorius (Rule of 5)
	Zmogus& operator=(const Zmogus& s) {
		if (&s == this) return *this;

		vardas_ = s.vardas_;
		pavarde_ = s.pavarde_;
		return *this;
	}
	///Padaro Zmogus class'e abstrakcia
	virtual void writeToFile(string file_name, std::ofstream& failas) = 0; //makes Zmogus class abstract

	///Grazina zmogaus varda
	string vardas() const { return vardas_; }
	///Grazina zmogaus pavarde
	string pavarde() const { return pavarde_; }

};                          