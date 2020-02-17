#pragma once
public ref class Individu abstract
{
protected :
	static unsigned long compteur = 0;
	System::String^ idUnique;
	System::String^ nom;
	System::String^ prenom;
	System::String^ gsm;
	System::String^ telephone;
	System::String^ email;
	System::String^ adresse;

	System::String^ numInami;

	float prixPrestation;
	bool freelance;

	int idLocalite;
	bool actif;
	int idControlLogin;

public: 
	//-------constructeur-----------
	Individu();
	Individu(System::String ^nom);
	//-------destructeur------------
	~Individu();
	//-------seter------------------

	void setNom(System::String^ const nom);
	void setPrenom(System::String^ const prenom);
	void setGsm(System::String^ const gsm);
	void setTelephone(System::String^ const telephone);
	void setEmail(System::String^ const email);
	void setAdresse(System::String^ const adresse);
	virtual void setNumInami(System::String^ const num) abstract;
	virtual void setPrixPresta(float const prix) abstract;
	virtual void setFreelance(System::Boolean const var) abstract;
	void setIdLocalite(int const localite);
	void setActif(bool const var);
	virtual void setIdControlLogin(int const idLogin) abstract;
	
	//--------getter-------------------
	System::String^ const getId();
	System::String^ const getNom();
	System::String^ const getPrenom();
	System::String^ const getGsm();
	System::String^ const getTelephone();
	System::String^ const getEmail();
	System::String^ const getAdresse();
	virtual System::String^ const getNumInami() abstract;
	virtual float const getPrixPresta() abstract;
	virtual System::Boolean const getFreelance() abstract;
	int const getIdLocalite();
	bool const estActif();
	virtual int const getIdControlLogin() abstract;
	//--------------fonction-----------
	static Individu^ findIndividu(System::Collections::Generic::List<Individu^> %listeIndividu, System::String ^id);




};

