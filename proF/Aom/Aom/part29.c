#include <stdio.h>

double circle( double r ) ; // บนหรือล่างก็ได้เพราะประกาศตัวแปรไว้แล้ว

double triangle ( double w , double h ); // บนหรือล่างก็ได้เพราะประกาศตัวแปรไว้แล้ว

double rectangle ( double w , double h ){ //วางไว้เหนือเมนเท่านั้น
    return  w * h ;

}



int main(){

    printf(" circle area is = %.2f \n",circle(5));
    printf(" triangle area is = %.2f \n",triangle(3,5));
    printf(" rectangle area is = %.2f \n",rectangle(3,5));

    return 0 ;
    

}

double circle( double r ) {
    return 3.14 * r * r ;
}

double triangle ( double w , double h ){
    return .5 * w * h ;
}



