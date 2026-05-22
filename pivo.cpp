/*
	Name: pivo.cpp
	Date: 22/05/26 17:08
	Description: 
*/
#include <stdio.h>
//main(){
//	int n1=0, n2=0, n3=0;
//	
//	scanf("%d", &n1);
//	scanf("%d", &n2);
//	scanf("%d", &n3);
//	
//	if(n1 >= n2 && n1<= n3)
//		printf("%d", n1);
//		
//	else if(n2 >= n1 && n1<= n3)
//		printf("%d", n3);
//		
//	else if(n2 >= n1 && n2 <= n3)
//		printf("%d", n2);
//	
//}

#include <stdio.h>

int main(){
    int n1=0, n2=0, n3=0;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    // Para o n1 ser o do meio, ele tem que estar entre n2 e n3 (em qualquer ordem)
    if((n1 >= n2 && n1 <= n3) || (n1 >= n3 && n1 <= n2))
    {
        printf("%d\n", n1);
    }
    // Para o n2 ser o do meio, ele tem que estar entre n1 e n3 (em qualquer ordem)
    else if((n2 >= n1 && n2 <= n3) || (n2 >= n3 && n2 <= n1))
    {
        printf("%d\n", n2);
    }
    // Se não for o n1 e nem o n2, com certeza o do meio é o n3
    else 
    {
        printf("%d\n", n3);
    }

    return 0;
}
