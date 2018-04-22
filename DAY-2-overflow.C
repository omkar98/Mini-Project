#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>
#include<dos.h>
#include<alloc.h>

#define size 10

void display();
void push(char);
char pop();

int midx,midy;
int j=0;
char sym,p,dup[20],postfix[20],array[20];
int top=-1;
char infix[20];
int temp=0;


char pop()
{
  if(top==-1)
 {
    setcolor(RED);
    settextstyle(8,0,2);
    outtextxy(midx,midy-150,"STACK UNDERFLOW");
    return 0;
 }
 //clrscr();
 display();
 settextstyle(0,0,0);
 return (array[top--]);
}

void push(char sym)
  {
    if(top==size-1)
    {
      setcolor(RED);
      settextstyle(8,0,2);
      outtextxy(midx,midy-150,"STACK OVERFLOW");
      return;
    }
   array[++top]=sym;
    // clrscr();
    display();
   }


 void display()
 {
  setfillstyle(USER_FILL,WHITE);
  floodfill(2,2,WHITE);
  rectangle(0,0,getmaxx(),getmaxy());
  settextstyle(0,0,1);
  setcolor(6);
  outtextxy(midx+30,midy-100,"Index");
  outtextxy(midx+105,midy+100,"Bottom");
  outtextxy(midx+55,midy+90,"0");
  outtextxy(midx+55,midy+70,"1");
  outtextxy(midx+55,midy+50,"2");
  outtextxy(midx+55,midy+30,"3");
  outtextxy(midx+55,midy+10,"4");
  outtextxy(midx+55,midy-10,"5");
  outtextxy(midx+55,midy-30,"6");
  outtextxy(midx+55,midy-50,"7");
  outtextxy(midx+55,midy-70,"8");
  outtextxy(midx+55,midy-90,"9");
  line(midx+100,midy+100,midx+100,midy-100);
  line(midx+70,midy+100,midx+70,midy-100);
  line(midx+100,midy+100,midx+70,midy+100);

  line(midx+100,midy+80,midx+70,midy+80);
  line(midx+100,midy+60,midx+70,midy+60);
  line(midx+100,midy+40,midx+70,midy+40);
  line(midx+100,midy+20,midx+70,midy+20);
  line(midx+100,midy,midx+70,midy);
  line(midx+100,midy-20,midx+70,midy-20);
  line(midx+100,midy-40,midx+70,midy-40);
  line(midx+100,midy-60,midx+70,midy-60);
  line(midx+100,midy-80,midx+70,midy-80);
}


int main()
{
 int ch,i,k;
 char a,b,c,d;
 int gdriver = DETECT, gmode, errorcode;

 initgraph(&gdriver, &gmode, "c:\\turboc3\\BGI");

 midx = getmaxx() / 2;
 midy = getmaxy() / 2;
 setcolor(BLACK);
 display();
 push(a);
 push(b);
 push(c);
 push(d);
 push(a);
 push(a);
 push(b);
 push(c);
 push(d);
 push(a);
 push(b);
 push(c);
 push(d);

 //k=pop();
 getch();
 clrscr();
 return 0;
}



