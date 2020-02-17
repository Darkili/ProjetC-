#include "Individu.h"
#include "Medecin.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Medecin::Medecin()
{
	compteur++;

	if (compteur < 10)
		idUnique = "Med0" + compteur;
	else
		idUnique = "Med" + compteur;
}

Medecin::~Medecin()
{
	compteur--;
}

void Medecin::setIdControlLogin(int const idLogin)
{
}

void Medecin::setNumInami(System::String ^ const num)
{
	numInami = num;
}

void Medecin::setPrixPresta(float const prix)
{
	throw gcnew System::NotImplementedException();
}

void Medecin::setFreelance(System::Boolean const var)
{
	throw gcnew System::NotImplementedException();
}

int const Medecin::getIdControlLogin()
{
	return 0;
}

System::String ^ const Medecin::getNumInami()
{
	return numInami; 
}

float const Medecin::getPrixPresta()
{
	//throw gcnew System::NotImplementedException();
	return 0.0;
}

System::Boolean const Medecin::getFreelance()
{
	//throw gcnew System::NotImplementedException();
	return false;
}

Medecin^ Medecin::findMedecin(List<Medecin^> %liste, System::String ^id)
{
	for each(Medecin ^medecin in liste)
	{
		if (medecin->getId() == id)
		{
			return medecin;
		}
	}

	return nullptr;
}

void Medecin::saveMedecin(List<Individu^> %liste)
{
	String^ fileName = "Medecin.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Medecin ^medecin in liste)
	{
		sw->WriteLine(medecin->estActif());
		sw->WriteLine(medecin->getNom());
		sw->WriteLine(medecin->getPrenom());
		sw->WriteLine(medecin->getGsm());
		sw->WriteLine(medecin->getTelephone());
		sw->WriteLine(medecin->getEmail());
		sw->WriteLine(medecin->getAdresse());
		sw->WriteLine(medecin->getIdLocalite());

		sw->WriteLine(medecin->getNumInami());
	}

	sw->Close();
}

int Medecin::loadMedecin(List<Individu^> %liste)
{
	String^ fileName = "Medecin.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Medecin ^ medecin = gcnew Medecin;

			medecin->setActif(System::Convert::ToBoolean(din->ReadLine()));
			medecin->setNom(din->ReadLine());
			medecin->setPrenom(din->ReadLine());
			medecin->setGsm(din->ReadLine());
			medecin->setTelephone(din->ReadLine());
			medecin->setEmail(din->ReadLine());
			medecin->setAdresse(din->ReadLine());
			medecin->setIdLocalite(System::Convert::ToInt32(din->ReadLine()));

			medecin->setNumInami(din->ReadLine());

			liste.Add(medecin);
		}

		din->Close();
	}

	return liste.Count;
}