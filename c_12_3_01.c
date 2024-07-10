#include <stdio.h>

int maze [5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0
};


struct point{
    int x, y;
    struct point pre_point;
}; 
struct point path[25];
struct point excur[4] = {[0] = {.x = -1, }, [1] = {.y = -1, }, [2] = {.x = 1, }, [3] = {.y = 1, }};

int top = 0;

void push(struct point pox)
{
    path[top++] = pox;
}

struct point pop(void)
{
    return path[--top];
}

int is_empt(void)
{
    return top == 0;
}



struct point excursion_point(struct point pox, int excur_x, int excur_y)
{
    struct point excur_pox;
    if(pox.x + excur_x >= 0 && coor.x + excur_x <= 4 && pox.y + excur_y >=0 && pox.y + excur_y <= 4) {
        excur_pox.x = pox.x + excur_x;
        excur_pox.y = pox.y + excur_y;
        excur_pox.pre_point = pox;
    }
    else {
        excur_pox.x = -1;
        excur_pox.y = -1;
        excur_pox.pre_point = pox; 
    } 

    return excur_pox;
}

int printf_maze(void)
{
    int j, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ", maze [i][j]);
        }
        printf("\n");
    }
    printf("**********\n")
    return 0;
}

int print_path(struct point pox)
{
    if (pox.x == -1 || pox.y == -1) {
        printf("\n");
        return 0;
    }else {
        printf("(%d, %d)", pox.x, pox.y);
        printf_path(pox.pre_point);
        return 0;
    }
}

int main(void)
{
    struct point init_pox = {0, 0, {-1, -1}}, judge_pox;
    push(init_pox);

    while (!is_empt()) {
        judge_pox = pop();
        if (judge_pox.x == 4 && judge_pox.y == 4) break;
        else {
            int i;
            for (i = 0; i < 4; i++) {
                struct point excur_judge_pox = excursion_point(judge_pox, excur[i].x, excur[i].y);
                if(!(excur_judge_pox.x == -1) && maze[excur_judge_pox.x][excur_judge_pox.y] == 0) { 
                    push(judge_pox);
                    excur_judge_pox.pre_poin = judge_pox;
                    push(excur_judge_pox);
                    maze [excur_judge_pox.x][excur_judge_pox.y] = 2;
                    break;
                }
            }
        }
    }
    if (judge_pox.x == 4 && judge_pox.y == 4) printf("successful!\n");
    else printf("fauilt!\n");

    return 0;
}

