#include <gtest/gtest.h>
#include "../3_uzduotis/Studentas.cpp"
#include "../3_uzduotis/Functions.h"


int fileSize(string filename) {
	int count = 0;
	string line;

	/* Creating input filestream */
	std::ifstream file(filename);
	while (std::getline(file, line)) {
		if(line != "")
			++count;
	}
	return count;
}
	


TEST(Generation, Random_num_generator) {
	std::vector<Student> Studentai;
	Studentai.resize(5);
	for (auto& Stud : Studentai) {
		Stud.randomStudent();
		EXPECT_GE(10, Stud.egz());
		EXPECT_LT(0, Stud.egz());
		EXPECT_NE("", Stud.vardas());
		EXPECT_NE("", Stud.pavarde());
		EXPECT_EQ(5, Stud.balai().size());
	}
}

TEST(Filtering, Max_len) {
	std::vector<string> vardai{ "Romas", "Arras" , "Tukkkkkkas", "Ro", "Leo" };
	EXPECT_EQ(10, max_len(vardai));
}

TEST(Sorting, Custom_sort) {
	std::vector<Student> Studentai;
	Studentai.resize(5);
	for (auto& Stud : Studentai) {
		Stud.randomStudent();
	}
	Custom::sort(Studentai);
	for (size_t i = 1; i < Studentai.size(); ++i) {
		EXPECT_LE(Studentai[i-1].galBalas(), Studentai[i].galBalas());
	}

}


TEST(Generation, File_generation) {
	Failo_generavimas_v2<vector<Student>>("../3_uzduotis/OUTPUT.txt", 1000);
	EXPECT_EQ(1000, fileSize("../3_uzduotis/OUTPUT.txt"));
}


TEST(Generation, File_split) {
	Failo_generavimas_v2<vector<Student>>("../3_uzduotis/OUTPUT.txt", 1000);
	Failo_nuskaitymas<vector<Student>>("../3_uzduotis/OUTPUT.txt", "neprint", "skirstyti", 1);
	EXPECT_EQ(1000,
		fileSize("../3_uzduotis/OUTPUT_KIETI.txt") +
		fileSize("../3_uzduotis/OUTPUT_SILPNI.txt"));
}