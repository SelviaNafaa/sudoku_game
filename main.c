#include <stdio.h>
#include <stdlib.h>
#define Rep_row 1
#define Rep_col 2
#define rep_square 3

static char count[9][9]= {0};

void print2dArr(char (*arr)[9],int row,int col)
{

    int i,j;
    for(i=0; i<row; i++)
    {

        for(j=0; j<col; j++)
        {

            printf("%2c  ",arr[i][j]);
        }
        printf("\n");
    }
}
void setIndexToOne(char arr[][9],int row, int col)
{
    int i,j;
    for(i=0; i<row; i++)
    {

        for(j=0; j<col; j++)
        {
            if(arr[i][j]!='-')
            {
                count[i][j]=1;
            }
        }
    }
}
int checkReptaionSquare(char arr[][9],int row,int col,int row_index,int col_index,char value)
{
    int i,j;
    if((row_index<3)&&(col_index<3))
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }
    else if((row_index>=3&&row_index<6)&&(col_index>=3&&col_index<6))
    {
        for(i=3; i<6; i++)
        {
            for(j=3; j<6; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }
    else if((row_index>=6&&row_index<9)&&(col_index>=6&&col_index<9))
    {
        for(i=6; i<9; i++)
        {
            for(j=6; j<9; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }
    else if((row_index<3)&&(col_index>=3&&col_index<6))
    {
        for(i=0; i<3; i++)
        {
            for(j=3; j<6; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }

    else if((row_index<3)&&(col_index>=6&&col_index<9))
    {
        for(i=0; i<3; i++)
        {
            for(j=6; j<9; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }

    else if((row_index>=3&&row_index<6)&&(col_index<3))
    {
        for(i=3; i<6; i++)
        {
            for(j=0; j<3; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }

    else if((row_index>=3&&row_index<6)&&(col_index>=6&&col_index<9))
    {
        for(i=3; i<6; i++)
        {
            for(j=6; j<9; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }

            }
        }
    }
    else if((row_index>=6&&row_index<9)&&(col_index<3))
    {
        for(i=6; i<9; i++)
        {
            for(j=0; j<3; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }
    else
    {
        for(i=6; i<9; i++)
        {
            for(j=3; j<6; j++)
            {
                if((arr[i][j]==value)&&(i!=row_index && j!=col_index))
                {
                    return 0;
                }


            }
        }
    }


    return 1;

}
int checkReptaion(char arr[][9],int row,int col,int row_index,int col_index,char value,char *flag)
{
    int i,j;
    *flag=0;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if((i==row_index)&&(arr[i][j]==value) &&(j!=col_index))
            {
                *flag=Rep_row;
                return 0;
            }
            if((j==col_index)&&(arr[i][j]==value)&&(i!=row_index))
            {
                *flag=Rep_col;
                return 0;
            }
            if(checkReptaionSquare(arr,row,col,row_index,col_index,value)==0)
            {
                *flag=rep_square;
                return 0;
            }

        }
    }



    return 1;



}
int checkFinish(char arr[][9],int row,int col)
{


    int i,j;
    char flag;
    for(i=0; i<row; i++)
    {

        for(j=0; j<col; j++)
        {
            if(arr[i][j]=='-')
            {
                return 0;
            }
            if(checkReptaion(arr,row,col,i,j,arr[i][j],&flag)==0)
            {
                return 0;
            }

        }

    }
    return 1;

}
int CheckIndex(int row_index,int col_index)
{
    if(count[row_index][col_index])
    {
        return 0;
    }
    return 1;

}


int main()
{
    /*char arr[9][9]= {{'-','3','-','1','5','6','-','-','-'},
        {'-','8','-','-','2','-','-','7','-'},
        {'6','-','-','-','-','-','5','-','-'},
        {'-','1','-','6','-','-','9','-','-'},
        {'2','-','-','9','4','1','-','-','6'},
        {'-','-','8','-','-','5','-','1','-'},
        {'-','-','7','-','-','-','-','-','9'},
        {'-','5','-','-','1','-','-','8','-'},
        {'-','-','-','2','6','8','-','4','-'},
    };*/
char arr[9][9] = {
    {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
    {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
    {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
    {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
    {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
    {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
    {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
    {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
    {'3', '4', '5', '2', '8', '6', '1', '7', '-'}
};

    setIndexToOne(arr,9,9);
    print2dArr(arr,9,9);
    int row_index;
    int col_index;
    char value;
    char flag;
    printf("----------------------------------------------------------------\n");
    while(checkFinish(arr,9,9)==0)
    {
    printf("Enter row Index:");
    scanf("%d",&row_index);
    printf("Enter col Index:");
    scanf("%d",&col_index);
    printf("Enter value:");
    fflush(stdin);
    scanf("%c",&value);
    if(CheckIndex(row_index,col_index)==0)
    {
        printf("Can NOT change value in that index\n");
    }
        else
        {
            if((value>='1')&&(value<='9')&& (row_index>=0&&row_index<9)&&(col_index>=0&&col_index<9))
            {
                if(checkReptaion(arr,9,9,row_index,col_index,value,&flag))
                {
                    arr[row_index][col_index]=value;
                    print2dArr(arr,9,9);
                }
                else
                {
                    if(flag==1)
                    {
                        printf("repeated in same Row\n");
                    }
                    else if(flag==2)
                    {
                        printf("repeated in same col\n");
                    }
                    else if(flag==3)
                    {
                        printf("repeated in same square\n");
                    }


                }

            }
            else
            {
                printf("please Enter Valid Inputs\n");
            }


        }
    }

    printf("congratulations You finished it correctly\n");

    return 0;
}
