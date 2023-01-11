//---------------------------------------------------------------------------

#ifndef Unit7H
#define Unit7H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormRate : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *EditName;
	TButton *ButtonSave;
	TButton *ButtonNotSave;
	TEdit *EditTime;
	TLabel *Label4;
	TEdit *EditCrutches;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall ButtonNotSaveClick(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRate(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRate *FormRate;
//---------------------------------------------------------------------------
#endif
