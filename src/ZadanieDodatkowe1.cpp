#include <iostream>
#include <cstring>

using namespace std;

// tablice i zmienne typu char są ustawione jako unsigned z powdu błędów wyrzucanych przez kompilator
unsigned char alphabetTable[26][26];

void createAlphabetTable(); // rysowanie tablicy alfabetu 26x26 do szyfrowania/deszyfrowania
void crypt(string inputString, string passString); // algorytm szyfrowania
void decrypt(string inputString, string passString); // algorytm deszyfrowania

void createAlphabetTable()
{
	for(unsigned char a = 'a'; a <= 'z'; a++)
	{
		unsigned char b = a;
		for(unsigned char z = 'a'; z <= 'z'; z++)
		{
			if(b == 'z' + 1){
				b = 'a';
			}
			alphabetTable[a][z] = b;
			b++;
		}
	}
}

void crypt(string inputString, string passString)
{
	// wrzucenie tekstu i klucza do tablicy char
	char textCharTable[inputString.length()];
	char passCharTable[passString.length()];

	strcpy(textCharTable, inputString.c_str());
	strcpy(passCharTable, passString.c_str());

	cout << "Wynik szyfrowania: " << endl;
	for(int i=0; i < (signed int)sizeof(textCharTable); i++)
	{
		if(textCharTable[i] != ' ')
			cout << alphabetTable[(unsigned char)textCharTable[i]][(unsigned char)passCharTable[i]];
		else
			cout << " ";
	}
	cout << endl;
}

void decrypt(string inputString, string passString)
{
		// wrzucenie tekstu i klucza do tablicy char
		char textCharTable[inputString.length()];
		char passCharTable[passString.length()];

		strcpy(textCharTable, inputString.c_str());
		strcpy(passCharTable, passString.c_str());

		cout << "Wynik deszyfrowania: " << endl;
		for(int i=0; i < (signed int)sizeof(textCharTable); i++)
			{
				if(textCharTable[i] != ' ')
				{
					for(unsigned char z = 'a'; z <= 'z'; z++)
					{
						if(alphabetTable[(unsigned char)textCharTable[i]][(unsigned char)passCharTable[i]] == alphabetTable[(unsigned char)passCharTable[i]][z])
							cout << alphabetTable['a'][z];
					}
				}else
					cout << " ";
				}
}
int main() {

	string inputString; // tekst podawany z klawiatury
	string passString;	// klucz podawany z klawiatury

	getline(cin, inputString);
	getline(cin, passString);

	createAlphabetTable();
	crypt(inputString, passString);
	decrypt(inputString, passString);


	return 0;
}
