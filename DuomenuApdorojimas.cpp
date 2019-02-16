#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <numeric> //accumulate
#include <algorithm> //sort
#include <ctime> //time(NULL)
#include <stdlib.h> //rand, sran
#include <fstream>
#include <sstream>
#include <iterator>

#include "mano_func.h" //cin_and_checkFormat(); ar_atsitiktinis();  median(); compareByFirstLetter(); find_longer_word()






int main()
{

	
	cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n";
	cout << std::string(35, '=') << endl;

	char read;
	cout << "Skaityti data is failo?(y/n)" << endl;
	cin >> read;

	int max_vardas;  //reikia, kad formatavimas butu lengvesnis
	int max_pavarde;
	vector<Items> Studentai;
	if (read == 'y' || read == 'Y') {
		vector<string> vardai;
		vector<string> pavardes;
		Studentai = fail_work("kursiokai.txt", vardai, pavardes);

		max_vardas = max_len(vardai); //reikia, kad formatavimas butu lengvesnis
		max_pavarde = max_len(pavardes);
	}
	else {
		string vardas;
		string pavarde;
		cout << "Iveskite mokinio varda ir pavarde: " << endl;
		cin >> vardas >> pavarde;


		char is_random;
		cout << "Ar norite, kad balai butu generuojami atsitiktinai?(y/n)" << endl;
		cin >> is_random;


		int egz;
		vector<int> balai;
		balai.reserve(2);
		ar_atsitiktinis(is_random, balai, egz);

		size_t dydis_balu = balai.size() != 0 ? balai.size() : 1;
		const double galutinis_vid = 0.4 * std::accumulate(balai.begin(), balai.end(), 0.0) / dydis_balu + 0.6 * egz;
		const double galutinis_med = 0.4 * median(balai, dydis_balu) + 0.6 * egz;

		
		Studentai.push_back({ vardas, pavarde, galutinis_med, galutinis_vid, egz });  //vieno studento data

		max_vardas = vardas.length(); //reikia, kad formatavimas butu lengvesnis
		max_pavarde = pavarde.length();
	}








	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*s %s\n", -int(max_pavarde) - 7, "Pavarde", -int(max_vardas) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());

	for (auto& line : Studentai) {
		printf("%*s %*s %*.2f %.2f\n", -int(max_pavarde) - 7, line.pavarde.c_str(), -int(max_vardas) - 7, line.vardas.c_str(), -19, line.final_vid, line.final_med);
	}
	printf("%s\n", std::string((max_pavarde + max_vardas) + 14 + 14 + 12 + 8, '-').c_str());
	
	


}