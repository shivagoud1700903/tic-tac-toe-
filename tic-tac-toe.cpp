#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char token = 'x';
bool tie = false;
string str1="";
string str2="";
void funcone()
{
    
    //string str1;
    //string str2;
    



    cout<<"   |     | "<<endl;
     cout<<" "<<space[0][0]<<" | "<<space[0][1]<<"   | "<<space[0][2]<< " "<<endl;
    cout<<"___|_____|___"<<endl;
    cout<<"   |     | "<<endl;
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<"   | "<<space[1][2]<< " "<<endl;
    cout<<"___|_____|___"<<endl;
    cout<<"   |     |   "<<endl;
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"   | "<<space[2][2]<< " "<<endl;
    cout<<"   |     |   "<<endl;
}


void functwo()
{
    int digit;
    if(token == 'x')
    {
        cout<<str1<<"  please enter"<<endl;
        cin>>digit;
    }
     if(token == '0')
    {
        cout<<str2<<"  please enter"<<endl;
        cin>>digit;
    }
    if(digit == 1)
    {
        row=0;
        col=0;
    }
    if(digit == 2)
    {
        row=0;
        col=1;
    }
    if(digit == 3)
    {
        row=0;
        col=2;
    }
    if(digit == 4)
    {
        row=1;
        col=0;
    }
    if(digit == 5)
    {
        row=1;
        col=1;
    }
    if(digit == 6)
    {
        row=1;
        col=2;
    }
    if(digit == 7)
    {
        row=2;
        col=0;
    }
    if(digit == 8)
    {
        row=2;
        col=1;
    }
    if(digit == 9)
    {
        row=2;
        col=2;
    }
    else //if (digit<1 || digit >9){
    {
        cout<<"INVALID !!!"<<endl;
    }

    if(token =='x' && (space[row][col]!= 'x' && space[row][col]!='0'))
    {
        space[row][col]='x';
        token='0';   
     }
    else if(token=='0'&& (space[row][col]!='x' && space[row][col]!='0'))
    {
        space[row][col]='0';
        token ='x';
    }
    else{
        cout<<"there is no empty space"<<endl;
        functwo();
    }
   // funcone();
}
bool functhree()
{
    for(int i=0;i<3;i++)
    {
   if(space[i][0]==space[i][1]&&space[i][0]==space[i][2]||
   space[0][i]==space[1][i]&&space[0][i]==space[2][i])
   return true;
    }
    if(space[0][0]==space[1][1] && space[0][0]== space[2][2] 
    || space[0][2]==space[1][1] && space[0][2] == space[2][0])
    return true;


    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(space[i][j]!= 'x' || space[i][j]!= '0')
            {
                return false;
            }
        }
        if(!tie)
        break;
    }

   if(tie)
    tie= true;
    return false;
    
}
int main()
{
    cout<<"enter the name of player1"<<endl;
    cin>>str1;
    cout<<"enter the name of player2"<<endl;
    cin>>str2;
    cout<<str1<<" is going to play first"<<endl;
    cout<<str2<<" is going to play second"<<endl;
    while(!functhree())
    {
        funcone();
        functwo();
        functhree();
    }
    if(token =='x' && tie == false)
    {
        cout<<str2<<"WINS"<<endl;
    }
    else if(token =='0' && tie ==false)
    {
        cout<<str1<<"WINS"<<endl;
    }
    else{
        cout<<"its a draw"<<endl;
    }
}
    