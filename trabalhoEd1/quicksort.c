


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define MAX 10000
#define MIN -10000

double getTempo(){
	struct timeval t;
	gettimeofday(&t,0);
	return t.tv_sec + t.tv_usec/1e6;
}

void swap(int *nums,int actual,int newPos){
	int temp = nums[actual];
	nums[actual] = nums[newPos];
	nums[newPos] = temp;
}
int partition(int *arr,int left,int right){
	int pivot = arr[left],

	i = left,	//variavel auxiliar que percorre o array da esquerda para a direita
	j= right;// variavel auxiliar que percorre o array da direita pra esquerda
	while(1){
		while(arr[i] <= pivot && i<=j)i++; //enquanto o valor lido for menor que o do pivo percorre pela direta
		while(arr[j]>pivot && j>=i)j--;//enquanto o valor lido for maior que o do pivo percorre pela esquerda
		if(i>=j) break;// se a esquerda encontrou ou passou a direita para o loop
		swap(arr,i,j);// troca valor maior com o valor menor
		i++;
		j--;
	}

	swap(arr,i-1,left); //troca pivo com o valor a esquerda da variavel auxiliar i

	return i-1;// retorna posicao final do pivo
}

int wallPartition(int *arr,int left,int right){//left eh a posicao da parede e direita vai ser a variavel q percorre o vetor
	int pivot = arr[left];
	int wall = right;
	int current;
	for(current=right;current>left;current--){
		if(arr[current] >= pivot){
			swap(arr,current,wall);
			wall--;
		}	
	}
	swap(arr,wall,left); //pivo eh colocado na posicao correta
	return wall;

}

int randomizedPartition(int *arr,int left,int right){
	int pivot = left + rand()%(right - left +1);
	swap(arr,pivot,left);
	return partition(arr,left,right);
}

void quicksort(int *arr,int left,int right){
	if(left<right){
		int pivot = partition(arr,left,right);//pega posicao final do pivo
		quicksort(arr,left,pivot -1);// aplica o quick sort a esquerda do pivo de forma recursiva
		quicksort(arr,pivot + 1,right);// aplica o quick sort a direita do pivo de forma recursiva
	}
}


void randomizedQuickSort(int *arr,int left,int right){
	if(left<right){
		int pivot = randomizedPartition(arr,left,right);
		randomizedQuickSort(arr,left,pivot -1);
		randomizedQuickSort(arr,pivot +1,right);
	}
}

int* geraArrayAleatorio(int tamanho){
	int *arrayAleatorio;
	
	int aux = posix_memalign((void**)&arrayAleatorio,64,tamanho*sizeof(int));
	int i;
	for(i=0;i<tamanho;i++){
		arrayAleatorio[i] = (rand()%(MAX-MIN)+MIN);
	}
    return arrayAleatorio;

}



int main(){
	srand(time(NULL));
	int n = 10;
	double t1,t2,tempoExec;
	FILE *saida = fopen("saidaQuick.txt","a+");
	for(n;n<20;n++){
		int tam = pow(2,n)/sizeof(int);
		int * nums;

		nums = geraArrayAleatorio(tam);
		t1 = getTempo();
		quicksort(nums,0,tam-1);
		t2 =getTempo();
   		tempoExec = (t2 - t1);
		fprintf(saida,"TAMANHO: %d TEMPO: %lf\n",tam,tempoExec);
		free(nums);

	}

	return 0;
}