#include<stdio.h>

int a[3001] ;

int main(void)
{

    int testCase , i , temp2 , temp1 ;

    while(scanf("%d",&testCase) != EOF)
    {

        for(i = 0 ; i < testCase ; i ++)
        {

            temp1 = temp2 ;
            scanf("%d",&temp2) ;

            if(i != 0)
            {

                if(temp1 >= temp2)
                {
                    a[ temp1 - temp2 ] =  1 ;
                }
                else a[ temp2 - temp1 ] =  1;
            }else {

                     a[0] = 1 ;
            }

        }

       for(i = 0 ; i < testCase - 1 ; i ++){

              if(a[i] != 1)break ;
       }
        if(a[ i ] != 1 )printf("Not jolly\n");
        else printf("Jolly\n") ;
        for(i = 0 ; i < testCase - 1 ; i ++){

              a[i] = 0 ;
        }

    }
    return 0 ;
}
