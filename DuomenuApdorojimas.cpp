#include "mano_func.h"
#include "Algoritmai.h"


int main()
{
	cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n" << std::string(40, '=') << endl;

	int choice;
	cout << "1 - Skaityti data is failo;\n2 - Ivesti data rankomis;\n3 - Sugeneruos failus is 10,000 studentu;\n4 - STL container'iu greiciu testavimas\n" << std::string(40, '=') << endl;
	choice = cin_and_checkFormat_in_interval(1, 4);
	constexpr int strategija = 2;
	try {
		switch (choice) {
		case 1:
			Failo_nuskaitymas<vector<Items>>("kursiokai.txt");
			break;
		case 2:
			Duomenu_ivedimas<vector<Items>>();
			break;
		case 3: 
			Failo_generavimas_v2<vector<Items>>("OUTPUT.txt", 1e4); // generate file
			Failo_nuskaitymas<vector<Items>>("OUTPUT.txt", "neprint", "skirstyti"); //split file
			cout << "Done." << endl;
			break;
		case 4: {
			Failo_generavimas_v2<vector<Items>>("OUTPUT.txt", 1e5); 
			Timer laikas;

			laikas.reset(); //start
			Failo_nuskaitymas<vector<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Strategija:(" << strategija << "):Suskirstymas <vector>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end

		
			laikas.reset();//start
			Failo_nuskaitymas<list<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Strategija:(" << strategija << "):Suskirstymas <list>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end

			laikas.reset();//start
			Failo_nuskaitymas<deque<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Strategija:(" << strategija << "):Suskirstymas <deque>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end
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

//-----TESTING TOOL------
//vector<long double> laikai1;
//vector<long double> laikai2;
//vector<long double> laikai3;
//for (int i = 0; i < 10; ++i) {
//	laikas.reset();
//	Failo_nuskaitymas<vector<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
//	laikai1.emplace_back(laikas.elapsed());
//
//	laikas.reset();
//	Failo_nuskaitymas<list<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
//	laikai2.emplace_back(laikas.elapsed());
//
//	laikas.reset();
//	Failo_nuskaitymas<deque<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
//	laikai3.emplace_back(laikas.elapsed());
//}
//
//cout << "Praejo (n = 10,000): " << std::accumulate(laikai1.begin(), laikai1.end(), 0.0) / 10 << endl;
//cout << "Praejo (n = 10,000): " << std::accumulate(laikai2.begin(), laikai2.end(), 0.0) / 10 << endl;
//cout << "Praejo (n = 10,000): " << std::accumulate(laikai3.begin(), laikai3.end(), 0.0) / 10 << endl;