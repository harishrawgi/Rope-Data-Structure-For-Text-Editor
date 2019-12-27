#include "Rope.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 1000

int main(){

  int ch;

  PRope prope = createEmptyPRope();
  if(!prope){
    printf("\nError in main(): Unable to create an empty Rope.\n");
    exit(0);
  }

  int toContinue = 1;

  while(toContinue){

    printf("\n----------------------------------------------------------------------------------------\n");
    printf("\nChoose one of the following options:\n");
    printf("1. Append a string\n");
    printf("2. Undo once\n");
    printf("3. Undo n times\n");
    printf("4. Print the text\n");
    printf("5. Quit\n");
    printf("----------------------------------------------------------------------------------------\n");
    scanf("%d", &ch);
    getchar();

    switch(ch){

      case 1:{

        char ar[MAX_CHARS];
        printf("\nEnter the string to be appended (Max 1000 chars):\n");
        int i=0;
        char c;

        while( (c=getchar()) != '\n' && i < MAX_CHARS-1){
          ar[i++] = c;
        }

        ar[i] = '\0';

        if(!appendString(prope, -1, ar, 0, i)){
          printf("\nError in main(): Unable to append to the Rope.\n");
          exit(0);
        }

      } break;

      case 2:{

        if(!undo(prope, 1)){
          printf("\nError in main(): Unable to undo once.\n");
          exit(0);
        }

      } break;

      case 3: {

        int n;
        printf("\nEnter the number of times you want to undo: ");
        scanf("%d", &n);
        if(!undo(prope, n)){
          printf("\nError in main(): Unable to undo (%d) times.\n", n);
          exit(0);
        }

      } break;

      case 4: {

        int n;
        printf("\nEnter the number of turns you want to go back and print the text (Enter 0 for latest text): ");
        scanf("%d", &n);
        if(!printPRope(prope, prope->liveVersion - n)){
          printf("\nError in main(): Unable to print the required text.\n");
          exit(0);
        }

      } break;

      case 5: {

        toContinue = 0;

      } break;

      default: printf("\nInvalid choice.\n");
               exit(0);

    }


  }

  return 0;
}
