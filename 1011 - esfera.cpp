#include <stdio.h>
 
int main() {
    double volume, raio, r, pi;
    
    printf("Insira o valor do raio: ");
    scanf("%lf", &r);
    raio = r*r*r;
    pi = 3.14159;
    volume = (4/3.0) * pi * raio;
    printf("VOLUME = %.3lf\n", volume);
    return 0;
}
