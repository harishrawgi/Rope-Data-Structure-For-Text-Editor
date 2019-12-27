#include "RopeHelper.h"
#include <stdio.h>
#include <stdlib.h>

// function to create a new rope
int createRope(Rope* rope, Rope* inv, char* ar, int beg, int end){

  (*rope) = (Rope) malloc(sizeof(struct rope));
  if(!(*rope)){
    printf("\nError in createRope(): Unable to allocate memory for rope node.\n");
    return 0;
  }

  (*rope)->left = (*rope)->right = NULL;

  if(inv){
    (*rope)->inverse = *inv;
  }
  else{
    (*rope)->inverse = NULL;
  }



  if(end-beg > MAX_LEAF_SIZE){
    (*rope)->str = NULL;
    (*rope)->count = (end-beg)/2;
    int mid = (beg+end)/2;
    if(!createRope(&((*rope)->left), rope, ar, beg, mid) || !createRope(&((*rope)->right), rope, ar, mid+1, end)){
      printf("\nError in createRope(): Unable to create rope recursively.\n");
      return 0;
    }
  }
  else{
    (*rope)->count = (end-beg);
    int j=0;
    (*rope)->str = (char*)malloc(MAX_LEAF_SIZE*sizeof(char));
    for(int i=beg; i<=end; i++){
      (*rope)->str[j++] = ar[i];
    }
    if(j<MAX_LEAF_SIZE-1) (*rope)->str[j] = '\0';

  }

  return 1;
}

// function to print rope
void printRope(Rope rope){

  if(!rope){
    return;
  }


  if(!rope->left && !rope->right){
    printf("%s", rope->str);
  }

  printRope(rope->left);
  printRope(rope->right);
}
