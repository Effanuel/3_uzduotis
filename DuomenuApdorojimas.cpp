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
	cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n" << std::string(38, '=') << endl;
	
	int max_vardas{}, max_pavarde{};  //reikia, kad formatavimas butu lengvesnis
	vector<string> vardai{}, pavardes{}; //

	vector<Items> Studentai1;
	vector<Items> Studentai2;
	vector<int> balai{};
	balai.reserve(2);
	



	char choice{};
	cout << "1 - Skaityti data is failo;\n2 - Ivesti data rankomis;\n3 - Sugeneruos faila is 'n' studentu;\n" << std::string(38, '=') << endl;
	cin >> choice;
	switch (choice) {
	case '1':
		Failo_nuskaitymas(Studentai1, "kursiokai.txt", vardai, pavardes);
		break;
	case '2':
		Duomenu_ivedimas(Studentai1, balai, vardai, pavardes);
		break;
	case '3':
		Timer laikas;
		Studentai1 = generateStudents(10);
		Studentai2 = split_students(Studentai1);
		generateFile(Studentai1, Studentai2);
		cout << "Praejo (n = 10): " << laikas.elapsed() << endl;

		laikas.reset();
		Studentai1 = generateStudents(100);
		Studentai2 = split_students(Studentai1);
		generateFile(Studentai1, Studentai2);
		cout << "Praejo (n = 100): " << laikas.elapsed() << endl;

		laikas.reset();
		Studentai1 = generateStudents(1000);
		Studentai2 = split_students(Studentai1);
		generateFile(Studentai1, Studentai2);
		cout << "Praejo (n = 1000): " << laikas.elapsed() << endl;

		laikas.reset();
		Studentai1 = generateStudents(10000);
		Studentai2 = split_students(Studentai1);
		generateFile(Studentai1, Studentai2);
		cout << "Praejo (n = 10000): " << laikas.elapsed() << endl;

		laikas.reset();
		Studentai1 = generateStudents(100000);
		Studentai2 = split_students(Studentai1);
		generateFile(Studentai1, Studentai2);
		cout << "Praejo (n = 100000): " << laikas.elapsed() << endl;

		laikas.reset();
		Studentai1 = generateStudents(1000000);
		Studentai2 = split_students(Studentai1);
		generateFile(Studentai1, Studentai2);
		cout << "Praejo (n = 1000000): " << laikas.elapsed() << endl;
		exit(1);
	}

	max_vardas = max_len(vardai); //reikia, kad formatavimas butu lengvesnis
	max_pavarde = max_len(pavardes);

	Print_table(Studentai1, max_vardas, max_pavarde);

	
	
	


}