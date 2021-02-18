#include <stdio.h>
#define HIGH 25
#define WEIGHT 50

char tableA[HIGH][WEIGHT];
char tableB[HIGH][WEIGHT];
void makeTable(){
	int i,j;
	for(i = 0 ; i<HIGH ; i++){
		for(j = 0 ; j<WEIGHT ; j++){
			tableA[i][j] = '-';
		}
	}
}

void makeTableB(){
	int i,j;
	for(i = 0 ; i<HIGH ; i++){
		for(j = 0 ; j<WEIGHT ; j++){
			tableB[i][j] = '-';
		}
	}
}
void printTable(){
	int i,j;
	for(i = 0 ; i<HIGH ; i++){
		for(j = 0 ; j<WEIGHT ; j++){
			printf("%c", tableA[i][j]);
		}
		printf("\n");
	}
}

void add(){
	int c, h, w;
	do{
		//system("cls");
		printf("Hucre eklemek istiyorsaniz 1, cikmak istiyorsaniz 0 giriniz");
		scanf("%d", &c);
		switch(c){
			case 1:
				printf("girmek istediginiz hucrenin ilk once yukseklik sonra genislik degerini giriniz");
				scanf("%d", &h);
				scanf("%d", &w);
				tableA[h][w] = 'X';
				break;
			case 0:
				printf("cikiliyor..\n");
				break;
			default:
				printf("yanlis deger girdiniz");
				break;
		}
		
	}while(c != 0);
}

int neighbours(int h , int w){
	
	int neighbours = 0;
	
	if(tableA[h-1][w-1] == 'X'){
		neighbours++;
	}
	if(tableA[h-1][w] == 'X'){
		neighbours++;
	}
	if(tableA[h-1][w+1] == 'X'){
		neighbours++;
	}
	if(tableA[h][w-1] == 'X'){
		neighbours++;
	}
	if(tableA[h][w+1] == 'X'){
		neighbours++;
	}
	if(tableA[h+1][w-1] == 'X'){
		neighbours++;
	}
	if(tableA[h+1][w] == 'X'){
		neighbours++;
	}
	if(tableA[h+1][w+1] == 'X'){
		neighbours++;
	}
	
	return neighbours;
}

void control(){
	int i,j, neighbour;
	for(i = 0 ; i<HIGH ; i++){
		for(j = 0 ; j<WEIGHT ; j++){
			neighbour = neighbours(i,j);
			if(tableA[i][j] == 'X'){
			
				if(neighbour < 2){
					tableB[i][j] = '-';
				}else if(neighbour == 2 || neighbour == 3){
					tableB[i][j] = 'X';
				}else{
					tableB[i][j] = '-';
				}
			}else{
				
				if(neighbour == 3){
					tableB[i][j] = 'X';
				}
			}
			
			
		}
		
	}
	for(i = 0 ; i<HIGH ; i++){
		for(j = 0 ; j<WEIGHT ; j++){
			tableA[i][j] = tableB[i][j];
		}
	}
}

int main(){
	int c = 1;
	makeTable();
	makeTableB();
	/*tableA[2][3] = 'X';
	tableA[3][4] = 'X';
	tableA[4][2] = 'X';
	tableA[4][3] = 'X';
	tableA[4][4] = 'X';*/
	/*tableA[3][4] = 'X';
	tableA[3][5] = 'X';
	tableA[3][6] = 'X';*/
	tableA[11][24] = 'X';
	tableA[12][23] = 'X';
	tableA[12][24] = 'X';
	tableA[12][25] = 'X';
	//printf("%d", neighbours(0,4));
	//add();
	printTable();
	printf("\n");
	while(c == 1){
	
		control();
		printTable();
		printf("devam etmek istiyorsan 1, cikmak istiyorsan 0");
		scanf("%d", &c);
	}
}










