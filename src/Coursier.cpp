#include "Individu.h"
#include "Coursier.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Coursier::Coursier()
{
	compteur++;

	if (compteur < 10)
		idUnique = "Cou0" + compteur;
	else
		idUnique = "Cou" + compteur;
}

Coursier::~Coursier()
{
	compteur--;
}

void Coursier::setIdControlLogin(int const idLogin)
{
	this->idControlLogin = idLogin;
}

void Coursier::setNumInami(System::String ^ const num)
{
	throw gcnew System::NotImplementedException();
}

void Coursier::setPrixPresta(float const prix)
{
	throw gcnew System::NotImplementedException();
}

void Coursier::setFreelance(System::Boolean const var)
{
	throw gcnew System::NotImplementedException();
}

int const Coursier::getIdControlLogin()
{
	return idControlLogin;
}

System::String ^ const Coursier::getNumInami()
{	
	return "";
}

float const Coursier::getPrixPresta()
{
	return 0.0;
}

System::Boolean const Coursier::getFreelance()
{
	return false;
}

Coursier^ Coursier::findCoursier(List<Coursier^> %liste, System::String ^id)
{
	for each(Coursier ^crs in liste)
	{
		if (crs->getId() == id)
		{
			return crs;
		}
	}

	return nullptr;
}

void Coursier::saveCoursier(List<Individu^> %liste)
{
	String^ fileName = "Coursier.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Coursier ^crs in liste)
	{
		sw->WriteLine(crs->estActif());
		sw->WriteLine(crs->getNom());
		sw->WriteLine(crs->getPrenom());
		sw->WriteLine(crs->getGsm());
		sw->WriteLine(crs->getTelephone());
		sw->WriteLine(crs->getEmail());
		sw->WriteLine(crs->getAdresse());
		sw->WriteLine(crs->getIdLocalite());
		sw->WriteLine(crs->getIdControlLogin());
	}

	sw->Close();
}

int Coursier::loadCoursier(List<Individu^> %liste)
{
	String^ fileName = "Coursier.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Coursier ^ crs = gcnew Coursier;

			crs->setActif(System::Convert::ToBoolean(din->ReadLine()));
			crs->setNom(din->ReadLine());
			crs->setPrenom(din->ReadLine());
			crs->setGsm(din->ReadLine());
			crs->setTelephone(din->ReadLine());
			crs->setEmail(din->ReadLine());
			crs->setAdresse(din->ReadLine());
			crs->setIdLocalite(System::Convert::ToInt32(din->ReadLine()));
			crs->setIdControlLogin(System::Convert::ToInt32(din->ReadLine()));

			liste.Add(crs);
		}

		din->Close();
	}

	return liste.Count;
}