#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cmath>
#include <windows.h>


using namespace std;

int menu, number1, number2, result;
int i, j, k, si, n, m, t, s, p;

double a, b, c, r, h, pole, obwod;
char sign;

HANDLE hOut;


/*-----------------------------------------KALKULATOR PROSTY----------------------------------------------------------------*/

int SimpleCalc(int menu)
{
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "KALKULATOR PROSTY - wpowadz dane w formacie:   liczba1 znak liczba2\tObslugiwane znaki: +, -, *, / or %: \n";
	cout<<"Wprowadz operacje arytmetyczna ktora chcesz obliczyc:" << endl;
	cin >> number1 >> sign >> number2;
	cout << number1 << " "<< sign << " " << number2 << " = ";
	switch (sign)
	{
	case '+':
		result = number1 + number2;
		cout << result;
		break;
	case '-':
		result = number1 - number2;
		cout << result;
		break;
	case '*':
	case 'x':
	case 'X':
		result = number1 * number2;
		cout << result;
		break;
	case '/':
		result = number1 / number2;
		cout << result;
		break;
	case '%':
		result = number1 % number2;
		cout << result;
		break;
	default:
		cout << "wprowadzony znak nie jest obslugiwany. Sprobuj ponownie!";
	}
	cout << endl;
	return result;
}
/*-----------------------------------------OBLICZANIE POL FIGUR----------------------------------------------------------------*/
class Figury
{
public:
	int w;
	Figury() { this->w = -1; } //konstruktor
	//WYPISZ NA EKRAN
	void WyswietlPole(double pole, double obwod)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\nPole figury wynosi:\t" << pole << endl;
		cout << "Obwod figury wynosi:\t" << obwod << endl;

	}
	//SPRAWDZENIE
	void Check(double a)
	{
		if (a <= 0)
		{
			cout << "Zle dane! ";
			this->wybor();
		}
	}

	//WYBOR FIGURY
	void wybor()
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "Dla ktorej figury mam wykonac obliczenia?\n1.kwadrat\n2.prostokat\n3.kolo\n4.trojkat\n5.wyjscie\t";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> menu;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		switch (menu)
		{
		case 1:
			this->Kwadrat();
			break;
		case 2:
			this->Prostokat();
			break;
		case 3:
			this->Kolo();
			break;
		case 4:
			this->Trojkat();
			break;
		case 5:
			exit(0);
		default:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "Brak opcji w menu! Sprobuj ponownie!";
		}
	}
	void Uruchom() {
		this->wybor();
	}

	//-------------------------------------------------------------------------KWADRAT
	double PoliczKwadratPole(double a)
	{
		return a*a;
	}
	double PoliczKwadratObwod(double a)
	{
		return 4*a;
	}
	void Kwadrat()
	{
		double a = 0;
		cout << "\nPodaj bok kwadratu \t a=";
		cin >> a;
		this->Check(a);
		pole = this->PoliczKwadratPole(a);
		obwod= this->PoliczKwadratObwod(a);
		this->WyswietlPole(pole,obwod);
	}
	//-------------------------------------------------------------------------PROSTOKAT
	double PoliczProstokatPole(double a, double b)
	{
		return a*b;
	}
	double PoliczProstokatObwod(double a, double b)
	{
		obwod = 2 * (a + b);
		return obwod;
	}
	void Prostokat()
	{
		double a = 0, b = 0;
		cout << "\nPodaj bok prostokata \t a=";
		cin >> a;
		this->Check(a);
		cout << "Podaj drugi bok prostokata \t b=";
		cin >> b;
		this->Check(b);
		pole = this->PoliczProstokatPole(a, b);
		obwod = this->PoliczProstokatObwod(a, b);
		this->WyswietlPole(pole,obwod);
	}
	//-------------------------------------------------------------------------KOLO
	double PoliczKoloPole(double r)
	{
		return 3.14*r*r;
	}
	double PoliczKoloObwod(double r)
	{
		return 2 * 3.14*r;
	}
	void Kolo()
	{
		double r = 0;
		cout << "\nPodaj promien \t r=";
		cin >> r;
		this->Check(r);
		pole = this->PoliczKoloPole(r);
		obwod = this->PoliczKoloObwod(r);
		this->WyswietlPole(pole,obwod);
	}

	//-------------------------------------------------------------------------TROJKAT
	double PoliczTrojkatPole(double a, double h)
	{
		return 0.5*a*h;
	}
	double PoliczTrojkatObwod(double a, double b, double c)
	{
		return a+b+c;
	}
	void Trojkat()
	{
		double a = 0, h = 0;
		cout << "\nPodaj bok trojkata \t a=";
		cin >> a;
		this->Check(a);
		cout << "Podaj wysokosc trojkata \t h=";
		cin >> h;
		this->Check(h);
		cout << "Podaj bok trojkata \t b=";
		cin >> b;
		this->Check(b);
		cout << "Podaj bok trojkata \t c=";
		cin >> c;
		this->Check(c);

		pole = this->PoliczTrojkatPole(a, h);
		obwod = this->PoliczTrojkatObwod(a, b, c);
		this->WyswietlPole(pole,obwod);
	}
};


/*-----------------------------------------KALKULATOR MACIERZY----------------------------------------------------------------*/
//-------------------------------------------------------MNO¯ENIE
int mnozenieMac() {
	if (m != s)
		cout << "Mnozenie macierzy niemozliwe - Ilosc kolumn w macierzy B musi byæ taka sama jak ilosc wierszy w macierzy A\n";
	else {
		int * A = new int[n * m];
		int * B = new int[m * t];
		int * C = new int[n * t];

		// odczytujemy zawartoœæ macierzy A
		cout << "Wypisz elementy macierzy A:\n";
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++) cin >> A[i * m + j];

		// odczytujemy zawartoœæ macierzy b
		cout << "Wypisz elementy macierzy B:\n";
		for (i = 0; i < m; i++)
			for (j = 0; j < t; j++) cin >> B[i * t + j];

		// Obliczamy iloczyn macierzy A i B w C

		for (i = 0; i < n; i++)
			for (j = 0; j < t; j++)
			{
				si = 0;
				for (k = 0; k < m; k++)
					si += A[i * m + k] * B[k * t + j];
				C[i * t + j] = si;
			}

		// Wyprowadzamy wyniki

		cout << "\nMacierz C=AxB\n";
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < t; j++) cout << C[i * t + j] << " ";
			cout << endl;
		}
	}
	return 0;
}

//----------------------------------------------------------DODAWANIE
int dodawanieMac()
{

	p = n * m;
	int * A = new int[p];
	int * B = new int[p];
	int * C = new int[p];
	cout << "Wypisz elementy macierzy A:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> A[i * m + j];

	cout << "Wypisz elementy macierzy B:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> B[i * m + j];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			p = i * m + j;       // indeks elementu macierzy A, B i C
			C[p] = A[p] + B[p];
		}

	cout << "\nC=A+B:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++) cout << C[i * m + j] << " ";
		cout << endl;
	}
	return 0;
}

//---------------------------------------------------ODEJMOWANIE
int odejmowanieMac() {
	p = n * m;
	int * A = new int[p];
	int * B = new int[p];
	int * C = new int[p];
	cout << "Wypisz elementy macierzy A:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> A[i * m - j];

	cout << "Wypisz elementy macierzy B:\n";
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) cin >> B[i * m - j];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			p = i * m - j;       // indeks elementu macierzy A, B i C
			C[p] = A[p] - B[p];
		}

	cout << "\nC=A+B:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++) cout << C[i * m - j] << " ";
		cout << endl;
	}
	return 0;
}

int pobierzMac() {
	cout << "\nWprowadz ilosc wierszy macierzy A:\t";
	cin >> n;
	cout << "Wprowadz ilosc kolumn macierzy A:\t";
	cin >> m;
	cout << "Wprowadz ilosc wierszy macierzy B:\t";
	cin >> s;
	cout << "Wprowadz ilosc kolumn macierzy B:\t";
	cin >> t;
	return 0;
}
/*-----------------------------------------KALKULATOR WIELOMIANOW-------------------------------------------------------------*/



int main()
{
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "MENU:\n1.Prosty kalkulator\n2.Obliczanie pola i obwodu figur\n3.Kalkulator macierzy\n";
		//4.Kalkulator wielomianow\n
		cout<<"5.Zakoncz\n";
	do {
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\nKtorego kalkulatora uzyc?\t";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			SimpleCalc(menu);
			break;
		}
		case 2:	{
			Figury*nFig = new Figury();
			nFig->Uruchom();
		} break;
		case 3: 
		{
			cout << "1.Mnozenie macierzy\n2.Dodawanie macierzy\n3.Odejmowanie macierzy:\t";
			cin >> menu;
			switch (menu)
			{
			case 1:
				pobierzMac();
				mnozenieMac();
				break;
			case 2:
				pobierzMac();
				dodawanieMac();
				break;
			case 3:
				pobierzMac();
				odejmowanieMac();
				break;
			default:
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << "Brak opcji w menu!";
				break;
			}
		} 
		break;
		case 4: {} break;

		case 5: exit(0);
		default:
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << "Brak opcji w menu! Sprobuj ponownie!";
		}
	} while (menu = 5);

	system("PAUSE");
	return 0;
}