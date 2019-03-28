#include <stdio.h>
#include <stdlib.h>

using namespace std;

void ignore_spaces();
void print_line(char, int);

int main(int argc, char** argv) {
    
    char m, code_char, client_code[7];
    char lastname1[20], lastname2[20], names[25];
    double mount;
    
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
        scanf("%lf", &mount);
        printf("%10.2lf", mount);
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

