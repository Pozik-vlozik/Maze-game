//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormSkins : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TFormSkins(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormSkins *FormSkins;
//---------------------------------------------------------------------------
#endif
