#include <bits/stdc++.h>

using namespace std;

// communist variablse
    int Row,
        Column,
        MAXN;

void init(int **&matrix)
{
	int i,j,k;
	for(i=0; i<Row; i++)
		for(j=0; j<Column; j++) {
			k=i*Column+j;
			matrix[k][k]=1;
			if (i>0)
                matrix[(i-1)*Column+j][k] = 1;
			if (i<Row-1)
                matrix[(i+1)*Column+j][k] = 1;
			if (j>0)
                matrix[i*Column+j-1][k] = 1;
			if (j<Column-1)
                matrix[i*Column+j+1][k] = 1;
		}
}

int  Gauss(int **(&matrix))
{
	int i,j,k,x,y=0,rand_coefficient,rand_matrix,rank1,rank2,inc=0;
	for(k=0; k < MAXN && y < MAXN; k++, y++) {
		x=k;
		for(i=k+1; i<MAXN; i++)
			if(matrix[i][y]>matrix[x][y])
                x=i;
		if(x-k)
			for(j=y; j<MAXN+1; j++) {
				matrix[k][j]=matrix[k][j]^matrix[x][j];
				matrix[x][j]=matrix[k][j]^matrix[x][j];
				matrix[k][j]=matrix[k][j]^matrix[x][j];
			}
		if (matrix[k][y]==0) {
			k--;
			continue;
		}
		for(i=k+1; i<MAXN; i++)
			if(matrix[i][y])
				for(j=y; j<MAXN+1; j++)
					matrix[i][j]^=matrix[k][j];
	}
	for(rand_coefficient=rand_matrix=i=0; i<MAXN; i++) {
		for(rank1=rank2=j=0; j<=MAXN; j++) 
			if(j<MAXN)rank1|=matrix[i][j];
				rank2|=matrix[i][j];
		rand_coefficient+=rank1;
		rand_matrix+=rank2;
	}
	if (rand_coefficient < rand_matrix)
		return -1;
    int ou = INT_MAX, solution[MAXN+2];
	for(k = 1 << (MAXN-rand_coefficient); k > 0; k--) {
        inc = 0;
		for(i=MAXN-1; i>rand_coefficient; i--) {
			matrix[i-1][MAXN]+=matrix[i][MAXN]>>1;
			matrix[i][MAXN]&=1;
		}
		for(i=0; i<MAXN; i++)
            solution[i]=matrix[i][MAXN];
		for(i=MAXN-1; i>=0; i--)
			for(j=i-1; j>=0; j--)
				if(matrix[j][i])solution[j]^=solution[i];
		for(i=0; i<MAXN; i++)
			if (solution[i])
		        inc++;
		matrix[MAXN-1][MAXN]++;
        ou = min(ou, inc);
	}
    if (ou > 100)
        return -1;
    return ou;
}

int main(void)
{
    string s;
    Row = Column = 5;
    MAXN = Column * Row;
  	while (cin >> s && s != "end") {
        int i; char C;

        int **matrix = new int*[MAXN+4]; 
        for(i = 0; i < MAXN + 4; i++)
            matrix[i] = new int [MAXN+4];

		memset(*matrix, 0, sizeof(*matrix)); init(matrix);

        for(i = 0; i < MAXN && cin >> C; i++)
            matrix[i][MAXN] = (C == '#') ? 0 : 1;
        cout << s << " " << Gauss(matrix) << "\n";
    }
}