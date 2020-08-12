#include <stdio.h>
const char left = 'L';
const char middle = 'M';
const char right = 'R';
void TOH(int disks, char l, char m, char r)
{
    if (disks == 0)
        return;
    TOH(disks - 1, l, r, m);
    printf("%c -> %c\n", l, r);
    TOH(disks - 1, m, l, r);
}
int main(void)
{
    printf("NOTE: L refers Left tower, M refers Middle tower and R refers right tower.\n\n");
    TOH(3, left, middle, right);
    return 0;
}