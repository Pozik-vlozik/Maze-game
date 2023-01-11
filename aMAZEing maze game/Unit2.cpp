//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormSkins *FormSkins;
//---------------------------------------------------------------------------
__fastcall TFormSkins::TFormSkins(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormSkins::FormClose(TObject *Sender, TCloseAction &Action)
{
    FormMenu->Show();
}
//---------------------------------------------------------------------------
