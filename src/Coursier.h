#pragma once
ref class Coursier : public Individu
{
protected:
	static unsigned long compteur = 0;
public:
	//------constructeur----------
	Coursier();
	//------destructeur-----------
	~Coursier();
	//------setter----------------
	virtual void setIdControlLogin(int const idLogin) override;
	virtual void setNumInami(System::String^ const num) override;
	virtual void setPrixPresta(float const prix) override;
	virtual void setFreelance(System::Boolean const var) override;
	//------getter----------------
	virtual int const getIdControlLogin() override;
	virtual System::String^ const getNumInami() override;
	virtual float const getPrixPresta() override;
	virtual System::Boolean const getFreelance() override;
	//---------fonction-------------
	static Coursier^ findCoursier(System::Collections::Generic::List<Coursier^> %liste, System::String ^id);
	static void saveCoursier(System::Collections::Generic::List<Individu^> %liste);
	static int loadCoursier(System::Collections::Generic::List<Individu^> %liste);


};