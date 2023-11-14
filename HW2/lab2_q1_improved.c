// TODO : 
"addi t1, zero, 16\n\t"
"addi %[arith_cnt], %[arith_cnt], 1\n\t"
"vvaddint16:\n\t"
    "vsetvli t0, t1, e16, ta, ma\n\t" //Set vector length based on 16-bit vectors
    "addi %[others_cnt], %[others_cnt], 1\n\t"
    "vle16.v v0, (%[h])\n\t" //Get first vector
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"
        "sub t1, t1, t0\n\t" //Decrement number done
        "addi %[arith_cnt], %[arith_cnt], 1\n\t"
        "slli t0, t0, 1\n\t" //Multiply number done by 2 bytes
        "addi %[arith_cnt], %[arith_cnt], 1\n\t"
        "add %[h], %[h], t0\n\t" //Bump pointer
        "addi %[arith_cnt], %[arith_cnt], 1\n\t"
    "vle16.v v1, (%[x])\n\t" //Get second vector
    "addi %[lw_cnt], %[lw_cnt], 1\n\t"
        "add %[x], %[x], t0\n\t" //Bump pointe
        "addi %[arith_cnt], %[arith_cnt], 1\n\t"
    "vadd.vv v2, v0, v1\n\t" //Sum vectors
    "addi %[arith_cnt], %[arith_cnt], 1\n\t"
    "vse16.v v2, (%[y])\n\t" //Store result
    "addi %[sw_cnt], %[sw_cnt], 1\n\t"
        "add %[y], %[y], t0\n\t" //Bump pointer
        "addi %[arith_cnt], %[arith_cnt], 1\n\t"
        "addi %[others_cnt], %[others_cnt], 1\n\t"
        "bnez t1, vvaddint16\n\t" //Loop back
        
        