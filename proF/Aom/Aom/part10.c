void demo_int() {
        int n=40;
        int m=41;
        printf("n=%d\nm=%5d\n",n,m);
        printf("n=%d\nm=%05d\n",n,m);
    }
 void demo_float(){
    float n=3.14159;
    printf("%f\n",n);
    printf("%.2f\n",n);
    printf("|%.3f|\n",n);
    printf("|%10.3f|\n",n); //เว้นไว้10ช่อง ทศ3ตำแหน่ง
}
void demo_char(){
    char x ='a';
    printf("x = %c %d\n", x, x);
    int y=98;
    printf("y = %c %d\n",y,y);

}
    int main (){
        demo_int();
        demo_float();
        demo_char();
    }