#pragma once

#include "ControlLogin.h"
#include "GestionUtilisateur.h"
#include "Localite.h"
#include "Individu.h"
#include "Secretaire.h"
#include "Infirmiere.h"
#include "Medecin.h"
#include "Patient.h"
#include "Coursier.h"
#include "GestionUtilisateur.h"
#include "Rdv.h"
#include "MenuRdv.h"
#include "Tourner.h"
#include "MenuTourner.h"




namespace ExamenPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;


	/// <summary>
	/// Summary for MenuPrincipal
	/// </summary>
	public ref class MenuPrincipal : public System::Windows::Forms::Form
	{
	public:
		MenuPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		
		MenuPrincipal(System::Windows::Forms::Form ^ form1, System::Collections::Generic::List<ControlLogin^> ^listeControlLogin)
		{
			oldForm = form1;
			ListCLogin = listeControlLogin;

			Localite::loadLocalite(ListeLocalite);
			Secretaire::loadSecretaire(ListeSecretaire);
			Infirmiere::loadInfirmiere(ListeInfirmiere);
			Medecin::loadMedecin(ListeMedecin);
			Patient::loadPatient(ListePatient);
			Coursier::loadCoursier(ListeCoursier);
			Rdv::loadRendezVous(ListeRdv);
			Tourner::loadTourner(ListeTourner,ListeLocalite);

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuPrincipal()
		{
			Patient::savePatient(ListePatient);
			for each(Patient ^var in ListePatient) delete var;
			ListePatient.Clear();

			Infirmiere::saveInfirmiere(ListeInfirmiere);
			for each(Infirmiere ^var in ListeInfirmiere) delete var;
			ListeInfirmiere.Clear();

			Coursier::saveCoursier(ListeCoursier);
			for each(Coursier ^var in ListeCoursier) delete var;
			ListeCoursier.Clear();

			Secretaire::saveSecretaire(ListeSecretaire);
			for each(Secretaire ^var in ListeSecretaire) delete var;
			ListeSecretaire.Clear();

			Medecin::saveMedecin(ListeMedecin);
			for each(Medecin ^var in ListeMedecin) delete var;
			ListeMedecin.Clear();

			Rdv::saveRendezVous(ListeRdv);
			for each(Rdv ^var in ListeRdv) delete var;
			ListeRdv.Clear();

			Tourner::saveTourner(ListeTourner, ListeLocalite);
			for each(Tourner ^var in ListeTourner) delete var;
			ListeTourner.Clear(); 

			for each(Localite ^localite in ListeLocalite) delete localite;
			ListeLocalite.Clear();

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form ^ oldForm;
	private: System::Collections::Generic::List<Rdv^> ListeRdv;
	private: System::Collections::Generic::List<Tourner^>	ListeTourner;
	private: System::Collections::Generic::List<ControlLogin^> ^ListCLogin;
	private: System::Collections::Generic::List<Localite^> ListeLocalite;
	private: System::Collections::Generic::List<Individu^> ListeSecretaire;
	private: System::Collections::Generic::List<Individu^> ListeInfirmiere;
	private: System::Collections::Generic::List<Individu^> ListeMedecin;
	private: System::Collections::Generic::List<Individu^> ListePatient;
	private: System::Collections::Generic::List<Individu^> ListeCoursier;

	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(51, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(195, 58);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Gestion des utilisateurs";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(53, 109);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(195, 64);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Gestion des tournées";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuPrincipal::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(53, 207);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(193, 69);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Gestion des rendez-vous";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuPrincipal::button3_Click);
			// 
			// MenuPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 326);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MenuPrincipal";
			this->Text = L"MenuPrincipal";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MenuPrincipal::MenuPrincipal_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MenuPrincipal::MenuPrincipal_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MenuPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MenuPrincipal_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		oldForm->Show();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	GestionUtilisateur ^gestionUtilisateur = gcnew GestionUtilisateur(this,%ListeLocalite,ListCLogin);
	gestionUtilisateur->setListeSecretaire(%ListeSecretaire);
	gestionUtilisateur->setListeCoursier(%ListeCoursier);
	gestionUtilisateur->setListeInfirmier(%ListeInfirmiere);
	gestionUtilisateur->setListeMedecin(%ListeMedecin);
	gestionUtilisateur->setListePatient(%ListePatient);

	gestionUtilisateur->Show();
	this->Hide();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

	MenuRdv ^menuRdv = gcnew MenuRdv(this, %ListeLocalite, %ListeRdv, %ListeTourner, %ListePatient, %ListeInfirmiere, %ListeSecretaire, %ListeCoursier, %ListeMedecin);

	menuRdv->Show();
	this->Hide();

}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	MenuTourner ^menutourner = gcnew MenuTourner(this, %ListeTourner, %ListeRdv, %ListeLocalite, %ListeMedecin, %ListePatient);

	menutourner->Show();
	this->Hide();
}
};
}
