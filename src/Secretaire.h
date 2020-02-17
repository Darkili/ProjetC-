#pragma once
ref class Secretaire : public Individu
{
protected:
	static unsigned long compteur = 0;

public:
	//-------constructeur-----
	Secretaire();
	//------destructeur-------
	~Secretaire();
	 //---------setter--------
	virtual void setIdControlLogin(int const idLogin) override;
	virtual void setNumInami(System::String^ const num) override;
	virtual void setPrixPresta(float const prix) override;
	virtual void setFreelance(System::Boolean const var) override;
	//--------getter----------
	virtual int const getIdControlLogin() override;
	virtual System::String^ const getNumInami() override;
	virtual float const getPrixPresta() override;
	virtual System::Boolean const getFreelance() override;

	static Secretaire^ Secretaire::findSecretaire(System::Collections::Generic::List<Secretaire^> %liste, System::String ^id);
	static void saveSecretaire(System::Collections::Generic::List<Individu^> %liste);
	static int loadSecretaire(System::Collections::Generic::List<Individu^> %liste);


};