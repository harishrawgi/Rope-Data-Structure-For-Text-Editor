#ifndef ROPE_H
#define ROPE_H

#define MAX_VERSIONS 100
#define MAX_LEAF_SIZE 5



typedef struct rope{

  struct rope* left;
  struct rope* right;
  struct rope* inverse;
  char* str;
  int count;

}* Rope;


typedef struct prope{

  struct rope* roots[MAX_VERSIONS];
  int liveVersion;

}* PRope;

// function to create an empty PRope
PRope createEmptyPRope();

// function to append a string to the already existing text
int appendString(PRope prope, int version, char* ar, int beg, int end);

// funtion to undo n times
int undo(PRope prope, int n);

//function to print rope of a given version
int printPRope(PRope prope, int version);

#endif
