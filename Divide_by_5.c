// -*- coding: utf-8 -*-
// Author : Arpan Mahanty

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int digit(char c){
 
    int value=0;
 
    switch(c){
         case 'I': value = 1; break;
         case 'V': value = 5; break;
         case 'X': value = 10; break;
         case 'L': value = 50; break;
         case 'C': value = 100; break;
         case 'D': value = 500; break;
         case 'M': value = 1000; break;
         case '\0': value = 0; break;
         default: value = -1; 
    }
 
    return value;
}


int main() {     
    int N,z;
    scanf("%d", &N);
    for(z=0;z<N;z++){
        char roman_Number[100];
        int i=0;
        long int number =0;
        scanf("%s",roman_Number);
        
        while(roman_Number[i]){
 
         if(digit(roman_Number[i]) >= digit(roman_Number[i+1]))
             number = number + digit(roman_Number[i]);
         else{
             number = number + (digit(roman_Number[i+1]) - digit(roman_Number[i]));
             i++;
         }
         i++;
        }
        
        if(number%5){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}
