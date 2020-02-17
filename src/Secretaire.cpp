#include "Individu.h"
#include "Secretaire.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Secretaire::Secretaire() : Individu()
{
	compteur++;

	if (compteur < 10)
		idUnique = "Sec0" + compteur;
	else
		idUnique = "Sec" + compteur;
}

Secretaire::~Secretaire()
{
	compteur--;
}

void Secretaire::setIdControlLogin(int const idLogin)
{
	this->idControlLogin = idLogin;
}

void Secretaire::setNumInami(System::String ^ const num)
{
	throw gcnew System::NotImplementedException();
}

void Secretaire::setPrixPresta(float const prix)
{
	throw gcnew System::NotImplementedException();
}

void Secretaire::setFreelance(System::Boolean const var)
{
	throw gcnew System::NotImplementedException();
}

int const  Secretaire::getIdControlLogin()
{
	return idControlLogin;
}

System::String ^ const Secretaire::getNumInami()
{
	
	return "";
}

float const Secretaire::getPrixPresta()
{
	
	return 0.0;
}

System::Boolean const Secretaire::getFreelance()
{
	return false;
}

Secretaire^ Secretaire::findSecretaire(Generic::List<Secretaire^> %liste, System::String ^id)
{
	for each(Secretaire ^secretaire in liste)
	{
		if (secretaire->getId() == id)
		{
			return secretaire;
		}
	}

	return nullptr;
}

void Secretaire::saveSecretaire(List<Individu^> %liste)
{
	String^ fileName = "Secretaire.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Secretaire ^secretaire in liste)
	{
		sw->WriteLine(secretaire->estActif());
		sw->WriteLine(secretaire->getNom());
		sw->WriteLine(secretaire->getPrenom());
		sw->WriteLine(secretaire->getGsm());
		sw->WriteLine(secretaire->getTelephone());
		sw->WriteLine(secretaire->getEmail());
		sw->WriteLine(secretaire->getAdresse());
		sw->WriteLine(secretaire->getIdLocalite());
		sw->WriteLine(secretaire->getIdControlLogin());
	}

	sw->Close();
}

int Secretaire::loadSecretaire(List<Individu^> %liste)
{
	String^ fileName = "Secretaire.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Secretaire ^ secretaire = gcnew Secretaire;

			secretaire->setActif(System::Convert::ToBoolean(din->ReadLine()));
			secretaire->setNom(din->ReadLine());
			secretaire->setPrenom(din->ReadLine());
			secretaire->setGsm(din->ReadLine());
			secretaire->setTelephone(din->ReadLine());
			secretaire->setEmail(din->ReadLine());
			secretaire->setAdresse(din->ReadLine());
			secretaire->setIdLocalite(System::Convert::ToInt32(din->ReadLine()));
			secretaire->setIdControlLogin(System::Convert::ToInt32(din->ReadLine()));

			liste.Add(secretaire);
		}

		din->Close();
	}

	return liste.Count;
}