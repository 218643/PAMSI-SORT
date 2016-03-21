
void BubbleSort(Tablica& tab, int rozmiar)
{
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<(rozmiar-1);j++)
	if(tab[j+1] < tab[j])
	  {
	    int a=tab[j+1];
	    tab[j+1]=tab[j];
	    tab[j]=a;
	  }
    } 

}
