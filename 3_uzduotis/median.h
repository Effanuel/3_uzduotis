#pragma once
#include <vector>

using std::vector;
/**
Skaiciuoja mediana is namu darbu balu ir egzamino
*/
double median(vector<double>);
/**
Skaiciuoja vidurki is namu darbu balu ir egzamino
*/
double vidurkis(vector<double>);

template <typename T> T cin_and_checkFormat_in_interval(double, double);