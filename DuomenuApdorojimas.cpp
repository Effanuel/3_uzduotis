#include "mano_func.h"
#include "Algoritmai.h"



int main()
{
	//cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n" << std::string(40, '=') << endl;
	cout << std::string(40, '=') << endl;

	int choice;
	cout << "1 - Ivesti data rankomis;\n2 - Skaityti data is failo;\n3 - Sugeneruos failus is 10,000 studentu;\n4 - STL container'iu greiciu testavimas\n" << std::string(40, '=') << endl;
	choice = cin_and_checkFormat_in_interval(1, 4);
	constexpr int strategija = 1;
	try {
		switch (choice) {
		case 1:
			Duomenu_ivedimas<vector<Items>>();
			break;
		case 2:
			Failo_nuskaitymas<vector<Items>>("kursiokai.txt");
			break;
		case 3: 
			Failo_generavimas_v2<vector<Items>>("OUTPUT.txt", 1e4); // generate file
			Failo_nuskaitymas<vector<Items>>("OUTPUT.txt", "neprint", "skirstyti"); //split file
			cout << "Done." << endl;
			break;
		case 4: {
			Failo_generavimas_v2<vector<Items>>("OUTPUT.txt", 1e5); 
			Timer laikas;

			Failo_nuskaitymas<vector<Items>>("output.txt", "neprint", "skirstyti", strategija);
			cout << "strategija:(" << strategija << "):suskirstymas <vector>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end

			laikas.reset();//start
			Failo_nuskaitymas<list<Items>>("output.txt", "neprint", "skirstyti", strategija);
			cout << "strategija:(" << strategija << "):suskirstymas <list>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end

			laikas.reset();//start
			Failo_nuskaitymas<deque<Items>>("output.txt", "neprint", "skirstyti", strategija);
			cout << "strategija:(" << strategija << "):suskirstymas <deque>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end
			break;
		}
		default:
			cout << "Nepavyko pasirinkti" << endl;
			break;
		}
	}
	catch (const std::runtime_error& e) {
		cout << e.what() << endl;
		exit(0);
	}
}

//-----TESTING TOOL------
//vector<long double> laikai1;
//vector<long double> laikai2;
//vector<long double> laikai3;
//for (int i = 0; i < 20; ++i) {
//	laikas.reset();
//	Failo_nuskaitymas<vector<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
//	laikai1.push_back(laikas.elapsed());
//
//	laikas.reset();
//	Failo_nuskaitymas<list<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
//	laikai2.push_back(laikas.elapsed());
//
//	laikas.reset();
//	Failo_nuskaitymas<deque<Items>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
//	laikai3.push_back(laikas.elapsed());
//}
//
//cout << std::accumulate(laikai1.begin(), laikai1.end(), 0.0) / 20 << endl;
//cout << std::accumulate(laikai2.begin(), laikai2.end(), 0.0) / 20 << endl;
//cout << std::accumulate(laikai3.begin(), laikai3.end(), 0.0) / 20 << endl;