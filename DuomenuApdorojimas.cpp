#include "mano_func.h"


int main()
{
	cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n" << std::string(38, '=') << endl;

	//reikia, kad formatavimas butu lengvesnis
	vector<string> vardai{}, pavardes{}; //

	vector<Items> Studentai2;
	vector<int> balai{};
	balai.reserve(2);

	int choice;
	cout << "1 - Skaityti data is failo;\n2 - Ivesti data rankomis;\n3 - Sugeneruos faila is 'n' studentu;\n" << std::string(38, '=') << endl;
	choice = cin_and_checkFormat_in_interval(1, 3);
	try {
		switch (choice) {
		case 1:
			Failo_nuskaitymas<vector<Items>>("kursiokai.txt");
			break;
		case 2:
			Duomenu_ivedimas<vector<Items>>();
			break;
		case 3: {

			Timer laikas;
			Failo_generavimas<vector<Items>>(1e4);
			cout << "Praejo (n = 10,000): " << laikas.elapsed() << endl;

			laikas.reset();
			Failo_generavimas<list<Items>>(1e4);
			cout << "Praejo (n = 10,000): " << laikas.elapsed() << endl;

			laikas.reset();
			Failo_generavimas<deque<Items>>(1e4);
			cout << "Praejo (n = 10,000): " << laikas.elapsed() << endl;
			break;
		}
		default:
			cout << "Nepavyko pasirinkti" << endl;
			break;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		exit(0);
	}
}