#include<stdio.h>
#include<string.h>
int main(){
//part1();
//part2();
//part3();
//part4();
//part5();
//part6();
}

void part1(){
    int i;
    float weight[5]={55.7,62.5,75.89,66.54,79.43};
      weight[0]=78.64;
      weight[4]=58.21; 
for ( i = 0; i < 5; i+=1)
{
        if(weight[i]>60){
    printf("%f\n",weight[i]);
    }
}
}
void part2(){
    char name[100];
    printf("What is your name :");
    scanf("%s",&name);
    printf("Nice to meet you %s ",name);
}
void part3(){
    char str[20]="12345 I love U";
    int str_length = strlen(str);
    printf("%d",str_length);
}
void part4(){
    char str1[] ="ABCDEFG";
    char str2[] ="ABCDEFG";
    char str3[] ="HIJKLMN";
    int result;
    result = strcmp(str1,str2);
    printf("strcmp(str1,str2) = %d\n",result);
    result = strcmp(str1,str3);
    printf("strcmp(str1,str3) = %d\n",result);

}
void part5(){
    int ans;
    char str1[100];
    char str2[100];
  printf("input your first string :");
  scanf("%s",&str1);
  printf("input your second string :");
  scanf("%s",&str2);
  ans = strcmp(str1,str2);
  if (ans==0)
  {
    printf("yes");
  }
  else{
    printf("No");
  }


}
void part6(){
    int i;
    int number[100];
    for ( i = 0; i < 100; i++)
    { 
      number[i]=i+1;
      if (number[i] %10 ==1)
      {
        printf("\n");
      }
      printf("%d ",number[i]);
    }
    }
