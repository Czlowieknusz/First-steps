#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void deleting(char* Tablica[],int &iWord_Len)
{
	for(int i=0;i<iWord_Len;i++)
	{
		delete[] Tablica[i];
	}
}

int main()
{
	cout << "========== Application sorting words given by the user ==========\n\n\n";
	const int iSize=40;
	int iWord_Len=0;
	char* Tablica[iSize];
	
	for(int i=0; i<iSize;i++)
	{
		char cNew_Word[81];
		cout << "Write a word of max length up to 80 chars/Enter to break: ";
		cin.getline(cNew_Word,80);
		if(cNew_Word[0]!=NULL)
		{
			Tablica[i]=new char[strlen(cNew_Word)+1];
			strcpy(Tablica[i],cNew_Word);
			iWord_Len++;
		}
		else
		{
			break;
		}
	}
	char** newTablica= new char*[iWord_Len];
	for(int i=0;i<iWord_Len;i++)
	{
		newTablica[i]=new char[strlen(Tablica[i])+1];
		strcpy(newTablica[i],Tablica[i]);
	}
	deleting(Tablica,iWord_Len);
	for(int i=0;i<iWord_Len;i++)
	{
		for(int j=0;j<iWord_Len;j++)
		{
			if(stricmp(newTablica[j],newTablica[i])>0)
			{
				swap(newTablica[i],newTablica[j]);
			}
		}
	}
	
	cout << "Sorted Words: " << endl;
	for(int i=0;i<iWord_Len;i++)
	{
		cout <<i+1 << " word: "<< newTablica[i]<<endl;
	}

	deleting(newTablica,iWord_Len);
	system("pause");
	return 0;
}