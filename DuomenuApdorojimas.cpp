#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <numeric> //accumulate
#include <algorithm> //sort
#include <ctime> //time(NULL)
#include <stdlib.h> //rand, srand

using std::cout;
using std::cin;
using std::endl;

int egz;
std::vector<int> nd;

double median(int, std::vector<int>);
void ar_atsitiktinis(char);


int main()
{
	std::string vardas;
	std::string pavarde;
	cout << "Iveskite varda ir pavarde mokinio: " << endl;
	cin >> vardas >> pavarde;

	char atsitiktinis;
	cout << "Ar norite, kad balai butu generuojami atsitiktinai?(y/n)" << endl;
	cin >> atsitiktinis;

	srand(time(NULL));
	ar_atsitiktinis(atsitiktinis);



	size_t size = nd.size();
	const double mediana = median(size, nd);
	const double vidurkis = std::accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
	const double galutinis_vid = 0.4 * vidurkis + 0.6 * egz;
	const double galutinis_med = 0.4 * mediana + 0.6 * egz;

	printf("%*s %*s %*s %s\n", -int(pavarde.length()) -7, "Pavarde", -int(vardas.length()) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string(int(pavarde.length()) + int(vardas.length()) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*.2f %.2f\n", -int(pavarde.length()) - 7, pavarde.c_str(), -int(vardas.length()) - 7, vardas.c_str(), -19, galutinis_vid, galutinis_med);


}




void ar_atsitiktinis(char a) {
	if (a == 'y') {
		nd.resize(5); //5 namu darbai
		std::generate(nd.begin(), nd.end(), []() {
			return rand() % 10 + 1;
		});
		egz = rand() % 10 + 1;
	}
	else {
		int input;
		cout << "Namu darbu rezultatai(iveskite 0 arba raide, kad nustoti ivedineti): " << endl;
		while (cin >> input && input != 0 && int(input)) {
			nd.push_back(input);
		}
		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Egzamino rezultatas: " << endl;
		cin >> egz;

	}
}


double median(int size, std::vector<int> arr) {
	std::sort(arr.begin(), arr.end()); //medianai
	return size % 2 != 0 ? arr[size / 2] : (arr[size / 2 - 1] + arr[size / 2]) / 2;
}
