#pragma once

#include <algorithm> //sort
#include <numeric>
#include <vector>
#include <list>
#include <deque>
#include <string>

using std::sort;
using std::vector;
using std::list;
using std::deque;
using std::string;


struct Items
{
	string vardas, pavarde;
	double final_med, final_vid;
	vector<int> balai;
	int egz;
};

namespace Custom {
	void sort(vector<Items>&);
	void sort(list<Items>&);
	void sort(deque<Items>&);
}



bool alphabetical_sorting(const Items &, const Items &);
bool final_mark_sorting(const Items &, const Items &);
bool cool_students_sort(const Items&);
int max_len(vector<string>);
double median(std::vector<int>, size_t, int);
double vidurkis(std::vector<int>, size_t, int);
