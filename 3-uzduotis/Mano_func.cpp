#include "mano_func.h"



void random_num_generator(vector<double>& balai, double& egz) {

	static std::mt19937 gen;
	gen.seed(std::random_device()());
	static std::uniform_real_distribution<double> distr(1, 10);

	balai.resize(5); //5 namu darbai
	generate(balai.begin(), balai.end(), []() {
		return distr(gen);
	});
	egz = distr(gen);
}

//

string cin_and_checkFormat() { //v1.07
	string name;
	do {
		cin >> name;
		for (auto &r : name) {
			if (toupper(r) < 'A' || toupper(r) > 'Z') {
				std::cout << "Netinkamas vardo formatas formatas. Iveskite is naujo: " << endl;
				cin.clear();
				name.clear(); //erases 'name' contents
				cin.ignore(1000, '\n');
				break;
			}
		}
	} while (name == "");
	return name;
}

void Rankinis_ivedimas(vector<double>& balai, double& egz) {

	cout << "Iveskite namu darbu rezultatus(0 arba raide sustabdys ivedinejima): " << endl;
	double ndbalai;
	while (cin >> ndbalai && ndbalai != 0 && ndbalai < 10 && ndbalai > 0) { //int(ndbalai)
		balai.push_back(ndbalai);
	}
	if (balai.empty()) { //error handling
		balai.resize(1); 
	}
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Egzamino rezultatas: " << endl;
	egz = cin_and_checkFormat_in_interval<double>(1, 10);

}