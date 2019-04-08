#include "Studentas.h"

double median(vector<double> arr) {
	typedef vector<double>::size_type vecSize;
	vecSize size = arr.size();
	std::sort(arr.begin(), arr.end());
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;

}
//PATCH
//egz final med vid updated to double


double vidurkis(std::vector<double> arr) {

	return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}


double Items::galBalas(double(*)(vector<double>) = median) const {
	if (balai_.empty()) throw std::domain_error("negalima skaiciuoti tusciam vektoriui");
	return 0.6 * median(balai_) + 0.4 * egz_;
}



template <typename T> void Sukurti_studenta(T& Studentai, string vardas, string pavarde, vector<double> balai, double egz) { //&
	Studentai.emplace_back(vardas, pavarde, balai, egz);
}







namespace Custom {
	void sort(vector<Items>& Studentai) {
		std::sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	}
	//void sort(list<Items>& Studentai) {
	//	Studentai.sort(final_mark_sorting);
	//}
	//void sort(deque<Items>& Studentai) {
	//	sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	//}
}



bool cool_students_sort(const Items& n) {
	return n.galBalas() >= 5.0;
}

bool final_mark_sorting(const Items &a, const Items &b) //sortina pagal medianos galutini bala
{
	return a.galBalas() < b.galBalas();
}

int max_len(vector<string> data) { //suranda ilgiausia varda/pavarde

	auto func = [](const string &a, const string &b) {return a.size() < b.size(); };
	return (*std::max_element(data.begin(), data.end(), func)).size();
}


bool alphabetical_sorting(const Items &a, const Items &b) //sortina pagal abecele
{
	return a.pavarde() < b.pavarde();
}



//namespace Custom {
//	void sort(vector<Items>& Studentai) {
//		sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
//	}
//	void sort(list<Items>& Studentai) {
//		Studentai.sort(final_mark_sorting);
//	}
//	void sort(deque<Items>& Studentai) {
//		sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
//	}
//}