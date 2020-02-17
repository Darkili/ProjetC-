#include "Localite.h"

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

Localite::Localite()
{
	compteur++;
	idUnique = compteur;
}

Localite::~Localite()
{
	compteur--;
}

void Localite::setNomLocalite(System::String^ const localite)
{
	this->nomLocalite = localite;
}

void Localite::setCodePostal(int const & cp)
{
	this->codePostal = cp;
}

const int Localite::getId()
{
	return idUnique;
}

String^ const Localite::getNomLocalite()
{
	return nomLocalite;
}

const int Localite::getCodePostal()
{
	return codePostal;
}

Localite^ Localite::findLocalite(List<Localite^> %listeLocalite, int id)
{
	for each(Localite ^localite in listeLocalite)
	{
		if (localite->getId() == id)
		{
			return localite;
		}
	}

	return nullptr;
}

void Localite::saveLocalite(List<Localite^> %listeLocalite)
{
	String^ fileName = "Localite.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(listeLocalite.Count);

	for each(Localite ^loc in listeLocalite)
	{
		sw->WriteLine(loc->getNomLocalite());
		sw->WriteLine(loc->getCodePostal());
	}

	sw->Close();
}

int Localite::loadLocalite(List<Localite^> %listeLocalite)
{
	Regex^ regex = gcnew Regex("(?<codepostal>[0-9]{4})\\s+(?<localite>.+)");
	String^ fileName = "Localite.txt";
	String^ line;

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			Localite ^ localite = gcnew Localite;

			line = din->ReadLine();

			Match^ match = regex->Match(line);

			if (match->Value->Length > 0)
			{
				localite->setCodePostal(System::Convert::ToInt32(match->Groups["codepostal"]->Value));
				localite->setNomLocalite(match->Groups["localite"]->Value);
			}

			listeLocalite.Add(localite);
		}

		din->Close();
	}

	return listeLocalite.Count;
}