#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int fibonacci(int nth) {
    int n1 = 0;
    
    int n2 = 1;
    int sum = 0;

    for(int i = 0; i < nth; i++) {
        sum = n1 + n2;
        n1 = n2;
        n2 = sum;
        printf("%d\n", sum);
    }

    return sum;

}

void gmp_fibonacci() {

    bool thousand_yet = false;
    int count = 1;
    mpz_t n1; 
    mpz_t n2;
    mpz_t sum;

    mpz_init(n1);
    mpz_init(n2);
    mpz_init(sum);

    mpz_set_ui(n2, 1);
/*
    for(int i = 0; i < nth; i++) {
        mpz_add(sum, n1, n2);
        mpz_set(n1, n2);
        mpz_set(n2, sum);
        gmp_printf("%Zd\n", sum);
    }*/

    //return(mpz_get_ui (sum));

    /*
    while(thousand_yet != true) {

        mpz_add(sum, n1, n2);
        mpz_set(n1, n2);
        mpz_set(n2, sum);
        count ++;

        if(count%200 == 0) {
            printf("Digits so far: %zu Count so far: %d\n", mpz_sizeinbase(sum, 10), count);
            if(mpz_sizeinbase(sum, 10) >= 1000) {
                thousand_yet = true;
                return(mpz_sizeinbase(sum, 10));
                
            }
        
        } 
    }
    */
   //Okay, so now we know that the answer is somewhere between 4600 and 4800, probably closer to the 4800 end because 4800th has 1004
    // digits

    while(thousand_yet != true) {

        mpz_add(sum, n1, n2);
        mpz_set(n1, n2);
        mpz_set(n2, sum);
        count ++;

        if(count>= 4780) {
            char* buf;
            gmp_asprintf(&buf, "%Zd", sum);
            printf("result len: %lu count: %d\n", strlen(buf), count);
            if(strlen(buf) == 1000) {
                printf("result: %s\n", buf);
            }
            if(mpz_sizeinbase(sum, 10) >= 1010) {
                thousand_yet = true;
                
            }
        
        } 
    }

    // YAY! The answer is the 4782th number, and it does start with 1070 and end with 7816!!
    
    



}

int main(int argc, char *argv[]) {
    gmp_fibonacci();
}