#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int N = 6, M = 6;
int summa( int index_row, int index_col, int arr[N][M])
{
        int temp_sum;
    temp_sum = arr[index_row][index_col] + arr[index_row][index_col-1] + arr[index_row][index_col + 1] + arr[index_row + 1][index_col] + arr[index_row + 2][index_col] + arr[index_row  + 2][index_col-1] + arr[index_row + 2][index_col + 1];
    return temp_sum;
}


int main(){
	int arr_i, arr_j;
	int arr[6][6];
	int j;
	int max;
    int index_row,index_col;
    int sum[16];
    int i = 0;
    for( arr_i = 0; arr_i < 6; arr_i++){
       for(arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    for(index_row = 0;index_row <= 3;index_row++){
       for(index_col = 1;index_col < 5;index_col++){
         sum[i] = summa(index_row, index_col, arr);
           i++;
       }
    }
	max = sum[0];
	for (j = 0;j < 16;j++) {
		if(sum[j] > max) {
			max = sum[j];
		}
	
	}
	printf("%d",max);
    return 0;
}


