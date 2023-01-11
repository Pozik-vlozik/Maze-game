//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"

#include <fstream>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRate *FormRate;
//---------------------------------------------------------------------------

char name[50];
char difficulty[10];
double passingTime;



__fastcall TFormRate::TFormRate(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRate::FormShow(TObject *Sender)
{
	EditName->Text = "";
	passingTime = StrToFloat(EditTime->Text) / 100;
	Label2->Caption = "���� �����: " + FloatToStr(passingTime) + " ������";
	Label4->Caption = "���� ���������: " + EditCrutches->Text;
}
//---------------------------------------------------------------------------
void __fastcall TFormRate::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormMenu->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormRate::ButtonNotSaveClick(TObject *Sender)
{
	FormMenu->Show();
	FormRate->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormRate::ButtonSaveClick(TObject *Sender)
{
	StrPCopy(name, EditName->Text);
	StrPCopy(difficulty, EditCrutches->Text);
	FormRate->Close();

	fstream RatingFile("E:\\Main\\!�������� ������ ���������\\aMAZEing maze game\\MazeRating.txt", ios_base::app);
	RatingFile << "\n" << difficulty << "\n" << name << "\n" << passingTime;
	RatingFile.close();
}
//---------------------------------------------------------------------------
