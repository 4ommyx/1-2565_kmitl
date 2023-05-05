#include<stdio.h>
#include<math.h>

int money( float pm, float rate , float fm){
    int i = 0;
    float tot = 0 ;

    do{
        tot = pm * pow(1+rate,i);
        printf("year %d | tot = %f \n",i,tot);
        i+=1;

    }
    while(tot<=fm);
    return i-1 ;
}
    

    int main (){
        printf("year = %d \n", money(1000,.005,1500));


    }
