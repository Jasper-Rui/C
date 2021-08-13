#include <stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr[n][m];
    int i = 0;
    int input;
    for(i = 0; i < n ; i++){
        int j = 0;
        for(j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    int arr2[m][n];

    for(i = 0; i < m ; i++){
        int j = 0;
        for(j = 0; j < n; j++){
            arr2[i][j] = arr[j][i];
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    
    
    /*
    for(i = 0; i < m; i++){
        int j = 0;
        for(j = 0; j < n; j++){
            arr2[i][j] = tmp[i + j];
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}