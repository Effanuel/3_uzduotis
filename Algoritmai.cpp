#include "Algoritmai.h"

namespace Custom {
	void sort(vector<Items>& Studentai) {
		sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	}
	void sort(list<Items>& Studentai) {
		Studentai.sort(final_mark_sorting);
	}
	void sort(deque<Items>& Studentai) {
		sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	}
}


double median(std::vector<int> arr, size_t size, int egz) {
	if (arr.empty()) return 0.6 * egz + 0.4;
	sort(arr.begin(), arr.end());
	const double med = size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;
	return 0.4 * med + 0.6 * egz;
}

double vidurkis(std::vector<int> arr, size_t size, int egz) {
	if (arr.empty()) return 0.6 * egz + 0.4;
	const double vid = std::accumulate(arr.begin(), arr.end(), 0.0) / size;
	return 0.4 * vid + 0.6 * egz;
}



bool cool_students_sort(const Items& n) {
	return n.final_med >= 5.0;
}

bool final_mark_sorting(const Items &a, const Items &b) //sortina pagal medianos galutini bala
{
	return a.final_med < b.final_med;
}

int max_len(vector<string> data) { //suranda ilgiausia varda/pavarde

	auto func = [](const string &a, const string &b) {return a.size() < b.size(); };
	return (*std::max_element(data.begin(), data.end(), func)).size();
}


bool alphabetical_sorting(const Items &a, const Items &b) //sortina pagal abecele
{
	return a.pavarde < b.pavarde;
}
