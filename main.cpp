#include <stdio.h>
#include <stdlib.h>

using namespace std;

void ignore_spaces();
void print_line(char, int);

int main(int argc, char** argv) {
    
    char m, m1, m2, m3, code_char, client_code[7];
    char lastname1[20], lastname2[20], names[25];
    double amount, op_amount;
    int dd, mm, aa, hs, ms, ss, items_read; // los uso para fecha u hora
    int op, dec_op_amount; // signo de la operacion D o R
    
    while((m = getchar()) != EOF) {
        
        ungetc(m, stdin); // devuelvo un char porque no es EOF.
        
        //Leer el codigo del cliente
        int i = 0;
        while((code_char = getchar()) != ' ') {
            // guardo el codigo del cliente en un arreglo y además lo muestro en pantalla
            client_code[i] = code_char;
            putchar(code_char);
            i++;
        }
        ignore_spaces();
        putchar(' ');
        
        // Leer el primer apellido
        i = 0;
        while((code_char = getchar()) != '/') {
            // guardo el primer apellido del cliente en un arreglo y además lo muestro en pantalla
            lastname1[i] = code_char;
            putchar(code_char);
            i++;
        }
        putchar(' ');
        
        // Leer el segundo apellido
        i = 0;
        while((code_char = getchar()) != '/') {
            // guardo el segundo apellido del cliente en un arreglo y además lo muestro en pantalla
            lastname2[i] = code_char;
            putchar(code_char);
            i++;
        }
        putchar(' ');
        
        // Leer los nombres
        i = 0;
        while((code_char = getchar()) != ' ') {
            // guardo el nombre del cliente en un arreglo y además lo muestro en pantalla
            names[i] = code_char;
            putchar(code_char);
            i++;
        }
        ignore_spaces();
        putchar(' ');
        
        // Leer el monto
        scanf("%lf", &amount);
        printf("%10.2lf\n", amount);
        
        
        while (1) { // Leer FECHA y todo lo demas
            scanf("%d%*c%d%*c%d", &dd, &mm, &aa); // leer fecha
            printf("Es una fecha: %02d-%02d-%04d ", dd, mm, aa);
            
            while (1) { // Leer "D/R - HORA - MONTO DE OPERACION"
                // Leo D/R y lo imprimo
                m1 = getchar();
                op = (m1 == 'D' ? 1 : -1);
                printf("%c ", m1);
                
                while (1) { // Leer la tupla "HORA - MONTO DE OPERACION"
                    items_read = scanf("%d%*c%d%*c%d", &hs, &ms, &ss);
                    if (items_read == 3) { // HORA o FECHA
                        if (ss < 100) {
                            printf("Es una hora: %02d-%02d-%02d ", hs, ms, ss);
                            continue;
                        }
                        else 
                            break;
                    } else if (items_read == 1){ // MONTO OPERACION y en hs tengo la parte entera del monto de la operacion
                        dec_op_amount;
                        scanf("%*c%d", dec_op_amount);
                        op_amount = hs + dec_op_amount / 100.0;
                        printf("Monto operacion: %8.2lf ", op*op_amount);
                        continue;
                    } else if (items_read == 0) { // EOF o CODIGO o D/R
                        m2 = getchar();
                        m3 = getchar();
                        if (m2 == EOF)
                            return 0;
                        else { // ESTO ES SI ENCUENTRA UN CODIGO O D/R
                            ungetc(m2, stdin);
                            ungetc(m3, stdin);
                            break;
                        }
                    }
                    break;
                }
                m2 = getchar(); m3 = getchar();
                if (m3 == ' '){ // Es un D/R y debe seguir este while
                    ungetc(m2, stdin);
                    ungetc(m3, stdin);
                    continue;
                } else { // Es otro CODIGO o FECHA y debemos romper este while que comienza en D/R
                    break;
                }
                
            }
            break; // solo puede ser un codigo y no debo leer fecha.
        }
    }
    
    
    
    return 0;
}


void print_line(char c, int n_times) {
    for (int i = 0; i < n_times; i++)
        putchar(c);
    putchar('\n');
}

void ignore_spaces() {
    char c;
    while((c = getchar()) == ' ')
        continue;
    ungetc(c, stdin);
}

