#include "Rope.h"
#include "RopeHelper.h"
#include <stdlib.h>
#include <stdio.h>

// function to create an empty PRope
PRope createEmptyPRope(){

  PRope prope = (PRope) malloc(sizeof(struct prope));
  if(!prope){
    printf("\nError in createEmptyPRope(): Unable to allocate memory for PRope.\n");
    return NULL;
  }

  for(int i=0; i<MAX_VERSIONS; i++){
    prope->roots[i] = NULL;
  }
  prope->liveVersion = 0;

  return prope;
}

// function to append a string to the already existing text
int appendString(PRope prope, int version, char* ar, int beg, int end){

  if(!prope || version >= MAX_VERSIONS){
    printf("\nError in appendString(): Invalid input.\n");
    return 0;
  }

  int liveVersion = prope->liveVersion;
  int nextVersion = liveVersion + 1;


  if(version == -1){
    version = liveVersion;
  }

  if(version > liveVersion){
    printf("\nError in appendString(): Version doesn't exist.\n");
    return 0;
  }

  Rope rope1 = prope->roots[version];

  Rope rope2 = NULL;
  if(!createRope(&rope2, NULL, ar, beg, end)){
    printf("\nError in appendString(): Unable to create a rope for the supplied string.\n");
    return 0;
  }

  if(!rope1){
    prope->roots[nextVersion] = rope2;
    prope->liveVersion = nextVersion;
    return 1;
  }

  Rope rope = (Rope) malloc(sizeof(struct rope));
  if(!rope){
    printf("\nError in appendString(): Unable to allocate memory for a new rope.\n");
    return 0;
  }
  rope->left = rope1;
  rope->right = rope2;
  rope->inverse = NULL;
  rope->count = rope1->count;
  rope->str = NULL;
  rope1->inverse = rope;
  rope2->inverse = rope;

  prope->roots[nextVersion] = rope;
  prope->liveVersion = nextVersion;

  return 1;


}

// funtion to undo n times
int undo(PRope prope, int n){

  if(!prope){
    printf("\nError in undo(): Invalid input.\n");
    return 0;
  }

  int liveVersion = prope->liveVersion;
  int version = liveVersion - n;
  if(version < 0){
    printf("\nError in undo(): Can't undo that many times.\n");
    return 0;
  }

  if(version == liveVersion){
    printf("\nMessage from undo(): Nothing to do.\n");
    return 1;
  }

  Rope rope = prope->roots[version];
  if(!rope){
    printf("\nMessage from undo(): Empty string now.\n");
  }
  else{
    Rope inv = rope->inverse;
    if(inv){
      //freeRopeTopRight(inv);
      rope->inverse = NULL;
    }
  }

  for(int i=version+1; i<=liveVersion; i++){
    prope->roots[i] = NULL;
  }

  prope->liveVersion = version;

  return 1;
}

//function to print rope of a given version
int printPRope(PRope prope, int version){

  if(!prope || version >= MAX_VERSIONS){
    printf("\nError in printRope(): Invalid input.\n");
    return 0;
  }

  int liveVersion = prope->liveVersion;
  int nextVersion = liveVersion + 1;


  if(version == -1){
    version = liveVersion;
  }

  if(version > liveVersion){
    printf("\nError in printRope(): Version doesn't exist.\n");
    return 0;
  }

  printf("\nMessage from printRope(): Printing the rope of version (%d).\n", version);

  Rope rope = prope->roots[version];
  printRope(rope);

  return 1;
}
