#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define size 20

struct stack{
	int top;
	float data[size];
};
typedef struct stack stack;

void push(stack *s,float item){
	s->data[++(s->top)]=item;
}

float pop(stack *s){
	return s->data[(s->top)--];
}

float operate(float op1,float op2,char symbol){
	switch(symbol){
		case '+':return op1+op2;
		case '*':return op1*op2;
		case '/':return op1/op2;
		case '^':return pow(op1,op2);
		case '-':return op1-op2;
	}
}

float eval(stack *s,char prefix[size]){
	int i;
	char symbol;
	float res,op1,op2;
	for(i=strlen(prefix)-1;i>=0;i--){
		symbol=prefix[i];
		if(isdigit(symbol))
			push(s,symbol-'0');
		else{
			op1=pop(s);
			op2=pop(s);
			res=operate(op1,op2,symbol);
			push(s,res);
		}
	}
	return pop(s);
}

int main(){
	 char prefix[size];
	 stack s;
	 s.top=-1;
	 printf("\n Enter the prefix expressoin: ");
	 scanf("%s",prefix);
	 float ans=eval(&s,prefix);
	 printf("\nThe final answer is: %f",ans);
	 return 0;
}
