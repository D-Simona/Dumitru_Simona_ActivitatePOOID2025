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

	//constructorul cu toti parametri
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

	//getteri si setteri
	float getGreutate()
	{
		return this->greutate;
	}

	void setGreutate(float greutate)
	{
		if (greutate > 0)
		{
			this->greutate = greutate;
		}
	}

	char* gretNume()
	{
		return this->nume;
	}

	void setNume(const char* nume)
	{
		if (strlen(nume) >= 3)
		{
			if (this->nume != NULL) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	float* getGreutatiSeminte()
	{
		return this->greutatiSeminte;
	}

	float getGreutateSamanata(int pozitie)
	{
		if (pozitie >= 0 && pozitie < nrSeminte)
		{
			return this->greutatiSeminte[pozitie];
		}
		throw 404;
	}

	void setGreutatiSeminte(int nrSeminte, float* greuatatiSeminte)
	{
		if (nrSeminte > 0)
		{
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != NULL) {
				delete[]this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++)
			{
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	int getIdFruct()
	{
		return this->idFruct;
	}

	static int getNumarFructe()
	{
		return numarFructe;
	}
	void setNumarFructe(int nrFructe)
	{
		numarFructe = nrFructe;
	}

	int getLunaMaturitate()
	{
		return this->lunaMaturitate;
	}

	string getCuloare()
	{
		return this->culoare;
	}

	void setCuloare(string culoare)
	{
		if (culoare.size() > 0)
		{
			this->culoare = culoare;
		}
	}
	int getNumarSeminte()
	{
		return this->nrSeminte;
	}
		

	//operatorul =
	Fruct operator=(const Fruct& copie)
	{
		if (this != &copie)
		{
			this->culoare = copie.culoare;
			this->greutate = copie.greutate;
			this->lunaMaturitate = copie.lunaMaturitate;
			this->nrSeminte = copie.nrSeminte;

			if (this->greutatiSeminte != NULL)
			{
				delete[]this->greutatiSeminte;
				this->greutatiSeminte = NULL;
			}

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

			if (this->nume != NULL)
			{
				delete[]this->nume;
				this->nume = NULL;
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
		return *this;
	}

	//destructor
	~Fruct()
	{
		if (this->greutatiSeminte != NULL)
		{
			delete[]this->greutatiSeminte;
		}
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
	}

	//operatori

	//operatorul +=


};

int Fruct::numarFructe = 0;

void main()
{
	float* vector = new float[3] {0.1, 0.2, 0.3};
	Fruct fruct("Mar", "Galben", 0.4, 8, 3, vector);

	try {
		cout << endl << fruct.getGreutateSamanata(3);
	}
	catch (int cod)
	{
		cout << endl << cod;
	}
	catch (const char* mesaj)
	{

		cout << endl << mesaj;
	}
	catch (...)
	{
		cout << endl < "Pozitia este in afara intervalului";
	}

	Fruct fruct2 = fruct;

	Fruct fructDefault;
	fructDefault = fruct;
}