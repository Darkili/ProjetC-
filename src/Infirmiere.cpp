#include "Individu.h"
#include "Infirmiere.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;

Infirmiere::Infirmiere() : Individu()
{
	compteur++;

	if (compteur < 10)
		idUnique = "Inf0" + compteur;
	else
		idUnique = "Inf" + compteur;
}

Infirmiere::~Infirmiere()
{
	compteur--;
}

void Infirmiere::setIdControlLogin(int const idLogin)
{
	this->idControlLogin = idLogin;
}

void Infirmiere::setNumInami(System::String ^ const num)
{
	numInami = num;
}

void Infirmiere::setPrixPresta(float const prix)
{
	prixPrestation = prix;
}

void Infirmiere::setFreelance(System::Boolean const var)
{
	freelance = var;
}

int const Infirmiere::getIdControlLogin()
{
	return idControlLogin;
}

System::String ^ const Infirmiere::getNumInami()
{
	return numInami;
}

float const Infirmiere::getPrixPresta()
{
	return prixPrestation;
}

System::Boolean const Infirmiere::getFreelance()
{
	return freelance;
}

Infirmiere^ Infirmiere::findInfirmiere(Generic::List<Infirmiere^> %liste, System::String ^id)
{
	for each(Infirmiere ^infirmiere in liste)
	{
		if (infirmiere->getId() == id)
		{
			return infirmiere;
		}
	}

	return nullptr;
}

void Infirmiere::saveInfirmiere(List<Individu^> %liste)
{
	String^ fileName = "Infirmiere.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Infirmiere ^infirmiere in liste)
	{
		sw->WriteLine(infirmiere->estActif());
		sw->WriteLine(infirmiere->getNom());
		sw->WriteLine(infirmiere->getPrenom());
		sw->WriteLine(infirmiere->getGsm());
		sw->WriteLine(infirmiere->getTelephone());
		sw->WriteLine(infirmiere->getEmail());
		sw->WriteLine(infirmiere->getAdresse());
		sw->WriteLine(infirmiere->getIdLocalite());

		sw->WriteLine(infirmiere->getNumInami());
		sw->WriteLine(infirmiere->getPrixPresta());
		sw->WriteLine(infirmiere->getFreelance());

		sw->WriteLine(infirmiere->getIdControlLogin());
	}

	sw->Close();
}

int Infirmiere::loadInfirmiere(List<Individu^> %liste)
{
	String^ fileName = "Infirmiere.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Infirmiere ^ infirmiere = gcnew Infirmiere;

			infirmiere->setActif(System::Convert::ToBoolean(din->ReadLine()));
			infirmiere->setNom(din->ReadLine());
			infirmiere->setPrenom(din->ReadLine());
			infirmiere->setGsm(din->ReadLine());
			infirmiere->setTelephone(din->ReadLine());
			infirmiere->setEmail(din->ReadLine());
			infirmiere->setAdresse(din->ReadLine());
			infirmiere->setIdLocalite(System::Convert::ToInt32(din->ReadLine()));

			infirmiere->setNumInami(din->ReadLine());
			infirmiere->setPrixPresta((float)Convert::ToDouble(din->ReadLine()));
			infirmiere->setFreelance(Convert::ToBoolean(din->ReadLine()));

			infirmiere->setIdControlLogin(System::Convert::ToInt32(din->ReadLine()));

			liste.Add(infirmiere);
		}

		din->Close();
	}

	return liste.Count;
}