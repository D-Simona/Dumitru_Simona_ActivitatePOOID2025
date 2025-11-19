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
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume)+1, nume);
		
		this->culoare = culoare;
		this->greutate = greutate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;
		
		//alocare memorie pt float
		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < this->nrSeminte; i++)
		{
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
	}

	//constructorul de copiere


};

int Fruct::numarFructe = 0;

void main()
{


}