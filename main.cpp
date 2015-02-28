#include <stdio.h>
#include <vector>

#define NX 10
#define NY 10

typedef struct _coord {
    int x,y;
} coord;

struct cell {
    char IsLand;
    char Color;
    char TypeStr;
/* 0 - empty
 * 1 - house
 * 2 - human
 * 3 - tree
 * 4 - tower
 */
    char IsActive; //for human
    int SubTypStr;
/* house: money
 * human: 1,2,3,4
 * tree: 1 - fir-tree, 2 - palm
 * tower: 1
 */
} map[NX][NY];

int Neighbours(int x0,int y0,coord *Neigs){ // Neighbours of point(x0,y0)
    int x,y;
    int n=0;
    coord p;
    for(int i=0;i<=5;i++){
        //x=x0+((i%3)-1);
        //y=y0+(0);
        x=x0+((i%3==0)?1:((i%3==1)?-1:0));
        y=y0+((i<2)?0:((i<5)?1:-1))+((((i==3)||(i==4))&&(x0%2))?-2:0);
        if(map[x][y].IsLand && (1<=x) && (x<=NX) && (1<=y) && (y<=NY)){
            n++;
            p.x=x;
            p.y=y;
            Neigs[n-1]=p;
        }
    }
    return n;
}

int main(){
    /*
    coord Neis[6];
    int n;
    
    n=Neighbours(3,2,Neis);
    
    printf("%i\n",n);
    
    for(int i=0;i<n;i++)
        printf("%i %i\n",Neis[i].x,Neis[i].y);
    
    */
    
    return 0;
}

//ortohonal coordinates
//first line starts from corner, x from lef to right, y from bottom to top
