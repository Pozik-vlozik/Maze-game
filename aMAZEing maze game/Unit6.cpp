//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include "Unit6.h"
#include "Unit7.h"

#include <stack>
#include <vector>
using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormGameHard *FormGameHard;
//---------------------------------------------------------------------------
int playTime;

__fastcall TFormGameHard::TFormGameHard(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int CellSize = 70;
int mWidth, mHeight, amountHor, amountVer;
int visitedCells;
int *mMaze;
int path_width = 5;
stack<pair<int, int>> mStack;


enum
{
	CELL_UP = 0x01,
	CELL_LEFT = 0x02,
	CELL_DOWN = 0x04,
	CELL_RIGHT = 0x08,
	CELL_VISITED = 0x10
};


void __fastcall TFormGameHard::Table()
{
	for (int i = 0; i <= amountHor; i++)
	{
		Image1->Canvas->MoveTo(2 + i * CellSize, 4);
		Image1->Canvas->LineTo(2 + i * CellSize, mHeight);
	}

	for (int j = 0; j <= amountVer; j++)
	{
		Image1->Canvas->MoveTo(2, 4 + j * CellSize);
		Image1->Canvas->LineTo(mWidth, 4 + j * CellSize);

	}
}


void __fastcall TFormGameHard::Marckup()
{
	Image1->Canvas->Brush->Color = clWhite;
	Image1->Canvas->Pen->Color = clWhite;
	Image1->Canvas->Pen->Width = path_width;
	Image1->Canvas->Rectangle(0, 0, mWidth, mHeight);
	Image1->Canvas->Pen->Color = clBlack;

	Table();
}


void __fastcall TFormGameHard::GetAll()
{
	amountHor = Image1->Width / CellSize;
	amountVer = Image1->Height / CellSize;
	mWidth = amountHor * CellSize;
	mHeight = amountVer * CellSize;
	mMaze = new int[amountHor * amountVer];
}


int __fastcall TFormGameHard::offset(int x, int y)
{
	return (mStack.top().second + y) * amountHor + (mStack.top().first + x);
}


void __fastcall TFormGameHard::Mazzer()
{
	for (int i = 0; i < amountHor * amountVer; i++)
	{
		mMaze[i] = 0x00;
	}
	int x = 0;
	int y = 0;
	mStack.push(make_pair(x, y));
	mMaze[y * amountHor + x] = CELL_VISITED;
	visitedCells = 1;


	while (visitedCells < amountHor * amountVer)
	{
		vector<int> neighbours;

		// ������� �����
		if (mStack.top().second > 0 && (mMaze[offset(0, -1)] &  CELL_VISITED) == 0)
			neighbours.push_back(0);
		// ������ �����
		if (mStack.top().first < amountHor - 1 && (mMaze[offset(1, 0)] & CELL_VISITED) == 0)
			neighbours.push_back(1);
		// ������ �����
		if (mStack.top().second < amountVer - 1 && (mMaze[offset(0, 1)] & CELL_VISITED) == 0)
			neighbours.push_back(2);
		// ����� �����
		if (mStack.top().first > 0 && (mMaze[offset(-1, 0)] & CELL_VISITED) == 0)
			neighbours.push_back(3);



		if (!neighbours.empty())
		{
			int next_cell_dir = neighbours[rand() % neighbours.size()];

			switch (next_cell_dir)
			{
			case 0: // �������
				mMaze[offset(0, -1)] |= CELL_VISITED | CELL_DOWN;
				mMaze[offset(0, 0)] |= CELL_UP;
				mStack.push(make_pair((mStack.top().first + 0), (mStack.top().second - 1)));
				break;
			case 1: // ������
				mMaze[offset(+1, 0)] |= CELL_VISITED | CELL_LEFT;
				mMaze[offset(0, 0)] |= CELL_RIGHT;
				mStack.push(make_pair((mStack.top().first + 1), (mStack.top().second + 0)));
				break;

			case 2: // ������
				mMaze[offset(0, +1)] |= CELL_VISITED | CELL_UP;
				mMaze[offset(0, 0)] |= CELL_DOWN;
				mStack.push(make_pair((mStack.top().first + 0), (mStack.top().second + 1)));
				break;

			case 3: // �����
				mMaze[offset(-1, 0)] |= CELL_VISITED | CELL_RIGHT;
				mMaze[offset(0, 0)] |= CELL_LEFT;
				mStack.push(make_pair((mStack.top().first - 1), (mStack.top().second + 0)));
				break;

			}

			visitedCells++;
		}
		else
		{
			// ��� ��������� �������
			mStack.pop();
		}

	}

	DrawMaze();

}


 void __fastcall TFormGameHard::DrawMaze()
 {
	Image1->Canvas->Pen->Width = path_width;
	Image1->Canvas->Brush->Color = clBlack;
	Image1->Canvas->Rectangle(0, 0, mWidth, mHeight);
	Image1->Canvas->Pen->Color = clBlack;

	for (int x = 0; x < amountHor; x++)
	{
		for (int y = 0; y < amountVer; y++)
		{
			if (mMaze[y * amountHor + x] & CELL_VISITED)
			{
				Image1->Canvas->Brush->Color = clWhite;
				Image1->Canvas->Rectangle(x * CellSize, y * CellSize, x * CellSize + CellSize, y * CellSize + CellSize);
			}
			else
			{
				Image1->Canvas->Brush->Color = clBlue;
				Image1->Canvas->Rectangle(x * CellSize, y * CellSize, x * CellSize + CellSize, y * CellSize + CellSize);
			}
		}
	}


	Image1->Canvas->Pen->Width = path_width + 1;
	Image1->Canvas->Pen->Color = clWhite;

	for (int x = 0; x < amountHor; x++)
	{
		for (int y = 0; y < amountVer; y++)
		{
			if (mMaze[y * amountHor + x] & CELL_DOWN)
			{
				//������� ������ ������ i-��� j-��� ������
				Image1->Canvas->Rectangle(6 + CellSize * x, CellSize  + 6 + CellSize * y, CellSize * x + CellSize - 5, CellSize - 5 + CellSize * y);
			}

			if (mMaze[y * amountHor + x] & CELL_RIGHT)
			{
				//������� ������ ������ i-��� j-��� ������
				Image1->Canvas->Rectangle(6 + CellSize * x + CellSize, CellSize * y + 6, CellSize * x + CellSize, CellSize + CellSize * y - 5);
			}
		}
	}

	Image1->Canvas->Brush->Color = clGreen;
	Image1->Canvas->Pen->Color = clWhite;
	Image1->Canvas->Rectangle(CellSize * (amountHor - 1) + 10, CellSize * (amountVer - 1) + 10, CellSize * (amountHor - 1) + CellSize - 10, CellSize * (amountVer - 1) + CellSize - 10);
 }
//---------------------------------------------------------------------------

void __fastcall TFormGameHard::FormCreate(TObject *Sender)
{
	GetAll();

	srand(time(NULL));

	Mazzer();
}
//---------------------------------------------------------------------------
void __fastcall TFormGameHard::FormClose(TObject *Sender, TCloseAction &Action)
{
	FormMenu->Show();
	delete FormGameHard;
}
//---------------------------------------------------------------------------

//��� ��� �������� ���������

int __fastcall TFormGameHard::is_pixel_black(TColor col)
{
	if (col == clGreen)
	{
		return 2;
	}

	else if (col == clBlack)
	{
		return 0;
	}

	else
	{
		return 1;
	}

}


int __fastcall TFormGameHard::position_check(int Key)
{

	switch(Key)
	{
		case 87:
		{
			TColor col = Image1->Canvas->Pixels[Character->Left + Character->Width / 2][Character->Top - 10];
			return is_pixel_black(col);

			break;
		}
		case 83:
		{
			TColor col = Image1->Canvas->Pixels[Character->Left + Character->Width / 2][Character->Top + Character->Height - 10];
			return is_pixel_black(col);

			break;
		}
		case 65:
		{
			TColor col = Image1->Canvas->Pixels[Character->Left - 10][Character->Top + Character->Height / 2];
			return is_pixel_black(col);

			break;
		}
		case 68:
		{
			TColor col = Image1->Canvas->Pixels[Character->Left + Character->Width - 10][Character->Top + Character->Height / 2];
			return is_pixel_black(col);

			break;
		}
	}

}


void __fastcall TFormGameHard::character_moveing(int Key)
{
	switch (Key)
	{
		case 87:
		{
			for (int i = 0; i < 10; i++)
			{
				if (position_check(Key) == 2)
				{
					ShowMessage("You Won");
					return;
				}
				else if (position_check(Key) == 1)
				{
					Character->Top -= 1;
				}
			}
			break;
		}
		case 83:
		{
			for (int i = 0; i < 10; i++)
			{
				if (position_check(Key) == 2)
				{
					ShowMessage("You Won");
					you_won();
					return;
				}
				else if (position_check(Key) == 1)
				{
					Character->Top += 1;
				}
			}
			break;
		}
		case 65:
		{
			for (int i = 0; i < 10; i++)
			{
				if (position_check(Key) == 2)
				{
					ShowMessage("You Won");
					you_won();
					return;
				}
				else if (position_check(Key) == 1)
				{
					Character->Left -= 1;
				}
			}
			break;
		}
		case 68:
		{
			for (int i = 0; i < 10; i++)
			{
				if (position_check(Key) == 2)
				{
					ShowMessage("You Won");
					you_won();
					return;
				}
				else if (position_check(Key) == 1)
				{
					Character->Left += 1;
				}
			}
			break;
		}
	}
}
void __fastcall TFormGameHard::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	character_moveing(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFormGameHard::FormKeyPress(TObject *Sender, System::WideChar &Key)
{
	character_moveing(Key);
}
//---------------------------------------------------------------------------

void __fastcall TFormGameHard::Timer1Timer(TObject *Sender)
{
	playTime++;
}
//---------------------------------------------------------------------------

void __fastcall TFormGameHard::FormShow(TObject *Sender)
{
	playTime = 0;
	Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormGameHard::you_won()
{
	Timer1->Enabled = false;
	FormRate->EditTime->Text = playTime;
    FormRate->EditCrutches->Text = "�������";
	delete FormGameHard;
	FormRate->Show();
}

