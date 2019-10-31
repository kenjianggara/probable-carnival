#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct book{
	char judul [100];
	int hal;
	char penulis [100];
};
void menu()
{
	printf("MENU\n");
	printf("--------------\n");
	printf("1. Insert Buku\n");
	printf("2. Update Buku\n");
	printf("3. Delete Buku\n");
	printf("4. Search Buku\n");
	printf("5. Sort Buku\n");
	printf("6. Save Buku\n");
	printf("7. Exit\n\n");
	printf("Input[1..7] : ");
}

void readData(book buku[100], int &totalData)
{
	FILE*file;
	file=fopen("buku.txt","r");
	while(fscanf(file,"%[^,],%d,%[^\n]\n",buku[totalData].judul,&buku[totalData].hal,buku[totalData].penulis)!=EOF)
	{
		totalData++;
	}
	fclose(file);
}

void printData(book buku[100], int totalData)
{
	int deret=1;
	printf("telolet plus\n");
	printf("Book Store\n\n");

	printf("|%-3s|%-50s|%-6s|%-20s|\n","No.","Judul  Buku", "Hal", "Nama pengarang");
	printf("--------------------------------------------------------------------\n");
	
	for(int i=0;i<totalData;i++)
	{
		printf("|%-3d|%-50s|%-6d|%-20s|\n",deret,buku[i].judul,buku[i].hal,buku[i].penulis);
		deret++;
	}
}

void insertData(book buku[100],int &totalData)
{
	do{
		printf("Input Judul Buku[3-50] : ");
		scanf("%[^\n]", buku[totalData].judul);
	}while(strlen(buku[totalData].judul) <3 || strlen(buku[totalData].judul) >50);

	do{
		printf("Input Jumlah Halaman[50-500] : ");
		scanf("%d",&buku[totalData].hal);fflush(stdin);
	}while(buku[totalData].hal <50 || buku[totalData].hal >500);

	do{
		printf("Input Nama Pengarang[Mr./Mrs.] : ");
		scanf("%[^\n]", buku[totalData].penulis);
	}while(strstr(buku[totalData].penulis, "Mr.")==0 && strstr(buku[totalData].penulis, "Mrs.")!=0);

	totalData++;
}

void updateData (book  buku[100], int &totalData)
{
	int choice;
	do{
		printf("Input Angka yang ingin di Update[1 - %d]: ",totalData);
		scanf("%d", &choice);fflush(stdin);
	}while(choice<1||choice>totalData);

	choice--;

	do{
		printf("Input Judul Buku[3-50] : ");
		scanf("%[^\n]", buku[choice].judul);
	}while(strlen(buku[choice].judul) <3 || strlen(buku[choice].judul) >50);

	do{
		printf("Input Jumlah Halaman[50-500] : ");
		scanf("%d",&buku[choice].hal);fflush(stdin);
	}while(buku[choice].hal <50 || buku[choice].hal >500);

	do{
		printf("Input Nama Pengarang[Mr./Mrs.] : ");
		scanf("%[^\n]", buku[choice].penulis);
	}while(strstr(buku[choice].penulis, "Mr.")==0 && strstr(buku[choice].penulis, "Mrs.")!=0);
}

void deleteData(book buku[100], int &totalData)
{
	char temp[100];
	
	printf("Input Buku yang ingin di Hapus : ");
	scanf("%[^\n]", temp);

	for(int i=0;i<totalData;i++)
	{
		if(strcmp(temp, buku[i].judul)==0)
		{
			for(int j=i; j<totalData-1; j++)
			{
				buku[j]=buku[j+1];
			}
			strcpy(buku[totalData].judul," ");
			totalData--;
		}
	}
}

void searchData(book buku[100],int &totalData)
{
	char temp[100];
	int deret=1;

	printf("Input Judul Buku yang dicari : ");
	scanf("%[^\n]",temp);

	for(int i=0; i<totalData; i++)
	{
		if(strstr(buku[i].judul,temp)!=0)
		{
			printf("\n\n%d.\n", deret++);
			printf("Judul buku : %s\n", buku[i].judul);
			printf("Hal Buku : %d\n", buku[i].hal);
			printf("Pengarang Buku : %s\n", buku[i].penulis);
		}
	}
	getchar();
}

void sortData(book buku[100], int &totalData)
{
	int pick;
	book sort;

	printf("\n1. Sort Judul Buku By Ascending\n");
	printf("2. Sort Halaman By Descending\n");		
	printf("3. Exit\n");		
	printf("Choice[1 - 3] : ");
	scanf("%d", &pick); fflush(stdin);

	switch(pick)
	{
	case 1:
		for (int i=0;i<totalData-1;i++)
		{
			for(int j=0;j<totalData-1;j++)
			{
				if(strcmp(buku[j].judul,buku[j+1].judul)<0)
				{
					sort=buku[j];
					buku[j]=buku[j+1];
					buku[j+1]=sort;
				}
			}
		}
		break;
	case 2:
		for (int i=0;i<totalData-1;i++)
		{
			for(int j=0;j<totalData-1;j++)
			{
				if(buku[j].hal>buku[j+1].hal)
				{
					sort = buku[j];
					buku[j] = buku[j+1];
					buku[j+1] = sort;
				}
			}
		}
		break;
	}
}

void saveData(book buku[100], int &totalData)
{
	FILE*file;
	file = fopen("buku.txt","w");
	for(int i=0;i<totalData;i++)
	{
		fprintf(file,"%s,%d,%s\n",buku[i].judul,buku[i].hal,buku[i].penulis);
	}
	fclose(file);
}

int main()
{
	book buku[100];
	int totalData=0;
	int pick;

	readData(buku, totalData);
	
	do{
		system("cls");
		printData(buku, totalData);
		menu();
		scanf("%d",&pick);fflush(stdin);
		
		switch (pick)
		{
		case 1:
			insertData(buku,totalData);
			break;
		case 2:
			updateData(buku,totalData);
			break;
		case 3:
			deleteData(buku,totalData);
			break;
		case 4:
			searchData(buku,totalData);
			break;
		case 5:
			sortData(buku,totalData);
			break;
		case 6:
			saveData(buku,totalData);
			break;
		}
	}while (pick!=7);

	getchar();
	return 0;
}