#include<iostream>
using namespace std;
#include<time.h>
#include<windows.h>
// windows.h to add delay in program
void mode_check(int *mode)
{
    if((*mode==1)||(*mode)==2||(*mode==3))
    {
        return ;
    }
    else
    {
        cout<<"Wrong entery, make correct choice.\n";
        cin>>*mode;
        mode_check(mode);
    }
}
void show_board(char a[3][3])
{
   int i,j;
   for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j<2)
            {
                if(a[i][j]!='x' && a[i][j]!='o')
                {
                    cout<<" "<<" "<<"| ";
                }
                else
                {
                  cout<<a[i][j]<<" "<<"| ";
                }
            }
            else
            {
                if(a[i][j]!='x' && a[i][j]!='o')
                {
                    cout<<" ";
                }
                else
                {
                    cout<<a[i][j];
                }
            }
        }
        cout<<endl;
        if(i<2)
        {
            cout<<"_"<<"   _ "<<"  _";
        }
        cout<<endl;
    }
}
void position_check(int *p, int mark[9])
{
    if((*p)<=0 || (*p)>9)
    {
        cout<<"Wrong position entered, choose between 1 to 9.\n";
        cin>>*p;
        position_check(p,mark);
    }
    else
    {
       if(mark[(*p)-1]==1)
       {
           cout<<"Position in preoccupied, Try again and Enter correct position.\n";
           cin>>(*p);
           position_check(p,mark);
       }
       else
       {
           return;
       }
    }
}
int win_or_not(char a[3][3], char firstplayer,char secondplayer)
{
    if(a[0][0]==firstplayer && a[0][1]==firstplayer && a[0][2]==firstplayer || a[0][0]==firstplayer && a[1][0]==firstplayer && a[2][0]==firstplayer || a[2][0]==firstplayer && a[2][1]==firstplayer && a[2][2]==firstplayer || a[2][2]==firstplayer && a[1][2]==firstplayer && a[0][2]==firstplayer ||a[1][0]==firstplayer && a[1][1]==firstplayer && a[1][2]==firstplayer || a[0][1]==firstplayer && a[1][1]==firstplayer && a[2][1]==firstplayer || a[0][0]==firstplayer && a[1][1]==firstplayer && a[2][2]==firstplayer || a[0][2]==firstplayer && a[1][1]==firstplayer && a[2][0]==firstplayer)
    {
        cout<<"PLAYER "<<firstplayer<<" WON\n";
        return 1;
    }
    if(a[0][0]==secondplayer && a[0][1]==secondplayer && a[0][2]==secondplayer || a[0][0]==secondplayer && a[1][0]==secondplayer && a[2][0]==secondplayer || a[2][0]==secondplayer && a[2][1]==secondplayer && a[2][2]==secondplayer || a[2][2]==secondplayer && a[1][2]==secondplayer && a[0][2]==secondplayer ||a[1][0]==secondplayer && a[1][1]==secondplayer && a[1][2]==secondplayer || a[0][1]==secondplayer && a[1][1]==secondplayer && a[2][1]==secondplayer || a[0][0]==secondplayer && a[1][1]==secondplayer && a[2][2]==secondplayer || a[0][2]==secondplayer && a[1][1]==secondplayer && a[2][0]==secondplayer)
    {
        cout<<"PLAYER "<<secondplayer<<" WON \n";
        return 1;
    }
    return 0;
    
}
int win_or_not2(char a[3][3], char firstplayer,char secondplayer)
{
    if(a[0][0]==firstplayer && a[0][1]==firstplayer && a[0][2]==firstplayer || a[0][0]==firstplayer && a[1][0]==firstplayer && a[2][0]==firstplayer || a[2][0]==firstplayer && a[2][1]==firstplayer && a[2][2]==firstplayer || a[2][2]==firstplayer && a[1][2]==firstplayer && a[0][2]==firstplayer ||a[1][0]==firstplayer && a[1][1]==firstplayer && a[1][2]==firstplayer || a[0][1]==firstplayer && a[1][1]==firstplayer && a[2][1]==firstplayer || a[0][0]==firstplayer && a[1][1]==firstplayer && a[2][2]==firstplayer || a[0][2]==firstplayer && a[1][1]==firstplayer && a[2][0]==firstplayer)
    {
        cout<<"Computer Won\n";
        return 1;
    }
    if(a[0][0]==secondplayer && a[0][1]==secondplayer && a[0][2]==secondplayer || a[0][0]==secondplayer && a[1][0]==secondplayer && a[2][0]==secondplayer || a[2][0]==secondplayer && a[2][1]==secondplayer && a[2][2]==secondplayer || a[2][2]==secondplayer && a[1][2]==secondplayer && a[0][2]==secondplayer ||a[1][0]==secondplayer && a[1][1]==secondplayer && a[1][2]==secondplayer || a[0][1]==secondplayer && a[1][1]==secondplayer && a[2][1]==secondplayer || a[0][0]==secondplayer && a[1][1]==secondplayer && a[2][2]==secondplayer || a[0][2]==secondplayer && a[1][1]==secondplayer && a[2][0]==secondplayer)
    {
        cout<<"You Won \n";
        return 1;
    }
    return 0;
    
}
void update_board(int pos, char player,char board[3][3])
{
    int i,j;
    pos=pos-1;
    i=pos/3;
    j=pos%3;
    board[i][j]=player;
}
int friends(char a[3][3],int mark[9])
{

    char p1,p2,firstmove,secondmove;
    int rndm,pos,fm,win=0;
    // rndm to make choice which player will play first
    // pos will be used to store the input position enterd by the players
    srand(time(NULL));
    rndm=rand()%2; 
    show_board(a);
    if(rndm==1)
    {
        cout<<"First player is X and second is O.\n";
        p1='x';
        p2='o';
    }
    else
    {
       cout<<"First player is O and second is X.\n";
        p1='o';
        p2='x';
    }
    fm=rand()%2;
    if(fm==0)
    {
        cout<<p1<<" will play first move.\n";
        firstmove=p1;
        secondmove=p2;
    }
    else
    {
        cout<<p2<<" will play first move.\n";
        firstmove=p2;
        secondmove=p1;
    }
    for(int i=0;i<9;i++)
    {
        if(i%2==0)
        {
           cout<<"Player "<<firstmove<<" choose position from 1 to 9 which is unoccupied.\n";
           cin>>pos;
           position_check(&pos,mark);
           system("cls");
           update_board(pos,firstmove,a);
           show_board(a);
           win=win_or_not(a,firstmove,secondmove);
           if(win==1)
           {
               return 1;
           }
        }
        else
        {
           cout<<"Player "<<secondmove<<" choose position from 1 to 9 which is unoccupied.\n";
           cin>>pos;
           position_check(&pos,mark);
           system("cls");
           update_board(pos,secondmove,a);
           show_board(a);
           win=win_or_not(a,firstmove,secondmove);
           if(win==1)
           {
               return 1;
           }
        }
    }
    return 0;
}
void position_check_comp(int *p,int mark[9],char computer,char board[3][3])
{ 
    if(mark[(*p)]==1)
    { 
        Sleep(100);
        srand(time(NULL));
        int h;
        h=rand();
        h=h%9;
        (*p)=h;
        Sleep(100);
        // execution was fast, making stack overflow thats why added delay function to slow down the program.
        position_check_comp(p,mark,computer,board);
    }
    else
    {
        return ;
    }
}
void computer_eassy_play(char board[3][3], int mark[9],char computer)
{  
    int r;
    srand(time(NULL));
    r=rand()%9;
    position_check_comp(&r,mark,computer,board);
    mark[r]=1;
    update_board(r+1,computer,board);
    system("cls");
    show_board(board);
    cout<<"Computer choosed position "<<r+1<<".\n";
}
void human_turn(char board[3][3], int mark[9],char human)
{
    int pos;
    cout<<"Enter pos which is unfilled:";
    cin>>pos;
    position_check(&pos,mark);
    mark[pos-1]=1;
    update_board(pos,human,board);
    system("cls");
    show_board(board);
}
int computer_eassy(char board[3][3], int mark[9])
{
        char human,comp,firstmove,secondmove;
        int r,pos,fm,w=0;
        //fm will tell which one will perform first moveand r will help to tell,pos to store pos enterd by user
        srand(time(NULL));
        r=rand()%2;
        show_board(board);
        if(r==1)
        {
            cout<<"computer is x and you are o.\n";
            human='o';
            comp='x';
        }
        else
        {
            cout<<"computer is o and you are x.\n";
            human='x';
            comp='o';
        }
        fm=rand()%2;
        if(fm==1)
        {
            cout<<"Computer will play first move.\n";
            firstmove=comp;
            secondmove=human;
        }
        else
        {
            cout<<"computer decided you to make first move.\n";
            firstmove=human;
            secondmove=comp;
        }
        if(firstmove==comp)
        {
             computer_eassy_play(board,mark,comp);
             for(int i=0;i<4;i++)
             {
                 w=win_or_not2(board,comp,human);
                 if(w==1)
                 {
                     return 1;
                 }
                 human_turn(board,mark,human);
                 w=win_or_not2(board,comp,human);
                 if(w==1)
                 {
                     return 1;
                 }
                 computer_eassy_play(board,mark,comp);
                  w=win_or_not2(board,comp,human);
                 if(w==1)
                 {
                     return 1;
                 }
             }
        }
        else
        {
            human_turn(board,mark,human);
            for(int i=0;i<4;i++)
            {
               w=win_or_not2(board,comp,human);
               if(w==1)
                 {
                     return 1;
                 }
               computer_eassy_play(board,mark,comp);
               w=win_or_not2(board,comp,human);
               if(w==1)
                 {
                     return 1;
                 }
               human_turn(board,mark,human);
                w=win_or_not2(board,comp,human);
                 if(w==1)
                 {
                     return 1;
                 }
            }
        }  
        return 0;     
}
void t_check(int *t)
{
    if((*t)!=1)
    {
        cout<<"Enter 1 to start game:\n";
        cin>>(*t);
        t_check(t);
    }
}
int main()
{
    char board[3][3];
    int mark[9]={0,0,0,0,0,0,0,0,0},w=0;
    int mode,choice;
    cout<<"Press 1 to play with friend.\nPress 2 to play against computer.\n";
    cin>>mode;
    mode_check(&mode);
    system("cls");
    show_board(board);
    cout<<"Instruction:- As the board has 9 blocks each block has a position 1 to 9 so Enetr unfilled location to make a move.\n";
    cout<<"Press 1 to start game:\n";
    int t;
    cin>>t;
    t_check(&t);
    system("cls");
    if(mode==1)
    {
        w=friends(board,mark); 
    }
    if(mode==2)
    {
        w=computer_eassy(board,mark);
    }
    if(w==0)
    {
        cout<<"DRAW.\n";
    }
    return 0;
}
