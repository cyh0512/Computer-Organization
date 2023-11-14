//Todo:
"addi %[flag],zero,1\n\t"
"addi t1,zero,8\n\t" //for-loop index
"addi t2,zero,-1\n\t" //
"add t3,%[p_x],zero\n\t"
"vsetvli t0,t1,e16,ta,ma\n\t"
"vle16.v v4,(%[p_tmp1])\n\t" //set v4=tmp1[0:7]=0
"vle16.v v0,(%[p_x])\n\t" //set v0=x[0:7]

"loop:\n\t"
"lh t5,0(t3)\n\t" //t5=x[j], j from 0 to 7.
"vadd.vx v1,v4,t5\n\t" //set v1= v4 + x[j]= x[j], j from 0 to 7.

"vadd.vv v2,v0,v1\n\t" //v2 = x[0:7] + x[j], j from 0 to 7.

"vmseq.vx v3,v2,%[target]\n\t" // if v2[k]=target ,then v3[k]=1, else v3[k]=0.
"vfirst.m t4,v3\n\t" //if find element=1 then return index, else return -1.

"bne t4,t2,exit\n\t" //match target, flag=1, doesn't change.

"addi t3,t3,2\n\t" //x[i] next element
"addi t1,t1,-1\n\t" //for-loop index --
"bne t1,zero,loop\n\t"

"addi %[flag],zero,0\n\t" //there is no match, flag=0
"exit:\n\t"