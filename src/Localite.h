#pragma once

public ref class Localite
{
protected:
	static unsigned long compteur = 0;
	int idUnique;
	System::String^ nomLocalite;
	int codePostal;

public:
	//-----------contrusteur------------
	Localite();
	//-----------destructeur------------
	~Localite();
	
	//------setter----------------------
	void  setNomLocalite(System::String^ const nomLocalite);
	void setCodePostal(int const& codepostal);

	const int getId();
	System::String^ const getNomLocalite();
	const int getCodePostal();

	//----------fonction---------------
	static Localite^ findLocalite(System::Collections::Generic::List<Localite^> %listeLocalite, int id);
	static void saveLocalite(System::Collections::Generic::List<Localite^> %listeLocalite);
	static int loadLocalite(System::Collections::Generic::List<Localite^> %listeLocalite);

};