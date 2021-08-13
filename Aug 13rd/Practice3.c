#include <stdio.h>
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int arr[n*2][m];
    int i = 0;
    int input;
    for(i = 0; i < n * 2; i++){
        int j = 0;
        for(j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(i = 0; i < n; i++){
            int j = 0;
            for(j = 0; j < m; j++){
                if(arr[i][j] != arr[i + n][j]){
                    printf("No\n");
                    return 0;
                }
            }
        }
        
    printf("Yes\n");
    return 0;
}