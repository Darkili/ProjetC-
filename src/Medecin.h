#pragma once
ref class Medecin : public Individu
{
protected:
	static unsigned long compteur = 0;

public:
	Medecin();
	~Medecin();

	virtual void setIdControlLogin(int const idLogin) override;
	virtual void setNumInami(System::String^ const num) override;
	virtual void setPrixPresta(float const prix) override;
	virtual void setFreelance(System::Boolean const var) override;

	virtual int const getIdControlLogin() override;
	virtual System::String^ const getNumInami() override;
	virtual float const getPrixPresta() override;
	virtual System::Boolean const getFreelance() override;

	static Medecin^ findMedecin(System::Collections::Generic::List<Medecin^> %liste, System::String ^id);
	static void saveMedecin(System::Collections::Generic::List<Individu^> %liste);
	static int loadMedecin(System::Collections::Generic::List<Individu^> %liste);


};