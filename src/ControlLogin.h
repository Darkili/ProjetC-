#pragma once
public ref class ControlLogin
{
private : 
	static unsigned long compteur = 0;

	int IdUnique;
	System::String^ login;
	System::String^ password;

public: 
	ControlLogin();
	ControlLogin(System::String^ login, System::String^ password);

	void setLogin(System::String^ const login);
	void setPassword(System::String^ const  password);

	System::String^ const getLogin();
	System::String^ const getPassword();

	const int getId();

	static ControlLogin^ findControlLogin(System::Collections::Generic::List<ControlLogin^> %listeControlLogin, int id);
	static void saveLoginPass(System::Collections::Generic::List<ControlLogin^> %listeControlLogin);
	static int loadLoginPass(System::Collections::Generic::List<ControlLogin^> %listeControlLogin);


};
