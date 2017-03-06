#include <stdio.h>
#include <conio.h>
#include <dos.h>
#define xmax 80
#define ymax 24

void marco()
{
	int x,y;

	clrscr();
	textbackground(8);
	textcolor(6);
	for(x=1;x<=xmax;x++)
	{
		gotoxy(x,3);
		cprintf("%c",205);
		gotoxy(x,ymax);
		cprintf("%c",205);
	}
	for(y=3;y<=ymax;y++)
	{
		gotoxy(1,y);
		cprintf("%c",186);
		gotoxy(xmax,y);
		cprintf("%c",186);
	}
	gotoxy(1,3); cprintf("%c",201);
	gotoxy(1,ymax); cprintf("%c",200);
	gotoxy(xmax,3); cprintf("%c",187);
	gotoxy(xmax,ymax); cprintf("%c",188);

	textbackground(7);
	for(y=4;y<=ymax-1;y++)
	{
		for(x=2;x<=xmax-1;x++)
		{
			gotoxy(x,y);
			cprintf(" ");
		}
	}
	return;
}
void barra()
{
	int x,y;
	textbackground(8);
	gotoxy(1,2);

	for(x=1;x<=16;x++)
	{
		textcolor(x);
		cprintf("%c ",219);
	}
	textbackground(16);
	textcolor(15);
	gotoxy(40,2); cprintf("%c %c %c %c %c %c %c %c %c %c",219,176,177,178,42,3,16,17,30,31);
	gotoxy(1,25); cprintf("Color:C-V  Brocha:B-N  Borrar:X  Limpiar:L  Centrar:Z  P gina:K");
	gotoxy(72,2); cprintf("Salir:ESC");
	textcolor(16);
	textbackground(7);
	gotoxy(64,2); cprintf("1"); gotoxy(66,2); cprintf("2");
	return ;
}
void limpiar(int j,int mat1[][xmax-1],int mat2[][xmax-1],int mat3[][xmax-1], int mat4[][xmax-1])
{
	int b,c;
	for(b=0;b<ymax-1;b++)
	{
		for(c=0;c<xmax-1;c++)
		{
			if(j==1||j==0)
			{
				mat1[b][c]=0;
				mat2[b][c]=0;
			}
			if(j==2||j==0)
			{
				mat3[b][c]=0;
				mat4[b][c]=0;
			}
		}
	}
	return;
}
int main()
{
	int x,y,color,o,p,ind,ind2,ind3,c,b,j;
	int mat1[ymax-1][xmax-1],mat2[ymax-1][xmax-1],mat3[ymax-1][xmax-1],mat4[ymax-1][xmax-1];
	char a;

	clrscr();
	textcolor(15);
	textbackground(8);
	gotoxy(13,ymax/2); printf("v3.1\n\n\n            Presione ALT + ENTER para ingresar a pantalla completa");
	for(x=1;x<=3;x++)
	{	printf(".");
		delay(800);
	}

	j=0;
	x=xmax/2;
	y=ymax/2;
	color=15;
	o=1;
	p=219;
	ind=29;
	ind2=40;
	ind3=64;
	textbackground(8);
	marco();
	barra();
	limpiar(j,mat1,mat2,mat3,mat4);
	j=1;
	while(a!=27)
	{
		textbackground(8);
		textcolor(15);
		gotoxy(ind,1); cprintf("%c",31);
		gotoxy(ind2,1); cprintf("%c",31);
		gotoxy(ind3,1); cprintf("%c",31);
		textcolor(color);
		gotoxy(x,y);

		if(o==1) p=219;
		if(o==2) p=176;
		if(o==3) p=177;
		if(o==4) p=178;
		if(o==5) p=42;
		if(o==6) p=3;
		if(o==7) p=16;
		if(o==8) p=17;
		if(o==9) p=30;
		if(o==10) p=31;

		a=getch();
		switch (a)
		{
			case 'w':
			y--;
			if(y<=3) y=4;
			gotoxy(x,y);
			break;

			case 's':
			y++;
			if(y>=ymax) y=23;
			gotoxy(x,y);
			break;

			case 'a':
			x--;
			if(x<=1) x=2;
			gotoxy(x,y);
			break;

			case 'd':
			x++;
			if(x>=xmax) x=79;
			gotoxy(x,y);
			break;

			case ' ':
			textbackground(7);
			cprintf("%c",p);
			gotoxy(x,y);
			if(j==1)
			{
				mat1[y-1][x-1]=color;
				mat2[y-1][x-1]=p;
			}
			if(j==2)
			{
				mat3[y-1][x-1]=color;
				mat4[y-1][x-1]=p;
			}
			break;

			case 'x':
			printf(" ");
			mat1[y-1][x-1]=0;
			break;

			case 'c':
			color++;
			gotoxy(ind,1); printf(" ");
			ind=ind+2;
			if (color>16) color=1;
			if (ind>31) ind=1;
			break;

			case 'v':
			color--;
			gotoxy(ind,1); printf(" ");
			ind=ind-2;
			if (color<1) color=16;
			if (ind<1) ind=31;
			break;

			case 'b':
			o++;
			gotoxy(ind2,1); printf(" ");
			ind2=ind2+2;
			if(ind2>58) ind2=40;
			if(o==11) o=1;
			break;

			case 'n':
			o--;
			gotoxy(ind2,1); printf(" ");
			ind2=ind2-2;
			if(ind2<40) ind2=58;
			if(o==0) o=10;
			break;

			case 'l':
			marco();
			barra();
			limpiar(j,mat1,mat2,mat3,mat4);
			break;

			case 'z':
			x=xmax/2;
			y=ymax/2;
			break;

			case 'k':
			marco();
			barra();
			j++; if(j==3) j=1;
			if(j==1)
			{
				ind3=64; gotoxy(ind3,1); printf(" ");
				for(c=0;c<ymax-1;c++)
				{
					for(b=0;b<xmax-1;b++)
					{
						if(mat1[c][b]!=0)
						{
							gotoxy(b+1,c+1);
							textbackground(7);
							textcolor(mat1[c][b]);
							cprintf("%c",mat2[c][b]);
						}
					}
				}
			}
			if(j==2)
			{
				ind3=66; gotoxy(ind3,1); printf(" ");
				for(c=0;c<ymax-1;c++)
				{
					for(b=0;b<xmax-1;b++)
					{
						if(mat3[c][b]!=0)
						{
							gotoxy(b+1,c+1);
							textbackground(7);
							textcolor(mat3[c][b]);
							cprintf("%c",mat4[c][b]);
						}
					}
				}
			}
			break;
		}
	}
	return 1;
}