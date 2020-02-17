#include "Localite.h"
#include "Individu.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Individu::Individu()
{
	compteur++;
	idUnique = "ind" + compteur;

	this->nom = String::Empty;
	this->prenom = String::Empty;
	this->gsm = String::Empty;
	this->telephone = String::Empty;
	this->email = String::Empty;
	this->adresse = String::Empty;
	this->idLocalite = 0;

	actif = true;
}

Individu::Individu(System::String^ nom)
{
	compteur++;
	idUnique = "ind" + compteur;

	this->nom = String::Empty;
	this->prenom = String::Empty;
	this->gsm = String::Empty;
	this->telephone = String::Empty;
	this->email = String::Empty;
	this->adresse = String::Empty;
	this->idLocalite = 0;

	actif = true;
}

Individu::~Individu()
{
	compteur--;
}

void Individu::setNom(System::String^ const nom)
{
	this->nom = nom;
}

void Individu::setPrenom(System::String^ const prenom)
{
	this->prenom = prenom;
}

void Individu::setGsm(System::String^ const gsm)
{
	this->gsm = gsm;
}

void Individu::setTelephone(System::String^ const telephone)
{
	this->telephone = telephone;
}

void Individu::setEmail(System::String^ const email)
{
	this->email = email;
}

void Individu::setAdresse(System::String^ const adresse)
{
	this->adresse = adresse;
}

void Individu::setIdLocalite(int localite)
{
	this->idLocalite = localite;
}

void Individu::setActif(bool var)
{
	this->actif = var;
}

System::String ^ const Individu::getId()
{
	return idUnique;
}

System::String ^ const Individu::getNom()
{
	return nom;
}

System::String ^ const Individu::getPrenom()
{
	return prenom;
}

System::String ^ const Individu::getGsm()
{
	return gsm;
}

System::String ^ const Individu::getTelephone()
{
	return telephone;
}

System::String ^ const Individu::getEmail()
{
	return email;
}

System::String ^ const Individu::getAdresse()
{
	return adresse;
}

int const Individu::getIdLocalite()
{
	return idLocalite;
}

bool const Individu::estActif()
{
	return actif;
}

Individu^ Individu::findIndividu(List<Individu^> %liste, System::String ^id)
{
	for each(Individu ^individu in liste)
	{
		if (individu->getId() == id)
		{
			return individu;

		}
	}

	return nullptr;
}