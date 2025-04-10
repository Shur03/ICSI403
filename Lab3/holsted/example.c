#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define OPERATORS "+-*/%=({&,;"
const char *oper[] = {"main", "int", "char", "double", "float", "scanf", "printf", "if", "else", 
                      "switch", "case", "go", "break", "return"};
int dtcount = 14;

int main() {
    int n1 = 0, n2 = 0, N1 = 0, N2 = 0, N, n, i = 0, j;
    double V, D, E, B;

    char code[] = "main () {\n"
                  "    int a,b,c,d;\n"
                  "    scanf(\"%d %d %d\", &a, &b, &c);\n"
                  "    d = (a + b + c) / 3;\n"
                  "    printf(\"dundaj = %f\", d);\n"
                  "}";
    
    int otor[256] = {0};
    char orand[20][20]; // Array to store unique operands as strings
    int count = 0; // Operand count

    while (code[i] != '\0') {
        if (isalpha(code[i])) {
            char var[20];
            j = 0;
            while (isalnum(code[i]) && j < 19) {
                var[j++] = code[i++];
            }
            var[j] = '\0';
            int is_op = 0; // Operator flag
            for (int k = 0; k < dtcount; k++) {
                if (strcmp(var, oper[k]) == 0) {
                    is_op = 1;
                    break;
                }
            }
            if (is_op) { // It's a keyword operator
                N1++;
                if (!otor[(int)var[0]]) {
                    n1++;
                    otor[(int)var[0]] = 1;
                }
            } else { // Treat as an operand (e.g., variable name)
                int is_unique = 1;
                for (int k = 0; k < count; k++) {
                    if (strcmp(orand[k], var) == 0) {
                        is_unique = 0;
                        break;
                    }
                }
                if (is_unique) {
                    strcpy(orand[count++], var);
                    n2++;
                }
                N2++;
            }
        }
        // Check for string literals as operands
        else if (code[i] == '"') {
            char literal[50];
            j = 0;
            i++;
            while (code[i] != '"' && code[i] != '\0' && j < 49) {
                literal[j++] = code[i++];
            }
            literal[j] = '\0';
            i++; // Skip closing quote

            int is_unique = 1;
            for (int k = 0; k < count; k++) {
                if (strcmp(orand[k], literal) == 0) {
                    is_unique = 0;
                    break;
                }
            }
            if (is_unique) {
                strcpy(orand[count++], literal);
                n2++;
            }
            N2++;
        }
        // Check for numbers as operands
        else if (isdigit(code[i])) {
            char number[10];
            j = 0;
            while (isdigit(code[i]) || code[i] == '.') {
                number[j++] = code[i++];
            }
            number[j] = '\0';

            int is_unique = 1;
            for (int k = 0; k < count; k++) {
                if (strcmp(orand[k], number) == 0) {
                    is_unique = 0;
                    break;
                }
            }
            if (is_unique) {
                strcpy(orand[count++], number);
                n2++;
            }
            N2++;
        }
        // хэрэв тодорхойлсон OPERATOR байвал
        else if (strchr(OPERATORS, code[i])) {
            N1++;
            if (!otor[(int)code[i]]) {
                n1++;
                otor[(int)code[i]] = 1;
            }
            i++;
        }
        else {
            i++;
        }
    }

    // Calculate Halstead metrics
    N = N1 + N2;
    n = n1 + n2;

    if (n > 0) {
        V = N * log2(n);                    // Volume
    } else {
        V = 0;
    }

    if (n2 > 0) {
        D = (n1 / 2.0) * (N2 / (double)n2); // Difficulty
    } else {
        D = 0;
    }

    E = D * V;                             // Effort
    B = pow(E, 2.0 / 3.0) / 3000;          // Estimated bugs

    // Output results
    printf(" n1 = %d, n2 = %d, N1 = %d, N2 = %d, n = %d, N = %d\n", n1, n2, N1, N2, n, N);
    printf(" V = %.2f, D = %.2f, E = %.2f, B = %.2f\n", V, D, E, B);

    return 0;
}
