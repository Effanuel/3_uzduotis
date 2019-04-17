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

string cin_and_checkFormat() {
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

bool cool_students_sort(const Student &n) {
	return n.galBalas() >= 5.0;
}


