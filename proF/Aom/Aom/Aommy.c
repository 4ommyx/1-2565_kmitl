#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
int main(){
    //part0();
    //part1();
    //part3();
    //part4();
    //part6();
    //part7();
    //part8();
    //part10();
    //part11();
    //part14(); part14_1()
    //part15(); part15_1();
    //part16(); part16_1();
    //part17();
    //part18();
    //part19();
    //part20();
    //part21();
    //part22_1(); part22_2();
    //part26();
    //part27();
    

    


}
void part0(){
    printf("hello world\n");   // hello world \n aomnattawut
    printf("aomnattawut");
}
void part1(){

    int area,h,w ;
    printf("enter high :");
    scanf("%d",&h);          //enter high :5 enter wide :5 area is = 25
    printf("enter wide :");
    scanf("%d",&w);
    area=w*h;
    printf("area is = %d",area);

}
void part3(){
    int h,w ;
    float area ;
    printf("enter high :");
    scanf("%d",&h);
    printf("enter wide :");
    scanf("%d",&w);
    area=0.5*w*h;
    printf("Triangle area is = %f",area);

}
void part4(){
    int Age,age;
    float price;
    char *hero="aommm";
    Age=20; age=19; price=102.51; 
    printf("%d\n",Age);
    printf("%d\n",age);
    printf("%.2f\n",price);
    printf("%s\n",hero);





} 
void part6(){
    float c,f;
    printf("Enter degree in celsius :");
    scanf("%f",&c); 
    f=(c*1.8)+32;
    printf(" %f celsius = %f fahrenheit\n ",c,f);

}
void part7(){
    int age;
    printf("Enter your age :");
    scanf("%d",&age);
    if(age<=6){
        printf("you're a kid\n");
        printf("free or you\n");
    }
    else
    {
        printf("you're an adult\n");
        printf("199 bath\n");

    }
    
}
void part8(){
    int i ;
    int sum=0;
    for ( i = 0; i <= 10; i+=1)
    {
        printf("%d\n",i);
        sum=sum+i;
    }
    printf("Answer is = %d",sum);
}
void part10(){
   
    int n=40;
    int m=41;
    printf("n=%d\nm=%5d\n",n,m);
    printf("n=%d\nm=%05d\n",n,m);
    
 
    float o=3.14159;
    printf("%f\n",o);
    printf("%.2f\n",o);
    printf("|%.3f|\n",o);
    printf("|%10.3f|\n",o); //เว้นไว้10ช่อง ทศ3ตำแหน่ง


    char x ='a';
    printf("x = %c %d\n", x, x);
    int y=98;
    printf("y = %c %d\n",y,y);


}
void part11(){
    
    char*str="4ommyx_";
    printf("str = |%s|\n",str);  // string=คำ char=ตัวอักศร(1ตัว)
    printf("str = |%-10s|\n",str);
    printf("str = |%10s|\n",str);

    int i ;
    for (i = 0; i <= 999; i+=11)
    {
        printf("i = %d |%p|\n",i, &i);
    }
    printf("-----Thx------\n");
    





 }  
 void part14(){
    int h;
    printf("Enter your height (cm) : ");
    scanf("%d",&h);
    if(h>160){
        printf("you pass\n");
        printf("congratulations\n");
        
        }
        else{
            printf(" sorry ");
        }
    
    } 
 void part14_1(){
        int h , age;
    printf("Enter your height (cm) : ");
    scanf("%d",&h);
    printf("Enter your age : ");
    scanf("%d",&age);
    if(h>160 && age<25){
        printf("you pass\n");
        printf("congratulations\n");
        
        }
        else{
            printf(" sorry ");
        }

    }
 void part15(){ 
    char menu;
    printf("mocha\n");
    printf("latte\n");
    printf("espresso\n");
    printf("cappuchino\n");
    printf("please select a menu : ");
    scanf("%c",&menu);
    if(menu=='m'){
        printf("40\n");
    } else if (menu=='l'){
        printf("30\n");
    }
    else if (menu=='e'){
        printf("20\n");
    }
    else if (menu=='c'){
        printf("30\n");
    }
    else {
        printf("please select a valid menu\n");
    }
    
 }
 void part15_1(){
    int age,ticket;
    printf("Enter your age : ");
    scanf("%d",&age);
    if(age<5 || age>=60){
        ticket = 0 ;
    }
    else{
        ticket = 50 ;
    }
    printf("%d bath",ticket);
 }
 void part16(){
    int a=100, b=700 ;
    int max;
    // if(a>b){
    //     max = a;
    // }
    // else {
    //     max =b;
    // }
    max = a > b ? a : b;
    printf("max = %d\n", max); // คือการย่อใช้ if
    
}
void part16_1(){  
    int age,ticket;
    printf("Enter your age : ");
    scanf("%d",&age);
    // if(age<5 || age>=60){
    //     ticket = 0 ;
    // }
    // else{
    //     ticket = 50 ;
    // }
    ticket = age<5 || age>60 ? 0 : 50 ; // คือการย่อใช้ if
    printf("%d bath",ticket);

}
void part17(){
 char menu;
    printf("1.mocha\n");
    printf("2.latte\n");
    printf("3.espresso\n");
    printf("4.cappuchino\n");
    printf("please select a menu : \n");
    scanf("%c",&menu);
    switch (menu){ //ในวงเล็บคือชื่อตัวแปร
        case '1':
        case 'm':
            printf("40\n");
            break;
        case '2':
        case 'l':
            printf("30\n");
            break;
        case '3':
        case 'e':
            printf("20\n");
            break;
        case '4':
        case 'c':
            printf("50\n");
            break;

        default: //เหมือน else
        printf("please select a valid menu\n");
    }
}
void part18(){
    int i;
    for (i=1;i<=10;i+=1)
    {                           // ในลูป(เงื่อนไข)
        printf("%d\n",i);
    }
    printf("---- end %d\n",i); //นอกลูป(ไม่ตรงเงื่อนไข)
    
}
void part19(){
    int sum=0;
    int j;
    for(j=1;j<=10;j+=1){

        printf("%d\n",j);
        sum=sum+j;
        printf("sum=%d\n",sum);
        printf("--------------\n");

    }
}
void part20(){
   int i;
    // for(i=1;i<=10;i+=1){
    //     printf("%d ounces = %f grams\n",i,i*28.3495); //ไม่สวย
    // }
    for(i=1;i<=10;i+=1){
        printf("%2d ounces = %8.4f grams\n",i,i*28.3495);
    }

}
void part21(){
    
    for( int j=1;j<=12;j+=1){
    for( int i=1;i<=12;i+=1){
        printf("%2d * %2d = %3d\n",j,i,i*j);
    }
    printf("-------------------\n");
    printf("\n");

     }
     
}
void part22_1(){
    int sum=0;
    int n;
    printf("Plese enter your number : ");
    scanf("%d",&n);
    while (n !=0)
    {   sum=sum+n;
        printf("Plese enter your number : ");
        scanf("%d",&n);   
    }
    printf("Ans = %d\n",sum);
   
}
void part22_2(){
    int sum=0;
    int n ; 
    do{
        printf("Plese enter your number : ");
        scanf("%d",&n);
        sum = sum + n ;
    } while (n != 0);
        printf("Ans = %d \n",sum);

    
}
void part26(){ 
    char c1 = 'A' ;
    char c2 = 'A'+1 ;
    char c3 = 'A'+2 ;
    printf("%c : %d \n",c1,c1);
    printf("%c : %d \n",c2,c2);
    printf("%c : %d \n",c3,c3);
   // for (int i = 0; i <= 256 ; i+=1)
  //  {
        //printf("%c : %d \n" ,i,i);

        //printf()
   // }
    for (char j = 'A'; j <= 'Z';j+=2 )
    {
        printf("%c : %d \n" ,j,j);
    }
    
}
void part27(){ 

    char s[] = "HELLO" ;
    for (int i = 0 ; i<= 4 ; i+=1){
        if(s[i] >='A' && s[i] <='M') {

            printf ("%c | %d \n",s[i]+13,s[i]+13);

        }
        else
        printf ("%c | %d \n",s[i]-13,s[i]-13);



    }




} 





































































































































































































































































































































































































































































































































































































































































































































































































































