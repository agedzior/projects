#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <windows.h>


using namespace std;

int menu, number1, number2, result;
char sign;
HANDLE hOut;

int SimpleCalc(int menu)
{
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	cout << "KALKULATOR PROSTY - wpowadz dane w formacie:   liczba1 znak liczba2\tObslugiwane znaki: +, -, *, / or %: \n";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY); 
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


int main()
{
	
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "MENU:\n1.Prosty kalkulator\n";
		//2.Kalkulator wielomanow\n3.Kalkulator wektorow\n4.Kalkulator macierzy\n5.Oblicz pola figur\n
		cout<<"6.Zakoncz\n";
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
		case 2:	{} break;
		case 3: {} break;
		case 4: {} break;
		case 5: {} break;
		case 6: exit(0);
		default:
			cout << "Brak opcji w menu! Sprobuj ponownie!";
		}
	} while (menu = 6);

	system("PAUSE");
	return 0;
}