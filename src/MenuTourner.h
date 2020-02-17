#pragma once

#include "Localite.h"
#include "Individu.h"
#include "Secretaire.h"
#include "Patient.h"
#include "Coursier.h"
#include "Medecin.h"
#include "Infirmiere.h"
#include "Rdv.h"
#include "Tourner.h"
#include "MenuTourner.h"

namespace ExamenPOO {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::InteropServices;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for MenuTourner
	/// </summary>
	public ref class MenuTourner : public System::Windows::Forms::Form
	{
	public:
		MenuTourner(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		MenuTourner(Form ^form1,List<Tourner^> ^lstTournee,List<Rdv^> ^lstRendezVous,List<Localite^> ^lstLocCP,List<Individu^> ^lstMedecin,List<Individu^> ^lstPatient)
		{
			oldForm = form1;
			ListeMedecin = lstMedecin;
			ListePatient = lstPatient;
			ListeTourner = lstTournee;
			ListeRdv = lstRendezVous;
			ListeLocalite = lstLocCP;

			InitializeComponent();

			for each(Localite ^localite in ListeLocalite)
			{
				this->listBox1->Items->Add(localite->getCodePostal() + " " + localite->getNomLocalite());
			}

			showTourner();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MenuTourner()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Form ^ oldForm;
	private: System::Collections::Generic::List<Localite^> ^ListeLocalite;
	private: System::Collections::Generic::List<Individu^> ^ListePatient;
	private: System::Collections::Generic::List<Individu^> ^ListeMedecin;
	private: System::Collections::Generic::List<Tourner^> ^ListeTourner;
	private: System::Collections::Generic::List<Rdv^> ^ListeRdv;
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;
	private: System::Windows::Forms::CheckBox^  checkBox7;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Nom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Prénom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Commentaire;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  IDTourner;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NomTourner;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->IDTourner = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NomTourner = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Prénom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Commentaire = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 446);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Nouveau";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MenuTourner::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(184, 446);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ajouter";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MenuTourner::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->IDTourner,
					this->NomTourner
			});
			this->dataGridView1->Location = System::Drawing::Point(358, 15);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(200, 385);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuTourner::dataGridView1_RowEnter);
			// 
			// IDTourner
			// 
			this->IDTourner->HeaderText = L"IDTourner";
			this->IDTourner->Name = L"IDTourner";
			this->IDTourner->ReadOnly = true;
			// 
			// NomTourner
			// 
			this->NomTourner->HeaderText = L"NomTourner";
			this->NomTourner->Name = L"NomTourner";
			this->NomTourner->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Nom de tourner";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(157, 22);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(169, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Type de tourner";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(166, 75);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(67, 17);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Infirmiere";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(272, 75);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(63, 17);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Coursier";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(29, 119);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(52, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Lundi";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(29, 142);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(52, 17);
			this->checkBox2->TabIndex = 9;
			this->checkBox2->Text = L"Mardi";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(29, 165);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(67, 17);
			this->checkBox3->TabIndex = 10;
			this->checkBox3->Text = L"Mercredi";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MenuTourner::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(29, 188);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(51, 17);
			this->checkBox4->TabIndex = 11;
			this->checkBox4->Text = L"Jeudi";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(29, 211);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(68, 17);
			this->checkBox5->TabIndex = 12;
			this->checkBox5->Text = L"Vendredi";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(29, 234);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(61, 17);
			this->checkBox6->TabIndex = 13;
			this->checkBox6->Text = L"Samedi";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Location = System::Drawing::Point(29, 257);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(74, 17);
			this->checkBox7->TabIndex = 14;
			this->checkBox7->Text = L"Dimanche";
			this->checkBox7->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(374, 442);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 38);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Supprimer";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MenuTourner::button3_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(157, 119);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(169, 160);
			this->listBox1->TabIndex = 16;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(157, 300);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(71, 36);
			this->button4->TabIndex = 17;
			this->button4->Text = L" +";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MenuTourner::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(246, 300);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(77, 36);
			this->button5->TabIndex = 18;
			this->button5->Text = L" -";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MenuTourner::button5_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(157, 342);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(166, 69);
			this->listBox2->TabIndex = 19;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBox2);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Controls->Add(this->checkBox7);
			this->groupBox1->Controls->Add(this->checkBox6);
			this->groupBox1->Controls->Add(this->checkBox5);
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Location = System::Drawing::Point(16, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(579, 426);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Tourner";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->ID, this->Type,
					this->Nom, this->Prénom, this->Date, this->Commentaire
			});
			this->dataGridView2->Location = System::Drawing::Point(630, 29);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(345, 478);
			this->dataGridView2->TabIndex = 21;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MenuTourner::dataGridView2_CellContentClick);
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
			// Prénom
			// 
			this->Prénom->HeaderText = L"Prénom";
			this->Prénom->Name = L"Prénom";
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
			// MenuTourner
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(992, 528);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Name = L"MenuTourner";
			this->Text = L"MenuTourner";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MenuTourner::MenuTourner_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void MenuTourner_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	oldForm->Show();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	viderFicheTourner();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	ajouter();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	supprimer();
}
private: System::Void viderFicheTourner()
{
	System::Collections::ArrayList ^listItem = gcnew System::Collections::ArrayList;

	this->textBox1->Text = "";

	this->radioButton1->Checked = false;
	this->radioButton2->Checked = false;

	this->checkBox1->Checked = false;
	this->checkBox2->Checked = false;
	this->checkBox3->Checked = false;
	this->checkBox4->Checked = false;
	this->checkBox5->Checked = false;
	this->checkBox6->Checked = false;
	this->checkBox7->Checked = false;

	for each (String ^ item in listBox2->Items)
		listItem->Add(item);
	for each (String ^ item in listItem)
	{
		listBox2->Items->Remove(item);
		listBox1->Items->Add(item);
	}

}
private: System::Void ajouter()
{
	Tourner ^tournee = gcnew Tourner(ListeLocalite);

	tournee->setNom(this->textBox1->Text);

	if (this->radioButton1->Checked == true)
		tournee->setTypeTournee("Infirmiere");
	else
		tournee->setTypeTournee("Coursier");

	tournee->setBoolJour("Monday", this->checkBox1->Checked);
	tournee->setBoolJour("Tuesday", this->checkBox2->Checked);
	tournee->setBoolJour("Wednesday", this->checkBox3->Checked);
	tournee->setBoolJour("Thursday", this->checkBox4->Checked);
	tournee->setBoolJour("Friday", this->checkBox5->Checked);
	tournee->setBoolJour("Saturday", this->checkBox6->Checked);
	tournee->setBoolJour("Sunday", this->checkBox7->Checked);

	for each (String ^ item in listBox2->Items)
		tournee->setLocTournee(item, true);

	ListeTourner->Add(tournee);

	showTourner();
	viderFicheTourner();
}
private: System::Void supprimer()
{
	if (dataGridView1->RowCount != 0)
	{
		Tourner ^tournee = Tourner::findTournee(*ListeTourner, dataGridView1->CurrentRow->Cells[0]->Value->ToString());

		tournee->setActif(false);

		showTourner();
		viderFicheTourner();
	}
	else
	{
		MessageBox::Show("La liste ne contient pas d'élément .");
	}
}
private: System::Void showTourner()
{
	int i = 0;

	dataGridView1->Rows->Clear();

	for each(Tourner ^trn in ListeTourner)
	{
		if (trn->isActif())
		{
			dataGridView1->Rows->Add();

			dataGridView1->Rows[i]->Cells[0]->Value = trn->getId();
			dataGridView1->Rows[i]->Cells[1]->Value = trn->getNom();

			++i;
		}
	}
}
private: System::Void showRdv()
{
	int i = 0;

	dataGridView2->Rows->Clear();

	for each(Rdv ^rdv in ListeRdv)
	{
		if (rdv->isActif())
		{
			dataGridView2->Rows->Add();

			dataGridView2->Rows[i]->Cells[0]->Value = rdv->getID();
			dataGridView2->Rows[i]->Cells[1]->Value = rdv->getTypeRdv();

			Individu ^individu;

			if (rdv->getTypeRdv() == "Medecin")
			{
				individu = Individu::findIndividu(*ListeMedecin, rdv->getIdIndividu());
			}
			else if (rdv->getTypeRdv() == "Patient")
			{
				individu = Individu::findIndividu(*ListePatient, rdv->getIdIndividu());
			}

			dataGridView2->Rows[i]->Cells[2]->Value = individu->getNom();
			dataGridView2->Rows[i]->Cells[3]->Value = individu->getPrenom();
			dataGridView2->Rows[i]->Cells[4]->Value = rdv->getDate();
			dataGridView2->Rows[i]->Cells[5]->Value = rdv->getCommentaire();

			++i;
		}
	}
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Collections::ArrayList ^listItem = gcnew System::Collections::ArrayList;

	for each (String ^ item in listBox1->SelectedItems)
		listItem->Add(item);
	for each (String ^ item in listItem)
	{
		listBox1->Items->Remove(item);
		listBox2->Items->Add(item);
	}

	this->listBox1->Sorted = true;
}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Collections::ArrayList ^listItem = gcnew System::Collections::ArrayList;

	for each (String ^ item in listBox2->SelectedItems)
		listItem->Add(item);
	for each (String ^ item in listItem)
	{
		listBox2->Items->Remove(item);
		listBox1->Items->Add(item);
	}

	this->listBox1->Sorted = true;
}
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView1_RowEnter(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	int i = 0;
	System::Collections::ArrayList ^listItem = gcnew System::Collections::ArrayList;

	dataGridView2->Rows->Clear();

	for each (String ^ item in listBox2->Items)
		listItem->Add(item);
	for each (String ^ item in listItem)
	{
		listBox2->Items->Remove(item);
		listBox1->Items->Add(item);
	}

	this->listBox1->Sorted = true;
	listItem->Clear();

	if (dataGridView1->CurrentRow != nullptr)
	{
		Tourner ^tournee = Tourner::findTournee(*ListeTourner, dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString());

		this->textBox1->Text = tournee->getNom();

		if (tournee->getTypeTournee() == "Infirmiere")
			this->radioButton1->Checked = true;
		else
			this->radioButton2->Checked = true;

		this->checkBox1->Checked = tournee->getBoolJour("Monday");
		this->checkBox2->Checked = tournee->getBoolJour("Tuesday");
		this->checkBox3->Checked = tournee->getBoolJour("Wednesday");
		this->checkBox4->Checked = tournee->getBoolJour("Thursday");
		this->checkBox5->Checked = tournee->getBoolJour("Friday");
		this->checkBox6->Checked = tournee->getBoolJour("Saturday");
		this->checkBox7->Checked = tournee->getBoolJour("Sunday");

		for each (String ^ item in listBox1->Items)
		{
			if (tournee->getLocTournee(item))
			{
				listItem->Add(item);
			}
		}

		for each (String ^ item in listItem)
		{
			listBox1->Items->Remove(item);
			listBox2->Items->Add(item);
		}

		for each(Rdv ^rdv in ListeRdv)
		{
			if (rdv->isActif() && rdv->getIdTournee() == dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString())
			{
				dataGridView2->Rows->Add();

				dataGridView2->Rows[i]->Cells[0]->Value = rdv->getID();
				dataGridView2->Rows[i]->Cells[1]->Value = rdv->getTypeRdv();

				Individu ^individu;

				if (rdv->getTypeRdv() == "Medecin")
				{
					individu = Individu::findIndividu(*ListeMedecin, rdv->getIdIndividu());
				}
				else if (rdv->getTypeRdv() == "Patient")
				{
					individu = Individu::findIndividu(*ListePatient, rdv->getIdIndividu());
				}

				dataGridView2->Rows[i]->Cells[2]->Value = individu->getNom();
				dataGridView2->Rows[i]->Cells[3]->Value = individu->getPrenom();
				dataGridView2->Rows[i]->Cells[4]->Value = rdv->getDate();
				dataGridView2->Rows[i]->Cells[5]->Value = rdv->getCommentaire();

				++i;
			}
		}
	}
}
};
}
