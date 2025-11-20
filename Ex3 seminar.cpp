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
	void operator+=(float valoareDeAdaugatLaGreutate)
	{
		this->greutate += valoareDeAdaugatLaGreutate;
	}

	friend Fruct operator+=(float valoareDeAdaugatLaGreutate, Fruct& f)
	{
		f.greutate += valoareDeAdaugatLaGreutate;
		
		return f;
	}

	//operator< comparatie intre 2 obiecte dupa un atribut => returneaza bool
	bool operator<(const Fruct& f)
	{
		return this->greutate < f.greutate;
	}

	//operator negatie
	bool operator!()
	{
		return this->lunaMaturitate != 0;
	}

	//operator functie
	float operator()(int pozitie)
	{
		return this->getGreutateSamanata(pozitie);
	}

	//operator index
	char& operator[](int index)
	{
		if (index >= 0 && index < strlen(this->nume))
		{
			return this->nume[index];
		}
		else
		{
			throw "Indexul nu se afla in interval!";
		}
	}

	//explicit  operator int
	explicit operator int()
	{
		return this->lunaMaturitate;
	}

	//operator postincrementare
	Fruct operator++(int)
	{
		Fruct copie = *this;
		this->lunaMaturitate++;
		return copie;
	}

	//operator preincrementare
	Fruct operator++()
	{
		this->lunaMaturitate++;
		return *this;
	}

	//operator de afisare
	friend void operator<<(ostream& consola, Fruct f)
	{
		consola << endl << "Id :" << f.idFruct;
		consola << endl << (f.nume != NULL ? "Nume: " + string(f.nume) : "Nume nespecificat");
		consola << endl << "Culoare :" << f.culoare;
		consola << endl << "Greutate :" << f.greutate;
		consola << endl << "Luna maturitate :" << f.lunaMaturitate;
		consola << endl << "Nr seminte :" << f.nrSeminte;
		if (f.greutatiSeminte != NULL)
		{
			consola << endl << "Greutati seminte: ";
			for (int i = 0; i < f.getNumarSeminte() - 1; i++)
			{
				consola << f.getGreutateSamanata(i) << ", ";
			}
			consola << f.getGreutateSamanata(f.getNumarSeminte() - 1) << ".";
		}
		else
		{
			consola << endl << "Greutati seminte nespecificat.";
		}

	}
	friend void operator>>(istream& in, Fruct& f);

};

//operator scriere
void operator>>(istream& cititor, Fruct& f)
{
	cout << endl << "Nume: ";
	if (f.nume != NULL)
	{
		delete[]f.nume;
		f.nume = NULL;
	}
	char buffer[20];
	cititor >> buffer;
	f.nume = new char[strlen(buffer) + 1];
	strcpy_s(f.nume, strlen(buffer) + 1, buffer);

	cout << endl << "Culoare: "; cititor >> f.culoare;
	cout << endl << "Greutate: "; cititor >> f.greutate;
	cout << endl << "Luna maturitate:"; cititor >> f.lunaMaturitate;
	cout << endl << "Numar seminte: "; cititor >> f.nrSeminte;

	if (f.greutatiSeminte != NULL)
	{
		delete[]f.greutatiSeminte;
		f.greutatiSeminte = NULL;
	}
	cout << endl << "Greutati seminte: ";
	f.greutatiSeminte = new float[f.nrSeminte];
	for (int i = 0; i < f.getNumarSeminte(); i++)
	{
		cout << endl << "Greutati[" << i << "]: ";
		cititor >> f.greutatiSeminte[i];
	}
	
}

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
		cout << endl << "Pozitia este in afara intervalului";
	}

	Fruct fruct2 = fruct;

	Fruct fructDefault;
	fructDefault = fruct;

	fruct += 0.1;
	0.1 += fruct;

	if (fruct < fruct2)
	{
		cout << endl << "Primul fruct are greutatea mai mica decat al doilea fruct";
	}
	else
	{
		cout << endl << "Al doilea fruct are greutatea mai mica decat primul fruct";
	}

	if (!fruct)
	{
		cout << endl << "Fructul este copt";
	}
	else
	{
		cout << "Fructul este crud";
	}

	cout << endl << fruct(2);

	cout << endl << "Litera de pe pozitia 2 din nume este" << fruct[1];
	fruct[1] = 'e';
	cout << endl << "Litera de pe pozitia 2 din nume este" << fruct[1];

	cout << endl << (int)fruct;

	Fruct f1 = fruct++;
	//f1.lunaMaturitate=8
	cout << f1;

	Fruct f2 = ++fruct;
	//f2.lunaMaturitate=10
	cout << f2;

}