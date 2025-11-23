#include<iostream>
#include<string>

using namespace std;

class Student
{
private:
	const int idStudent;//nr unic pentru student
	string nume;
	int nota;
	string* materii;
	int nrMaterii; //dimensiunea vectorului

public:
	static int numarator; //pt a numara studentii (obiectele)

	//constructorul default
	Student():idStudent(numarator++)
	{
		this->nume = "N/A";
		this->nota = 0;
		this->materii = NULL;
		this->nrMaterii = 0;
	}

	Student(string nume, int nota, string* materii, int nrMaterii) :idStudent(numarator++)
	{
		if (nume.size() >= 3)
		{
			this->nume = nume;
		}
		else
		{
			this->nume = "N/A";
		}
		
		if(nota > 0)
		{
			this->nota = nota;
		}
		else
		{
			this->nota = 0;
		}
		if (nrMaterii > 0 && materii != NULL)
		{
			this->nrMaterii = nrMaterii;
			for (int i = 0; i < this->nrMaterii; i++)
			{
				this->materii[i] = materii[i];
			}
		}
		else
		{
			this->nrMaterii = 0;
			this->materii = NULL;
		}
	}

	~Student()
	{
		if (this->materii != NULL)
		{
			delete[]this->materii;

		}
		numarator--;
	}

};

int Student::numarator = 1;

void main()
{


}