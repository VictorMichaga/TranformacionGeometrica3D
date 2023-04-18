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
int maxvtx=10;
VTX lista[3000]={{0,0,0,0} ,
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
   rotarx(30);
   Repaint();
}
//---------------------------------------------------------------------------

