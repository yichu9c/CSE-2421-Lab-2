/*BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED
 * TO THE TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY
 * WITH RESPECT TO THIS ASSIGNMENT
 *
 * Name: Yihone Chu*/

#include <stdio.h>

/*
 *This is the function that creates the key. I or the return value with 0x11 depending
if the user enters 1 or 0. Then I shift and or it a certain amount based in 3-i 
 * */
unsigned char create_key(){	
	unsigned char return_value =0x00;
 	int i;
	int value;	
	#ifdef PROMPT
		printf("enter 4-bit key:\n");	
	#endif
	for(i=0; i<4;i++){
		value = getchar();
		if(value == '1'){
			return_value = return_value | (0x11<<3-i);
		}
	}	
	return return_value;
}
/*To rotate I shift left 1 then or it with itself shifted right 7 times
 * */
unsigned char left_rotate(unsigned char x){
	return(x<<1) | (x>>7);
}

/*
 *To rotate right I shift right 1 then or it with itself shifted left 7 times.
*/
unsigned char right_rotate(unsigned char x){
	return (x>>1) | (x<<7);
}
/*
 *First I declare variables, then I use the create_key function to 
get and process the key. Then I have the preprocessor determine
whether to run the blocl of code.Then I use a loop and print out 
the characters that are rotated.  
 *
*/
int main(void){
	unsigned char joinKey;
	int i=0;
	int var1;

	joinKey = create_key();
	
	#ifdef PROMPT	
		printf("enter encoded text:\n");
	#endif
	
	do{
		scanf("%2x",&var1);
		if(i%2==0){
			putchar(right_rotate((unsigned char)var1)^joinKey);	
		}
		else{
			putchar(left_rotate((unsigned char)var1)^joinKey);
		}
		
		i++;		
	}while(getchar()!='\n');


	putchar('\n');
	return 0;
}
