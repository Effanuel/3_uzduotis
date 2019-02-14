#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <numeric> //accumulate
#include <algorithm> //sort
#include <ctime> //time(NULL)
#include <stdlib.h> //rand, srand
#include "mano_func.h" //cin_and_checkFormat(); ar_atsitiktinis();  median()


int main()
{

	cout << "Ivedus mokinio varda, pavarde, n namu darbu balus\nir egzamino bala bus isvedama lentele\n";
	cout << std::string(35, '=') << endl;

	std::string vardas;
	std::string pavarde;
	cout << "Iveskite varda ir pavarde mokinio: " << endl;
	cin >> vardas >> pavarde;

	int dydis;
	cout << "Iveskite namu darbu kieki: " << endl;
	dydis = cin_and_checkFormat();
	int *nd = new int[dydis];

	char atsitiktinis;
	cout << "Ar norite, kad balai butu generuojami atsitiktinai?(y/n)" << endl;
	cin >> atsitiktinis;

	srand(time(NULL));

	int egz;
	ar_atsitiktinis(atsitiktinis, nd, dydis, egz);



	//size_t size = nd.size();
	const double mediana = median(nd, dydis);
	const double vidurkis = std::accumulate(nd, nd+dydis, 0.0) / dydis;
	const double galutinis_vid = 0.4 * vidurkis + 0.6 * egz;
	const double galutinis_med = 0.4 * mediana + 0.6 * egz;

	delete[] nd;
	nd = NULL;

	printf("%*s %*s %*s %s\n", -int(pavarde.length()) -7, "Pavarde", -int(vardas.length()) - 7, "Vardas", -19, "VidGalutinis", "MedGalutinis");
	printf("%s\n", std::string(int(pavarde.length()) + int(vardas.length()) + 14 + 14 + 12 + 8, '-').c_str());
	printf("%*s %*s %*.2f %.2f\n", -int(pavarde.length()) - 7, pavarde.c_str(), -int(vardas.length()) - 7, vardas.c_str(), -19, galutinis_vid, galutinis_med);


}