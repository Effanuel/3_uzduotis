#include "Studentas.h"

double median(vector<double> arr) {
	typedef vector<double>::size_type vecSize;
	vecSize size = arr.size();
	std::sort(arr.begin(), arr.end());
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;

}


double vidurkis(vector<double> arr) {

	return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}


double Student::galBalas(double(*kriterijus)(vector<double>)) const {
	if (balai_.empty()) throw std::domain_error("negalima skaiciuoti tusciam vektoriui");
	return 0.6 * kriterijus(balai_) + 0.4 * egz_;
}

void Student::randomStudent() {
	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	vardas_ = "Vardas" + std::to_string(int(distr(gen)*10001)); //pseudo unique numbers
	pavarde_ = "Pavarde" + std::to_string(int(distr(gen)*9999));
	balai_.resize(5); //5 namu darbai
	generate(balai_.begin(), balai_.end(), []() {
		return distr(gen);
	});
	egz_ = distr(gen);
}


void Student::writeToFile(string filename, std::ofstream& failas) {
	failas << '\n' << vardas() << '\t' << pavarde() << '\t';
	for (auto& balas : balai()) {
		failas << std::setprecision(3) << balas << '\t';
	}
	failas << std::setprecision(3) << egz();
}

bool operator==(const Student& a, const Student& b) {
	return a.galBalas() == b.galBalas();

}




//namespace Custom {
//	void sort(vector<Student>& Studentai) {
//		std::sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
//	}
//	//void sort(list<Student>& Studentai) {
//	//	Studentai.sort(final_mark_sorting);
//	//}
//	//void sort(deque<Student>& Studentai) {
//	//	sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
//	//}
//}



bool final_mark_sorting(const Student &a, const Student &b) //sortina pagal medianos galutini bala
{
	return a.galBalas() < b.galBalas();
}

int max_len(vector<string> data) { //suranda ilgiausia varda/pavarde

	auto func = [](const string &a, const string &b) {return a.size() < b.size(); };
	return (*std::max_element(data.begin(), data.end(), func)).size();
}


bool alphabetical_sorting(const Student &a, const Student &b) //sortina pagal abecele
{
	return a.pavarde() < b.pavarde();
}
