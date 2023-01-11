//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormDificult *FormDificult;
//---------------------------------------------------------------------------
__fastcall TFormDificult::TFormDificult(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormDificult::FormClose(TObject *Sender, TCloseAction &Action)
{
    FormMenu->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormDificult::Button1Click(TObject *Sender)
{
	FormGameEasy = new TFormGameEasy(Owner);

	FormGameEasy->Show();
	FormDificult->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFormDificult::Button2Click(TObject *Sender)
{
	FormGameNormal = new TFormGameNormal(Owner);

	FormGameNormal->Show();
	FormDificult->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFormDificult::Button3Click(TObject *Sender)
{
    FormGameHard = new TFormGameHard(Owner);

	FormGameHard->Show();
	FormDificult->Hide();
}
//---------------------------------------------------------------------------

