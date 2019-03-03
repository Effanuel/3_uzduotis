#include "mano_func.h"


namespace Custom {
	void sort(vector<Items>& Studentai) {
		std::sort(Studentai.begin(), Studentai.end(), final_mark_sorting);
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



void random_num_generator(vector<int>& balai, int& egz) {

	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	balai.resize(5); //5 namu darbai
	generate(balai.begin(), balai.end(), []() {
		return (int)(distr(gen));
	});
	egz = (int)distr(gen);
}

bool find_split_mark(Items& n) {
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

int cin_and_checkFormat_in_interval(int a, int b) {
	int input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas balo formatas. Iveskite is naujo: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}

void Rankinis_ivedimas(vector<int>& balai, int& egz) {

	cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << endl;
	int ndbalai{};
	while (cin >> ndbalai && ndbalai != 0) { //int(ndbalai)
		balai.push_back(ndbalai);
	}
	if (balai.empty()) { //error handling
		balai.resize(1); 
	}
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Egzamino rezultatas: " << endl;
	egz = cin_and_checkFormat_in_interval(1, 10);

}




