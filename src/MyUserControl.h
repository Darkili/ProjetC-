#pragma once

#include "ControlLogin.h"
#include "Localite.h"
#include "Individu.h"
#include "Secretaire.h"
#include "Infirmiere.h"
#include "Medecin.h"
#include "Patient.h"
#include "Coursier.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Text::RegularExpressions;

namespace ExamenPOO {

	/// <summary>
	/// Summary for MyUserControl
	/// </summary>
	public ref class MyUserControl : public System::Windows::Forms::UserControl
	{
	public:
		MyUserControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MyUserControl(System::Collections::Generic::List<Localite^> ^liste, System::Collections::Generic::List<ControlLogin^> ^listeLogin)
		{
			ListeLocalite = liste;
			ListCLogin = listeLogin;

			InitializeComponent();

			ajoutLocalite();
			
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}



	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyUserControl()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Collections::Generic::List<ControlLogin^> ^ListCLogin;
	private: System::Collections::Generic::List<Localite^> ^ListeLocalite;
	private: System::Collections::Generic::List<Individu^> ^ListeIndividu;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox1;




	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::GroupBox^  groupBox1;

	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Prenom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Gsm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Téléphone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Email;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Adresse;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  CodePostal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Localité;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prenom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Gsm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Téléphone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Email = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adresse = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CodePostal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Localité = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nom";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Prenom";
			this->label2->Click += gcnew System::EventHandler(this, &MyUserControl::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Gsm";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Téléphone";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 82);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 2;
			this->label5->Text = L"Email";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 111);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Adresse";
			this->label6->Click += gcnew System::EventHandler(this, &MyUserControl::label6_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(10, 292);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(44, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Localité";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 266);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"N°INAMI";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 240);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 13);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Login";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(10, 214);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(71, 13);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Mot de passe";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(10, 189);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(88, 13);
			this->label12->TabIndex = 6;
			this->label12->Text = L"Prix de prestation";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(130, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(130, 20);
			this->textBox1->TabIndex = 12;
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(130, 266);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(130, 20);
			this->textBox6->TabIndex = 21;
			// 
			// textBox7
			// 
			this->textBox7->Enabled = false;
			this->textBox7->Location = System::Drawing::Point(130, 240);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(130, 20);
			this->textBox7->TabIndex = 20;
			// 
			// textBox8
			// 
			this->textBox8->Enabled = false;
			this->textBox8->Location = System::Drawing::Point(130, 214);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(130, 20);
			this->textBox8->TabIndex = 19;
			// 
			// textBox9
			// 
			this->textBox9->Enabled = false;
			this->textBox9->Location = System::Drawing::Point(130, 189);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(130, 20);
			this->textBox9->TabIndex = 18;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(130, 163);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(130, 20);
			this->textBox10->TabIndex = 17;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(130, 137);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(130, 20);
			this->textBox11->TabIndex = 16;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(130, 111);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(130, 20);
			this->textBox12->TabIndex = 15;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(130, 82);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(130, 20);
			this->textBox13->TabIndex = 14;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(130, 56);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(130, 20);
			this->textBox14->TabIndex = 13;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 400);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 36);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Nouveau";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyUserControl::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(146, 400);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 36);
			this->button2->TabIndex = 27;
			this->button2->Text = L"Ajouter";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyUserControl::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(29, 451);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 36);
			this->button3->TabIndex = 28;
			this->button3->Text = L"Modifier";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyUserControl::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(146, 451);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(93, 36);
			this->button4->TabIndex = 29;
			this->button4->Text = L"Supprimer";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyUserControl::button4_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(403, 57);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(29, 13);
			this->label13->TabIndex = 30;
			this->label13->Text = L"Nom";
			this->label13->Click += gcnew System::EventHandler(this, &MyUserControl::label13_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(602, 56);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(43, 13);
			this->label14->TabIndex = 31;
			this->label14->Text = L"Prénom";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(457, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 20);
			this->textBox2->TabIndex = 32;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(666, 53);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(121, 20);
			this->textBox3->TabIndex = 33;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(410, 88);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(80, 24);
			this->button5->TabIndex = 34;
			this->button5->Text = L"Rechercher";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyUserControl::button5_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->textBox14);
			this->groupBox1->Controls->Add(this->textBox13);
			this->groupBox1->Controls->Add(this->textBox12);
			this->groupBox1->Controls->Add(this->textBox11);
			this->groupBox1->Controls->Add(this->textBox10);
			this->groupBox1->Controls->Add(this->textBox9);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(16, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(296, 370);
			this->groupBox1->TabIndex = 36;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"GroupBox";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(130, 291);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(130, 21);
			this->comboBox1->TabIndex = 22;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(10, 347);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 13);
			this->label15->TabIndex = 28;
			this->label15->Text = L"Indépendant";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Enabled = false;
			this->checkBox1->Location = System::Drawing::Point(130, 347);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 27;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->ID, this->Nom,
					this->Prenom, this->Gsm, this->Téléphone, this->Email, this->Adresse, this->CodePostal, this->Localité
			});
			this->dataGridView1->Location = System::Drawing::Point(410, 154);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(389, 350);
			this->dataGridView1->TabIndex = 37;
			this->dataGridView1->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyUserControl::dataGridView1_RowEnter);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			// 
			// Nom
			// 
			this->Nom->HeaderText = L"Nom";
			this->Nom->Name = L"Nom";
			this->Nom->ReadOnly = true;
			// 
			// Prenom
			// 
			this->Prenom->HeaderText = L"Prenom";
			this->Prenom->Name = L"Prenom";
			this->Prenom->ReadOnly = true;
			// 
			// Gsm
			// 
			this->Gsm->HeaderText = L"Gsm";
			this->Gsm->Name = L"Gsm";
			this->Gsm->ReadOnly = true;
			// 
			// Téléphone
			// 
			this->Téléphone->HeaderText = L"Téléphone";
			this->Téléphone->Name = L"Téléphone";
			this->Téléphone->ReadOnly = true;
			// 
			// Email
			// 
			this->Email->HeaderText = L"Email";
			this->Email->Name = L"Email";
			this->Email->ReadOnly = true;
			// 
			// Adresse
			// 
			this->Adresse->HeaderText = L"Adresse";
			this->Adresse->Name = L"Adresse";
			this->Adresse->ReadOnly = true;
			// 
			// CodePostal
			// 
			this->CodePostal->HeaderText = L"CodePostal";
			this->CodePostal->Name = L"CodePostal";
			this->CodePostal->ReadOnly = true;
			// 
			// Localité
			// 
			this->Localité->HeaderText = L"Localité";
			this->Localité->Name = L"Localité";
			this->Localité->ReadOnly = true;
			// 
			// MyUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyUserControl";
			this->Size = System::Drawing::Size(868, 536);
			this->Load += gcnew System::EventHandler(this, &MyUserControl::MyUserControl_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: System::Void setListeIndividu(System::Collections::Generic::List<Individu^> ^liste) {

		ListeIndividu = liste;

		showIndividu();
	}
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void MyUserControl_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
}


public: System::Void setGroupeBoxText(String ^titre)
{
	this->groupBox1->Text = titre;
}

public: System::Void showLogin()
{
	this->textBox8->Enabled = true;
}

public: System::Void showPassword()
{
	this->textBox7->Enabled = true;
}

public: System::Void showPrestation()
{
	this->textBox9->Enabled = true;
}

public: System::Void showInami()
{
	this->textBox6->Enabled = true;
}
public: System::Void showCheckBox()
{
	this->checkBox1->Enabled = true;
}
private: System::Void ajoutLocalite() {

	int i = 0;
	String^ line;

	for each(Localite ^localite in ListeLocalite)
	{
		line = (localite->getCodePostal()  + " " + localite->getNomLocalite());
		comboBox1->Items->Add(line);
	}
}

private: Individu^ creationIndividu() {

	Individu ^individu;

	if (groupBox1->Text == "Fiche Secrétaire")
	{
		ControlLogin ^login = gcnew ControlLogin(this->textBox7->Text, this->textBox8->Text);
		ListCLogin->Add(login);

		individu = gcnew Secretaire();
		individu->setIdControlLogin(login->getId());
	}
	else if (groupBox1->Text == "Fiche Infirmiere")
	{
		ControlLogin ^login = gcnew ControlLogin(this->textBox7->Text, this->textBox8->Text);
		ListCLogin->Add(login);

		individu = gcnew Infirmiere();
		individu->setIdControlLogin(login->getId());
		individu->setNumInami(this->textBox6->Text);
		individu->setPrixPresta((float)Convert::ToDouble(this->textBox10->Text));
		individu->setFreelance(this->checkBox1->Checked);
	}
	else if (groupBox1->Text == "Fiche Coursier")
	{
		ControlLogin ^login = gcnew ControlLogin(this->textBox7->Text, this->textBox8->Text);
		ListCLogin->Add(login);

		individu = gcnew Coursier();
		individu->setIdControlLogin(login->getId());
	}
	else if (groupBox1->Text == "Fiche Médecin")
	{
		individu = gcnew Medecin();
		individu->setNumInami(this->textBox6->Text);
	}
	else if (groupBox1->Text == "Fiche Patient")
	{
		individu = gcnew Patient();
	}

	individu->setNom(this->textBox1->Text);
	individu->setPrenom(this->textBox14->Text);	
	individu->setEmail(this->textBox13->Text);
	individu->setAdresse(this->textBox12->Text);
	individu->setGsm(this->textBox11->Text);
	individu->setTelephone(this->textBox10->Text);

	individu->setIdLocalite(this->comboBox1->SelectedIndex +1);
	

	return individu;
}

private: System::Void viderFiche()
{
	this->textBox1->Text = "";
	this->textBox2->Text = "";
	this->textBox3->Text = "";
	this->textBox6->Text = "";
	this->textBox7->Text = "";
	this->textBox8->Text = "";
	this->textBox9->Text = "";
	this->textBox10->Text = "";
	this->textBox11->Text = "";
	this->textBox12->Text = "";
	this->textBox13->Text = "";
	this->textBox14->Text = "";
	this->comboBox1->SelectedIndex = -1;
	this->checkBox1->Checked = false;
}
private: System::Void suppresion()
{
	if (dataGridView1->RowCount != 0)
	{
		Individu ^individu = Individu::findIndividu(*ListeIndividu, dataGridView1->CurrentRow->Cells[0]->Value->ToString());
		individu->setActif(false);

		showIndividu();
		viderFiche();
	}
	else
	{
		MessageBox::Show("La liste ne contient aucun élément.");
	}
}
private: System::Void ajouter()
{
	Individu ^individu = creationIndividu();

	(*ListeIndividu).Add(individu);

	showIndividu();
	viderFiche();
}
private: System::Void modification()
{
	if (dataGridView1->RowCount != 0)
	{
		Individu ^individu = Individu::findIndividu(*ListeIndividu, dataGridView1->CurrentRow->Cells[0]->Value->ToString());

		individu->setNom(this->textBox1->Text);
		individu->setPrenom(this->textBox14->Text);
		individu->setEmail(this->textBox13->Text);
		individu->setAdresse(this->textBox12->Text);
		individu->setGsm(this->textBox11->Text);
		individu->setTelephone(this->textBox10->Text);
		individu->setIdLocalite(this->comboBox1->SelectedIndex + 1);

		if (groupBox1->Text == "Fiche Infirmiere")
		{
			individu->setNumInami(this->textBox6->Text);
			individu->setPrixPresta((float)Convert::ToDouble(this->textBox9->Text));
			individu->setFreelance(this->checkBox1->Checked);
		}
		else if (groupBox1->Text == "Fiche Médecin")
		{
			individu->setNumInami(this->textBox6->Text);
		}

		showIndividu();
	}
	else
	{
		MessageBox::Show("La liste ne contient aucun élément");
	}
}
private: System::Void recherche()
{
	int i = 0;
	bool etat[4] = { 0 };

	etat[0] = (textBox2->Text != "");
	etat[1] = (textBox3->Text != "");

	dataGridView1->Rows->Clear();

	for each(Individu ^individu in ListeIndividu)
	{
		if (individu->estActif())
		{
			etat[2] = (individu->getNom()->ToLower()->StartsWith(textBox7->Text->ToLower()) && textBox2->Text != "");
			etat[3] = (individu->getPrenom()->ToLower()->StartsWith(textBox8->Text->ToLower()) && textBox3->Text != "");

			if (etat[0] == etat[2] && etat[1] == etat[3])
			{
				dataGridView1->Rows->Add();

				dataGridView1->Rows[i]->Cells[0]->Value = individu->getId();
				dataGridView1->Rows[i]->Cells[1]->Value = individu->getNom();
				dataGridView1->Rows[i]->Cells[2]->Value = individu->getPrenom();
				dataGridView1->Rows[i]->Cells[3]->Value = individu->getGsm();
				dataGridView1->Rows[i]->Cells[4]->Value = individu->getTelephone();
				dataGridView1->Rows[i]->Cells[5]->Value = individu->getEmail();
				dataGridView1->Rows[i]->Cells[6]->Value = individu->getAdresse();

				Localite ^tempLoc = Localite::findLocalite(*ListeLocalite, individu->getIdLocalite());

				dataGridView1->Rows[i]->Cells[7]->Value = tempLoc->getCodePostal();
				dataGridView1->Rows[i]->Cells[8]->Value = tempLoc->getNomLocalite();

				++i;
			}
		}
	}
}
private: System::Void showIndividu()
{
	int i = 0;

	dataGridView1->Rows->Clear();

	for each(Individu ^individu in ListeIndividu)
	{
		if (individu->estActif())
		{
			dataGridView1->Rows->Add();

			dataGridView1->Rows[i]->Cells[0]->Value = individu->getId();
			dataGridView1->Rows[i]->Cells[1]->Value = individu->getNom();
			dataGridView1->Rows[i]->Cells[2]->Value = individu->getPrenom();
			dataGridView1->Rows[i]->Cells[3]->Value = individu->getGsm();
			dataGridView1->Rows[i]->Cells[4]->Value = individu->getTelephone();
			dataGridView1->Rows[i]->Cells[5]->Value = individu->getEmail();
			dataGridView1->Rows[i]->Cells[6]->Value = individu->getAdresse();

			Localite ^LocActuel = Localite::findLocalite(*ListeLocalite, individu->getIdLocalite());

			dataGridView1->Rows[i]->Cells[7]->Value = LocActuel->getCodePostal();
			dataGridView1->Rows[i]->Cells[8]->Value = LocActuel->getNomLocalite();
			
			++i;
		}
	}

}

private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {


}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	viderFiche();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	ajouter();

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	modification();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	suppresion();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

	recherche();
}

private: System::Void dataGridView1_RowEnter(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (dataGridView1->CurrentRow != nullptr)
	{
		Individu ^individu = Individu::findIndividu(*ListeIndividu, dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());

		if (individu != nullptr)
		{
			this->textBox1->Text = individu->getNom();
			this->textBox14->Text = individu->getPrenom();
			this->textBox13->Text = individu->getEmail();
			this->textBox12->Text = individu->getAdresse();
			this->textBox11->Text = individu->getGsm();
			this->textBox10->Text = individu->getTelephone();
			this->comboBox1->SelectedIndex = individu->getIdLocalite() - 1;


			this->textBox6->Text = individu->getNumInami();
			this->textBox9->Text = Convert::ToString(individu->getPrixPresta());
			this->checkBox1->Checked = individu->getFreelance();

			if (groupBox1->Text == "Fiche Secrétaire" || groupBox1->Text == "Fiche Infirmiere" || groupBox1->Text == "Fiche Coursier")
			{
			ControlLogin ^login = ControlLogin::findControlLogin(*ListCLogin, individu->getIdControlLogin());

			this->textBox7->Text = login->getLogin();
			this->textBox8->Text = login->getPassword();
			}
		}
	}

}

};
}
