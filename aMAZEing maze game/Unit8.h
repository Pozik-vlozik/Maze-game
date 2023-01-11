//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
struct Rate
{
	char time[10];
	char name[50];
	char difficulty[11];
};


class TFormRateing : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *SGEasy;
	TStringGrid *SGHard;
	TStringGrid *SGNormal;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRateing(TComponent* Owner);
	void __fastcall sortByTime(Rate* arr, int arrIndex);
    void __fastcall SGSetup();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRateing *FormRateing;
//---------------------------------------------------------------------------
#endif
