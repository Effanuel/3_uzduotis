#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

using std::string;
using std::vector;

class Items
{
private:
	string vardas_, pavarde_;
	vector<double> balai_;
	double egz_;
public:
	Items() : egz_(0){ }
	Items(string vardas, string pavarde, vector<double> balai, double egz)
		: vardas_(vardas), pavarde_(pavarde), balai_(balai), egz_(egz) {}
	//Items(string filename);
	string vardas() const { return vardas_; }
	string pavarde() const { return pavarde_; }
	double galBalas(double(*) (vector<double>)) const;//+

};

template <typename T> void Sukurti_studenta(T&, string, string, vector<double>, double);


bool cool_students_sort(const Items&);//+
bool final_mark_sorting(const Items &, const Items &);//+
int max_len(vector<string>);//+
bool alphabetical_sorting(const Items &, const Items &);//+



