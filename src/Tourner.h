#pragma once
public ref class Tourner
{

protected:
	static unsigned long compteur = 0;
	System::String^ idUnique;
	System::String^ nom;
	System::String^ typeTournee;
	array<int> ^listeIdloc;
	System::Collections::Generic::Dictionary<System::String^, bool> locTournee;
	System::Collections::Generic::Dictionary<System::String^, bool> jourSemaine;
	bool actif;

public:
	Tourner();
	Tourner(System::Collections::Generic::List<Localite^> ^liste);

	void setActif(bool const var);
	void setNom(System::String^ const nom);
	void setTypeTournee(System::String^ const type);
	void setBoolJour(System::String^ const jour, bool const var);
	void setLocTournee(System::String^ const localite, bool const var);

	bool isActif();
	System::String^ const getNom();
	System::String^ const getTypeTournee();
	bool const getBoolJour(System::String^ jour);
	bool const getLocTournee(System::String^ localite);
	System::String^ const getId();

	static Tourner^ findTournee(System::Collections::Generic::List<Tourner^> %liste, System::String^ id);
	static void saveTourner(System::Collections::Generic::List<Tourner^> %liste, System::Collections::Generic::List<Localite^> %listeLoc);
	static int loadTourner(System::Collections::Generic::List<Tourner^> %liste, System::Collections::Generic::List<Localite^> %listeLoc);
	System::Collections::Generic::Dictionary<System::String^, bool> ^ getAttributLocTournee();

};