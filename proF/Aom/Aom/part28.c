 #include<stdio.h>
 #include<stdbool.h>

 bool leapyear (int year)
    {
    return year % 4 == 0 ? true : false ;
    }


    int main(){


        printf("leapyear is  = %d \n ",leapyear(2016));



        }
