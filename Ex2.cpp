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

	//Constructor = functie memmbra speciala, nu are tip returnat, au acelasi nume cu clasa
	//il folosim pt a crea obiecte
	// 3 feluri: 
	//1. constructor fara parametri/implicit/default
	//2. constructor cu parametri (de la 1 la nr atributelor din clasa
	//3. constructor de copiere

	Activitate() :idActivitate(numarator++)
	{ //constructor fara parametri
		this->denumire = NULL;
		this->locatie = "";
		this->durata = 0;
		this->nrObiecte = 0;
		this->denumireObiecte = NULL;
		this->greutateObiecte = NULL;
		this->gradDificultate = Usoara;
	}

	Activitate(const char* denumire,string locatie, int durata, int nrObiecte, string* denumireObiecte, float* greutateObiecte, grad gradDificultate ):idActivitate(numarator++) 
	{
	 
	}
};

//initializarea staticului
int Activitate::numarator = 1;

void main() {
	Activitate a;
}