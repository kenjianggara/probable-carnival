#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
	char nama[100];
	char nim[50];
	float harta;

	struct data* next;
	struct data* prev;
}*head, *tail, *curr;

void inputdata (char nama[], char nim[], float harta)
{
	curr=(struct data*)malloc(sizeof(struct data*));
	strcpy(curr->nama, nama);
	strcpy(curr->nim, nim);
	curr->harta=harta;

	head->next=head->prev=NULL;
	tail->next=tail->prev=NULL;
}

void printdata()
{
	int no;
	if(head==NULL)
	{
		printf("Antrian Kosong!!\n");
	}
	else
	{
		printf("==============================================\n");
	}
}

void pushhead()
{
	curr->next=head;
	head->prev=curr;
	curr=head;
}

void pushtail()
{
	curr->prev=tail;
	tail->next=curr;
	curr=tail;
}

void menu()
{
	char nama[100];
	char nim[50];
	float harta;
	int pilih;
	do{
		printf("\nMenu\n");
		printf("=====\n");
		printf("1. Ambil antrian\n");
		printf("2. Panggil antrian\n");
		printf("3. Hapus semua antrian\n");
		printf("4. Exit\n");
		printf("Choice: ");
		scanf("%d", &pilih);fflush(stdin);
		
		if(pilih==1)
		{
			do{
				printf("Input Nama: ");
				scanf("%[^\n]", nama);fflush(stdin);
			}while(strlen(curr->nama)>=5 && strlen(curr->nama)<=50);
			
			do{
				printf("Input Nim: ");
				scanf("%[^\n]", nim);fflush(stdin);
			}while(strlen(curr->nim)==10);
			
			do{
				printf("Input Harta: ");
				scanf("%.f", &harta);fflush(stdin);
			}while(curr->harta>=10000 && curr->harta<=1000000000);

			printf("[^\n] ditambahkan ke antrian", curr->nama);
		}
		if(pilih==2)
		{
			printf("pilihan 2");
		}
		if(pilih==3)
		{
			printf("pilihan 3");		
		}
		if(pilih==4)
		{
			printf("Terimakasih!!");
		}
	}while(pilih!=4);
}
int main()
{
	printdata();
	menu();

	getchar();
	return 0;
}