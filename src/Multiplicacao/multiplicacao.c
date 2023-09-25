#include "multiplicacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int int_to_bin(unsigned long long int k){
    return (k == 0 || k == 1 ? k : ((k % 2) + 10 * int_to_bin(k/2)));
}

int hash(char* num){
    int soma = 0;
    char* binchar = (char*) malloc(128*sizeof(char));
    for(int i = 0; i<strlen(num); i++){
        soma+= (num[i]-'0');
    }
    
    long long int q = soma*soma;
    long long int numbin = int_to_bin(q);
    printf("S e Q: %d %lli\t", soma, q);

    int ii=0;
    sprintf(binchar, "%lli", numbin);
    printf("Original: %s\t", binchar);
    while(strlen(binchar)>5){
        if(ii%2==0){
            binchar[strlen(binchar)-1] = '\0';
        } else {
            //binchar* = binchar+1;
            sprintf(binchar, "%s", binchar+1);
        }
        ii++;
    }
    int hashr = (binchar[0]-'0')*16 + (binchar[1]-'0')*8 + (binchar[2]-'0')*4 + (binchar[3]-'0')*2 + (binchar[4]-'0');

    return hashr;
}


// 
int main(){
    int i, n;
    char* tele = (char*) malloc(128*sizeof(char));
    time_t t;
    
    n = 20;
    
    srand((unsigned) time(&t));
    
    for( i = 0 ; i < n ; i++ ) {
        sprintf(tele, "%li", rand() % 9999999999999);
        printf("- Hash: %d\tNumero: %s\n", hash(tele), tele);
    }

    //char* tele0 = sprintf("%d", rand() % 9999999999999);
    char* tele1 = "5584996861005";

    //printf("Hash: %d\tNumero: %s\n", hash(tele0), tele0);
}