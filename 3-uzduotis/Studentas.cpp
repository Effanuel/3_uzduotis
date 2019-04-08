#include "Studentas.h"

//PATCH
//egz final med vid updated to double
//sukurti studenta uses emplace back instead of pushback

double median(vector<double> arr) {
	typedef vector<double>::size_type vecSize;
	vecSize size = arr.size();
	std::sort(arr.begin(), arr.end());
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;

}


double vidurkis(std::vector<double> arr) {

	return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}


double Items::galBalas(double(*)(vector<double>)) const {
	if (balai_.empty()) throw std::domain_error("negalima skaiciuoti tusciam vektoriui");
	return 0.6 * median(balai_) + 0.4 * egz_;
}

void Items::randomStudent() {
	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	vardas_ = "Vardas" + std::to_string(distr(gen));
	pavarde_ = "Pavarde" + std::to_string(distr(gen));
	balai_.resize(5); //5 namu darbai
	generate(balai_.begin(), balai_.end(), []() {
		return distr(gen);
	});
	egz_ = distr(gen);
}


void Items::writeToFile(string filename, std::ofstream& failas) {
	failas << '\n' << vardas() << '\t' << pavarde() << '\t';
	for (auto& balas : balai()) {
		failas << std::setprecision(3) << balas << '\t';
	}
	failas << std::setprecision(3) << egz();
}


//namespace Custom {
//	void sort(vector<Items>& Studentai) {
//		std::sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
//	}
//	//void sort(list<Items>& Studentai) {
//	//	Studentai.sort(final_mark_sorting);
//	//}
//	//void sort(deque<Items>& Studentai) {
//	//	sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
//	//}
//}



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