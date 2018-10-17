#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#define TRUE 1

//Hanif Rachmadani - 1606870774
//Ahmad Aufar - 

//Ticketing App ver 2 - 17/10/18

void mainmenu(), listFilm(), listJadwal(), readFilm(), readJadwal(), seating(), summary();

int i, chinput, j; //Counter & Misc.
int filmpil, jadwalpil, jumlahtiket; //Kode Film, Jadwal, Jumlah Tiket yang dipilih

int main()
{
	char Film[4][40], Jadwal[4][4][10]; 
	
	system("color 0f");
//	SetColor(15);
	
	readFilm(Film);
	readJadwal(Jadwal);
		

	while(TRUE)
	{
	
		mainmenu();
		
		listFilm(Film,Jadwal);
		listJadwal(filmpil,Film,Jadwal);
		
		printf("\n\n  Berapa Jumlah Tiket yang Diinginkan? : ");
		scanf("%d", &jumlahtiket);
		
		char seat[jumlahtiket][3];
		
		seating(seat, jumlahtiket);
		system("cls");
		
		summary(seat,Film,Jadwal,filmpil,jadwalpil,jumlahtiket);
	}
		return 0;	
}

void mainmenu()
{

	int pilihan = 1, tipe = 0;
	menudisp(pilihan, tipe);	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilihan)
				{
					case 1 : 
						return ; break;
					case 2 : 
						tipe = 1;
						menudisp(pilihan, tipe);
						break;
					case 3 : 
						exit(0); break;
				}
				break;
			case 80 :
				pilihan++;
				if(pilihan == 4){ pilihan = 1;}
				menudisp(pilihan, tipe);
				break;
			case 72 :
				pilihan--;
				if(pilihan == 0){ pilihan = 3;}
				menudisp(pilihan, tipe);
				break;
			default : 
				menudisp(pilihan, tipe);
				fflush(stdin);
				break;
		}
	}
}

void listFilm(char judul[4][40] ,char jadwal[][4][10])
{
	int pilihan = 1;
	
	listdisp(pilihan,judul,jadwal);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilihan)
				{
					case 1 :
						filmpil = pilihan;
						return;
						break;
					case 2 :
						filmpil = pilihan;
						return;
						break;
					case 3 :
						filmpil = pilihan;
						return;
						break;
					case 4 :
						filmpil = pilihan;
						return;
						break;
				}
				break;
			case 80 :
				pilihan++;
				if(pilihan == 5){ pilihan = 1;}
				listdisp(pilihan,judul,jadwal);
				break;
			case 72 :
				pilihan--;
				if(pilihan == 0){ pilihan = 4;}
				listdisp(pilihan,judul,jadwal);
				break;
			default :
				listdisp(pilihan,judul,jadwal);
				fflush(stdin);
				break;
		}
	}
}

void listJadwal(int filmpil ,char judul[][40] ,char jadwal[][4][10])
{
	int pilhrzntl = 1, tipe = 0;
	
	jadwaldisp(filmpil,pilhrzntl,judul,jadwal);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilhrzntl)
				{
					case 1 :
						jadwalpil = pilhrzntl;
						return;
						break;
					case 2 :
						jadwalpil = pilhrzntl;
						return;
						break;
					case 3 :
						jadwalpil = pilhrzntl;;
						return;
						break;
					case 4 :
						jadwalpil = pilhrzntl;
						return;
						break;
				}
				break;
	
			case 77 :
				pilhrzntl++;
				if(pilhrzntl == 5){ pilhrzntl = 1;}
				jadwaldisp(filmpil,pilhrzntl,judul,jadwal);
				break;
			case 75 :
				pilhrzntl--;
				if(pilhrzntl == 0){ pilhrzntl = 4;}
				jadwaldisp(filmpil,pilhrzntl,judul,jadwal);
				break;
			default :
				jadwaldisp(filmpil,pilhrzntl,judul,jadwal);
				fflush(stdin);
				break;
		}
	}
}

void seating(char input[][3], int jumlahtiket)
{	
	int theater;
	srand(time(NULL));
	theater = rand() % 2;
	seatingdisp(theater);
	
	for(i=0;i<jumlahtiket;i++)
	{
		seatingdisp(theater);
		printf("\n\n  Silakan Pilih Kursi ke %d : ", i+1);
		scanf(" %[^\n]s", &input[i]);
	}
}

void summary(char seat[][3], char judul[][40] ,char jadwal[][4][10] ,int filmpil ,int jadwalpil ,int jumlahtiket)
{
	int pilihan = 1;
	
	summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
	
	while((chinput = getch()) != 27)
	{
		switch(chinput)
		{
			case 13 :
				switch(pilihan)
				{
					case 1 : 
						fflush(stdin);
						fflush(stdout);
						return ; break;
					case 2 : 
						exit(0); break;
				}
				break;
			case 77 :
				pilihan++;
				if(pilihan == 3){ pilihan = 1;}
				summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
				break;
			case 75 :
				pilihan--;
				if(pilihan == 0){ pilihan = 2;}
				summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
				break;
			default : 
				summarydisp(pilihan, judul,jadwal,seat,filmpil,jadwalpil,jumlahtiket);
				fflush(stdin);
				break;
		}
	}
}

void readFilm(char input[][40])
{
	int i= 0;
	FILE *ptrfile;
	
	ptrfile = fopen("ListFilm.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(input[i], 40, ptrfile) != NULL)
		{
			input[i][strcspn(input[i], "\n")] = 0;
			i++;
		}
	}	
	fclose(ptrfile);
}

void readJadwal(char input[][4][10])
{
	i= 0;
	FILE *ptrfile;
	char temp[4][40];
	
	ptrfile = fopen("Jadwal.txt","r");

	while(!feof(ptrfile))
	{
		if(fgets(temp[i], 40, ptrfile) != NULL)
		{
			temp[i][strcspn(temp[i], "\n")] = 0;
			i++;
		}
	}	
	fclose(ptrfile);
	
	for(i=0;i<4;i++)
	{
		j = 0;
		sscanf(temp[i], "%s %s %s %s", &input[i][j], &input[i][j+1], &input[i][j+2], &input[i][j+3]);
	}
}



