#include<iostream>
using namespace std;

class Fruct {

private:
	const int idFruct;
	static int numarFructe;
	char* nume;
	string culoare;
	float greutate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;

public:

	//constructorul default
	Fruct():idFruct(++numarFructe)
	{
		this->nume = NULL;
		this->culoare = "Necunoscuta";
		this->greutate = 0;
		this->lunaMaturitate = 0;
		this->nrSeminte = 0;
		this->greutatiSeminte = NULL;
	}

	//constructorul cu toti parametrii
	Fruct(const char* nume, string culoare, float greutate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) :idFruct(++numarFructe)
	{
		//alocare memorie pt char
		//validare char
		if (strlen(nume) >= 3)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
		{
			this->nume = new char[strlen("N/A") + 1];
			strcpy_s(this->nume, strlen("N/A") + 1, "N/A");
		}
		
		
		//validare string
		if(culoare.size() >= 3) {
			this->culoare = culoare;

		}
		else
		{
			this->culoare = "";

		}
		//validare numeric
		if (greutate > 0)
		{
			this->greutate = greutate;
			this->lunaMaturitate = lunaMaturitate;

		}
		else
		{
			this->greutate = 0;
			this->lunaMaturitate = 0;

		}
		
		//alocare memorie pt float
		//validare vector
		if (nrSeminte > 0 && greutatiSeminte != NULL)
		{
			this->nrSeminte = nrSeminte;
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < this->nrSeminte; i++)
			{
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
		else
		{
			this->nrSeminte = 0;
			this->greutatiSeminte = NULL;

		}
	}

	//constructorul de copiere
	Fruct(const Fruct& copie) :idFruct(++numarFructe)
	{
		this->culoare = copie.culoare;
		this->greutate = copie.greutate;
		this->lunaMaturitate = copie.lunaMaturitate;
		this->nrSeminte = copie.nrSeminte;

		if (copie.greutatiSeminte != NULL)
		{
			this->greutatiSeminte = new float[copie.nrSeminte];
			for (int i = 0; i < copie.nrSeminte; i++)
			{
				this->greutatiSeminte[i] = copie.greutatiSeminte[i];
			}
		}
		else
		{
			this->greutatiSeminte = NULL;
		}

		if (copie.nume != NULL)
		{
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy_s(this->nume, strlen(copie.nume) + 1, copie.nume);
		}
		else 
		{
			this->nume = NULL;
		}
	}



};

int Fruct::numarFructe = 0;

void main()
{
	float* vector = new float[3] {0.1, 0.2, 0.3};
	Fruct fruct("Mar", "Galben", 0.4, 8, 3, vector);


}