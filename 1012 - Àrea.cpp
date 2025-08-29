#include <stdio.h>
 
int main() {
    double a, b, c, alt, base, aT, aC, aTrap, aQ, aR, pi, r, bTrap;
    printf("insira o valor de A: ");
    scanf("%lf", &a);
    printf("insira o valor de B: ");
    scanf("%lf", &b);
    printf("insira o valor de C: ");
    scanf("%lf", &c);
    
    bTrap = a+b;
    r = c*c;
    pi = 3.14159;
    
	aT = (a * c)/2;
	aC = pi * r;
	aTrap = (bTrap * c)/2;
	aQ = b*b;
	aR = a*b;
	
	printf("TRIANGULO: %.3lf\n",aT);
	printf("CIRCULO: %.3lf\n",aC);
	printf("TRAPEZIO: %.3lf\n",aTrap);
	printf("QUADRADO: %.3lf\n",aQ);
	printf("RETANGULO: %.3lf\n",aR);
    return 0;
}
