#include <stdio.h>
 
int main() {
	
	float N, auxiliar_moedas, verificador_N_menos1;
	int nota_100, nota_50, nota_20, nota_10, nota_5, nota_2, auxiliar_N, nota_100_real, moeda_1_real, moeda_50cents, moeda_25cents, moeda_10cents, moeda_5cents, moeda_1cent, auxiliar_real_moedas, auxiliar_N_menos1;
	scanf("%f", &N);
	if (N>= 0 && N <=1000000.00)
	{
	auxiliar_N = N;
	auxiliar_moedas = (N - auxiliar_N)*100;
	auxiliar_N_menos1 = auxiliar_moedas;
	verificador_N_menos1 = auxiliar_moedas - auxiliar_N_menos1;
	auxiliar_real_moedas = auxiliar_moedas;
	if (verificador_N_menos1 >= 0.8){
		auxiliar_real_moedas += 1;
	}
	nota_100_real = (auxiliar_N / 100);
	nota_100 = (auxiliar_N % 100);
	nota_50 = nota_100 / 50;
	nota_20 = (nota_100 % 50) / 20;
	nota_10 = ((nota_100 % 50) % 20) / 10;
	nota_5 = (((nota_100 % 50) % 20) % 10) / 5;
	nota_2 = (((((nota_100 % 50) % 20) % 10)) % 5)/2;
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", nota_100_real);
	printf("%d nota(s) de R$ 50.00\n", nota_50);
	printf("%d nota(s) de R$ 20.00\n", nota_20);
	printf("%d nota(s) de R$ 10.00\n", nota_10);
	printf("%d nota(s) de R$ 5.00\n", nota_5);
	printf("%d nota(s) de R$ 2.00\n", nota_2);
	printf("MOEDAS:\n");
	moeda_1_real = (((((nota_100 % 50) % 20) % 10)) % 5)%2;
	moeda_50cents = (auxiliar_real_moedas / 50);
	moeda_25cents = (auxiliar_real_moedas % 50) / 25;
	moeda_10cents = ((auxiliar_real_moedas % 50) % 25) / 10;
	moeda_5cents = (((auxiliar_real_moedas % 50) % 25) % 10) / 5;
	moeda_1cent = ((((auxiliar_real_moedas % 50) % 25) % 10) % 5);
	printf("%d moeda(s) de R$ 1.00\n", moeda_1_real);
	printf("%d moeda(s) de R$ 0.50\n", moeda_50cents);
	printf("%d moeda(s) de R$ 0.25\n", moeda_25cents);
	printf("%d moeda(s) de R$ 0.10\n", moeda_10cents);
	printf("%d moeda(s) de R$ 0.05\n", moeda_5cents);
	printf("%d moeda(s) de R$ 0.01\n", moeda_1cent);
	}
	
    return 0;
}
