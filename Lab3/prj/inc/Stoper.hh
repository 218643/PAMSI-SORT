#pragma once ///zastepuje kilkukrotne wklejanie pliku naglowkowego

#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "IStoper.hh"

/*!
*\brief Mierzy czas,wyswitla czas okrazenia, zwraca wyniki do pliku.
*/

class Stoper :public IStoper {
public:
/*!
*Start pobiera czas systemowy przed wykonaniem zadania
*/
void Start();
/*!
*Stop pobiera czas systemowy po wykonaniu zadania
*/
void Stop();
/*!
*getElapsedTime wykonuje roznice (Stop-Start) i zwraca czas w milisekundach
*/
double getElapsedTime();

/*!
*dumpToFile wysyla wyniki do pliku tekstowego. Jesli go nie am to go tworzy. Wyniki wysylane sa w kolejnosci wykonania petli.
*
*/
void dumpToFile(std::string const&); ///const& =unikamy kopi

using clock = std::chrono::high_resolution_clock;///czas systemowy
using time_point = clock::time_point;
using time_type = std::chrono::milliseconds;

private:
time_point punkt_startowy;
time_point punkt_koncowy;
};
