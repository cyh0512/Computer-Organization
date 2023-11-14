// description: matrix muliply with two-level for loop
#include<stdio.h>
int main()
{
 int f,i=0;
 int h[9]={0}, x[3]={0}, y[3]={0};
 FILE *input = fopen("../input/3.txt","r");
 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
 fclose(input);
 
 int *p_x = &x[0] ;
 int *p_h = &h[0] ;
 int *p_y = &y[0] ;
 
 for (i = 0 ; i < 3; i++)
 {
 p_x = &x[0];
 //printf("`p_y addr:%p`\n",p_y);
 for (f = 0 ; f < 3; f++)

asm volatile(
"lw t0, 0(%[h])\n\t"
"lw t1, 0(%[x])\n\t"
"lw t2, 0(%[y])\n\t"
"mul t3, t0, t1\n\t"
"add t2, t2, t3\n\t"
"addi %[h], %[h], 4\n\t"
"addi %[x], %[x], 4\n\t"
"sw t2, 0(%[y])\n\t"
: [h]"+r"(p_h), [x]"+r"(p_x), [y]"+r"(p_y)
:
:"t0","t1","t2","t3"	 		 		 
);
 p_y++;
 }
 p_y = &y[0];
 for(i = 0; i<3; i++)
	 printf("%d \n", *p_y++);
 
 return(0) ;
}
