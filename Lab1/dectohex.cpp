#include <stdio.h>
#include <string.h>
#include <math.h>

// 10-таас 16-т руу хөрвүүлэх
void decimalToHex(int decimal, char hex[]) {
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0'; // 0-9 digits
        } else {
            hex[i] = remainder - 10 + 'A'; // A-F for 10-15
        }
        decimal = decimal / 16;
        i++;
    }
    hex[i] = '\0';  // Null-terminate the string
    
    // Reverse the hex array to get the correct order
    int len = strlen(hex);
    for (int j = 0; j < len / 2; j++) {
        char temp = hex[j];
        hex[j] = hex[len - j - 1];
        hex[len - j - 1] = temp;
    }
}

// 16-таас 10-т руу хөрвүүлэх
int hexToDecimal(char hex[]) {
    int decimal = 0, base = 1;
    int length = strlen(hex);
    
    for (int i = length - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - '0') * base;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    
    return decimal;
}

int main() {
    int decimal;
    char hex[20];
    char hexInput[20];
    
    // Input Decimal number
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);
    
    // Convert Decimal to Hexadecimal
    decimalToHex(decimal, hex);
    printf("Hexadecimal representation: %s\n", hex);
    
    // Convert Hexadecimal back to Decimal
    printf("Converted back to Decimal: %d\n", hexToDecimal(hex));
    if(decimal == hexToDecimal(hex)) 
    printf("Correct");
    else printf("Incorrect");
    return 0;
}
