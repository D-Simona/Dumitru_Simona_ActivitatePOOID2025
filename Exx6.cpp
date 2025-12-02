#include<iostream>
#include<string>

using namespace std;

class Biblioteca {
private:
	string adresa;
	int nrAbonati;
	float pretAbonament;
	string* ultimaVizita;
public:
	Biblioteca() {
		this->adresa = "";
		this->nrAbonati = 0;
		this->pretAbonament = 0;
		this->ultimaVizita = NULL;
	}

	string getAdresa()
	{
		return this->adresa;
	}
	void setAdresa(string adresa)
	{
		this->adresa = adresa;
	}
	string* getUltimaVizita()
	{
		return this->ultimaVizita;
	}
	void setUltimaVizita(string* ultimaVizita, int nrAbonati)
	{

		if (nrAbonati > 0 && ultimaVizita != NULL)
		{
			this->nrAbonati = nrAbonati;
			this->ultimaVizita = new string[this->nrAbonati];
			for (int i = 0; i < this->nrAbonati; i++)
			{
				this->ultimaVizita[i] = ultimaVizita[i];
			}
		}
	}

};

void main()
{
	Biblioteca default;
	cout << default.getAdresa();
	default.setAdresa("Bucuresti");

}