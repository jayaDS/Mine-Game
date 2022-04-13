// Mine Game is the game where player has to guess non mine locations till he reaches required score to win
// else if a player press mine location the game terminate and player looses the game
#include<graphics.h>

#include<stdio.h>

int i;
int j;
int n;
int m;

int cnt = 0;
int x = 400;
int y = 400;
int sc = 0;

int bomb[4][4] = {0};
int score[4][4] = {0};
int disp[4][4] = {0};

char *ch;

// Hidden locations where bomb is placed
void placebomb()
{
    bomb[0][1] = 1;
    bomb[1][3] = 1;
    bomb[2][2] = 1;
    bomb[3][0] = 1;
}

// Place score value
void placescore()
{
    score[0][0] = 1;
    score[0][2] = 2;
    score[0][3] = 1;

    score[1][0] = 1;
    score[1][1] = 2;
    score[1][2] = 3;

    score[2][0] = 1;
    score[2][1] = 4;
    score[2][3] = 3;

    score[3][1] = 2;
    score[3][2] = 1;
    score[3][3] = 1;
}

// Used to display mine game matrix
void dispmat()
{
    x = 150;
    y = 100;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            sprintf(ch,"%d",disp[i][j]);
            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            rectangle(x,y,x+30,y+30);
            floodfill(x+1,y+1,WHITE);
            outtextxy(x+15,y+15,ch);
            x += 30;
        }
        x = 150;
        y += 30;
    }
}

// this function gets executed once a person press mine
void dispbomb()
{
    x = 150;
    y = 300;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            sprintf(ch,"%d",bomb[i][j]);
            setfillstyle(SOLID_FILL,BLUE);
            rectangle(x,y,x+30,y+30);
            floodfill(x+1,y+1,WHITE);
            if(bomb[i][j] != 0)
            {
                setcolor(RED);
            }
            outtextxy(x+10,y+10,ch);
            setcolor(WHITE);
            x += 30;
        }
        x = 150;
        y += 30;
    }
}

// Used to re-initiate matrix grid
void reintiate()
{
    int gd = DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\tc\\bgi");
    setbkcolor(CYAN);
}

// User response
void user()
{
    int x1;
    int y1;
    printf("Please enter the value of x1, y1:");
    scanf("%d",&x1);
    scanf("%d",&y1);
    if(x1>=0 && y1>=0 && x1<=3 && y1<=3)
    {
        // If mine is pressed
        if(bomb[x1][y1] == 1)
        {
            printf("you pressed a mine");
            dispbomb();
            return;
        }
        // If pressed key is not mine
        disp[x1][y1] = score[x1][y1];
        sc += score[x1][y1];
        cleardevice();
        reintiate();
        dispmat();
        printf("\n**The current score is : %d**\n",sc);
        cnt++;
        // if count is greater than or equal to 12 then the person won the game
        if(cnt >= 12)
        {
            printf("you won the game");
            dispmat();
            return;
        }
        user();
    }
    // If above if condition is not satisfied the person pressed the mine and a bomb got exploded
    else
    {
        printf("you pressed a mine as you have entered out of region");
        dispbomb();
        return;
    }
}

// It is first function that is responsible for starting the execution and termination of program
void main()
{
    reintiate();
    placebomb();
    placescore();
    dispmat();
    user();
    getch();
}
