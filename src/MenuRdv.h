#pragma once

#include "Localite.h"
#include "Individu.h"
#include "Secretaire.h"
#include "Infirmiere.h"
#include "Medecin.h"
#include "Patient.h"
#include "Coursier.h"
#include "Rdv.h"
#include "Tourner.h"

namespace ExamenPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for MenuRdv
	/// </summary>
	public ref class MenuRdv : public System::Windows::Forms::Form
	{
	public:
		MenuRdv(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MenuRdv(Form ^form1, System::Collections::Generic::List<Localite^> ^Loc, System::Collections::Generic::List<Rdv^> ^Rdv, System::Collections::Generic::List<Tourner^> ^Tour, System::Collections::Generic::List<Individu^> ^Pat, System::Collections::Generic::List<Individu^> ^Inf, System::Collections::Generic::List<Individu^> ^Sec, System::Collections::Generic::List<Individu^> ^Cour, System::Collections::Generic::List<Individu^> ^Med)
		{
			oldForm = form1;

			InitializeComponent();

			ListeLocalite = Loc;
			ListePatient = Pat;
			ListeInfirmiere = Inf;
			ListeSecretaire = Sec;
			ListeCoursier = Cour;
			ListeMedecin = Med;
			ListeRdv = Rdv;
			ListeTourner = Tour;

			this->radioButton1->Checked = true;

			showRdv();
		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuRdv()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form ^ oldForm;
	private: System::Collections::Generic::List<Rdv^> ^ListeRdv;
	private: System::Collections::Generic::List<Tourner^>	^ListeTourner;
	private: System::Collections::Generic::List<Localite^> ^ListeLocalite;
	private: System::Collections::Generic::List<Individu^> ^ListeSecretaire;
	private: System::Collections::Generic::List<Individu^> ^ListeInfirmiere;
	private: System::Collections::Generic::List<Individu^> ^ListeMedecin;
	private: System::Collections::Generic::List<Individu^> ^ListePatient;
	private: System::Collections::Generic::List<Individu^> ^ListeCoursier;

	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	protected:
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::MonthCalendar^  monthCalendar1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Prenom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Commentaire;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;

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
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->monthCalendar1 = (gcnew System::Windows::Forms::MonthCalendar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prenom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Commentaire = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(122, 44);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(211, 20);
			this->dateTimePicker1->TabIndex = 0;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(169, 125);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(70, 20);
			this->numericUpDown1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(48, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Medecin";
			this->label1->Click += gcnew System::EventHandler(this, &MenuRdv::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Tourner";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Coursier";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1, 125);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Prélèvements";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1, 159);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Commentaire";
			// 
			// monthCalendar1
			// 
			this->monthCalendar1->Location = System::Drawing::Point(12, 223);
			this->monthCalendar1->Name = L"monthCalendar1";
			this->monthCalendar1->TabIndex = 7;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->comboBox3);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->monthCalendar1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(21, 93);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(258, 398);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Rendez vous";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(144, 194);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(56, 17);
			this->checkBox2->TabIndex = 13;
			this->checkBox2->Text = L"A jeun";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 194);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(77, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Diabétique";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(87, 155);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(151, 20);
			this->textBox1->TabIndex = 11;
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(96, 88);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(143, 21);
			this->comboBox3->TabIndex = 10;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(96, 55);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(143, 21);
			this->comboBox2->TabIndex = 9;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(96, 28);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(143, 21);
			this->comboBox1->TabIndex = 8;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button5);
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->dateTimePicker1);
			this->groupBox2->Location = System::Drawing::Point(421, 93);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(339, 412);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Recherche";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(18, 43);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(96, 20);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Rechercher";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MenuRdv::button5_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID, this->Type,
					this->Nom, this->Prenom, this->Date, this->Commentaire
			});
			this->dataGridView1->Location = System::Drawing::Point(18, 114);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(314, 297);
			this->dataGridView1->TabIndex = 5;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuRdv::dataGridView1_CellContentClick);
			// 
			// ID
			// 
			this->ID->HeaderText = L"ID";
			this->ID->Name = L"ID";
			// 
			// Type
			// 
			this->Type->HeaderText = L"Type";
			this->Type->Name = L"Type";
			// 
			// Nom
			// 
			this->Nom->HeaderText = L"Nom";
			this->Nom->Name = L"Nom";
			// 
			// Prenom
			// 
			this->Prenom->HeaderText = L"Prenom";
			this->Prenom->Name = L"Prenom";
			// 
			// Date
			// 
			this->Date->HeaderText = L"Date";
			this->Date->Name = L"Date";
			// 
			// Commentaire
			// 
			this->Commentaire->HeaderText = L"Commentaire";
			this->Commentaire->Name = L"Commentaire";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(233, 80);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(75, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(91, 20);
			this->textBox2->TabIndex = 3;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(178, 80);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Prénom";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(26, 80);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Nom";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(301, 184);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 20);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Nouveau";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuRdv::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(301, 210);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 20);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Ajouter";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuRdv::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(301, 236);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(96, 20);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Modifier";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuRdv::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(301, 262);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(96, 20);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Supprimer";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuRdv::button4_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(268, 34);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(89, 17);
			this->radioButton1->TabIndex = 14;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Rdv Médecin";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MenuRdv::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(421, 34);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(81, 17);
			this->radioButton2->TabIndex = 15;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Rdv Patient";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MenuRdv::radioButton2_CheckedChanged);
			// 
			// MenuRdv
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 531);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MenuRdv";
			this->Text = L"MenuRdv";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MenuRdv::MenuRdv_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}


private: System::Void showRdv()
{

	int i = 0;

	dataGridView1->Rows->Clear();

	for each(Rdv ^rdv in ListeRdv)
	{
		if (rdv->isActif())
		{
			dataGridView1->Rows->Add();

			dataGridView1->Rows[i]->Cells[0]->Value = rdv->getID();
			dataGridView1->Rows[i]->Cells[1]->Value = rdv->getTypeRdv();

			Individu ^individu;

			if (rdv->getTypeRdv() == "Medecin")
			{
			
				individu = Individu::findIndividu(*ListeMedecin, rdv->getIdIndividu());
			}
			else if (rdv->getTypeRdv() == "Patient")
			{
		
				individu = Individu::findIndividu(*ListePatient, rdv->getIdIndividu());
			}

			dataGridView1->Rows[i]->Cells[2]->Value = individu->getNom();
			dataGridView1->Rows[i]->Cells[3]->Value = individu->getPrenom();
			dataGridView1->Rows[i]->Cells[4]->Value = rdv->getDate();
			dataGridView1->Rows[i]->Cells[5]->Value = rdv->getCommentaire();

			++i;
		}
	}
}

private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->radioButton2->Checked == false)
	{
		String^ line;

		comboBox1->Items->Clear();
		comboBox2->Items->Clear();
		comboBox3->Items->Clear();

		this->label1->Text = "Médecin";
		this->label3->Text = "Coursier";

		for each(Medecin ^med in ListeMedecin)
		{
			if (med->estActif())
			{
				line = (med->getId() + " : " + med->getNom() + " " + med->getPrenom());
				comboBox1->Items->Add(line);
			}
		}

		for each(Tourner ^trn in ListeTourner)
		{
			if (trn->isActif())
			{
				line = (trn->getId() + " : " + trn->getNom());
				comboBox2->Items->Add(line);
			}
		}

		for each(Coursier ^cour in ListeCoursier)
		{
			if (cour->estActif())
			{
				line = (cour->getId() + " : " + cour->getNom() + " " + cour->getPrenom());
				comboBox3->Items->Add(line);
			}
		}

		this->numericUpDown1->Enabled = true;
		this->checkBox1->Enabled = false;
		this->checkBox2->Enabled = false;

		viderFichierRdv();
	}
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->radioButton1->Checked == false)
	{
		String^ line;

		comboBox1->Items->Clear();
		comboBox2->Items->Clear();
		comboBox3->Items->Clear();

		this->label1->Text = "Patient";
		this->label3->Text = "Infirmiere";

		for each(Patient ^ptt in ListePatient)
		{
			line = (ptt->getId() + " : " + ptt->getNom() + " " + ptt->getPrenom());
			comboBox1->Items->Add(line);
		}

		for each(Tourner ^trn in ListeTourner)
		{
			line = (trn->getId() + " : " + trn->getNom());
			comboBox2->Items->Add(line);
		}

		for each(Infirmiere ^inf in ListeInfirmiere)
		{
			line = (inf->getId() + " : " + inf->getNom() + " " + inf->getPrenom());
			comboBox3->Items->Add(line);
		}

		this->numericUpDown1->Enabled = false;
		this->checkBox1->Enabled = true;
		this->checkBox2->Enabled = true;

		viderFichierRdv();
	}
}
private: System::Void viderFichierRdv()
{
	this->comboBox1->SelectedIndex = -1;
	this->comboBox2->SelectedIndex = -1;
	this->comboBox3->SelectedIndex = -1;

	this->checkBox1->Checked = false;
	this->checkBox2->Checked = false;

	this->numericUpDown1->Value = 0;
	this->textBox1->Text = "";

	this->monthCalendar1->SetDate(this->monthCalendar1->TodayDate);
}
private: System::Void ajouter()
{
	Regex^ regex = gcnew Regex("(?<id>.+)\\s+:\\s+");
	Match^ match;
	
		Rdv ^rdv = gcnew Rdv();

		
		if (this->radioButton1->Checked == true)
		{
			rdv->setTypeRdv("Medecin");
			rdv->setPrelevements(System::Convert::ToInt32(this->numericUpDown1->Value));
		}
		else if (this->radioButton2->Checked == true)
		{
			rdv->setTypeRdv("Patient");
			rdv->setDiabetique(this->checkBox1->Checked);
			rdv->setAJeun(this->checkBox2->Checked);
		}

		match = regex->Match(this->comboBox1->Text);
		rdv->setIdIndividu(match->Groups["id"]->Value);

		match = regex->Match(this->comboBox2->Text);
		rdv->setIdTournee(match->Groups["id"]->Value);

		match = regex->Match(this->comboBox3->Text);
		rdv->setIdEmploye(match->Groups["id"]->Value);

		rdv->setCommentaire(this->textBox1->Text);
		rdv->setDate(this->monthCalendar1->SelectionStart.ToString("dd/MM/yyyy"));

		
		ListeRdv->Add(rdv);

		showRdv();
		viderFichierRdv();	
}
private: System::Void modifier()
{
	if (dataGridView1->RowCount != 0)
	{
		Regex^ regex = gcnew Regex("(?<id>.+)\\s+:\\s+");
		Match^ match;

		Rdv ^rdv = Rdv::findRendezVous(*ListeRdv, System::Convert::ToInt32(dataGridView1->CurrentRow->Cells[0]->Value));

		if (this->radioButton1->Checked == true)
		{
			rdv->setPrelevements(System::Convert::ToInt32(this->numericUpDown1->Value));
		}
		else if (this->radioButton2->Checked == true)
		{
			rdv->setDiabetique(this->checkBox1->Checked);
			rdv->setAJeun(this->checkBox2->Checked);
		}

		match = regex->Match(this->comboBox1->Text);
		rdv->setIdIndividu(match->Groups["id"]->Value);

		match = regex->Match(this->comboBox2->Text);
		rdv->setIdTournee(match->Groups["id"]->Value);

		match = regex->Match(this->comboBox3->Text);
		rdv->setIdEmploye(match->Groups["id"]->Value);

		rdv->setCommentaire(this->textBox1->Text);
		rdv->setDate(this->monthCalendar1->SelectionStart.ToString("dd/MM/yyyy"));

		showRdv();
	}
	else
	{
		MessageBox::Show("La liste ne contient pas d'élèment .");
	}
}
private: System::Void supprimer()
{
	if (dataGridView1->RowCount != 0)
	{
		Rdv ^rdv = Rdv::findRendezVous(*ListeRdv, System::Convert::ToInt32(dataGridView1->CurrentRow->Cells[0]->Value));

		rdv->setActif(false);

		showRdv();
		viderFichierRdv();
	}
	else
	{
		MessageBox::Show("La liste ne contient pas élément .");
	}
}
private: System::Void rechercher()
{
	int i = 0;
	bool etat[6] = { 0 };

	etat[0] = (textBox2->Text != "");
	etat[1] = (textBox3->Text != "");
	

	dataGridView1->Rows->Clear();

	for each(Rdv ^rdv in ListeRdv)
	{
		if (rdv->isActif())
		{
			Individu ^individu = Individu::findIndividu(*ListeMedecin, rdv->getIdIndividu());

			etat[2] = (individu->getNom()->ToLower()->StartsWith(textBox2->Text->ToLower()) && textBox2->Text != "");
			etat[3] = (individu->getPrenom()->ToLower()->StartsWith(textBox3->Text->ToLower()) && textBox3->Text != "");
			etat[6] = (this->dateTimePicker1->Value.ToString("dd/MM/yyyy") == rdv->getDate() && etat[5] == true);

			if (etat[0] == etat[2] && etat[1] == etat[3] && etat[5] == etat[6])
			{
				dataGridView1->Rows->Add();

				dataGridView1->Rows[i]->Cells[0]->Value = rdv->getID();
				dataGridView1->Rows[i]->Cells[1]->Value = rdv->getTypeRdv();

				if (this->radioButton1->Checked == true)
				{
					individu = Individu::findIndividu(*ListeMedecin, rdv->getIdIndividu());
				}
				else
				{
					individu = Individu::findIndividu(*ListePatient, rdv->getIdIndividu());
				}

				dataGridView1->Rows[i]->Cells[2]->Value = individu->getNom();
				dataGridView1->Rows[i]->Cells[3]->Value = individu->getPrenom();
				dataGridView1->Rows[i]->Cells[4]->Value = rdv->getDate();
				dataGridView1->Rows[i]->Cells[5]->Value = rdv->getCommentaire();

				++i;
			}
		}
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	viderFichierRdv();
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	ajouter();
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	modifier();
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	supprimer();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	rechercher();
}

private: System::Void MenuRdv_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	oldForm->Show();
}
};
}