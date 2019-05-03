#pragma once
#include <string>
#include <utility>

using std::string;

class Zmogus {
protected:
	string vardas_;
	string pavarde_;
	
public:
	Zmogus(string v = "", string p = "") : vardas_(v), pavarde_(p) {}
	Zmogus(const Zmogus& p) : vardas_{ p.vardas_ }, pavarde_{ p.pavarde_ } {}
	Zmogus(Zmogus&& a) noexcept : vardas_{ std::move(a.vardas_) }, pavarde_{ std::move(a.pavarde_) } {} //VS19 warning about no except

	Zmogus& operator=(const Zmogus& s) {
		if (&s == this) return *this;

		vardas_ = s.vardas_;
		pavarde_ = s.pavarde_;
		return *this;
	}
	virtual void writeToFile(string file_name, std::ofstream& failas) = 0; //makes Zmogus class abstract


	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }

};                          