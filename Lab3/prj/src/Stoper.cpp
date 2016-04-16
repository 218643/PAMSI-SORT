#include "Stoper.hh"


//czas systemu przed funkcja
void Stoper::Start()
{
    punkt_startowy = clock::now();
}
//czas systemowy po wykonaniu funckji
void Stoper::Stop()
{
    punkt_koncowy=clock::now();
}
//czas okrazenia to roznica czasu pocz i koncowego
double Stoper::getElapsedTime()
///duration cast=operator porownujacy, pozwala odjac 2 punkty w czasie
{
    return std::chrono::duration_cast<time_type>(punkt_koncowy - punkt_startowy).count();
}
//zapisanie wynikow do pliku textowego.
void Stoper::dumpToFile(std::string const& nazwaPliku)
{
  std::ofstream strumienNaPlik (nazwaPliku, std::ios::app); // parametr ios::app powoduje to, ze do pliku bedziemy dopisywac linijki a nie nadpisywac
    double roznica_czasow = getElapsedTime();
    strumienNaPlik << roznica_czasow << std::endl;
}
