#pragma once

#pragma once
public ref class Rdv
{
protected:

	static unsigned long compteur = 0;
	int idUnique;
	System::String^ typeRdv;
	System::String^ idIndividu;
	System::String^ idTournee;
	System::String^ idEmploye;
	System::String^ commentaire;
	System::String^ date;
	bool diabetique;
	bool aJeun;
	int prelevements;

	bool actif;
public:
	Rdv();

	void setTypeRdv(System::String^ const type);
	void setIdIndividu(System::String^ const id);
	void setIdTournee(System::String^ const id);
	void setIdEmploye(System::String^ const id);
	void setCommentaire(System::String^ const commentaire);
	void setDate(System::String^ const date);
	void setDiabetique(bool const var);
	void setAJeun(bool const var);
	void setPrelevements(int const nbr);
	void setActif(bool const var);

	System::String^ const getTypeRdv();
	System::String^ const getIdIndividu();
	System::String^ const getIdTournee();
	System::String^ const getIdEmploye();
	System::String^ const getCommentaire();
	System::String^ const getDate();
	bool const getDiabetique();
	bool const getAJeun();
	int  const getPrelevements();
	int const getID();
	bool const isActif();

	static Rdv^ findRendezVous(System::Collections::Generic::List<Rdv^> %liste, int id);
	static void saveRendezVous(System::Collections::Generic::List<Rdv^> %liste);
	static int loadRendezVous(System::Collections::Generic::List<Rdv^> %liste);


};