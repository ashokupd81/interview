#include<stdio.h>



void markIsland(int rows, int cols, int i , int j, int M[rows][cols])
{
        //boundary case!!
        if(i<0 || i> rows || j<0 || j> cols || M[i][j]!= 1)
                return;
        M[i][j]=2;//already visisted

        //check all four values
        markIsland(rows, cols, i+1, j, M);//down
        markIsland(rows, cols, i, j+1, M);//right
        markIsland(rows, cols, i-1, j, M);//top
        markIsland(rows, cols, i, j-1, M);//left
}


int main()
{
        int M[][5] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

        int i,j;
        int noIsland = 0;
        int r =5, c=5;
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        if(M[i][j] == 1)
                        {
                                markIsland(r,c,i,j,M);
                                noIsland +=1;
                        }
                }
        }
        printf("%d",noIsland);
}
