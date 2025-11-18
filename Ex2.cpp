#define _CRT_SECURE_NO_WARNINGS
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
		//validare pt durata (numeric)
		if (durata > 0)
		{
			this->durata = durata;
		}
		else
		{
			this->durata = 0;
		}

		if (nrObiecte > 0 && denumireObiecte != NULL & greutateObiecte != NULL)
		{
			this->nrObiecte = nrObiecte;
			this->denumireObiecte = new string[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->denumireObiecte[i] = denumireObiecte[i];
			}
			this->greutateObiecte = new float[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->greutateObiecte[i] = greutateObiecte[i];
			} 			
		}
		else
		{
			this->nrObiecte = 0;
			this->denumireObiecte = NULL;
			this->greutateObiecte = NULL;
		}
		this->gradDificultate = gradDificultate;
	}

	//constructorul de copiere
	Activitate(const Activitate& a) :idActivitate(a.idActivitate)
	{
			if (strlen(denumire) >= 3)
			{
				this->denumire = new char[strlen(a.denumire) + 1];
				strcpy(this->denumire, a.denumire);
			}
			else
			{
				this->denumire = new char[strlen("Necunoscut") + 1];
				strcpy(this->denumire, "Necunoscut");
			}
		//validare pt string
		if (locatie.size() >= 3)
		{
			this->locatie = a.locatie;
		}
		else
		{
			this->locatie = "Necunoscuta";
		}
		//validare pt durata (numeric)
		if (durata > 0)
		{
			this->durata = a.durata;
		}
		else
		{
			this->durata = 0;
		}

		if (nrObiecte > 0 && denumireObiecte != NULL & greutateObiecte != NULL)
		{
			this->nrObiecte = a.nrObiecte;
			this->denumireObiecte = new string[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->denumireObiecte[i] = a.denumireObiecte[i];
			}
			this->greutateObiecte = new float[this->nrObiecte];
			for (int i = 0; i < this->nrObiecte; i++)
			{
				this->greutateObiecte[i] = a.greutateObiecte[i];
			}
		}
		else
		{
			this->nrObiecte = 0;
			this->denumireObiecte = NULL;
			this->greutateObiecte = NULL;
		}
		this->gradDificultate = a.gradDificultate;
	}

	const int getIdActivitate()
	{
		return this->idActivitate;
	}
	char* getDenumire()
	{
		return this->denumire;
	}
	string getLocatie()
	{
		return this->locatie;
	}
	int getDurata() 
	{
		return this->durata;
	}
	int getNrObiecte()
	{
		return this->nrObiecte;
	}
	string* getDenumireObiecte()
	{
		return this->denumireObiecte;
	}
	float* getGreutateObiecte()
	{
		return this->greutateObiecte;
	}
	grad getGradDificultate()
	{
		return this->gradDificultate;
	}

	//operatorul =
	Activitate& operator=(const Activitate& a)
	{
		if (this != &a)
		{
			if (this->denumire != NULL)
			{
				delete[]this->denumire;
			}
			if (this->denumireObiecte != NULL)
			{
				delete[]this->denumireObiecte;
			}
			if (this->greutateObiecte != NULL)
			{
				delete[]this->greutateObiecte;
			}
			if (strlen(denumire) >= 3)
			{
				this->denumire = new char[strlen(a.denumire) + 1];
				strcpy(this->denumire, a.denumire);
			}
			else
			{
				this->denumire = new char[strlen("Necunoscut") + 1];
				strcpy(this->denumire, "Necunoscut");
			}
			if (locatie.size() >= 3)
			{
				this->locatie = a.locatie;
			}
			else
			{
				this->locatie = "Necunoscuta";
			}
			if (durata > 0)
			{
				this->durata = a.durata;
			}
			else
			{
				this->durata = 0;
			}

			if (nrObiecte > 0 && denumireObiecte != NULL & greutateObiecte != NULL)
			{
				this->nrObiecte = a.nrObiecte;
				this->denumireObiecte = new string[this->nrObiecte];
				for (int i = 0; i < this->nrObiecte; i++)
				{
					this->denumireObiecte[i] = a.denumireObiecte[i];
				}
				this->greutateObiecte = new float[this->nrObiecte];
				for (int i = 0; i < this->nrObiecte; i++)
				{
					this->greutateObiecte[i] = a.greutateObiecte[i];
				}
			}
			else
			{
				this->nrObiecte = 0;
				this->denumireObiecte = NULL;
				this->greutateObiecte = NULL;
			}
			this->gradDificultate = a.gradDificultate;
			
			return *this;
		}
		
	}

	//destructor
	~Activitate()
	{
		if (this->denumire != NULL)
		{
			delete[]this->denumire;
		}
		if (this->denumireObiecte != NULL)
		{
			delete[]this->denumireObiecte;
		}
		if (this->greutateObiecte != NULL)
		{
			delete[]this->greutateObiecte;
		}
	}

};

//initializarea staticului
int Activitate::numarator = 1;

void main() {
	Activitate a;

	string denumiri[] = { "bara", "haltere" };
	float greutate[] = { 20, 17.5 };
	Activitate a1("Sala", "Acasa", 30, 2, denumiri, greutate, Usoara);

	cout << a1.getIdActivitate() << endl;
	cout << a1.getDenumire() << endl;
	cout << a1.getLocatie() << endl;
	cout << a1.getDurata() << endl;
	cout << a1.getNrObiecte() << endl;
	for (int i = 0; i < a1.getNrObiecte(); i++)
	{
		cout << a1.getDenumireObiecte()[i] << endl;

	}
	for (int i = 0; i < a1.getNrObiecte(); i++)
	{
		cout << a1.getGreutateObiecte()[i] << endl;
	}	
	cout << a1.getGradDificultate() << endl;

	Activitate a2 = a1;

	
}