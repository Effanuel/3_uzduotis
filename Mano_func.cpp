#include "mano_func.h"


void random_num_generator(vector<int>& balai, int& egz) {

	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_int_distribution<int> distr(1, 10);

	balai.resize(5); //5 namu darbai
	generate(balai.begin(), balai.end(), []() {
		return distr(gen);
	});
	egz = distr(gen);
}


int cin_and_checkFormat_in_interval(int a, int b) {
	unsigned int input;
	while (!(cin >> input) || a > input || input > b) {
		std::cout << "Netinkamas balo formatas. Iveskite is naujo: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	return input;
}

void Rankinis_ivedimas(vector<int>& balai, int& egz) {

	cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << endl;
	unsigned int ndbalai{};
	while (cin >> ndbalai && ndbalai != 0 && ndbalai < 10) { //int(ndbalai)
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




