//67 - 74
#include <stdio.h>
#include <limits.h>
#include <math.h>
int main()
{
	//zad_67();

	//zad_68();

	//zad_69();

	//zad_70();

	//zad_71();

	//zad_72();

	//zad_73();
	
	zad_74();
}
int wczytaj_i(int min,int max)
{
	int x;
	while (scanf_s("%i", &x) != 1 || x < min || x > max || getchar() != '\n')
	{
		while (getchar() != '\n');
		printf("Wprowadz dane ponownie :");
	}
	return x;
}
int zad_67()
{
	printf("Zad 67 - wypisywanie gwiazdek.\n\n");
	printf("Wpisz ilosc gwiazdek ktora zostanie wypisana :");
	int iloscg= wczytaj_i(0, INT_MAX);;
	for (int i = 0; i < iloscg; i++)
	{
		printf("*");
	}
	printf("\n%i", iloscg);
	printf("\nKoniec programu.");
	return 0;
}
int zad_68()
{
	printf("Zad 68 - Wypisywanie kwadratu z gwiazdek\n");
	for (int i = 0; i < 3; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\nKoniec programu.");
	return 0;
}
int zad_69()
{
	printf("Zad 69 - Rysowanie prostokata z gwiazdek\n");
	printf("Podaj dlugosc mniejszeg boku : ");
	int a= wczytaj_i(INT_MIN, INT_MAX);
	for (int y = 0; y < a; y++)
	{
		for (int x = 0; x < 2*a; x++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\nKoniec programu.");
	return 0;
}
int zad_70()
{
	printf("Zad 70 - Rysowanie trojkata z katem 90 z gwiazdek");
	int a = 0;
	for (int y=0; y < 4; y++)
	{
		for (int x=0; x < a; x++)
		{
			printf("*");
		}
		printf("\n");
		a++;
	}
	printf("Koniec programu.");
	return 0;
}
int zad_71()
{
	printf("Zad 71 - Rysowanie trojkata.\n");
	printf("Wprowadz liczbe wierszy :");
	int iloscrzedow=wczytaj_i(0,INT_MAX);
	int lewyb = iloscrzedow-1, prawyb = iloscrzedow-1;

	for (int y = 0; y < iloscrzedow; y++)
	{
		for (int x = 0; x < (iloscrzedow*2)-1; x++)
		{
			if (x >= lewyb&& x <= prawyb)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		lewyb--;
		prawyb++;
		printf("\n");
	}
	printf("\nKoniec programu.");
	return 0;
}
int zad_72()
{
int max = 15;
int min = 1;
	printf("Zad 72 - Tabliczka mnozenia do 15\n\n");
	int ilwierszy = wczytaj_i(min, max);
	int mnozenie=0;
	for (int y=0; y < ilwierszy+2; y++)	//siatka y
	{
		if (y == 0)
		{
			printf("    ");
			for (int n_1 = 0; n_1 < ilwierszy; n_1++) // wypisywanie "   1   2   3..."
			{
				if (n_1 < 9)
					printf("   %i", n_1 + 1);
				else
					printf("  %i", n_1 + 1);
			}
			printf("\n");
		}
		if (y == 1)
		{
			for (int n_2 = 0; n_2 < 4 + 4 * ilwierszy; n_2++) //wypisywanie _____________________
				printf("_");
			printf("\n");
		}
		if (y >= 2)
		{
			for (int x = 0; x <ilwierszy+1; x++) //siatka x
			{
				if (x == 0) //Wypisywanie " 1 " lub "10 "...
				{
					if (y < 11)
						printf(" %i |", y - 1);
					else
						printf("%i |", y - 1);
				}
				else if(x==1) //Wypisywanie siatki z mnozeniem
				{
					for (int n_3 = 0; n_3 < ilwierszy; n_3++)
					{
						mnozenie = (y - 1) * (n_3 + 1);
						if (mnozenie < 10)
						{
							printf("   %i", mnozenie);
						}
						else if(mnozenie < 100)
						{
							printf("  %i", mnozenie);
						}
						else
						{
							printf(" %i", mnozenie);
						}
					}
				}
			}
			printf("\n");
		}
	}
	printf("\nKoniec programu.");
	return 0;
}
int zad_73()
{
	printf("%s","Zad 73 - Wypisywanie znakow ASCII\n\n");
	printf("Wprowadz liczbe kolejnych znakow ktore zostana wypisane (np: wprowadzenie 40 wyswietli znaki o numerze od 0 do 40) : ");
	int ilosc = wczytaj_i(1, 255);
	for (int i = 0; i <= ilosc; i++)
	{
		if (i == 0){
			printf("%i    %s\n", i, "nul");
		}
		else if (i == 7) {
			printf("%i    %s\n", i, "bel");
		}
		else if (i == 8) {
			printf("%i    %s\n", i, "bs");
		}
		else if (i == 9) {
			printf("%i    %s\n", i, "ht");
		}
		else if (i == 10) {
			printf("%i   %s\n", i, "nl");
		}
		else if (i == 11) {
			printf("%i   %s\n", i, "vt");
		}
		else if (i == 12) {
			printf("%i   %s\n", i, "np");
		}
		else if (i == 13) {
			printf("%i   %s\n", i, "cr");
		}
		else if (i == 26) {
			printf("%i   %s\n", i, "eof");
		}
		else if (i == 27) {
			printf("%i   %s\n", i, "esc");
		}
		else if (i == 127) {
			printf("%i  %s\n", i, "del");
		}
		else if(i< 10) {
			printf("%i    %c\n", i, i);
		}
		else if(i<100) {
			printf("%i   %c\n", i, i);
		}
		else {
			printf("%i  %c\n", i, i);
		}
	}
	printf("\nKoniec programu.");
	return 0;
}
int zad_74()
{
	printf("Zad 74 - Wypisywanie sumy.\n");
	printf("Wpisz liczbe n aby obliczyc n wyraz ciagu (od 1 do 9) : ");
	long long int suma = 0,x;
	int n = wczytaj_i(1, 9);
	for (int i = 1; i <= n; i++) {
		x = n * pow(10, i - 1);
		suma += x;
		if(i<n)
		printf("%i + ", x);
		else
		printf("%i ", x);
	}
	printf("= %i", suma);
	printf("\nKoniec programu.");
	return 0;
}
