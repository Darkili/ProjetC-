#include "Localite.h"
#include "Individu.h"
#include "Secretaire.h"
#include "Infirmiere.h"
#include "Coursier.h"
#include "Medecin.h"
#include "Patient.h"
#include "Rdv.h"
#include "Tourner.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Text::RegularExpressions;

Tourner::Tourner()
{
	compteur++;

	if (compteur < 10)
		idUnique = "Trn0" + compteur;
	else
		idUnique = "Trn" + compteur;

	setBoolJour("Monday", false);
	setBoolJour("Tuesday", false);
	setBoolJour("Wednesday", false);
	setBoolJour("Thursday", false);
	setBoolJour("Friday", false);
	setBoolJour("Saturday", false);
	setBoolJour("Sunday", false);

	this->actif = true;
}

Tourner::Tourner(System::Collections::Generic::List<Localite^>^ liste)
{
	compteur++;

	if (compteur < 10)
		idUnique = "Trn0" + compteur;
	else
		idUnique = "Trn" + compteur;

	setBoolJour("Monday", false);
	setBoolJour("Tuesday", false);
	setBoolJour("Wednesday", false);
	setBoolJour("Thursday", false);
	setBoolJour("Friday", false);
	setBoolJour("Saturday", false);
	setBoolJour("Sunday", false);

	for each(Localite ^localite in liste)
	{
		setLocTournee(localite->getCodePostal() + " " + localite->getNomLocalite(), false);
	}

	this->actif = true;
}

void Tourner::setActif(bool var)
{
	actif = var;
}

void Tourner::setNom(System::String ^ nom)
{
	this->nom = nom;
}

void Tourner::setTypeTournee(System::String ^ type)
{
	this->typeTournee = type;
}

void Tourner::setBoolJour(System::String ^ jour, bool var)
{
	jourSemaine[jour] = var;
}

void Tourner::setLocTournee(System::String ^ localite, bool var)
{
	locTournee[localite] = var;
}

bool Tourner::isActif()
{
	return actif;
}

System::String ^ const Tourner::getNom()
{
	return nom;
}

System::String ^ const Tourner::getTypeTournee()
{
	return typeTournee;
}

bool const Tourner::getBoolJour(System::String ^ jour)
{
	return jourSemaine[jour];
}

bool const Tourner::getLocTournee(System::String ^ localite)
{
	return locTournee[localite];
}

System::String ^ const Tourner::getId()
{
	return idUnique;
}

System::Collections::Generic::Dictionary<System::String^, bool>^ Tourner::getAttributLocTournee()
{
	return %locTournee;
}

Tourner ^ Tourner::findTournee(System::Collections::Generic::List<Tourner^>% liste, System::String ^id)
{
	for each(Tourner ^trn in liste)
	{
		if (trn->getId() == id)
		{
			return trn;
		}
	}

	return nullptr;
}

void Tourner::saveTourner(System::Collections::Generic::List<Tourner^>% liste, System::Collections::Generic::List<Localite^> %listeLoc)
{
	int nbrElements = 0;

	String^ fileName = "Tourner.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Tourner ^trn in liste)
	{
		sw->WriteLine(trn->isActif());
		sw->WriteLine(trn->getNom());
		sw->WriteLine(trn->getTypeTournee());
		sw->WriteLine(trn->getBoolJour("Monday"));
		sw->WriteLine(trn->getBoolJour("Tuesday"));
		sw->WriteLine(trn->getBoolJour("Wednesday"));
		sw->WriteLine(trn->getBoolJour("Thursday"));
		sw->WriteLine(trn->getBoolJour("Friday"));
		sw->WriteLine(trn->getBoolJour("Saturday"));
		sw->WriteLine(trn->getBoolJour("Sunday"));

		for each(bool var in trn->getAttributLocTournee()->Values)
		{
			if (var == true)
			{
				nbrElements++;
			}
		}

		sw->WriteLine(nbrElements);

		for each(System::String^ loc in trn->getAttributLocTournee()->Keys)
		{
			if (trn->getAttributLocTournee()[loc] == true)
			{
				sw->WriteLine(loc);
			}
		}

		nbrElements = 0;
	}

	sw->Close();
}

int Tourner::loadTourner(System::Collections::Generic::List<Tourner^> %liste, System::Collections::Generic::List<Localite^> %listeLoc)
{
	int nbrElements = 0;

	String^ fileName = "Tourner.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Tourner ^ trn = gcnew Tourner(%listeLoc);

			trn->setActif(System::Convert::ToBoolean(din->ReadLine()));
			trn->setNom(din->ReadLine());
			trn->setTypeTournee(din->ReadLine());
			trn->setBoolJour("Monday", System::Convert::ToBoolean(din->ReadLine()));
			trn->setBoolJour("Tuesday", System::Convert::ToBoolean(din->ReadLine()));
			trn->setBoolJour("Wednesday", System::Convert::ToBoolean(din->ReadLine()));
			trn->setBoolJour("Thursday", System::Convert::ToBoolean(din->ReadLine()));
			trn->setBoolJour("Friday", System::Convert::ToBoolean(din->ReadLine()));
			trn->setBoolJour("Saturday", System::Convert::ToBoolean(din->ReadLine()));
			trn->setBoolJour("Sunday", System::Convert::ToBoolean(din->ReadLine()));

			nbrElements = System::Convert::ToInt32(din->ReadLine());

			for (int i = 0; i < nbrElements; ++i)
			{
				trn->setLocTournee(din->ReadLine(), true);
			}

			liste.Add(trn);
		}

		din->Close();
	}

	return liste.Count;
}
