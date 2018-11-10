#include <stdio.h>
#define SIZE 9 //kich thuoc o sudoku la SIZE x SIZE

int n = SIZE;

int Nhap(); //nhap de bai sudoku
int Xuat(); //xuat bang sudoku
int isOK(int i, int j, int x); //kiem tra xem vi tri i, j dat gia tri x co hop le khong


int main()
{
	printf("Nhap so lieu de bai...");
	Nhap();
	printf("De bai:");
	Xuat();
	printf("Bam enter de bat dau giai...");
	getchar();

	return 0;
}

int Nhap()
{
	int i, j, tmp;
	FILE *fp = NULL;
	fp = fopen("input", "r");
	for (i = 0; i < n; i++)
	{
		//printf("Nhap %d so hang thu %d, o nao trong thi nhap 0:n", n, i+1);
		for (j = 0; j < n; j++)
		{
			//scanf("%d", &tmp);
			fscanf(fp, "%d", &tmp);
			a[i][j] = tmp;
		}
	}
	fclose(fp);
	return 0;
}

int Xuat()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %d", a[i][j]);
		printf("n");
	}
	return 0;
}



int isOK(int i, int j, int x)
{
	int k, t;
	int tmpX, tmpY;
	//kiem tra hang thu i da co cai nao trung chua
	for (k = 0; k < n; k++)
		if (a[i][k] == x)
			return 0;
	//kiem tra cot thu j da co cai nao trung chua
	for (k = 0; k < n; k++)
		if (a[k][j] == x)
			return 0;

	//kiem tra trong o 3x3
	tmpX = i % 3; tmpY = j % 3;
	for (k = i - tmpX; k <= i - tmpX + 2; k++)
		for (t = j - tmpY; t <= j - tmpY + 2; t++)
			if (a[k][t] == x)
				return 0;
	return 1;
}

