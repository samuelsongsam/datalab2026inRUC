/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(x & y) & ~(~x & ~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if (!x) {
        return !y;
    }
    
    if (!y) {
        return 0;
    }
    
    return !((x ^ y) >> 31);}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int b16, b8, b4, b2, b1;
    
    b16 = ((v >> 16) > 0) << 4;
    v = v >> b16;
    
    b8 = ((v >> 8) > 0) << 3;
    v = v >> b8;
    
    b4 = ((v >> 4) > 0) << 2;
    v = v >> b4;
    
    b2 = ((v >> 2) > 0) << 1;
    v = v >> b2;
    
    b1 = (v >> 1) > 0;
    
    return b16 | b8 | b4 | b2 | b1;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    n = n << 3;
    m = m << 3;
    int notSame = (((x >> n) & 0xFF) ^ ((x >> m) & 0xFF));
    return x ^ (notSame << n) ^ (notSame << m);
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    v = (v << 16) | (v >> 16);
    v = ((v & 0x00ff00ff) << 8) | ((v >> 8) & 0x00ff00ff);
    v = ((v & 0x0f0f0f0f) << 4) | ((v >> 4) & 0x0f0f0f0f);
    v = ((v & 0x33333333) << 2) | ((v >> 2) & 0x33333333);
    v = ((v & 0x55555555) << 1) | ((v >> 1) & 0x55555555);
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int isNeg = (x >> 31) & 0x1;
    x = x & 0x7fffffff;
    x = (x >> n);
    x = x | (isNeg << 31 + ~n + 1);
    return x;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    x = ~x;
    int b16 = !(x >> 16) << 4;
    x = x << b16;
    int b8 = !(x >> 24) << 3;
    x = x << b8;
    int b4 = !(x >> 28) << 2;
    x = x << b4;
    int b2 = !(x >> 30) << 1;
    x = x << b2;
    int b1 = !(x >> 31);
    x = x << b1;
    int b0 = !(x >> 31);
    return b16 + b8 + b4 + b2 + b1 + b0;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned int sign;
    unsigned int ux;
    int exp;
    int frac;
    int dropped;
    int round_up;
    if (x == 0) {
        return 0;
    }
    sign = x & 0x80000000;
    if (x < 0) {
        ux = ~x + 1;
    } else {
        ux = x;
    }
    exp = 31;
    while (!(ux >> 31)) {
        ux = ux << 1;
        exp = exp - 1;
    }
    frac = (ux >> 8) & 0x7FFFFF;
    dropped = ux & 0xFF;  
    round_up = 0;
    if (dropped > 0x80) {        
        round_up = 1;
    } else if (dropped == 0x80) { 
        if (ux & 0x100) {
            round_up = 1;
        }
    }
    if (round_up) {
        frac = frac + 1;
        if (frac >> 23) {
            frac = frac & 0x7FFFFF;
            exp = exp + 1;
        }
    }
    return sign | ((exp + 127) << 23) | frac;
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned sign = uf & 0x80000000;
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0xff) return uf;
    if (exp == 254) frac = 0;
    if (exp == 0) return sign | (frac << 1);
    exp = exp + 1;
    return sign | (exp << 23) | frac;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int res;
    if (!uf1 & !uf2) return 0;
    unsigned sign = uf2 & 0x80000000;
    unsigned frac1 = (uf2 & 0x000fffff) | 0x00100000;
    int E = ((uf2 >> 20) & 0x7ff) - 1023;
    if (E < 0) return 0;
    if (E >= 31) {
	return 0x80000000;
    }
    if (E <= 20) res = (frac1 >> 20 - E);
    else res = (frac1 << E - 20) | (uf2 >> 52 - E);
    if (sign) res = ~res + 1;
    return res;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if (x > 127) return 0x7f800000;
    if (x < -149) return 0;
    if (x >= -126) return (x + 127) << 23;
    return 1 << (x + 149);
}
