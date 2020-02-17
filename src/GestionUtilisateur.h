#pragma once

#include "ControlLogin.h"
#include "Localite.h"
#include "Individu.h"
#include "Secretaire.h"
#include "Infirmiere.h"
#include "Medecin.h"
#include "Patient.h"
#include "Coursier.h"
#include "MyUserControl.h"

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
	/// Summary for GestionUtilisateur
	/// </summary>
	public ref class GestionUtilisateur : public System::Windows::Forms::Form
	{
	public:
		GestionUtilisateur(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		GestionUtilisateur(System::Windows::Forms::Form ^ form1, System::Collections::Generic::List<Localite^> ^liste, System::Collections::Generic::List<ControlLogin^> ^listeLogin)
		{
			oldForm = form1;
			InitializeComponent();

			ListeLocalite = liste;
			ListCLogin = listeLogin;

			actuel = gcnew array<MyUserControl^>(5);

			for (int i = 0; i < actuel->Length; ++i)
			{
				actuel[i] = gcnew MyUserControl(ListeLocalite, ListCLogin);
			}

			actuel[0]->setGroupeBoxText("Fiche Secrétaire");		/* Affichage de du UserControl tab 1 Secretaire et activation des champs de login et mot de passe.*/
			actuel[0]->showLogin();
			actuel[0]->showPassword();
			tabControl1->TabPages[0]->Controls->Add(actuel[0]);

			actuel[1]->setGroupeBoxText("Fiche Infirmiere");		/* Affichage du UserControl tab 2 Infirmiere et activation des champs de login, mot de passe, Inami, Prestation et CheckBox */
			actuel[1]->showInami();
			actuel[1]->showPrestation();
			actuel[1]->showCheckBox();
			actuel[1]->showLogin();
			actuel[1]->showPassword();
			tabControl1->TabPages[1]->Controls->Add(actuel[1]);

			actuel[2]->setGroupeBoxText("Fiche Coursier");		// Affichage du UserControl Tab 3 Coursier et activation des champs login et mot de passe.
			actuel[2]->showLogin();
			actuel[2]->showPassword();
			tabControl1->TabPages[2]->Controls->Add(actuel[2]);

			actuel[3]->setGroupeBoxText("Fiche Médecin");	//	Affichage du UserControl Tab 4 et activation du champ Inami
			actuel[3]->showInami();
			tabControl1->TabPages[3]->Controls->Add(actuel[3]);

			actuel[4]->setGroupeBoxText("Fiche Patient");	// Affichage du UserControl Tab 5 
			tabControl1->TabPages[4]->Controls->Add(actuel[4]);





			//
			//TODO: Add the constructor code here
			//

		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GestionUtilisateur()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Form ^ oldForm;
	private: array<MyUserControl^> ^actuel;
	private: System::Collections::Generic::List<ControlLogin^> ^ListCLogin;
	private: System::Collections::Generic::List<Localite^> ^ListeLocalite;
	private: System::Collections::Generic::List<Individu^> ^ListeSecretaire;
	private: System::Collections::Generic::List<Individu^> ^ListeInfirmiere;
	private: System::Collections::Generic::List<Individu^> ^ListeMedecin;
	private: System::Collections::Generic::List<Individu^> ^ListePatient;
	private: System::Collections::Generic::List<Individu^> ^ListeCoursier;
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::TabPage^  tabPage5;




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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(860, 525);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(852, 499);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Secrétaire";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &GestionUtilisateur::tabPage1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(852, 499);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Infirmiere";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(852, 499);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Coursier";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(852, 499);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Médecin";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage5
			// 
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(852, 499);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Patient";
			this->tabPage5->UseVisualStyleBackColor = true;
			this->tabPage5->Click += gcnew System::EventHandler(this, &GestionUtilisateur::tabPage5_Click);
			// 
			// GestionUtilisateur
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 577);
			this->Controls->Add(this->tabControl1);
			this->Name = L"GestionUtilisateur";
			this->Text = L"q";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GestionUtilisateur::GestionUtilisateur_FormClosing);
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void GestionUtilisateur_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

		oldForm->Show();
	}
		private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
public: System::Void setListeSecretaire(System::Collections::Generic::List<Individu^> ^liste) {
ListeSecretaire = liste;
actuel[0]->setListeIndividu(ListeSecretaire);
}

public: System::Void setListeInfirmier(System::Collections::Generic::List<Individu^> ^liste) {
ListeInfirmiere = liste;
actuel[1]->setListeIndividu(ListeInfirmiere);
}

public: System::Void setListeCoursier(System::Collections::Generic::List<Individu^> ^liste) {
ListeCoursier = liste;
actuel[2]->setListeIndividu(ListeCoursier);
}

public: System::Void setListeMedecin(System::Collections::Generic::List<Individu^> ^liste) {
ListeMedecin = liste;
actuel[3]->setListeIndividu(ListeMedecin);
}

public: System::Void setListePatient(System::Collections::Generic::List<Individu^> ^liste) {
ListePatient = liste;
actuel[4]->setListeIndividu(ListePatient);
}
	
	private: System::Void tabPage5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
