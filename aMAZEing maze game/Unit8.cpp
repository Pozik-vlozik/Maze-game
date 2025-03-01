//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit8.h"

#include <fstream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRateing *FormRateing;
int EasyIndex,
	NormalIndex,
	HardIndex;

//---------------------------------------------------------------------------
__fastcall TFormRateing::TFormRateing(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRateing::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormMenu->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFormRateing::sortByTime(Rate* arr, int arrIndex)
{
	for (int i = 0; i < arrIndex; i++)
		for (int j = i; j < arrIndex; j++)
			if (stof(arr[i].time) > stof(arr[j].time))
			{
				swap(arr[i].time, arr[j].time);
				swap(arr[i].difficulty, arr[j].difficulty);
				swap(arr[i].name, arr[j].name);
			}
}

void __fastcall TFormRateing::FormShow(TObject *Sender)
{
	fstream RatingFile;
	Rate* results;
	char buffer[50];

	int MicroChelsAmount;

	RatingFile.open("E:\\Main\\!�������� ������ ���������\\aMAZEing maze game\\MazeRating.txt");

	if (!RatingFile.is_open())
	{
		ShowMessage("�� ���������� ������� ���� � ������������");
	}
	else
	{
		MicroChelsAmount = 0;

		while (!RatingFile.eof())
		{
			RatingFile.getline(buffer, 255);
			MicroChelsAmount++;
		}
		MicroChelsAmount /= 3;

		results = new Rate[MicroChelsAmount];
		RatingFile.seekg(0);

		EasyIndex = 0,
		NormalIndex = 0,
		HardIndex = 0;

		int i = 0;

		while (!RatingFile.eof())
		{
			RatingFile.getline(results[i].difficulty, 255);
			if (strcmp(results[i].difficulty, "�������") == 0)
				EasyIndex++;
			else if (strcmp(results[i].difficulty, "����������") == 0)
				NormalIndex++;
			else if (strcmp(results[i].difficulty, "�������") == 0)
				HardIndex++;

			RatingFile.getline(results[i].name, 255);
			RatingFile.getline(results[i].time, 255);
			i++;
		}

		RatingFile.close();

		Rate* EasyArr = new Rate[EasyIndex],
			* NormalArr = new Rate[NormalIndex],
			* HardArr = new Rate[HardIndex];

		EasyIndex = 0;
		NormalIndex = 0;
		HardIndex = 0;

		for (int i = 0; i < MicroChelsAmount; i++)
		{
			if (strcmp(results[i].difficulty, "�������") == 0)
			{
				strcpy(EasyArr[EasyIndex].difficulty, results[i].difficulty);
				strcpy(EasyArr[EasyIndex].name, results[i].name);
				strcpy(EasyArr[EasyIndex].time, results[i].time);

				EasyIndex++;
			}

			else if (strcmp(results[i].difficulty, "����������") == 0)
			{
				strcpy(NormalArr[NormalIndex].difficulty, results[i].difficulty);
				strcpy(NormalArr[NormalIndex].name, results[i].name);
				strcpy(NormalArr[NormalIndex].time, results[i].time);

				NormalIndex++;
			}

			else if (strcmp(results[i].difficulty, "�������") == 0)
			{
				strcpy(HardArr[HardIndex].difficulty, results[i].difficulty);
				strcpy(HardArr[HardIndex].name, results[i].name);
				strcpy(HardArr[HardIndex].time, results[i].time);

				HardIndex++;
			}
		}

		sortByTime(EasyArr, EasyIndex);
		sortByTime(NormalArr, NormalIndex);
		sortByTime(HardArr, HardIndex);

		SGSetup();

		int HighestIndex;

		HighestIndex = (EasyIndex > NormalIndex) ? EasyIndex:NormalIndex;
		if (HardIndex > HighestIndex)
		{
			HighestIndex = HardIndex;
		}


		for (int i = 0; i < HighestIndex; i++)
		{
			if (i < EasyIndex)
			{
				SGEasy->Cells[0][i + 1] = i + 1;
				SGEasy->Cells[1][i + 1] = EasyArr[i].name;
				SGEasy->Cells[2][i + 1] = EasyArr[i].time;
			}

			if (i < NormalIndex)
			{
				SGNormal->Cells[0][i + 1] = i + 1;
				SGNormal->Cells[1][i + 1] = NormalArr[i].name;
				SGNormal->Cells[2][i + 1] = NormalArr[i].time;
			}
			if (i < HardIndex)
			{

				SGHard->Cells[0][i + 1] = i + 1;
				SGHard->Cells[1][i + 1] = HardArr[i].name;
				SGHard->Cells[2][i + 1] = HardArr[i].time;
			}
		}


	}

}
//---------------------------------------------------------------------------
void __fastcall TFormRateing::SGSetup()
{
	SGEasy->ColCount = 3;
	SGEasy->RowCount = EasyIndex + 1;

	SGNormal->ColCount = 3;
	SGNormal->RowCount = NormalIndex + 1;

	SGHard->ColCount = 3;
	SGHard->RowCount = HardIndex + 1;


	SGEasy->Cells[0][0] = "�����";
	SGEasy->Cells[1][0] = "���";
	SGEasy->Cells[2][0] = "�����, �";

	SGNormal->Cells[0][0] = "�����";
	SGNormal->Cells[1][0] = "���";
	SGNormal->Cells[2][0] = "�����, �";

	SGHard->Cells[0][0] = "�����";
	SGHard->Cells[1][0] = "���";
	SGHard->Cells[2][0] = "�����, �";
}


