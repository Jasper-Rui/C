#include <stdio.h>

int count_diff_bit(int a, int b){
    int count = 0;
    for(int i = 0; i < 32; i++){
        if(((a >> i) & 1) != ((b >> i ) & 1)){
            count ++;
        }
    }
    return count;
}




int main()
{
    int n1 = 0;
    int n2 = 0;
    scanf("%d%d", &n1, &n2);
    int result = count_diff_bit(n1, n2);
    printf("There are %d different bits", result);
    return 0;
}
