#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <chrono>

using namespace std;

#include "test_lista.hh"

/*!
 *\file
 *\brief Definicje funkcji oraz metod klasy test_lista.
 * Plik ten zawierqa definicje funkcji oraz metod
 * dla obiektow klasy test_lista. Sa one umieszczone tutaj
 * a nie w pliku naglowkowym aby zwiekszyc przejrzystosc
 * kodu.
 */

/*!
 *\brief Konstruktor bezparametryczny dla obiektow klasy test_lista.
 * Ustawia wszystkie pola klasy na 0;
 */
test_lista::test_lista()
{
  siz=0;
  sta=0;
  end=0;
}

/*!
 *\brief Metoda start.
 * Jest to jedna z metod, ktora implementuje metode czysto wirtualna
 * interfejsu Istoper. Uruchamia zegar i zapisuje wynik do
 * pola listy sta.
 */
void test_lista:: start()
{
  sta=clock();
}

/*!
 *\brief Metoda stop.
 * Jest to jedna z metod, ktora implementuje metode czysto wirtualna
 * interfejsu Istoper. Uruchamia zegar i zapisuje wynik do
 * pola listy end.
 */
void test_lista:: stop()
{
  end=clock();
}

/*!
 *\brief Metoda stop.
 * Jest to jedna z funkcji dziedziczacych po metodzie czysto wirtualnej
 * interfejsu Istoper. Liczy czas, ktory uplynal pomiedzy
 * uruchomieniem i zatrzymaniem stopera.
 * \return Zwraca czas, ktory uplynal pomiedzy wywolaniem metoda start i stop.
 */
long test_lista:: get_time()
{
  return 1000./CLOCKS_PER_SEC*(end-sta);

}

/*!
 *\brief Metoda wyswietl_wynik dla obiektow klasy test_lista.
 * Metoda ta wyswietla pole get_time na standardowym wyjsciu.
 */
void test_lista::wyswietl_wynik()
{
  cout << get_time() << endl;

}

/*!
 *\brief Metoda losuj_slowo.
 * Metoda losuje slowo z listy.
 * Na poczatku ustawiam zarodek czasu, by za kazdym razem losowana
 * byla inna wartosc. Nastepnie definiuje zmienna pomocnicza, ktora
 * bedzie poruszac sie po  liscie. Nastepnie losuje liczbe z przedzialu
 * od zera do rozmiaru wczytanej listy. Potem przesuwam sie do wylosowanego
 * miejsca, pobieram slowo i zwracam jego wartosc.
 *\return slowo - wraca wyloswane slowo.
 */
string test_lista:: losuj_slowo()
{
  srand (time(NULL));   //ustawienie zarodka, by przy kazdym uruchom prog
                        //losowane byly inne liczby
  Kaf* tmp=this->przod;
  int rn= rand() % (siz+1); //Losowanie elementu, ktory ma zostac wyszukany
  for(int i=0;i<(rn-1);i++) //rn-1,bo indeksuje od 0
    {
      tmp=tmp->prev;
    }
  cout <<"Los:  "<< tmp->wartosc << endl;
  return tmp->wartosc;
}

/*!
 *\brief Metoda szukaj.
 * Metoda losuje slowo z listy.
 * Odpalam stoper, sciagam elementy, do momentu, gdy znajde slowowo,
 * ktore szukam, zatrzymuje stoper.
 *\param[in] los - jako argument przyjmuje wylosowane slowo.
 */
void test_lista::szukaj(string los)
{
  start();
  while(get()!=los)
    {
      pop_front();
    }
  stop();
}

void test_lista::generateINT(int gen)
{
int a, b;
    a = 0;
    b = 900000;
std::ofstream plik("tekst.txt");
for(int i = 0; i < gen; i++)
    plik << a+(rand() % (b-a+1)) << endl;
}

// zapisdotabeli kod metody
void test_lista::zapisDoTabeli()
{
    int ind = 0;
    std::ifstream plik("tekst.txt");
    for(int wartosc; plik >> wartosc;)
    {
        tab[ind] = wartosc;
        ind ++;
    }
}

void test_lista::zapisdoPliku(std::string const& nazwaPliku)
{
  std::ofstream strumienNaPlik (nazwaPliku); // parametr ios::app powoduje to, ze do pliku bedziemy dopisywac linijki a nie nadpisywac
    for( int i = 0; i < ilosc_elementow; i++){
    strumienNaPlik << tab[i] << std::endl;}
}

/**************SO RT OW AN IA ********************/
void test_lista::quick_sort(int tab[], int left, int right)
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
        {
             i++;
             }

        while( tab[ j ] > x )
        {
             j--;
             }
        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) {quick_sort( tab, left, j );}

    if( right > i ) {quick_sort( tab, i, right );}

}



void test_lista::merge(int tab[], int start, int srodek, int koniec)
{
int *tab_pom = new int[(koniec-start+1)]; // utworzenie tablicy pomocniczej
int i = start, j = srodek+1, k = 0; // zmienne pomocnicze

while (i <= srodek && j <= koniec)
{
if (tab[j] < tab[i])
{
tab_pom[k] = tab[j];
j++;
}
else
{
tab_pom[k] = tab[i];
i++;
}
k++;
}

if (i <= srodek)
{
while (i <= srodek)
{
tab_pom[k] = tab[i];
i++;
k++;
}
}
else
{
while (j <= koniec)
{
tab_pom[k] = tab[j];
j++;
k++;
}
}

for (i = 0; i <= koniec-start+1; i++)
tab[start+i] = tab_pom[i];
}



void test_lista::mergesort(int tab[], int start, int koniec)
{
int srodek;

if (start != koniec)
{
srodek = (start + koniec)/2;
mergesort(tab, start, srodek);
mergesort(tab, srodek+1, koniec);
merge(tab, start, srodek, koniec);
}
}



/*!
 *\brief Metoda run.
 * Jest to jedna z metod implementujaca metode czysto wirtualna
 * interfejsu Irunnable.
 * Jezeli podano odpowiednia ilosc plikow na wejscie, otwieramny
 * jest strumien plikowy i elementy z tego strumienia wpisywane sa
 * na liste. Nastepnie zamykany jest uchwyt do pliku i uruchomione
 * metody szukaj oraz losuj_slowo.
 * \param[in] - Argc jest to ilosc komend wpisanych w terminalu.
 * \param[in] - Argv[] - jest to tablica nazw komend wpisanych w terminalu.
 * \return -Zwraca true, gdy operacja zakonczona powodzeniem, w przeciwny wypadku false.
 */
bool test_lista:: run(int Argc,char* Argv[])
{
  if(Argc!=2)
    {
      cerr << "Niewlasciwa ilosc plikow na wejsciu."<< endl;
      return false;
    }
  else
    {
      //***************Obsluga pliku***************//
      string elem;
      fstream plik; //zmienna pozwalajaca otworzyc strumien plikowy
      plik.open(Argv[1],ios::in); //otwarcie strumienia plikowego
      if(plik.good()) //jezeli udalo sie otworzyc plik
	{
	  while(!plik.eof())
	    {
	      plik >> elem;
	      push_front(elem);
	    }
	  pop_front();
	}
      plik.close(); //zamkniecie strumienia plikowego

      siz=size(); //ustawienie rozmiaru problemu

      szukaj(losuj_slowo());

    }
  return true;
  //*********************************//
}
