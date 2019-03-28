#include <stdio.h>
#include <stdlib.h>

using namespace std;

void ignore_spaces();
void print_line(char, int);

int main(int argc, char** argv) {
    
    char m, m1, code_char, client_code[7];
    char lastname1[20], lastname2[20], names[25];
    double amount;
    int a, b, c, items_read; // los uso para fecha u hora
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
        
        
        // Leer fecha y todo lo demas
        while (1) {
            putchar(' ');
            m = getchar();
            if ( m == EOF) return 0;
            else ungetc(m, stdin);
            
            items_read = scanf("%d%*c%d%*c%d%*c", &a, &b, &c);
            if (items_read == 3) { // es fecha u hora
                if (c < 100) 
                    printf("Es una hora: %02d-%02d-%02d", a, b, c);
                else
                    printf("Es una fecha: %02d-%02d-%04d", a, b, c);
            }
            else if (items_read == 0) { // Puede ser un codigo o D/R
                m = getchar(); m1 = getchar();
                if (m1 == ' ') { // es D(op = +1) o R(op = -1)
                    op = (m == 'D' ? 1 : -1); 
                    printf("%d", op);
                }
                else { // es un código
                    ungetc(m, stdin);
                    ungetc(m1, stdin);
                    break;
                }
            } else { // es un monto a retirar o depositar
                printf("MONTO!");
                scanf("%d", &dec_op_amount);
                printf("Es un monto a retirar o depositar: %d.%d", a*op, dec_op_amount);
            }
            printf("\n");
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

