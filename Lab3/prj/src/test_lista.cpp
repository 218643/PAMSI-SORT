#include <cstdio>
#include <unistd.h>
#include <string>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

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
    int x;
    std::fstream plik;


    a = 0;
    b = 900000;
    plik.open( "tekst.txt", std::ios::in | std::ios::out );
    if( plik.good() == true )
    {
        for (int i = 0; i< gen; i++)
        {
            x = a+(rand() % (b-a+1));
            plik << x << endl;
        }
    }
    plik.close();

}


// zapisdotabeli kod metody
void test_lista::zapisDoTabeli()
{
  fstream plik;
    plik.open("tekst.txt", std::ios::in | std::ios::out);
    if(plik.good())
	{
        //ind =0;
        while(!plik.eof())
	    {
	      plik >> tab[ind];
	      ind++;
	    }

	}
	plik.close();
}

/*void test_lista::zapisdoPliku()
{
    ofstream plik;
  plik.open( "posortowane.txt", std::ios::in | std::ios::out );
    if( plik.good() == true )
    {
            plik << tab[ind] << endl;
        }

    plik.close();
}*/
void test_lista::zapisdoPliku(std::string const& nazwaPliku)
{
  std::ofstream strumienNaPlik (nazwaPliku, std::ios::app); // parametr ios::app powoduje to, ze do pliku bedziemy dopisywac linijki a nie nadpisywac
    strumienNaPlik << tab[ind] << std::endl;
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



void Lista::merge(int pocz, int sr, int kon)
{
int i,j,q;
for (i=pocz; i<=kon; i++) t[i]=tab[i];  // Skopiowanie danych do tablicy pomocniczej
i=pocz; j=sr+1; q=pocz;                 // Ustawienie wskaźników tablic
while (i<=sr && j<=kon) {         // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy głównej
if (t[i]<t[j])
tab[q++]=t[i++];
else
tab[q++]=t[j++];
}
while (i<=sr) tab[q++]=t[i++]; // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór się skończył
}

/* Procedura sortowania tab[pocz...kon] */
void Lista::merge_sort(int pocz, int kon)
{
int sr;
if (pocz<kon) {
sr=(pocz+kon)/2;
mergesort(pocz, sr);    // Dzielenie lewej części
mergesort(sr+1, kon);   // Dzielenie prawej części
merge(pocz, sr, kon);   // Łączenie części lewej i prawej
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
