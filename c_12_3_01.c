#include <stdio.h>

struct coordinate {
    int x, y;
};

int maze [5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0
};

struct coordinate path[25];

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

struct coordinate exist[25];

int top_e = 0;

void push_exist(struct coordinate coor)
{
    exist[top_e++] = coor;
}

int is_exist(struct coordinate pox)
{
    int i;
    for (i = 0; i < 25; i++) if (pox.x == exist[i].x && pox.y == exist[i].y) return 1;
    return 0;
}


struct coordinate com_coor(int x, int y)
{
    struct coordinate c;
    c.x = x;
    c.y = y;
    return c;
}

int main(void)
{
    struct coordinate init_pox = {0, 0}, judge_pox;
    push(init_pox);
    push_exist(init_pox);

    while (!is_empt()) {
        judge_pox = pop();
        if (judge_pox.x == 4 && judge_pox.y == 4) break;
        else {
            if (maze[judge_pox.x - 1][judge_pox.y] == 0 && !is_exist(com_coor(judge_pox.x - 1, judge_pox.y)) && judge_pox.x - 1 >= 0 && judge_pox.x - 1 <= 4) {
                push(com_coor(judge_pox.x, judge_pox.y));  
                push(com_coor(judge_pox.x - 1, judge_pox.y)); 
                push_exist(com_coor(judge_pox.x - 1, judge_pox.y));
                continue;
            }
            if (maze[judge_pox.x][judge_pox.y - 1] == 0 && !is_exist(com_coor(judge_pox.x, judge_pox.y - 1)) && judge_pox.y - 1 >= 0 && judge_pox.y - 1 <= 4) {
                push(com_coor(judge_pox.x, judge_pox.y));  
                push(com_coor(judge_pox.x, judge_pox.y - 1)); 
                push_exist(com_coor(judge_pox.x, judge_pox.y - 1));
                continue;
            }
            if (maze[judge_pox.x + 1][judge_pox.y] == 0 && !is_exist(com_coor(judge_pox.x + 1, judge_pox.y)) && judge_pox.x + 1 >= 0 && judge_pox.x + 1 <= 4) {
                push(com_coor(judge_pox.x, judge_pox.y));  
                push(com_coor(judge_pox.x + 1, judge_pox.y)); 
                push_exist(com_coor(judge_pox.x + 1, judge_pox.y));
                continue;
            }
            if (maze[judge_pox.x][judge_pox.y + 1] == 0 && !is_exist(com_coor(judge_pox.x, judge_pox.y + 1)) && judge_pox.y + 1 >= 0 && judge_pox.y + 1 <= 4) {
                push(com_coor(judge_pox.x, judge_pox.y));  
                push(com_coor(judge_pox.x, judge_pox.y + 1)); 
                push_exist(com_coor(judge_pox.x, judge_pox.y + 1));
                continue;
            }
        }
    }
    if (judge_pox.x == 4 && judge_pox.y == 4) printf("successful!\n");
    else printf("fauilt!\n");

    return 0;
}
















