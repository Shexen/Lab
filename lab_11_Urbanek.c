#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//75 - 81
int wczytaj_i(int min, int max) {
	int x;
	while (scanf_s("%i", &x) != 1 || x<min || x>max || getchar() != '\n')
	{
		while (getchar() != '\n');
		printf("Wprowadz dane ponownie : ");
	}
	return x;
}
int zad_75() {
	printf("Zad 75 - Pobieranie 10 liczb calkowitych.\n");
	printf("Wprowadz liczby. \n");
	int tab[10];
	for (int i = 0; i < 10; i++) { //Wprowadzenie danych
		if (i != 9)
		{
			printf("%i  : ", i + 1);
			tab[i] = wczytaj_i(0, INT_MAX);
		}
		else {
			printf("%i : ", i + 1);
			tab[i] = wczytaj_i(0, INT_MAX);
		}
	}
	printf("\n");	//Oddzielenie wprowadzenia i wypisania
	for (int i = 9; i > -1; i--) { //Wypisanie danych w odwrotnej kolejnosci
		if (i != 9)
		{
			printf("%i  : %i", i + 1, tab[i]);
		}
		else {
			printf("%i : %i", i + 1, tab[i]);
		}
		printf("\n");
	}
	printf("Koniec programu.");
}
int zad_76_tablica() {
	printf("Zad 76 - Zczytywanie ciagu liczb i wyznaczanie sume oraz iloczyn (z tablicy)\n\n");
	printf("Wprowadz liczbe n oznaczajaca ilosc liczb w ciagu (maksymalnie 100) : ");
	int iloczyn=1,suma=0,tab[100];
	int n = wczytaj_i(1, 100);
	for (int i = 0; i < n; i++)
	{
		printf("Wprowadz liczbe %i : ", i + 1);
		tab[i] = wczytaj_i(INT_MIN, INT_MAX);
		suma += tab[i];
		iloczyn *= tab[i];
	}
	printf("\nSuma ciagu wynosi : %i, a jego iloczyn : %i", suma, iloczyn);
	printf("\n\nKoniec programu.");
}
zad_76_beztablicy() {
	printf("Zad 76 - Zczytywanie ciagu liczb i wyznaczanie sume oraz iloczyn (z tablicy)\n\n");
	printf("Wprowadz liczbe n oznaczajaca ilosc liczb w ciagu (maksymalnie 100) : ");
	int iloczyn = 1, suma = 0,x;
	int n = wczytaj_i(1, 100);
	for (int i = 0; i < n; i++)
	{
		printf("Wprowadz liczbe %i : ", i + 1);
		x = wczytaj_i(INT_MIN, INT_MAX);
		suma += x;
		iloczyn *= x;
	}
	printf("\nSuma ciagu wynosi : %i, a jego iloczyn : %i", suma, iloczyn);
	printf("\n\nKoniec programu.");
}
int zad_77() {
	printf("Zad 77 - Wypisywanie sumy szescianow poszczegolnych liczb.\n");
	printf("Wprowadz cyfre(1-9) aby zobaczyc trzycyfrowe liczby rowne sumie szescianow tejze cyfry : ");
	int x = wczytaj_i(1, 9),szukanal=0; 
	int podstawa = pow(x, 3);
	while (szukanal < 1000) {
		if (szukanal >= 100) {
			printf("%i\n", szukanal);
		}
		szukanal += podstawa;
	}
	printf("\nKoniec programu.");
}
int zad_78() {
	printf("Zad 78 - Wypisywanie n kolejnych wyrazow ciagu Fibbonaciego.\n");
	printf("Wprowadz n : ");
	int n = wczytaj_i(0, 20), tab[20] = {0,1};
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			printf("%i wyraz  : %i\n", i + 1, tab[i]);
		}
		else if (i == 1) {
			printf("%i wyraz  : %i\n", i + 1, tab[i]);
		}
		else {
			tab[i] = tab[i - 2] + tab[i - 1];
			if (i < 9) {
				printf("%i wyraz  : %i\n", i + 1, tab[i]);
			}
			else
			printf("%i wyraz : %i\n", i + 1,tab[i]);
		}
	}
	printf("\nKoniec programu.");
}
int zad_79() {
	printf("Zad 79 - Wczytanie i segregacja 10 liczb calkowitych.\n");
	int tab[10]; //tablica 10 elementowa
	int start = 0,zamiana;	//zamiana = zmienna pomocnicza sluzaca zamianie elementow w tablicy, start = zmienna sluzaca rozpoczynaniu kolejnego szukania najmniejszej liczby od elementu o jeden wiekszego niz poprzednio
	for (int i = 0; i < 10; i++) {	//Wczytanie
		printf("Liczba %i : ", i + 1);
		tab[i] = wczytaj_i(INT_MIN, INT_MAX);
	}
	int najmn=tab[0],najmn_i; //najmn_i = miejsce w tabeli, najmn = najmniejsza liczba
	for (int a = 0; a < 10; a++) {	//Segregacja
		for (int b = start; b < 10; b++) {
			if (tab[b] <= najmn) {
				najmn_i = b;
				najmn = tab[b];
			}
		}
		//zamiana
		zamiana = tab[start];
		tab[start] = tab[najmn_i];
		tab[najmn_i] = zamiana;

		najmn = tab[start + 1]; //Liczba w warunku segregacji jest teraz na miejscu o jeden wiekszym od ilosci iteracji (a)
		start++;
	}

	printf("\n");
	for (int i = 0; i < 10; i++) {	//Odczytanie
		if(i<9)
			printf("Liczba %i  : %i\n",i+1,tab[i]);
		else
			printf("Liczba %i : %i\n", i + 1, tab[i]);
	}
	printf("\nKoniec programu.");
}
int zad_80() {
	printf("Zad 80 - Losowanie i segregacja 10 liczb calkowitych.\n");
	srand(time(NULL));
	int tab[10]; //tablica 10 elementowa
	int start = 0, zamiana;	//zamiana = zmienna pomocnicza sluzaca zamianie elementow w tablicy, start = zmienna sluzaca rozpoczynaniu kolejnego szukania najmniejszej liczby od elementu o jeden wiekszego niz poprzednio
	for (int i = 0; i < 10; i++) {	//Losowanie
		tab[i] = rand() % INT_MAX;
	}
	int najmn = tab[0], najmn_i; //najmn_i = miejsce w tabeli, najmn = najmniejsza liczba
	for (int a = 0; a < 10; a++) {	//Segregacja
		for (int b = start; b < 10; b++) {
			if (tab[b] <= najmn) {
				najmn_i = b;
				najmn = tab[b];
			}
		}
		//zamiana
		zamiana = tab[start];
		tab[start] = tab[najmn_i];
		tab[najmn_i] = zamiana;

		najmn = tab[start + 1]; //Liczba w warunku segregacji jest teraz na miejscu o jeden wiekszym od ilosci iteracji (a)
		start++;
	}

	printf("\n");
	for (int i = 0; i < 10; i++) {	//Odczytanie
		if (i < 9)
			printf("Liczba %i  : %i\n", i + 1, tab[i]);
		else
			printf("Liczba %i : %i\n", i + 1, tab[i]);
	}
	printf("\nKoniec programu.");
}
int zad_81() {
	printf("Zad 80 - Losowanie i segregacja 10 liczb calkowitych.\n");
	srand(time(NULL));
	int tab[10]; //tablica 10 elementowa
	int start = 0, zamiana;	//zamiana = zmienna pomocnicza sluzaca zamianie elementow w tablicy, start = zmienna sluzaca rozpoczynaniu kolejnego szukania najmniejszej liczby od elementu o jeden wiekszego niz poprzednio
	for (int i = 0; i < 10; i++) {	//Losowanie
		tab[i] = rand() % 2+1;
	}
	int najmn = tab[0], najmn_i; //najmn_i = miejsce w tabeli, najmn = najmniejsza liczba
	for (int a = 0; a < 10; a++) {	//Segregacja
		for (int b = start; b < 10; b++) {
			if (tab[b] <= najmn) {
				najmn_i = b;
				najmn = tab[b];
			}
		}
		//zamiana
		zamiana = tab[start];
		tab[start] = tab[najmn_i];
		tab[najmn_i] = zamiana;

		najmn = tab[start + 1]; //Liczba w warunku segregacji jest teraz na miejscu o jeden wiekszym od ilosci iteracji (a)
		start++;
	}

	printf("\n");
	for (int i = 0; i < 10; i++) {	//Odczytanie
		if (i < 9)
			printf("Liczba %i  : %i\n", i + 1, tab[i]);
		else
			printf("Liczba %i : %i\n", i + 1, tab[i]);
	}
	printf("\nKoniec programu.");
}
int main()
{
	//zad_75();

	//zad_76_tablica();

	//zad_76_beztablicy();

	//zad_77();

	//zad_78();

	//zad_79();

	//zad_80();

	zad_81();
}