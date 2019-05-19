#include "Studentas.h"

//--------------------
double median(std::vector<double> arr) {
	//typedef std::vector<double>::size_type vecSize;
	std::size_t size = arr.size();
	std::sort(arr.begin(), arr.end());
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;

}
//--------------------
double vidurkis(std::vector<double> arr) {
	return std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
}
//--------------------
double Student::galBalas(double(*kriterijus)(std::vector<double>)) const {
	if (balai_.empty()) throw std::domain_error("negalima skaiciuoti tusciam vektoriui");
	return 0.6 * kriterijus(balai_) + 0.4 * egz_;
}
//--------------------
void Student::randomStudent() {
	static std::mt19937 gen(0);
	//gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	vardas_ = "Vardas" + std::to_string(int(distr(gen)*10001)); //pseudo unique numbers
	pavarde_ = "Pavarde" + std::to_string(int(distr(gen)*9999));
	balai_.resize(5); //5 namu darbai
	std::generate(balai_.begin(), balai_.end(), []() {
		return distr(gen);
	});
	egz_ = distr(gen);
}
//--------------------
void Student::writeToFile(string filename, std::ofstream& failas) {
	failas << '\n' << vardas() << '\t' << pavarde() << '\t';
	for (auto& balas : balai()) {
		failas << std::setprecision(3) << balas << '\t';
	}
	failas << std::setprecision(3) << egz();
}
//--------------------
Student& Student::operator=(const Student& s) {
	if (&s == this) return *this;

	Zmogus::operator=(s);

	balai_ = s.balai_;
	egz_ = s.egz_;

	
	return *this;

}
//--------------------
bool operator==(const Student& a, const Student& b) {
	return a.galBalas() == b.galBalas();
}
//--------------------
bool operator!=(const Student& a, const Student& b) {
	return a.galBalas() != b.galBalas();
}
//--------------------
std::ostream& operator<<(std::ostream& out, const Student& stud) {
	out << stud.vardas() << '\t' << stud.pavarde() << '\t';
	for (auto& balas : stud.balai()) {
		out << std::setprecision(3) << balas << '\t';
	}
	out << std::setprecision(3) << stud.galBalas();
	return out;
}
//--------------------
std::istream& operator>>(std::istream& in, Student& stud) {
	std::cout << "Iveskite mokinio varda ir pavarde: " << std::endl;
	stud.vardas_ = cin_and_checkFormat(in);
	stud.pavarde_ = cin_and_checkFormat(in);

	double ndbalai;
	std::cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << std::endl;
	while (in >> ndbalai && ndbalai != 0 && ndbalai < 10 && ndbalai > 0) { //int(ndbalai)
		stud.balai_.push_back(ndbalai);
	}
	if (stud.balai_.empty()) { //error handling
		stud.balai_.resize(1);
	}
	in.clear();
	in.ignore(1000, '\n'); // nepersoka i return
	std::cout << "Egzamino rezultatas(1-10): " << std::endl;
	stud.egz_ = cin_and_checkFormat_in_interval(in);
	return in;
	
}
//--------------------
string cin_and_checkFormat(std::istream& in) {
	string name;
	do {
		in >> name;
		for (auto& r : name) {
			if (toupper(r) < 'A' || toupper(r) > 'Z') {
				std::cout << "Netinkamas vardo formatas formatas. Iveskite is naujo: " << std::endl;
				in.clear();
				name.clear(); //erases 'name' contents
				in.ignore(1000, '\n');
				break;
			}
		}
	} while (name == "");
	return name;
}
//--------------------
double cin_and_checkFormat_in_interval(std::istream& in) {
	double input;
	while (!(std::cin >> input) || 1 > input || input > 10) {
		std::cout << "Netinkamas ivesties formatas. Iveskite is naujo: " << std::endl;
		in.clear();
		in.ignore(1000, '\n');
	}
	return input;
}

namespace Custom {
	void sort(std::vector<Student>& Studentai) {
		std::sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	}
	//void sort(list<Student>& Studentai) {
	//	Studentai.sort(final_mark_sorting);
	//}
	//void sort(deque<Student>& Studentai) {
	//	sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
	//}
}

//--------------------
bool final_mark_sorting(const Student &a, const Student &b)
{
	return a.galBalas() < b.galBalas();
}
//--------------------
int max_len(std::vector<string> data) { 

	auto func = [](const string &a, const string &b) {return a.size() < b.size(); };
	return (*std::max_element(data.begin(), data.end(), func)).size();
}
//--------------------
bool alphabetical_sorting(const Student &a, const Student &b)
{
	return a.pavarde() < b.pavarde();
}
