#include <stdio.h>

void move(char pos1, char pos2){
    printf(" %c -> %c ", pos1, pos2);
}
void Hanoi(int n, char pos1, char pos2, char pos3){
    //n : how many boards
    //pos1: start position
    //pos2: tmp postion
    //pos3: final position

    //there are 3 case
    if(n == 1){
        move(pos1, pos3);//base case
    }
    else{
        Hanoi(n - 1,pos1, pos3, pos2);
        move(pos1, pos3);
        Hanoi(n - 1, pos2, pos1, pos3);
    }

}


int main(){

    Hanoi(1, 'A', 'B', 'C');
    printf("\n");
    Hanoi(2, 'A', 'B', 'C');
    printf("\n");
    Hanoi(3, 'A', 'B', 'C');

    printf("\n");
    Hanoi(10, 'A', 'B', 'C');







    return 0;
}
