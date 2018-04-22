#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<alloc.h>
#include<process.h>
#include<conio.h>
#define size 10

int j=0;
static char symb[1],sym,p,dup[20],postfix[20],array[20];
int top=-1,midx,midy;
char infix[20];
int temp=0;

void display();
char pop()
{
    if(top==-1)
    {
	setcolor(RED);
	settextstyle(7,0,2);
	outtextxy(midx-50,midy-150,"STACK UNDER FLOW");
	return;
    }
    getch();
    clrscr();
    printf("\n%s",postfix);
    delay(1000);
    display();
    settextstyle(0,0,0);
    return (array[top--]);
}


void push(char sym)
{
    if(top==size-1)
    {
	setcolor(BLUE);
	settextstyle(5,0,2);
	outtextxy(midx-50,midy-150,"STACK OVERFLOW");
	return;
    }
    array[++top]=sym;
    display();
}

void display()
{
    int n,i=80,count=48,increment=0;
    char index[1]={48};
    setfillstyle(SOLID_FILL,BLACK);
    floodfill(2,2,BLACK);
    rectangle((getmaxx()/2),0,getmaxx(),getmaxy());
    setcolor(GREEN);
    settextstyle(7,0,2);
    settextstyle(0,0,1);
    setcolor(6);
    outtextxy(midx+30,midy-100,"Index");
    outtextxy(midx+105,midy+100,"Bottom");
    /*while(i>-100)
    {
      outtextxy(midx+55,midy+i,index);
      index[0]=++count;
      i=i-20;
    } */
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
    while(i>-90)
    {
      line(midx+100,midy+i,midx+70,midy+i);
      index[0]=++count;
      i=i-20;
    }
    /*line(midx+100,midy+100,midx+70,midy+100);
    line(midx+100,midy+80,midx+70,midy+80);
    line(midx+100,midy+60,midx+70,midy+60);
    line(midx+100,midy+40,midx+70,midy+40);
    line(midx+100,midy+20,midx+70,midy+20);
    line(midx+100,midy,midx+70,midy);
    line(midx+100,midy-20,midx+70,midy-20);
    line(midx+100,midy-40,midx+70,midy-40);
    line(midx+100,midy-60,midx+70,midy-60);
    line(midx+100,midy-80,midx+70,midy-80);*/
    for (i=0; i<=top; i++)
    {
	setcolor(13);
	settextstyle(7,0,2);
	settextstyle(0,0,0);
	symb[0]=array[i];
	getch();
	outtextxy(midx+75,midy+90-increment,symb);
	increment+=20;
    }

}


int prec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
	return 2;
    case '*':
    case '/':
	return 3;
    case '(':
	return 4;
    }
}

int isEmpty()
{
    return top==-1?1:0;
}

int isoperator(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
	return 1;
    default :
	return 0;
    }
}

int main()
{
    int ch,i;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\BGI");
    errorcode = graphresult();
    if (errorcode != grOk)
    {
	printf("Graphics error: %s\n", grapherrormsg(errorcode));
	printf("Press any key to halt:");
	getch();
	exit(1);
    }

    midx = getmaxx() / 2;
    midy = getmaxy() / 2;
    setcolor(RED);
    settextstyle(7,0,2);
    outtextxy(midx-300,midy-100,"INFIX TO POSTFIX CONVERSION USING C GRAPHICS");
    setcolor(9);
    settextstyle(5,0,2);
    outtextxy(midx+150,midy+150,"Developed By,");
    outtextxy(midx+160,midy+170,"Omkar Deshpande ");
    outtextxy(midx+160,midy+190,"Anuj Chourange");
    getch();
    clrscr();
    setbkcolor(BLACK);

    setfillstyle(SOLID_FILL,BLACK);
    floodfill(2,2,BLACK);
    rectangle(0,0,getmaxx(),getmaxy());
    printf("Enter an expression:");
    gets(infix);
    clrscr();
    for(i=0; infix[i]!='\0'; i++)
    {
	sym=infix[i];
	if(sym=='(')
	{
	    push(sym);
//  continue;
	}

	else if(sym==')')
	{
	    while(1)
	    {
		sym=pop();

		if(sym=='(')
		    break;
		postfix[j++]=sym;
	    }
//continue;
	}

	else if(!isoperator(sym))
	{
	    postfix[j++]=sym;
	    printf("\n%s",postfix);
	    delay(1000);
	}

	else
	{
	    while(prec(array[top])>=prec(sym) && !isEmpty())
	    {

		postfix[j++]=pop();

		delay(1000);
	    }
	    push(sym);

	}

    }

    while(!isEmpty())
    {

	postfix[j++]=pop();
	delay(1000);

	clrscr();
	display();
	printf("\n%s\n",postfix);
	delay(1000);
    }
    postfix[j]='\0';
    printf("\nThe infix expression is: %s",infix);
    printf("\nThe postfix expression is: %s",postfix);
    getch();
}