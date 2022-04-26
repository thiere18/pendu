#include <stdio.h>
#include <ctype.h>
#include<time.h>
#include<string.h>
#include <stdlib.h>

int page1();
int page2();
int page3();
int page4();
int page5();
int level_num,score=0,fail=0;
char id[50];

struct all_word
{
    int num[100],all,play[100];
    //             �ӫѾ������ eng    , �纤ӷ���ҹ��ë�͹����
    char words[100][100],hide[100][100];

}word;


main(void)
{
    int page=1;
    do
    {
        switch(page)
        {
            case 1 : page=page1(); break;
            case 2 : page=page2(); break;
            case 3 : page=page3(); break;
            case 4 : page=page4(); break;
            case 5 : page=page5(); break;
        }
    }while(page!=6);

}

// logo
void logo(int a)
{
    if(a==1)
        printf("\n     oo    oo    ooo    ooo    oo    oooo   ooo     ooo    ooo    ooo    oo  \n     oo    oo  oo   oo  oooo   oo  oo    oo oooo   oooo  oo   oo  oooo   oo  \n     oo    oo oo     oo oo oo  oo oo        oo oo oo oo oo     oo oo oo  oo  \n     oooooooo ooooooooo oo  oo oo oo    ooo oo  ooo  oo ooooooooo oo  oo oo  \n     oo    oo oo     oo oo   oooo  oo    oo oo       oo oo     oo oo   oooo  \n     oo    oo oo     oo oo    ooo    oooo   oo       oo oo     oo oo    ooo  \n     ----------------------------------------------------------------------");
    else if(a==2)
        printf("\n\t\t\t\t* * * * * * * * * *\n\t\t\t\t*     HANGMAN     *\n\t\t\t\t* * * * * * * * * *\n\n\n");
    else if(a==3)
        printf("\t\t\t ***** Administrator Console *****\n\n");
}


// hangman
void hangman(int a)
{
    if(a==0)
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
    else if(a==1)
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t       0   |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
    else if(a==2)
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t       0   |   \n\t\t\t\t       |   |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
    else if(a==3)
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t       0   |   \n\t\t\t\t      /|   |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
    else if(a==4)
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t       0   |   \n\t\t\t\t      /|\\  |   \n\t\t\t\t           |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
    else if(a==5)
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t       0   |   \n\t\t\t\t      /|\\  |   \n\t\t\t\t      /    |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
    else
        printf("\t\t\t\t       +---+   \n\t\t\t\t       |   |   \n\t\t\t\t       0   |   \n\t\t\t\t      /|\\  |   \n\t\t\t\t      / \\  |   \n\t\t\t\t           |   \n\t\t\t\t     ========= \n");
}


// �֧���Ѿ��ҡ������㹵���� �Ҩӹǹ���ѷ� �Ҩӹǹ�ѡ�����е��㹤��Ѿ��
void chack_word()
{
    FILE *fptr;
    fptr = fopen("word.txt","r");
    int i=0,j;
    if(fptr==NULL)
        exit(1);
    while(fscanf(fptr,"%s",word.words[i])!=EOF) //�纤�ŧ㹵����
    {
        j=0;
        while(word.words[i][j]!='\0') //�礨ӹǹ����ѡ�õ�ͤ�
        {
            j++;
        }
        word.num[i]=j;
        i++;
    }
    word.all = i;
    fclose(fptr);
}
void add_hide_word()
{
    FILE *fptr;
    fptr = fopen("word.txt","r");
    int i=0,j;
    if(fptr==NULL)
        exit(1);
    while(fscanf(fptr,"%s",word.hide[i])!=EOF) //�纤�ŧ㹵����
    {
        i++;
    }
    fclose(fptr);
}



void randoms(int a,int b,int c,int d)
{
	int result[a],i,value,counter;
	char chFound;

	srand(time(0));
	for(i=0; i<a; i++) result[i]=0;
	counter = 0;
	do
    {
		value = rand()%b;
		result[counter] = value;
		chFound = 'N';
		for(i=0;i<counter;i++)
		{
			if(result[i] == value)
				chFound = 'Y';
		}
		if(chFound != 'Y')
			counter++;
	}while(counter<a);

    if(c==1)
    {
        for(i=0;i<a;i++)
            word.play[i] = result[i];
    }
    else if(c==2)
    {
        for(i=0;i<a;i++)
            word.hide[d][result[i]]='_';
    }
}


int level(int a,int b)
{
    int sum;
    if(a==1)
    {
        sum = 0.35*word.num[b];
    }
    else if(a==2)
    {
        sum = 0.60*word.num[b];
    }
    else if(a==3)
    {
        sum = 0.80*word.num[b];
    }
    return sum;
}


int admin()
{
    system("clear");
    char num;
    do
    {
        logo(2);
        logo(3);
        printf("\t\t\t\t  [1] Add word\n\t\t\t\t  [2] Clear word\n\t\t\t\t  [3] Clear score\n\t\t\t\t  [4] Back to Home\n\n");
        printf("\t\t\t    Please enter your number : ");
        scanf("%c",&num);
        system("clear");
    } while(!(num=='1'||num=='2'||num=='3'||num=='4'));
    FILE *fptr;
    char add[20];
    if(num=='1') //�������Ѿ��ŧ����
    {
        fptr = fopen("word.txt","a");
        do
        {
            system("clear");
            logo(2);
            logo(3);
            printf("\t\t\t\t  [1] Add word\n\n");
            printf("\t\t\t   Please enter the word : ");
            scanf("%s",add);
            fprintf(fptr,"%s\n",add);
            printf("\n\n\t\t\t\t  Add complete!");
            printf("\n\n\n\n\t\t\t  Do you want to continue (Y/N)");
        }while(tolower(getchar())=='y');
        fclose(fptr);
    }
    else if(num=='2') //��ҧ���Ѿ�������
    {
        system("clear");
        logo(2);
        logo(3);
        printf("\t\t\t\t  [2] Clear word\n\n");
        printf("\n\n\t\t        Do you want to delete all word (Y/N)");
        if(tolower(getchar())=='y')
        {
            fptr = fopen("word.txt","w");
            printf("\n\n\t\t\t\t  Delete complete!");
            getchar();
            fclose(fptr);
        }
    }
    else if(num=='3') //��ҧ��ṹ�ͧ�����蹷�����
    {
        system("clear");
        logo(2);
        logo(3);
        printf("\t\t\t\t  [3] Clear score\n\n");
        printf("\n\n\t\t        Do you want to delete all score (Y/N)");
        if(tolower(getchar())=='y')
        {
            fptr = fopen("score.txt","w");
            printf("\n\n\t\t\t\t  Delete complete!");
            getchar();
            fclose(fptr);
        }
    }
    else if(num=='4')
        return 0;
}


void answer(char a,int b) // a=�ӵͺ / b=�ӴѺ������
{
    int i,count=0;
    for(i=0;i<word.num[b];i++)
    {
        if(a==word.words[b][i])
        {
            if(a!=word.hide[b][i])
                score++;
            word.hide[b][i] = word.words[b][i];
        }
        else
        {
            count++;
        }
    }
    if(count==word.num[b])
        fail++;
}

int chack_answer(int a) //a=�ӴѺ������
{
    int i,count=0;
    for(i=0;i<word.num[a];i++)
    {
        if(word.hide[a][i]==word.words[a][i])
            count++;
    }
    if(count==word.num[a])
        return 1;
    else
        return 0;
}

void top_score()
{
    FILE *fptr;
    fptr = fopen("score.txt","a");
    fprintf(fptr,"%s\t%d\n",id,score);
    fclose(fptr);

    fptr = fopen("score.txt","r");
    int i=0,top1[100];
    char id1[100][100];
    while(fscanf(fptr,"%s%d",id1[i],&top1[i])!=EOF)
        i++;

    int n,j,tmp;
    char tmp2[100];
    char name[100][30];
    n=i;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(top1[j]<top1[j+1])
            {
                tmp = top1[j];
                top1[j] = top1[j+1];
                top1[j+1] = tmp;

                strcpy(tmp2,id1[j]);
                strcpy(id1[j],id1[j+1]);
                strcpy(id1[j+1],tmp2);
            }
        }
    }

    printf("\t\t\t\t [Top 5 Score]\n\n");
    for(i=0;i<5;i++)
        printf("\t\t\t\t  %s\t= %d\n",id1[i],top1[i]);

}

int page1()
{
    system("clear");
    printf("\n\n\n\n     Welcome to\n");
    logo(1);
    printf("\n\n\n\n\t\t\t\tPress any key ");
    getchar();
    return 2;
}

int page2()
{
    system("clear");
    logo(2);
    printf("\n\t\t\t\t  Your name : ");
    scanf("%s",id);
    printf("\n\n\t\t\t >> WELCOME TO THE HANGMAN GAME <<\n\n\n\n\n\n");
    printf("\t\t\t\t   Pres any key");
    getchar();
    if (id[0]=='a'&&id[1]=='d'&&id[2]=='m'&&id[3]=='i'&&id[4]=='n'&&id[5]=='\0') //chack word for admin
        {
            admin();
            return 1;
        }
    else
        return 3;
}

int page3()
{
    system("clear");
    char num;
    do
    {
        system("clear");
        logo(2);
        printf("\t\t\t\t  -Select level-\n\n");
        printf("\t\t\t\t   [1] level 1\n\t\t\t\t   [2] level 2\n\t\t\t\t   [3] level 3\n\n");
        printf("\t\t\t    Please enter your level : ");
        scanf("%c",&num);
    } while(!(num=='1'||num=='2'||num=='3'));
    if(num=='1')
        level_num = 1;
    else if(num=='2')
        level_num = 2;
    else
        level_num = 3;
    chack_word();
    add_hide_word();
    return 4;

}

int page4()
{
    system("clear");
    int i;
    char sum;
    randoms(word.all,word.all,1,1); //�����ӴѺ������
    for(i=0;i<word.all;i++)
        randoms(level(level_num,i),word.num[i],2,i); //�����ѡ�÷���͹�ͧ���Ф�

    for(i=0;i<word.all;i++)
    {
        do
        {
            system("clear");
            logo(2);
            printf("\t\t\t\t\t\t\t   Score : %d\n",score);
            hangman(fail);
            printf("\n\n\t\t\t\t       %s\n\n\n",word.hide[word.play[i]]);
            printf("\t\t\t      Please enter the answer ?");
            if(fail==6)
                return 5;
            sum = getchar();
            answer(sum,word.play[i]);
        }while(chack_answer(word.play[i])!=1);

        system("clear");
        logo(2);
        printf("\t\t\t\t\t\t\t   Score : %d\n",score);
        hangman(fail);
        printf("\n\n\t\t\t\t       %s\n\n\n",word.hide[word.play[i]]);
        printf("\t\t\t\t     Complete!\n\n");
        printf("\007");
        printf("\t\t\t       Press any key for next");
        getchar();
    }
    return 5;

}

int page5()
{
    system("clear");
    logo(1);
    printf("\n\n\n\t\t\t\t...GAME OVER...");
    printf("\n\n\n\t\t\t       [ %s ] score = %d\n\n\n",id,score);
    top_score();
    getchar();
    return 6;
}
