#pragma once
ref class Patient : public Individu
{
protected:
	static unsigned long compteur = 0;
public:
	Patient();
	~Patient();

	virtual void setIdControlLogin(int const idLogin) override;
	virtual void setNumInami(System::String^ const num) override;
	virtual void setPrixPresta(float const prix) override;
	virtual void setFreelance(System::Boolean const var) override;

	virtual int const getIdControlLogin() override;
	virtual System::String^ const getNumInami() override;
	virtual float const getPrixPresta() override;
	virtual System::Boolean const getFreelance() override;

	static Patient^ findPatient(System::Collections::Generic::List<Patient^> %liste, System::String ^id);
	static void savePatient(System::Collections::Generic::List<Individu^> %liste);
	static int loadPatient(System::Collections::Generic::List<Individu^> %liste);


};