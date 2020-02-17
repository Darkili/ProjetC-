#include "ControlLogin.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;

ControlLogin::ControlLogin()
{
	compteur++;

	IdUnique = compteur;
}

ControlLogin::ControlLogin(System::String ^ login, System::String ^ password)
{
	compteur++;

	IdUnique = compteur;

	this->login = login;
	this->password = password;
}

void ControlLogin::setLogin(String ^ login)
{
	this->login = login;
}

void ControlLogin::setPassword(String ^ password)
{
	this->password = password;
}

String ^ const  ControlLogin::getLogin()
{
	return login;
}

String ^ const ControlLogin::getPassword()
{
	return password;
}

const int ControlLogin::getId()
{
	return IdUnique;
}

ControlLogin ^ ControlLogin::findControlLogin(System::Collections::Generic::List<ControlLogin^>% listeControlLogin, int id)
{
	for each(ControlLogin ^login in listeControlLogin)
	{
		if (login->getId() == id)
		{
			return login;
		}
	}

	return nullptr;
}

void ControlLogin::saveLoginPass(System::Collections::Generic::List<ControlLogin^>% listeControlLogin)
{
	String^ fileName = "ControlLogin.txt";
	StreamWriter^ sw = gcnew StreamWriter(fileName);

	sw->WriteLine(listeControlLogin.Count);

	for each(ControlLogin ^login in listeControlLogin)
	{
		sw->WriteLine(login->getLogin());
		sw->WriteLine(login->getPassword());
	}

	sw->Close();
}

int ControlLogin::loadLoginPass(System::Collections::Generic::List<ControlLogin^>% listeControlLogin)
{
	String^ fileName = "ControlLogin.txt";

	if (File::Exists(fileName))
	{
		StreamReader^ din = File::OpenText(fileName);

		int nbrElem = System::Convert::ToInt32(din->ReadLine());

		for (int i = 0; i < nbrElem; ++i)
		{
			ControlLogin ^ login = gcnew ControlLogin;

			login->setLogin(din->ReadLine());
			login->setPassword(din->ReadLine());

			listeControlLogin.Add(login);
		}

		din->Close();
	}

	return listeControlLogin.Count;
}
