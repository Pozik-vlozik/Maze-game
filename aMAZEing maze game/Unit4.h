//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFormGameEasy : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Character;
	TTimer *Timer1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormGameEasy(TComponent* Owner);
	void __fastcall GetAll();
	void __fastcall Mazzer();
	int __fastcall offset(int x, int y);
	void __fastcall DrawMaze();
	void __fastcall Table();
	void __fastcall Marckup();
    //��� ��� �������� ���������, ��������, �������� ��� ����������((
	int __fastcall is_pixel_black(TColor col);
	int __fastcall position_check(int Key);
	void __fastcall character_moveing(int Key);
    void __fastcall you_won();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormGameEasy *FormGameEasy;
//---------------------------------------------------------------------------
#endif
