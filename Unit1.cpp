//---------------------------------------------------------------------------
#include <vcl.h>
#include <Math.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
typedef struct {
   float v[4][4];
} MATRIZ;
MATRIZ identidad= {{{1,0,0,0},
                                  {0,1,0,0},
                                  {0,0,1,0},			       {0,0,0,1} }};
MATRIZ mtrans=identidad;
typedef struct {
   float x,y,z;
   int dib;
} VTX;
/*int maxvtx=18;
VTX lista[3000]={{0,0,0,0} ,    //cubo3D
                 {100,0,0,1},
                 {100,100,0,1},
                 {0,100,0,1},
                 {0,0,0,1},

                 {0,0,100,0} ,
                 {100,0,100,1},
                 {100,100,100,1},
                 {0,100,100,1},
                 {0,0,100,1},

                 {0,0,0,0} ,
                 {0,0,100,1} ,
                 {100,0,0,0},
                 {100,0,100,1},
                 {100,100,0,0},
                 {100,100,100,1},
                 {0,100,0,0},
                 {0,100,100,1}
                 };
*/
/*
int maxvtx=13;
VTX lista[3000]={{0,0,0,0} ,    //triangulo
                 {100,0,0,1},
                 {100,100,0,1},
                 {0,100,0,1},
                 {0,0,0,1},

                 {50,50,100,0} ,
                 {0,0,0,1},
                 {50,50,100,0} ,
                 {100,0,0,1},
                 {50,50,100,0} ,
                 {100,100,0,1},
                 {50,50,100,0} ,
                 {0,100,0,1},
                 };
*/  /*
int maxvtx=12;
VTX lista[3000]={{0,0,0,0},
                 {100,0,0,1},
                 {100,100,0,1},
                 {0,100,0,1},
                 {0,0,0,1},

                 {0,50,50,1},
                 {0,100,0,1},
                 {100,0,0,0},
                 {100,50,50,1},
                 {100,100,0,1},

                 {0,50,50,0},
                 {100,50,50,1},
                 };
*/
int maxvtx=100;
VTX lista[3000]={{0,0,0,0},//H
                 {50,0,0,1},
                 {50,10,0,1},
                 {30,10,0,1},
                 {30,20,0,1},
                 {50,20,0,1},
                 {50,30,0,1},
                 {0,30,0,1},
                 {0,20,0,1},
                 {20,20,0,1},
                 {20,10,0,1},
                 {0,10,0,1},
                 {0,0,0,1},
                 /////
                 {0,0,10,0},
                 {50,0,10,1},
                 {50,10,10,1},
                 {30,10,10,1},
                 {30,20,10,1},
                 {50,20,10,1},
                 {50,30,10,1},
                 {0,30,10,1},
                 {0,20,10,1},
                 {20,20,10,1},
                 {20,10,10,1},
                 {0,10,10,1},
                 {0,0,10,1},
                 /////
                 {0,0,0,0},
                 {0,0,10,1},

                 {50,0,0,0},
                 {50,0,10,1},

                 {50,10,0,0},
                 {50,10,10,1},

                 {30,10,0,0},
                 {30,10,10,1},

                 {30,20,0,0},
                 {30,20,10,1},

                 {50,20,0,0},
                 {50,20,10,1},

                 {50,30,0,0},
                 {50,30,10,1},

                 {0,30,0,0},
                 {0,30,10,1},

                 {0,20,0,0},
                 {0,20,10,1},

                 {20,20,0,0},
                 {20,20,10,1},

                 {20,10,0,0},
                 {20,10,10,1},

                 {0,10,0,0},
                 {0,10,10,1},
                  //////M
                 {0,50,0,0},
                 {50,50,0,1},
                 {50,60,0,1},
                 {20,60,0,1},
                 {30,65,0,1},
                 {20,70,0,1},
                 {50,70,0,1},
                 {50,80,0,1},
                 {0,80,0,1},
                 {0,70,0,1},
                 {10,65,0,1},
                 {0,60,0,1},
                 {0,50,0,1},

                 {0,50,10,0},
                 {50,50,10,1},
                 {50,60,10,1},
                 {20,60,10,1},
                 {30,65,10,1},
                 {20,70,10,1},
                 {50,70,10,1},
                 {50,80,10,1},
                 {0,80,10,1},
                 {0,70,10,1},
                 {10,65,10,1},
                 {0,60,10,1},
                 {0,50,10,1},

                 {0,50,0,0},
                 {0,50,10,1},

                 {50,50,0,0},
                 {50,50,10,1},

                 {50,60,0,0},
                 {50,60,10,1},

                 {20,60,0,0},
                 {20,60,10,1},

                 {30,65,0,0},
                 {30,65,10,1},

                 {20,70,0,0},
                 {20,70,10,1},

                 {50,70,0,0},
                 {50,70,10,1},

                 {50,80,0,0},
                 {50,80,10,1},

                 {0,80,0,0},
                 {0,80,10,1},

                 {0,70,0,0},
                 {0,70,10,1},

                 {10,65,0,0},
                 {10,65,10,1},

                 {0,60,0,0},
                 {0,60,10,1},
                 };
void aplica_matriz(VTX a,VTX &b) {
  b.x=mtrans.v[0][0]*a.x+
      mtrans.v[0][1]*a.y+
      mtrans.v[0][2]*a.z+
      mtrans.v[0][3]*1;
  b.y=mtrans.v[1][0]*a.x+
      mtrans.v[1][1]*a.y+
      mtrans.v[1][2]*a.z+
      mtrans.v[1][3]*1;
  b.z=mtrans.v[2][0]*a.x+
      mtrans.v[2][1]*a.y+
      mtrans.v[2][2]*a.z+
      mtrans.v[2][3]*1;
  b.dib=a.dib;
}
void dibujar(void)
{
   VTX aux;
   int i;
   for (i=0;i<maxvtx;i++)
   {
        aplica_matriz(lista[i],aux);
        if(aux.dib==0)
           Form1->Canvas->MoveTo(aux.x, aux.y);
        else
           Form1->Canvas->LineTo(aux.x, aux.y);
   }
}

void multiplica(MATRIZ a,MATRIZ b,MATRIZ &c)
{
   int i,j,k;
   for (i=0;i<4;i++)  {
      for (j=0;j<4;j++)  {
          c.v[i][j]=0;
          for (k=0;k<4;k++)
             c.v[i][j]+=a.v[i][k]*b.v[k][j];
     }
   }
}
void trasladar(float tx,float ty,float tz)
{
    MATRIZ aux,temp;
    aux=identidad;
    aux.v[0][3]=tx;
    aux.v[1][3]=ty;
    aux.v[2][3]=tz;
    temp=mtrans;
    multiplica(aux,temp,mtrans);
}

void escalar(float sx,float sy,float sz)
{
    MATRIZ aux,temp;
    aux=identidad;
    aux.v[0][0]=sx;
    aux.v[1][1]=sy;
    aux.v[2][2]=sz;
    temp=mtrans;
    multiplica(aux,temp,mtrans);
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   trasladar(-10,0,0);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   trasladar(10,0,0);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   trasladar(0,-10,0);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   trasladar(0,10,0);
   Repaint();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{
   dibujar();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
   trasladar(0,0,-10);
   Repaint();
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
   trasladar(0,0,-10);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
   escalar(0.8,0.8,0.8);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
   escalar(1.2,1.2,1.2);
   Repaint();
}
//---------------------------------------------------------------------------
void rotarx(float ang)
{
    MATRIZ aux=identidad,temp;
    ang=ang*3.141516/180;
    float vcos=cos(ang), vsin=sin(ang);
    aux.v[1][1]=vcos;
    aux.v[1][2]=-vsin;
    aux.v[2][1]=vsin;
    aux.v[2][2]=vcos;
    temp=mtrans;
    multiplica(aux,temp, mtrans);
}
void __fastcall TForm1::Button9Click(TObject *Sender)
{
   rotarx(-30);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
  rotarx(30);
  Repaint();
}
//---------------------------------------------------------------------------
void rotary(float ang)
{
    MATRIZ aux=identidad,temp;
    ang=ang*3.141516/180;
    float vcos=cos(ang), vsin=sin(ang);
    aux.v[0][0]=vcos;
    aux.v[0][2]=vsin;
    aux.v[2][0]=-vsin;
    aux.v[2][2]=vcos;
    temp=mtrans;
    multiplica(aux,temp, mtrans);
}

void __fastcall TForm1::Button11Click(TObject *Sender)
{
   rotary(-30);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
   rotary(30);
   Repaint();
}
//---------------------------------------------------------------------------
void rotarz(float ang)
{
    MATRIZ aux=identidad,temp;
    ang=ang*3.141516/180;
    float vcos=cos(ang), vsin=sin(ang);
    aux.v[0][0]=vcos;
    aux.v[0][1]=-vsin;
    aux.v[1][0]=vsin;
    aux.v[1][1]=vcos;
    temp=mtrans;
    multiplica(aux,temp, mtrans);
}

void __fastcall TForm1::Button13Click(TObject *Sender)
{
   rotarz(-30);
   Repaint();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
   rotarz(30);
   Repaint();
}
//---------------------------------------------------------------------------

