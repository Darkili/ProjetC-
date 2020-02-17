#include "Individu.h"
#include "Patient.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

Patient::Patient() : Individu()
{
	compteur++;

	if (compteur < 10)
		idUnique = "Pat0" + compteur;
	else
		idUnique = "Pat" + compteur;
}

Patient::~Patient()
{
	compteur--;
}

void Patient::setIdControlLogin(int idLogin)
{
}

void Patient::setNumInami(System::String ^ const num)
{
	throw gcnew System::NotImplementedException();
}

void Patient::setPrixPresta(float const prix)
{
	throw gcnew System::NotImplementedException();
}

void Patient::setFreelance(System::Boolean const var)
{
	throw gcnew System::NotImplementedException();
}

int const Patient::getIdControlLogin()
{
	return 0;
}

System::String ^ const Patient::getNumInami()
{
	return "";
}

float const Patient::getPrixPresta()
{
	
	return 0.0;
}

System::Boolean const Patient::getFreelance()
{
	
	return false;
}

Patient^ Patient::findPatient(List<Patient^> %liste, System::String ^id)
{
	for each(Patient ^patient in liste)
	{
		if (patient->getId() == id)
		{
			return patient;
		}
	}

	return nullptr;
}

void Patient::savePatient(List<Individu^> %liste)
{
	String^ fileName = "Patient.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(liste.Count);

	for each(Patient ^patient in liste)
	{
		sw->WriteLine(patient->estActif());
		sw->WriteLine(patient->getNom());
		sw->WriteLine(patient->getPrenom());
		sw->WriteLine(patient->getGsm());
		sw->WriteLine(patient->getTelephone());
		sw->WriteLine(patient->getEmail());
		sw->WriteLine(patient->getAdresse());
		sw->WriteLine(patient->getIdLocalite());
	}

	sw->Close();
}

int Patient::loadPatient(List<Individu^> %liste)
{
	String^ fileName = "Patient.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Patient ^ patient = gcnew Patient;

			patient->setActif(System::Convert::ToBoolean(din->ReadLine()));
			patient->setNom(din->ReadLine());
			patient->setPrenom(din->ReadLine());
			patient->setGsm(din->ReadLine());
			patient->setTelephone(din->ReadLine());
			patient->setEmail(din->ReadLine());
			patient->setAdresse(din->ReadLine());
			patient->setIdLocalite(System::Convert::ToInt32(din->ReadLine()));

			liste.Add(patient);
		}

		din->Close();
	}

	return liste.Count;
}