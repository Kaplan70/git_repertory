#include <stdio.h>

int maze [5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0
};


struct coordinate {
    int x, y, exist;
};
struct coordinate path[25];
struct coordinate excur[4] = {[0] = {.x = -1, }, [1] = {.y = -1, }, [2] = {.x = 1, }, [3] = {.y = 1, }};

int top = 0;

void push(struct coordinate pox)
{
    path[top++] = pox;
}

struct coordinate pop(void)
{
    return path[--top];
}

int is_empt(void)
{
    return top == 0;
}



struct coordinate excursion_coor(struct coordinate coor, int excur_x, int excur_y, int able_exist)
{
    struct coordinate excur_coor;
    if(coor.x + excur_x >= 0 && coor.x + excur_x <= 4 && coor.y + excur_y >=0 && coor.y + excur_y <= 4) {
        excur_coor.x = coor.x + excur_x;
        excur_coor.y = coor.y + excur_y;
        excur_coor.exist = able_exist;
    }
    else {
        excur_coor.x = -1;
        excur_coor.y = -1;
        excur_coor.exist = 0; 
    } 

    return excur_coor;
}


int main(void)
{
    struct coordinate init_pox = {0, 0, 1}, judge_pox;
    push(init_pox);

    while (!is_empt()) {
        judge_pox = pop();
        if (judge_pox.x == 4 && judge_pox.y == 4) break;
        else {
            int i;
            for (i = 0; i < 4; i++) {
                struct coordinate excur_judge_pox = excursion_coor(judge_pox, excur[i].x, excur[i].y, 0);
                if(!(excur_judge_pox.x == -1) && 
                        maze[excur_judge_pox.x][excur_judge_pox.y] == 0 && 
                        excur_judge_pox.exist == 0) {
                    push(judge_pox);
                    excur_judge_pox.exist = 1;
                    push(excur_judge_pox);
                    break;
                }
            }
        }
    }
    if (judge_pox.x == 4 && judge_pox.y == 4) printf("successful!\n");
    else printf("fauilt!\n");

    return 0;
}

