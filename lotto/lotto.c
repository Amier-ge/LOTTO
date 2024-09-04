//LOTTO

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void lotto_num(int *num);
void lotto_num_print(int *num);

int main() {

	int random_num[7] = {0};
	int i, j;

	lotto_num(random_num);
	lotto_num_print(random_num);

	return 0;
}

void lotto_num(int *num){

	int i, j, check_i;

	srand((unsigned int)time(NULL));

	for(i = 0 ; i < 7 ; i++){
		num[i] = (rand() % 45) + 1;
		check_i = i;
		if(i > 0){
			for(j = 0 ; j < i ; j++){
				if(num[i] == num[j]){
					i--;
					break;
				}
			}
		}

		if(check_i != i) continue;

		if(i < 6) printf("No.%d : %d\n", i+1, num[i]);
		else printf("Bonus Number : %d\n", num[i]);
	}

	printf("\n");

}

void lotto_num_print(int *num){

	int i;

	for(i = 0 ; i < 6 ; i++){
		printf("[%d] ", num[i]);
	}
	printf("<<%d>>\n", num[6]); //Bonus Num

}