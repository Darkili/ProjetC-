#include "Individu.h"
#include "Infirmiere.h"
#include "Coursier.h"
#include "Medecin.h"
#include "Patient.h"
#include "Rdv.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Rdv::Rdv()
{
	compteur++;
	idUnique = compteur;

	this->typeRdv = String::Empty;
	this->idIndividu = String::Empty;
	this->idTournee = String::Empty;
	this->idEmploye = String::Empty;
	this->commentaire = String::Empty;
	this->diabetique = false;
	this->aJeun = false;
	this->prelevements = 0;

	actif = true;
}

void Rdv::setTypeRdv(System::String ^ const type)
{
	this->typeRdv = type;
}

void Rdv::setIdIndividu(System::String^ const id)
{
	this->idIndividu = id;
}

void Rdv::setIdTournee(System::String ^ const id)
{
	this->idTournee = id;
}

void Rdv::setIdEmploye(System::String ^ const id)
{
	this->idEmploye = id;
}

void Rdv::setCommentaire(System::String ^ const commentaire)
{
	this->commentaire = commentaire;
}

void Rdv::setDate(System::String ^ const date)
{
	this->date = date;
}

void Rdv::setDiabetique(bool const var)
{
	this->diabetique = var;
}

void Rdv::setAJeun(bool const var)
{
	this->aJeun = var;
}

void Rdv::setPrelevements(int const nbr)
{
	this->prelevements = nbr;
}

void Rdv::setActif(bool const var)
{
	this->actif = var;
}

System::String ^ const Rdv::getTypeRdv()
{
	return typeRdv;
}

System::String^ const Rdv::getIdIndividu()
{
	return idIndividu;
}

System::String ^ const Rdv::getIdTournee()
{
	return idTournee;
}

System::String ^ const Rdv::getIdEmploye()
{
	return idEmploye;
}

System::String ^ const Rdv::getCommentaire()
{
	return commentaire;
}

System::String ^ const Rdv::getDate()
{
	return date;
}

bool const Rdv::getDiabetique()
{
	return diabetique;
}

bool const Rdv::getAJeun()
{
	return aJeun;
}

int const Rdv::getPrelevements()
{
	return prelevements;
}

int const Rdv::getID()
{
	return idUnique;
}

bool const Rdv::isActif()
{
	return actif;
}

Rdv ^ Rdv::findRendezVous(System::Collections::Generic::List<Rdv^>% liste, int id)
{
	for each(Rdv ^rdv in liste)
	{
		if (rdv->getID() == id)
		{
			return rdv;
		}
	}

	return nullptr;
}

void Rdv::saveRendezVous(System::Collections::Generic::List<Rdv^>% liste)
{
	String^ fileName = "RendezVous.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Rdv ^rdv in liste)
	{
		sw->WriteLine(rdv->isActif());
		sw->WriteLine(rdv->getTypeRdv());
		sw->WriteLine(rdv->getIdIndividu());
		sw->WriteLine(rdv->getIdTournee());
		sw->WriteLine(rdv->getIdEmploye());
		sw->WriteLine(rdv->getCommentaire());
		sw->WriteLine(rdv->getDate());
		sw->WriteLine(rdv->getDiabetique());
		sw->WriteLine(rdv->getAJeun());
		sw->WriteLine(rdv->getPrelevements());
	}

	sw->Close();
}

int Rdv::loadRendezVous(System::Collections::Generic::List<Rdv^>% liste)
{
	String^ fileName = "RendezVous.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Rdv ^ rdv = gcnew Rdv;

			rdv->setActif(System::Convert::ToBoolean(din->ReadLine()));
			rdv->setTypeRdv(din->ReadLine());
			rdv->setIdIndividu(din->ReadLine());
			rdv->setIdTournee(din->ReadLine());
			rdv->setIdEmploye(din->ReadLine());
			rdv->setCommentaire(din->ReadLine());
			rdv->setDate(din->ReadLine());
			rdv->setDiabetique(System::Convert::ToBoolean(din->ReadLine()));
			rdv->setAJeun(System::Convert::ToBoolean(din->ReadLine()));
			rdv->setPrelevements(System::Convert::ToInt32(din->ReadLine()));

			liste.Add(rdv);
		}

		din->Close();
	}

	return liste.Count;
}
