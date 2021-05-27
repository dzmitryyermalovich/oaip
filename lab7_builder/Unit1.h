//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TMemo *Memo1;
	TMemo *Memo2;
	TRadioGroup *RadioGroup1;
	TRadioGroup *RadioGroup2;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TEdit *Edit3;
	TLabel *Label3;
	TEdit *Edit4;
	TLabel *Label4;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
