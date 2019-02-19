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
	cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n" << std::string(35, '=') << endl;
	
	int max_vardas{}, max_pavarde{};  //reikia, kad formatavimas butu lengvesnis
	vector<string> vardai{}, pavardes{}; //

	vector<Items> Studentai{};
	vector<int> balai{};
	balai.reserve(2);


	char choice{};
	cout << "1 - Skaityti data is failo;\n2 - Ivesti data rankomis;"<< endl;
	cin >> choice;
	switch (choice) {
	case '1':
		Failo_nuskaitymas(Studentai, "kursiokai.txt", vardai, pavardes);
		break;
	case '2':
		Duomenu_ivedimas(Studentai, balai, vardai, pavardes);
		break;
	}

	max_vardas = max_len(vardai); //reikia, kad formatavimas butu lengvesnis
	max_pavarde = max_len(pavardes);

	Print_table(Studentai, max_vardas, max_pavarde);
	
	


}