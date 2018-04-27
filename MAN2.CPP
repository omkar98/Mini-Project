#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#define CLIP_ON 1
main()
{
    int gd=DETECT, gm, i,j,x,y;
    clrscr();
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    clearviewport();
    setviewport(0, 130, getmaxx()-0, getmaxy()-10, CLIP_ON);
    for(i=0; i<=500; i+=5)
    {
        line(0,300,800,300); //road
        if(i%2==0)
        {
            line(100+i,260,80+i,300); //left leg
            line(100+i,260,120+i,300); //right leg
            line(100+i,240,120+i,250); //right hand
            delay(20);
        }
        else
        {
            line(100+i,260,100+i,300);
            line(100+i,230,110+i,250);
            delay(20);
        }
        circle(100+i,200,10);    //face
        line(100+i,210,100+i,260); //body
        line(100+i,240,120+i,250); //hand
        line(120+i,250,120+i,162); //umbrella vertical line
        line(75+i,160,165+i,160);  //umbrella horizontal line
        arc(120+i,160,0,180,45); //umbrella
//cloud 1
        fillellipse(140,30,40,15); //left
        fillellipse(180,30,40,15); //right
        fillellipse(160,20,50,25); //top
        fillellipse(140,40,30,15); //bottom
//cloud 2
        fillellipse(300,40,30,15); //left
        fillellipse(320,30,40,15); //right
        fillellipse(320,20,50,25); //top
//cloud 3
        fillellipse(500,40,30,15); //left
        fillellipse(550,30,40,15); //right
        fillellipse(520,20,50,25);  //top
//rain drops
        x=getmaxx();
        y=getmaxy();
        for(j=0; j<100; j++)
        {
            outtextxy(random(x),random(y-50),"/");
            setcolor(WHITE);
        }
        delay(100);
        cleardevice();
    }
    getch();
    closegraph();
}

