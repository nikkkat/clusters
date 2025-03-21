//---------------------------------------------------------------------------
#include <windows.h>
#include <string>

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//struct Clr {
//   String Red, Black, Green, Yellow, Purple, Blue, Olive, Lime, Aqua;
//};
struct Pint
{
	int x;
	int y;
	String color;
};
int NUM_CL = 8;
int NUM_PO = 4900;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Canvas->Pen->Color=clRed;
	Canvas->Pen->Width=5;

	Pint points[NUM_PO];

	for (int i = 0 ; i < NUM_PO; i++) {
		int x = rand() % 501;
		int y = rand() % 501;
		Canvas->MoveTo(x,y);
		Canvas->LineTo(x,y);
		points[i].x = x;
		points[i].y = y;
		points[i].color = "Red";

	}

	Pint clusters[NUM_CL];
	int i = 0;

	Canvas->Pen->Width=10;

	Canvas->Pen->Color= clBlack;

	int x = rand() % 501;
	int y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Black";
	i++;

	Canvas->Pen->Color= clGreen;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Green";
	i++;

	Canvas->Pen->Color= clYellow;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Yellow";
	i++;

	Canvas->Pen->Color= clPurple;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Purple";
	i++;

	Canvas->Pen->Color= clBlue;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Blue";
	i++;

	Canvas->Pen->Color= clOlive;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Olive";
	i++;

	Canvas->Pen->Color= clLime;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Lime";
	i++;

	Canvas->Pen->Color= clAqua;

	 x = rand() % 501;
	 y = rand() % 501;
	Canvas->MoveTo(x,y);
	Canvas->LineTo(x,y);
	clusters[i].x = x;
	clusters[i].y = y;
	clusters[i].color = "Aqua";


	Sleep(2500);

	Canvas->Pen->Width=5;

	for (int i = 0 ; i < NUM_PO; i++) {
		int minDist = round(sqrt( (clusters[0].x-points[i].x)*(clusters[0].x-points[i].x) + (clusters[0].y-points[i].y)*(clusters[0].y-points[i].y) ));
		int numC = 0;
		for (int j = 1; j < NUM_CL; j++) {
			int rast = round(sqrt( (clusters[j].x-points[i].x)*(clusters[j].x-points[i].x) + (clusters[j].y-points[i].y)*(clusters[j].y-points[i].y)) );
			if (rast < minDist ) {
				minDist = rast;
				numC = j;
			}
		}

		switch (numC) {
		case 0:
			Canvas->Pen->Color=clBlack;
			points[i].color = "Black";
			break;
		case 1:
			Canvas->Pen->Color=clGreen;
			points[i].color = "Green";
			break;
		case 2:
			Canvas->Pen->Color=clYellow;
			points[i].color = "Yellow";
			break;
		case 3:
			Canvas->Pen->Color=clPurple;
			points[i].color = "Purple";
			break;
		case 4:
			Canvas->Pen->Color=clBlue;
			points[i].color = "Blue";
			break;
		case 5:
			Canvas->Pen->Color=clOlive;
			points[i].color = "Olive";
			break;
		case 6:
			Canvas->Pen->Color=clLime;
			points[i].color = "Lime";
			break;
		case 7:
			Canvas->Pen->Color=clAqua;
			points[i].color = "Aqua";
			break;
		}

		Canvas->MoveTo(points[i].x,points[i].y);
		Canvas->LineTo(points[i].x,points[i].y);


	}

	Sleep(1000);

	int lastx[NUM_CL], lasty[NUM_CL];
	for (int i = 0; i < NUM_CL; i++) {
		lastx[i] = clusters[i].x;
		lasty[i] = clusters[i].y;
	}

	bool flag = true;

	do {

	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(Canvas->ClipRect);

	for (int i = 0; i < NUM_CL; i++) {
		int newX = 0;
		int newY = 0;
		int count = 0;
		for (int j = 0; j < NUM_PO; j++) {
			if (points[j].color == clusters[i].color) {
				newX += points[j].x;
				newY += points[j].y;
				count++;
			}
		}

		clusters[i].x = round(newX/count);
		clusters[i].y = round(newY/count);


		Canvas->Pen->Color=clRed;

		Canvas->Pen->Width=10;
		Canvas->MoveTo(clusters[i].x,clusters[i].y);
		Canvas->LineTo(clusters[i].x,clusters[i].y);

	}

    Canvas->Pen->Width=5;

	for (int i = 0 ; i < NUM_PO; i++) {
		int minDist = round(sqrt( (clusters[0].x-points[i].x)*(clusters[0].x-points[i].x) + (clusters[0].y-points[i].y)*(clusters[0].y-points[i].y) ));
		int numC = 0;
		for (int j = 1; j < NUM_CL; j++) {
			int rast = round(sqrt( (clusters[j].x-points[i].x)*(clusters[j].x-points[i].x) + (clusters[j].y-points[i].y)*(clusters[j].y-points[i].y)) );
			if (rast < minDist ) {
				minDist = rast;
				numC = j;
			}
		}

		switch (numC) {
		case 0:
			Canvas->Pen->Color=clBlack;
			points[i].color = "Black";
			break;
		case 1:
			Canvas->Pen->Color=clGreen;
			points[i].color = "Green";
			break;
		case 2:
			Canvas->Pen->Color=clYellow;
			points[i].color = "Yellow";
			break;
		case 3:
			Canvas->Pen->Color=clPurple;
			points[i].color = "Purple";
			break;
		case 4:
			Canvas->Pen->Color=clBlue;
			points[i].color = "Blue";
			break;
		case 5:
			Canvas->Pen->Color=clOlive;
			points[i].color = "Olive";
			break;
		case 6:
			Canvas->Pen->Color=clLime;
			points[i].color = "Lime";
			break;
		case 7:
			Canvas->Pen->Color=clAqua;
			points[i].color = "Aqua";
			break;
		}

		Canvas->MoveTo(points[i].x,points[i].y);
		Canvas->LineTo(points[i].x,points[i].y);


	}

		 flag = true;
		 for (i = 0; i < NUM_CL; i++) {
			 if (lastx[i] != clusters[i].x) {
				flag = false;
				lastx[i] = clusters[i].x;
			 }
			 if (lasty[i] != clusters[i].y) {
				flag = false;
				lasty[i] = clusters[i].y;
			 }
		 }

		 //Sleep(200);

	} while (!flag);


}
//---------------------------------------------------------------------------
