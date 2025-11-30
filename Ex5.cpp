#include<iostream>

using namespace std;

class Calatorie
{
private:
	char* numeDestinatie;
	const int idCalatorie;
public:

	Calatorie(const char* numeDestinatie) :idCalatorie(1)
	{
		if (strlen(numeDestinatie) >= 3)
		{
			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
			strcpy_s(this->numeDestinatie, strlen(numeDestinatie) + 1, numeDestinatie);
		}
		else
		{
			this->numeDestinatie = new char[strlen("N/A") + 1];
			strcpy_s(this->numeDestinatie, strlen("N/A") + 1, "N/A");
		}
	}

	int getIdCalatorie()
	{
		return this->idCalatorie;
	}

	void setNumeDestinatie(const char* numeDestinatie)
	{
		if (strlen(numeDestinatie) >= 3)
		{
			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
			strcpy_s(this->numeDestinatie, strlen(numeDestinatie) + 1, numeDestinatie);
		}
		else
		{
			this->numeDestinatie = new char[strlen("N/A") + 1];
			strcpy_s(this->numeDestinatie, strlen("N/A") + 1, "N/A");
		}
	}

	Calatorie operator=(const Calatorie& c)
	{
		if (this != &c)
		{
			if (this->numeDestinatie != NULL)
			{
				delete[]this->numeDestinatie;
				this->numeDestinatie = NULL;
			}
			if (c.numeDestinatie != NULL)
			{
				this->numeDestinatie = new char[strlen(c.numeDestinatie) + 1];
				strcpy_s(this->numeDestinatie, strlen(c.numeDestinatie) + 1, c.numeDestinatie);
			}
			else
			{
				this->numeDestinatie = NULL;
			}
		}
		return *this;
	}

	friend void operator<<(ostream& out, Calatorie c)
	{
		out << "Id: " << c.idCalatorie;
		out << (c.numeDestinatie != NULL ? "Nume destinatie: " + string(c.numeDestinatie) : "Nume nespecificat");
	}

	void operator()(const char* numeDestinatie)
	{

		if (strlen(numeDestinatie) >= 3)
		{
			this->numeDestinatie = new char[strlen(numeDestinatie) + 1];
			strcpy_s(this->numeDestinatie, strlen(numeDestinatie) + 1, numeDestinatie);
		}
		else
		{
			this->numeDestinatie = new char[strlen("N/A") + 1];
			strcpy_s(this->numeDestinatie, strlen("N/A") + 1, "N/A");
		}
	}
};

void main()
{
	Calatorie c1("Brasov");
	cout << c1.getIdCalatorie() << endl;
	c1.setNumeDestinatie("Craiova");
	Calatorie c2("Bacau");
	c2 = c1;
	cout << c2;
	cout << endl;
	c2.operator()("Constanta");
	cout << c2;
}