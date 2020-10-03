#include <stdio.h>
#define rangee 3
#define colonne 3
#define carre 3
void AdditionMat(int a[rangee][colonne],int b[rangee][colonne]);
void MultiMat(int a[rangee][colonne],int b[rangee][colonne]);
int main(int argc, char **argv)
{
	int a[carre][carre]={{1,1,1},{1,1,1},{1,1,1}};
	int b[carre][carre]={{2,2,2},{2,2,2},{2,2,2}};
	AdditionMat(a,b);
	int f[carre][carre]={{1,2,3},{4,5,6},{7,8,9}};
	int g[carre][carre]={{1,2,3},{4,5,6},{7,8,9}};
	MultiMat(f,g);
	return 0;
}
void AdditionMat(int a[rangee][colonne],int b[rangee][colonne]){
	int c [rangee][colonne];
	for(int i=0;i<carre;i++){
		for(int j=0;j<carre;j++){
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
}
void MultiMat(int a[carre][carre],int b[carre][carre]){
	int temp=0;
	int c[carre][carre];
	for (int i=0; i < 3; i++)
	{
		for (int j=0; j < 3; j++) {
			for (int k=0; k < 3; k++) {
				temp += a[i][k]*b[k][j];
			}
			c[i][j] = temp;
			temp = 0;
		}
	}
	for(int i=0;i<carre;i++){
		printf("|");
		for(int j=0;j<carre;j++){
			printf(" %d",c[i][j]);
		}
		printf("|\n");
	}
}
