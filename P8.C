//suraj kawadkar
//mandar majalgaonkar
//pharmacy management
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct med
{
    char med_name[44];
    char id[33];
    char mfg_date[44];
    char exp_date[44];
    float price;
};
struct med m;

int stock=1000;
void insert_med_detail();
void show();
void search();
void delet();
//void modify();


void main()
{
    int ch;
    clrscr();
    do
    {
	printf("******************************************\n");

	printf("1.INSERT \n");
	printf("2.SHOW ALL\n");
	printf("3.SEARCH \n");
	printf("4.DELETE \n");
	printf("5.MODIFY \n");
	printf("6.EXIT \n");
	printf("******************************************\n");
	printf("\n ENTER THE CHOICE\n");

	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	    insert_med_detail();
	    break;
	case 2:
	    show();
	    break;
	case 3:
	    search();
     break;
	case 4:
	    delet();
	    break;
	/*case 5:
	      modify();
	      break;
    */default:
	    printf("THANK YOU\n");
	}
    }
    while(ch!=6);
    getch();
}
void insert_med_detail()
{
    FILE *fp;
    struct med m;
    printf("\n ENTER MED id :- ");
    scanf("%s",&m.id);
    printf("\n ENTER THE NAME OF medicine :- ");
    scanf("%s",&m.med_name);
    printf("\n ENTER mfg DATE :- ");
    scanf("%s",&m.mfg_date);
    printf("ENTER THE exp DATE :- ");
    scanf("%s",&m.exp_date);
    printf("\n ENTER THE PRICE of medicine:- ");
    scanf("%f",&m.price);

    fp=fopen("medicos.txt","a");
    if(fp==NULL)
    {
	printf("\n EMPTY FILE");
    }

    else
    {
	//  fwrite(&m,sizeof(m),1,fp);
	fprintf(fp,"Medicine id=%s   Med Name=%s  mfg date=%s exp date=%s price=%f \n",m.id,m.med_name,m.mfg_date,m.exp_date,m.price);
	printf("\n RECORD INSERTED SUCCESSFULLY");
    }
    printf("\n-----------------------------------------------");
    printf("\n");
    fclose(fp);
}
void show()
{
//char line[301];
    char c;
    FILE *fp;
    fp=fopen("medicos.txt","r");
    if(fp==NULL)
    {
	printf("error in file\n");
    }
    while(!feof(fp))
    {
	//fgets(line,300,fp);
	c=fgetc(fp);
	printf("%c",c);
    }
    fclose(fp);
}
void search()
{
    FILE *fp;
    char line1[301], line2[300];
    printf("ENTER med id: ");
    scanf("%s",&line1);
    fp=fopen("medicos.txt","r");
    if(fp==NULL)
    {
	printf("error in file\n");
    }
    while(fgets(line2,300,fp)!=NULL)
    {

	if((strstr(line2,line1))!=NULL);
	  {
		printf("Available:\n");
		printf("%s", line2);     //search
	  }
    }
    if(strstr(line2,line1)!=0)
    {
	printf("Not Available:\n");     //search
	return;
    }
}

void delet()
{

    FILE *fp1, *fp2;


    char c;
    int del_line, temp = 1;
    fp1 = fopen("medicos.txt", "r");
    c = getc(fp1);

    while (c != EOF)
    {
        printf("%c", c);
        //print current character and read next character
        c = getc(fp1);
    }
    //rewind
    rewind(fp1);
    printf(" \n Enter line number of the line to be deleted:");

    scanf("%d", &del_line);
    //open new file in write mode
    fp2 = fopen("copy.c", "w");
    c = getc(fp1);
    while (c != EOF) {
        c = getc(fp1);
        if (c == '\n')
            temp++;
        //except the line to be deleted
        if (temp != del_line)
        {
            putc(c, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("medicos.txt");

    rename("copy.c","medicos.txt");
    printf("\n The contents of file after being modified are as  follows:\n");
    fp1 = fopen("medicos.txt", "r");
    c = getc(fp1);
    while (c != EOF) {
        printf("%c", c);
        c = getc(fp1);
    }
    fclose(fp1);

}
/*
void modify()
{



}
*/