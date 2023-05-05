// local vs global variable
#include<stdio.h>

int a=999; // global
int main(){
    int a=10; // local
    printf("a (main) = %d\n",a);
    //f1();
    //f2();
    //f3();
    f4();


}
void f1(){ 
    int a=20; // local
    printf("a (f1) = %d\n",a);
}
void f2(){
    int a=30; // local
    printf("a (f2) = %d\n",a);
}
void f3(){ // global
    printf("a (f3) = %d\n",a);
}
void f4(){
    int i;
    char g ='Z';
        for ( i = 1; i <= 49; i+=1){
            char g='F';
            printf("|%p| %d %c\n",&g,i,g);

        }
        for ( i = 50; i <= 59; i+=1){
            char g='D';
            printf("|%p| %d %c\n",&g,i,g);

        }
        for ( i = 60; i <= 69; i+=1){
            char g='C';
            printf("|%p| %d %c\n",&g,i,g);

        }
        for ( i = 70; i <= 79; i+=1){
            char g='B';
            printf("|%p| %d %c\n",&g,i,g);

        }
        for ( i = 80; i <= 100; i+=1){
            char g='A';
            printf("|%p| %d %c\n",&g,i,g);

        }
     printf("|%p| %d %c\n",&g,i,g);

    }
    
    


























































    
    
    
