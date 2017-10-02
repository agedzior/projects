
/*SOLOLEARN Challenge : : Making a random password generator.
The password generator will take the length of password (always greater than 3) and output a random password containing at least:
1. An Alphabet( either lowercase or uppercase)
2. A number.
3. A special character.
The postion of all these characters will also be random i.e. the number might be the first to come.
Constraints:
3<= length<=100
*/

#include<iostream> 
#include<string> 
#include<cstdlib> 
#include<ctime> 
#include <windows.h>

using namespace std;

HANDLE hOut;

static const char elements[] = "0123456789" "!@#$%^&*" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int stringLength = sizeof(elements) - 1;
char genRandom()
{
	return elements[rand() % stringLength];
}
int main()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

	cout << "SOLOLEARN Challenge : : Making a random password generator.\n";
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE); 
	cout<<"The password generator will take the length of password(always greater than 3) and output a random password containing at least : \n"
		<< "1. An Alphabet(either lowercase or uppercase)\n"
		<< "2. A number.\n"
		<< "3. A special character.\n"
		<< "The postion of all these characters will also be random i.e.the number might be the first to come.\n"
		<< "Constraints: 3 <= length <= 100\n\n";

	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	int n;
	srand(time(0));
	cout << "Enter the length of the password:\t";
	cin >> n;
	cout << "Your Password have "<<n<<" characters and was placed below:\n" ;
	for (int z = 0; z < n; z++)
	{

		cout << genRandom();
	}

	cout << "\n\n";
	system("PAUSE");
	return 0;
}