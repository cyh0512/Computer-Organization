// description: matrix muliply with two-level for loop
#include<stdio.h>
int main()
{
 int f,i=0;
 int h[9]={0}, x[3]={0}, y[3]={0};
 FILE *input = fopen("../input/4.txt","r");
 for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
 for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
 fclose(input);
 
 /*
 for(i = 0; i<9; i++) printf("%d ",h[i]);
 printf("\n");
 for(i = 0; i<3; i++) printf("%d ",x[i]);
 printf("\n");
 for(i = 0; i<3; i++) printf("%d ",y[i]);
 printf("\n");
 */
 
 int *p_x = &x[0] ;
 int *p_h = &h[0] ;
 int *p_y = &y[0] ;

asm volatile(
"lw t0, 0(%[h])\n\t" // Load h11
"lw t1, 0(%[x])\n\t" // Load x1
"lw t2, 0(%[y])\n\t" // Load y1
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"

"lw t0, 4(%[h])\n\t" // Load h12
"lw t1, 4(%[x])\n\t" // Load x2
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"

"lw t0, 8(%[h])\n\t" // Load h13
"lw t1, 8(%[x])\n\t" // Load x3
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"
"sw t2, 0(%[y])\n\t" // Store y1

/////////////////////////////////////////////////

"lw t0, 12(%[h])\n\t" // Load h21
"lw t1, 0(%[x])\n\t" // Load x1
"lw t2, 4(%[y])\n\t" // Load y2
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"

"lw t0, 16(%[h])\n\t" // Load h22
"lw t1, 4(%[x])\n\t" // Load x2
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"

"lw t0, 20(%[h])\n\t" // Load h23
"lw t1, 8(%[x])\n\t" // Load x3
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"
"sw t2, 4(%[y])\n\t" // Store y2

//////////////////////////////////////////////////

"lw t0, 24(%[h])\n\t" // Load h31
"lw t1, 0(%[x])\n\t" // Load x1
"lw t2, 8(%[y])\n\t" // Load y3
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"

"lw t0, 28(%[h])\n\t" // Load h32
"lw t1, 4(%[x])\n\t" // Load x2
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"

"lw t0, 32(%[h])\n\t" // Load h33
"lw t1, 8(%[x])\n\t" // Load x3
"mul t3, t0, t1\n\t" // Multiply h[i][j] and x[j]
"add t2, t2, t3\n\t"
"sw t2, 8(%[y])\n\t" // Store y3

: [h]"+r"(p_h), [x]"+r"(p_x), [y]"+r"(p_y)
:
:"t0","t1","t2","t3"	 		 		 
);
 
 p_y = &y[0];
 for(i = 0; i<3; i++)
	 printf("%d \n", *p_y++);
 
 return(0) ;
}
