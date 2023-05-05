
#include<stdio.h>
#include<math.h>
int gcd(int a , int b){
    int min = a < b ? a : b ;
    for(int i=min ; i>=1 ; i-=1){
        if(a % i == 0 && b % i == 0 ){
            return i ;
        }

    }



}


int main (){
    int a = 21 ;
    int b = 9 ;
    printf("gcd ( %d , %d ) = %d ",a,b,gcd(a,b));



}

