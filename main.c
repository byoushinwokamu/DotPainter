#include "conio.h"

unsigned long long canvas;
int rcur = 7, ccur = 7;

void print() {
  clrscr();
  for (int r = 7; r >= 0; r--) {
    for (int c = 7; c >= 0; c--) {
      printf(rcur == r && ccur == c ? "<" : " ");
      printf((canvas & (1ULL << (r * 8 + c))) ? "■" : "□");
      printf(rcur == r && ccur == c ? ">" : " ");
    }
    printf("\n");
  }
  printf("Move with <h,j,k,l>, Set bit with <s>, Clear bit with <c>, Terminate "
         "with <t>");
}

int main(int argc, char **argv) {
  int ch = 0;
  print();
  while ((ch = getch()) != 't') {
    printf("%d\n", ch);
    switch (ch) {
    case 'h':
      (ccur == 7) ? ccur : ccur++;
      break;
    case 'j':
      (rcur == 0) ? rcur : rcur--;
      break;
    case 'k':
      (rcur == 7) ? rcur : rcur++;
      break;
    case 'l':
      (ccur == 0) ? ccur : ccur--;
      break;
    case 's':
      canvas |= 1ULL << (rcur * 8 + ccur);
      break;
    case 'c':
      canvas &= ~(1ULL << (rcur * 8 + ccur));
      break;
    }
    print();
  }
  printf("\nTerminated Painting.\n");
  printf("Hex code is 0x%llX\n", canvas);
  printf("Dec code is %llu\n", canvas);

  return 0;
}