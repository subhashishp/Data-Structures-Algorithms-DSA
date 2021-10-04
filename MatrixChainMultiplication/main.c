#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printParenthesis(int i,int j,int n,int **bracket,char *name);

void paren(int** s, int i, int j)
{
    if (i == j)
        printf(" %d ", i+1);
    else
    {
        printf("(");
        paren(s, i, s[i][j]-1);
        paren(s, s[i][j]+1, j);

    }
    printf(")");
}

int main()
{
    int n,i,j,k,z,min=INT_MAX;
    int *sizes;
    int **m,**br;
    printf("number of matrix present\n");
    scanf("%d",&n);
    //n=n+1;
    sizes=(int*)malloc((n+1)*sizeof(int));
    printf("enter sizes in MCM format\n");
    for(i=0;i<(n+1);i++)
        scanf("%d",&sizes[i]);

    //  creating dp table and k table
    m=(int**)malloc(n*sizeof(int*));
    br=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        m[i]=(int*)malloc(n*sizeof(int));
        br[i]=(int*)malloc(n*sizeof(int));
    }

    //  preprocessing dp table
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(i==j)
                 m[i][i]=0;
            else
                m[i][j]=INT_MAX;
        }
    }

    //  traversing in dp table
    for(i=0;i<n;i++)
    {
        z=0;
        for(j=i+1;j<n;j++)
        {
            for(k=z+1;k<j+1;k++)
            {
                min=m[z][k-1]+m[k][j]+sizes[z]*sizes[k]*sizes[j+1];
                if(min < m[z][j])
                {
                    m[z][j]=min;
                    br[z][j]=k;
                }
            }
            z++;
        }
    }

    //  printing dp table
    printf("<--------------DP table------------->\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
                printf("%d ",m[i][j]);
            else
                printf("    ");
        }

        printf("\n");
    }
    printf("\n");
    printf("<--------------K table------------->\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
                printf("%d ",br[i][j]);
            else
                printf("  ");
        }

        printf("\n");
    }
    printf("-------------Parenthesis------------->\n");
    char name = 'A';
    printParenthesis(0,n-1,n-1,br,name);
    //paren(br, 0, n-1);
    return 0;
}

/*void printParenthesis(int i,int j,int n,int **bracket,char *name)
{
    if (i == j)
    {
        printf(" %c%d ",name,i);
        return;
    }
    printf("(");
    printParenthesis(i, *((bracket + i * n) + j), n,bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n,bracket, name);
    printf(")");
}
*/
void printParenthesis(int i,int j,int n,int **bracket,char *name)
{
    if (i == j)
    {
        printf(" %c%d ",name,i);
        return;
    }
    printf("(");
    printParenthesis(i, bracket[i][j]-1, n,bracket, name);
    printParenthesis(bracket[i][j], j, n,bracket, name);
    printf(")");
}

