#include "mano_func.h"
#include "Studentas.h"



int main()
{
	//cout << "Ivedus mokinio varda, pavarde, 'n' namu darbu balus\nir egzamino bala, bus isvedama lentele.\n" << std::string(40, '=') << endl;
	cout << std::string(40, '=') << endl;

	int choice;
	cout << "1 - Ivesti data rankomis;\n2 - Skaityti data is failo;\n3 - Sugeneruos failus is 10,000 studentu;\n4 - vector<class Student> greicio testavimas\n" << std::string(40, '=') << endl;
	choice = cin_and_checkFormat_in_interval<int>(1, 4);
	constexpr int strategija = 1;
	try {
		switch (choice) {
		case 1: {
			//vector<Student> Studentai;
			//vector<double> balai{ 1, 2, 3, 4, 5 };
			//Studentai.emplace_back("ok", "123", balai, 6.2);
			//Studentai.emplace_back("ok", "123", balai, 6.2);
			//Sukurti_studenta(Studentai, "ok", "123", balai, 6.2);

			//for (const auto& stud : Studentai) {
			//	cout << stud.vardas() << stud.pavarde() << endl;
			//}
			Duomenu_ivedimas<vector<Student>>();
			break;
		}
		case 2:
			Failo_nuskaitymas<vector<Student>>("kursiokai.txt");
			break;
		case 3:
			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 10); // generate file
			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "print", "skirstyti"); //split file
			cout << "Done." << endl;
			break;
		case 4: {
			Failo_generavimas_v2<vector<Student>>("OUTPUT.txt", 1000000);
			Timer laikas;

			Failo_nuskaitymas<vector<Student>>("OUTPUT.txt", "neprint", "skirstyti", strategija);
			cout << "strategija:(" << strategija << "):suskirstymas <vector>\t(n = 10,000): " << laikas.elapsed() << " s" << endl; //end
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