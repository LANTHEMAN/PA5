//Author: LMAO RWWITTENBERG
#include <cstdlib>
#include <iostream>
#include "board.h"
/*PA5 gridSize #doodlebugs #ants #time_steps seed pause*/

/**
*prints the addresses of the board
*@param o Organism*** is a pointer to the game board
*@param size is the integer size of the gridSize
*@return void
*/
void printAddresses(Organism*** o, int size){
  //iterates through the board cells
  for(int i=0; i<size; i++){
    for(int j=0 ; j<size; j++){
      printf("%p  ", o[i][j]);
    }
    printf("\n");
  }
}

/**
*prints the board
*@param o Organism*** is a pointer to the game board
*@param size is the integer size of the gridSize
*@return void
*/
void printBoard(Organism*** o, int size){
  //iterates through the board cells
  for(int i=0; i<size; i++){
    for(int j=0 ; j<size; j++){
      Organism* op = o[i][j];
      if(op){
        if(op->isAnt()){
          printf("A  ");
        }else{
          printf("D  ");
        }
      }else{
        printf("E  ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char* argv[])
{
    //command line arguments
    int gridSize = 20;
    int numBug = 5;
    int numAnt = 100;
    int steps = 1000;
    int seed = 1;
    int pause = 0;

  //switch based on the different number of commandline arguments
  switch(argc)
  {
    case 1:
    gridSize = 20;
    numBug = 5;
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 2:
    gridSize = atoi(argv[1]);
    numBug = 5;
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 3:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = 100;
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 4:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = 1000;
    seed = 1;
    pause = 0;
    break;

    case 5:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = atoi(argv[4]);
    seed = 1;
    pause = 0;
    break;

    case 6:
    gridSize = atoi(argv[1]);
    numBug = atoi(argv[2]);
    numAnt = atoi(argv[3]);
    steps = atoi(argv[4]);
    seed = atoi(argv[6]);
    pause = 0;
    break;

    case 7:
    printf("seven");
    gridSize = atoi(argv[1]);//
    numBug = atoi(argv[2]);//
    numAnt = atoi(argv[3]);//
    steps = atoi(argv[4]);//
    seed = atoi(argv[5]);
    pause = atoi(argv[6]);
    break;
  }

    const int s= gridSize;
    Board* board = new Board(s);
    Organism*** boardValues = board->getValues();

    //printAddresses(boardValues, gridSize);

    printf("loading doodlebugs\n");
    //iterates through and loads bugs in random locations
    for(int i=0; i<numBug; i++){
      bool added = false;
      do{//do while bug isnt added

        int rowD = rand() % gridSize;
        int columnD = rand() % gridSize;
        if(!boardValues[rowD][columnD]){
          DoodleBug* d = new DoodleBug(rowD, columnD);
          printf("new doodlebug in   %i    %i\n", rowD, columnD);
          board->addOrganism(d);
          added=true;
        }
      }while(!added);
    }

    printf("loading ants\n");
    //iterates through and loads ants randomly
    for(int i=0; i<numAnt; i++){
      bool added = false;
      int count =0;
      do{//do while ant isnt added
        int rowA = rand() % gridSize;
        int columnA = rand() % gridSize;
        if(!boardValues[rowA][columnA]){
          Ant* a = new Ant(rowA, columnA);
          board->addOrganism(a);
          added=true;
        }else{
          count++;
        }
      }while(!added && count<4);
    }

    printf("Loaded Board:\n");
    printBoard(boardValues, gridSize);

    //iterates through the user specified number of steps
    for(int i=0; i<steps; i++){
      board->step();
      if(pause ==1){
        printBoard(boardValues, gridSize);
        char* c;
        scanf("%i", &c);
      }
    }
    //prints final game board
    printBoard(boardValues, gridSize);


}
