#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

void to_words(string);
void search(int);

int main(int argc, char *argv[])
{
	int n = atoi(*(argv+1));
	search(n);
}

void to_words(string number)
{
	
	int n = number.size();
	int *digits = new int[n];

	int num = atoi(number.c_str());
	int divisor = 1;

	for(int i=0;  i < n ; i++)
	{
		digits[i] = (num/divisor) %10;
		divisor *= 10;
	}

	for(int i = n-1; i >= 0; i--)
	{
		if(i == 6)
			cout << "milion ";

		if(i == 5 || i == 2)
		{
			switch(digits[i])
			{
			case 1: 
				cout << "sto ";
				break;
			case 2: 
				cout << "dwieście ";
				break;
			case 3: 
				cout << "trzysta ";
				break;
			case 4: 
				cout << "czterysta ";
				break;
			case 5: 
				cout << "pięćset ";
				break;
			case 6: 
				cout << "sześćset ";
				break;
			case 7: 
				cout << "siedemset ";
				break;
			case 8: 
				cout << "osiemset ";
				break;
			case 9: 
				cout << "dziewięćset ";
				break;
			default:
				break;
			}
		}

		if(i == 4 || i == 1)
		{
			switch(digits[i])
			{
			case 1: 
				cout << "dziesięć ";
				break;
			case 2: 
				cout << "dwadzieścia ";
				break;
			case 3: 
				cout << "trzydzieści ";
				break;
			case 4: 
				cout << "czterdzieści ";
				break;
			case 5: 
				cout << "pięćdziesiąt ";
				break;
			case 6: 
				cout << "sześćdziesiąt ";
				break;
			case 7: 
				cout << "siedemdziesiąt ";
				break;
			case 8: 
				cout << "osiemdziesiąt ";
				break;
			case 9: 
				cout << "dziewięćdziesiąt ";
				break;
			default:
				break;
			}
		}

		if(i == 0 || i == 3)
		{
			switch(digits[i])
			{
			case 1: 
				if(i == 0)
					cout << "jeden ";
				else
					cout << "tysiąc ";
				break;
			case 2: 
				cout << "dwa ";
				break;
			case 3: 
				cout << "trzy ";
				break;
			case 4: 
				cout << "cztery ";
				break;
			case 5: 
				cout << "pięć ";
				break;
			case 6: 
				cout << "sześć ";
				break;
			case 7: 
				cout << "siedem ";
				break;
			case 8: 
				cout << "osiem ";
				break;
			case 9: 
				cout << "dziewięć ";
				break;
			default:
				break;
			}

			if(i == 3 && digits[3] > 1 && digits[3] < 5)
				cout << "tysiące ";
			if(i == 3 && ((digits[3] == 0 && n < 7) || (digits[3] > 4 && digits[3] < 10)))
				cout << "tysięcy ";
			if(n == 1 && digits[0] == 0)
				cout << "zero ";
		}
	}

	cout << endl;

	delete [] digits;
}


void search(int n)
{

	for(int i = 0; i<= 1000000; i++)
	{
		int product1 = i*n;
		if(product1 <= 1000000)
		{
			string k = to_string(i);
			int length = k.length();
			bool approved = true;
			
			for(int i = 0; i < length; i++)
			{
				if((*(k.begin()+i)) != 0 && (*(k.begin()+i)) != 1 )
				{
					approved = false;
					break;
				}
			}

			to_words(k);
			int _k = atoi(k.c_str());
			int product = (_k*n);
			string _product = to_string(product);
			to_words(_product);
		}
	}
}





