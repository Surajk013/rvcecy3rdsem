#include<stdio.h>
#include<stdlib.h>
#define L 10

int main(){
    int a=1;
    printf("%f\n%f\n",4.0/3.0,0.333*4.00);
    switch(a){
        case 1+2/2: printf("case 1:");break;
        case 2/2*3: printf("case 2:");break;
        case L*3: printf("case 3:");break;
        default: printf("default");
        
    }
}