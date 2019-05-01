#include "Functions.h"


int main()
{
	cout << std::string(60, '=') << endl;

	int choice; 
	cout << "1 - Ivesti data rankomis;\n2 - Skaityti data is failo;\n3 - Sugeneruos failus is 100 studentu;\n4 - vector<class Student : public Zmogus> greicio testavimas\n" << std::string(60, '=') << endl;
	choice = cin_and_checkFormat_in_interval<int>(1, 4);
	constexpr int strategija = 1;
	try {
		switch (choice) {
		case 1: {
			//vector<double> vec{ 1, 2, 3, 4 , 5 };
			//Student a{ "a", "b", vec, 5 };
			//Student b;
			//cin >> b;
			//cout << b << endl;
			Duomenu_ivedimas<vector<Student>>();
			break;
		}
		case 2:
			Failo_nuskaitymas<vector<Student>>("kursiokai.txt", "print", "neskirstyti", strategija);
			break;
		case 3:
			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 100); // generate file
			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "print", "skirstyti", strategija); //split file
			cout << "Done." << endl;
			break;
		case 4: {
			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 10000);
			Timer laikas;

			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Suskirstymas <vector>\t(n = 10,000): " << laikas.elapsed() << " s" << endl; //end
			
			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 100000);
			laikas.reset();
			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Suskirstymas <vector>\t(n = 100,000): " << laikas.elapsed() << " s" << endl; //end

			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 300000);
			laikas.reset();
			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Suskirstymas <vector>\t(n = 300,000): " << laikas.elapsed() << " s" << endl; //end

			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 500000);
			laikas.reset();
			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "Suskirstymas <vector>\t(n = 500,000): " << laikas.elapsed() << " s" << endl; //end
			cout << "Done." << endl;
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