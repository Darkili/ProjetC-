#pragma once
ref class Infirmiere : public Individu
{
protected :
	static unsigned long compteur = 0;

public :
	Infirmiere();
	~Infirmiere();

	virtual void setIdControlLogin(int const idLogin) override;
	virtual void setNumInami(System::String^ const num) override;
	virtual void setPrixPresta(float const prix) override;
	virtual void setFreelance(System::Boolean const var) override;

	virtual int const getIdControlLogin() override;
	virtual System::String^ const getNumInami() override;
	virtual float const getPrixPresta() override;
	virtual System::Boolean const getFreelance() override;

	static Infirmiere^ Infirmiere::findInfirmiere(System::Collections::Generic::List<Infirmiere^> %liste, System::String ^id);
	static void saveInfirmiere(System::Collections::Generic::List<Individu^> %liste);
	static int loadInfirmiere(System::Collections::Generic::List<Individu^> %liste);

};