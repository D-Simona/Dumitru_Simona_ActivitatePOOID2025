#include<iostream>
#include<string>
using namespace std;

enum grad
{
	Usoara, Medie, Grea, FoarteGrea
};

class Activitate 
{
	const int idActivitate;
	
protected:
	char* denumire;
	string locatie;
	int durata; //minute
	int nrObiecte;
	string* denumireObiecte;
	float* greutateObiecte;
	grad gradDificultate;

public:
	static int numarator;


	Activitate() :idActivitate(numarator++)
	{ //constructor fara parametri
		this->denumire = NULL;
		this->locatie = "Necunoscuta";
		this->durata = 0;
		this->nrObiecte = 0;
		this->denumireObiecte = NULL;
		this->greutateObiecte = NULL;
		this->gradDificultate = Usoara;
	}

	//constructor cu toti parametri
	Activitate(const char* denumire,string locatie, int durata, int nrObiecte, string* denumireObiecte, float* greutateObiecte, grad gradDificultate ):idActivitate(numarator++) 
	{
		//validare pt char*
		if (strlen(denumire) >= 3)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = new char[strlen("Necunoscut") + 1];
			strcpy(this->denumire, "Necunoscut");
		}
		//validare pt string
		if (locatie.size() >= 3)
		{
			this->locatie = locatie;
		}
		else
		{
			this->locatie = "Necunoscuta";
		}
	}
};

//initializarea staticului
int Activitate::numarator = 1;

void main() {
	Activitate a;
}