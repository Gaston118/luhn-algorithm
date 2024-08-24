#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool luhn_checker(char *card_number);

int main(){

    char card_number[17];
    strcpy(card_number, "5533443434334341");

    if(luhn_checker(card_number)){
        printf("La tarjeta es válida\n");
    }else{
        printf("La tarjeta no es válida\n");
    }

    return 0;
}

bool luhn_checker(char *card_number){
    int sum = 0;
    int length = strlen(card_number);
    bool is_second = false;

    for(int i=length-1; i>=0; i--){
        int digit = card_number[i] - '0';

        if(is_second){
            digit = digit * 2;
            if(digit > 9){
                digit = digit - 9;
            }
        }

        sum += digit;
        is_second = !is_second;
    }
    return (sum % 10 == 0);
}

