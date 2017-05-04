#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	float result;
	int line = 0;
	double (*function_pointer)(int,int);

	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line-1; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				//result = add(operand1, operand2);
				function_pointer=add;
				break;
				case '-':
				//result = minus(operand1, operand2);
				function_pointer=minus;
				break;
				case '*':
				//result = mul(operand1,operand2);
				function_pointer=mul;
				break;
				case '/':
				//result = div(operand1, operand2);
				function_pointer=div;
				break;
			}
			result = function_pointer(operand1,operand2);		
			printf("%d %c %d = %f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

