//Author: Briana Singleton
//NYU ID: bfs254    
//HW 13
//Doodlebug-ant, predator-prey simulator on a 20x20 board
//Last modified: 15 October 2021

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Coordinate {
private: 
    int row;
    int col;
public: 
    Coordinate(int newRow = 0, int newCol = 0) : row(newRow), col(newCol) {}

    int getRow() const {return row;}
    int getCol() const {return col;}

    void setRow(int newRow) {row = newRow;}
    void setCol(int newCol) {col = newCol;}
    void setCoordinates(int newRow, int newCol) {row = newRow; col = newCol;}

    void operator=(const Coordinate& coord){
        row = coord.row;
        col = coord.col;
    }
};

class Organism {
private: 
    int breedTimer; 
    string species;
    int starveTimer;
    Coordinate current;
    Coordinate adjacentCellArr[4];
    Coordinate* adjacentCellArrPtr = adjacentCellArr;
public:
    Organism(int newBreedTimer = 1, string newSpecies = "ant", int newStarveTimer = 1);
    virtual ~Organism() {
        delete this;
    };
    Organism (const Organism& org) {
        breedTimer = org.breedTimer;
        species = org.species;
        current.setCoordinates(org.current.getRow(), org.current.getCol());
        for (int i = 0; i < 4; i++) {
            adjacentCellArr[i].setCoordinates(org.adjacentCellArr->getRow(), org.adjacentCellArr->getCol());
        }
    }
    Organism& operator=(const Organism& org) {
        breedTimer = org.breedTimer;
        species = org.species;
        current.setCoordinates(org.current.getRow(), org.current.getCol());
        for (int i = 0; i < 4; i++) {
            adjacentCellArr[i].setCoordinates(org.adjacentCellArr->getRow(), org.adjacentCellArr->getCol());
        }
        return *this;
    }
    
    virtual void move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr) = 0;
    virtual void breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr) = 0;
    virtual void printOrganism() const = 0;

    int getBreedTimer() const {return breedTimer;}
    string getSpecies() const {return species;}
    int getCurrentRow() const {return current.getRow();}
    int getCurrentCol() const {return current.getCol();}
    Coordinate* getAdjacentCellArr() const {return adjacentCellArrPtr;}

    void increaseBreedTimer() {breedTimer++;}
    void resetBreedTimer() {breedTimer = 1;}

    void setCurrent(int newCurrentRow, int newCurrentCol) {current.setCoordinates(newCurrentRow, newCurrentCol);}
    void setAdjacentCellUp(int newUpRow, int newUpCol) {adjacentCellArr[0].setCoordinates(newUpRow, newUpCol);}
    void setAdjacentCellDown(int newDownRow, int newDownCol) {adjacentCellArr[1].setCoordinates(newDownRow, newDownCol);}
    void setAdjacentCellLeft(int newLeftRow, int newLeftCol) {adjacentCellArr[2].setCoordinates(newLeftRow, newLeftCol);}
    void setAdjacentCellRight(int newRightRow, int newRightCol) {adjacentCellArr[3].setCoordinates(newRightRow, newRightCol);}
    void setAdjacentCells(int newUpRow, int newUpCol, int newDownRow, int newDownCol, int newLeftRow, int newLeftCol, int newRightRow, int newRightCol) {
        setAdjacentCellUp(newUpRow, newUpCol);
        setAdjacentCellDown(newDownRow, newDownCol);
        setAdjacentCellLeft(newLeftRow, newLeftCol);
        setAdjacentCellRight(newRightRow, newRightCol);
    }

    int getStarveTimer() const {return starveTimer;}
    void increaseStarveTimer() {starveTimer++;}
    void resetStarveTimer() {starveTimer = 1;}

    friend ostream& operator<<(ostream& os, Organism& org);   
};

class Ant : public Organism {
public: 
    Ant() : Organism(1, "ant", 1) {};

    void move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr);
    void breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr);
    void printOrganism() const {cout << "o";} 
};

class Doodlebug : public Organism {
public: 
    Doodlebug() : Organism(1, "doodlebug", 1) {};

    void move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr);
    void breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr);

    void printOrganism() const {cout << "X";}
};

class FillerBug : public Organism {
public: 
    FillerBug() : Organism (1, "fillerbug", 1) {};
    void move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr);
    void breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr);
    void printOrganism() const {cout << "_";}
};

typedef Organism* OrganismPtr;

int getRandNum(int range);
//takes an int range
//generates a random number between 1 and range

void makeOrganismArray(OrganismPtr*& arrPtr, int arrSize);
//takes an array pointer for Organisms and the array size for the number of desired organisms
//returns an array with 5 doodlebugs and (arrSize - 5) ants 

void generateCurrCoordinates(OrganismPtr*& arrPtr, int arrSize);
//takes an array pointer for Organisms and the array size for the number of desired organisms
//sets random coordinates from each Organism with no repeated coordinate combinations

void generateInitialAdjCoordinates(OrganismPtr*& arrPtr, int arrSize); 
//takes organism array that intially creates all organisms and its size
//gives the proper adjacent coordinates to each organism in the array based off the organism's current coordinates

void initialWorldPositioning(OrganismPtr*& worldArrPtr, OrganismPtr*& orgArrPtr, int orgArrSize);
//takes an array of Organisms to place and its size, takes an array for the world to place the Organisms in
//places Organisms in the world array

void printWorld(OrganismPtr*& worldArrPtr);
//takes world array of Organisms and prints it to the user

void organismActionsInWorld(OrganismPtr*& worldArrPtr);
//takes the world array
//moves organisms, checks breed timers and breeds organisms, checks starvation timers and kills doodlebugs

ostream& operator<<(ostream& os, Organism& org);
//overloads the << operator for Organism to print out the organism's current coordinates

int main(){
    int timeStep = 0;
    string userInput;
    srand(time(0));

    OrganismPtr* worldArrPtr;
    worldArrPtr = new OrganismPtr [20 * 20];
    //set worldArrPtrs to fillerbugs 
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++) {
            *(worldArrPtr + i * 20 + j) = new FillerBug();
        }
    }

    //Create array of Organisms and give them unique coordinates
    int orgArraySize = 105;
    OrganismPtr* orgArrayPtr = new OrganismPtr [orgArraySize];
    makeOrganismArray(orgArrayPtr, orgArraySize);
    generateCurrCoordinates(orgArrayPtr, orgArraySize);

    generateInitialAdjCoordinates(orgArrayPtr, orgArraySize);
    //Place Organisms from Organism array into world array
    initialWorldPositioning(worldArrPtr, orgArrayPtr, orgArraySize);
        
    cout<< "Ant and Doodlebug Simulator" << endl;
    printWorld(worldArrPtr);

    do {
        cout<< "Type [enter] to move to next time step. Type 'end' to quit simulation." << endl
            << "Time step: " << timeStep << endl;
        timeStep++;
        getline(cin, userInput);
        if (userInput == "end") {
            break;
        }
        organismActionsInWorld(worldArrPtr);
        printWorld(worldArrPtr);
    } while (userInput == "");
        
// Delete all arrays
    for (int i = 0; i < orgArraySize; i++) {
        delete [] orgArrayPtr[i];
        orgArrayPtr[i] = NULL;
    }
    for (int i = 0; i < 20; i++){
        delete [] worldArrPtr[i];
        worldArrPtr[i] = NULL;
    }
    delete [] orgArrayPtr;
    delete [] worldArrPtr;
    worldArrPtr = NULL;
    orgArrayPtr = NULL;
}

int getRandNum(int range){
    int randNum;
    randNum = rand() % range;
    return randNum;
}

void makeOrganismArray(OrganismPtr*& arrPtr, int arrSize){
    for (int i = 0; i < 5; i++) {
        *(arrPtr + i) = new Doodlebug(); //indexes 0 - 4 are Doodlebugs
    }
    for(int i = 5; i < arrSize; i++){
        *(arrPtr + i) = new Ant();     //indexes 5 - arrSize are Ants
    }
}

void generateCurrCoordinates(OrganismPtr*& arrPtr, int arrSize) {
    int num1, num2;
    bool seen = false;

    for (int i = 0; i < arrSize; i++) {
        num1 = getRandNum(19);
        num2 = getRandNum(19);

        for (int j = 0; j < i; j++) {
            if ((num1 == (*arrPtr[j]).getCurrentRow()) && (num2 == (*arrPtr[j]).getCurrentCol())){
                seen = true;
            }
        }

        if (seen == false) {
            (*arrPtr[i]).setCurrent(num1, num2);
        }
        else {
            --i;
        }
        seen = false;
    }
}

void generateInitialAdjCoordinates(OrganismPtr*& arrPtr, int arrSize) {
    int row, col;

    for (int i = 0; i < arrSize; i++){
        row = arrPtr[i]->getCurrentRow();
        col = arrPtr[i]->getCurrentCol();

        if ((row > 0) && (row < 19) && (col > 0) && (col < 19)){ // if coordinates aren't on edges
            arrPtr[i]->setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, (col + 1));
        }
        else { // if coordinates are on edges 
            if (row <= 0 && col <= 0 && row < 19  && col < 19) { //top left corner 
                arrPtr[i]->setAdjacentCells(row, col, (row + 1), col, row, col, row, (col + 1));
            }
            else if (row <= 0 && row < 19 && col > 0 && col < 19) { //top edge
                arrPtr[i]->setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, (col + 1));
            }
            else if (row <= 0 && col >= 19 && row < 19 && col > 0 ) { // top right corner
                arrPtr[i]->setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (col >= 19 && row > 0 && row < 19 && col > 0) { //right edge
                arrPtr[i]->setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (row >= 19 && col >= 19 && row > 0 && col > 0) { //bottom right corner
                arrPtr[i]->setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, col);
            }
            else if (row >= 19 && row > 0 && col > 0 && col < 19) { //bottom edge
                arrPtr[i]->setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, (col + 1));
            }
            else if (row >= 19 && col <= 0 && row > 0 && col < 19) { // bottom left corner
                arrPtr[i]->setAdjacentCells((row - 1), col, row, col, row, col, row, (col + 1));
            }
            else if (col <= 0 && col < 19 && row > 0 && row < 19) { //left edge 
                arrPtr[i]->setAdjacentCells((row - 1), col, (row + 1), col, row, col, row, (col + 1));
            }
        }
    }
}

void initialWorldPositioning (OrganismPtr*& worldArrPtr, OrganismPtr*& orgArrPtr, int orgArrSize) {
    //loop through Organism array, get current cooridnate of each Organism, place Organism at coordinates within the worldArray
    
    int worldArrCols = 20;

    for (int i = 0; i < orgArrSize; i++){
        *(worldArrPtr + ((*orgArrPtr[i]).getCurrentRow()) * worldArrCols + ((*orgArrPtr[i]).getCurrentCol())) = *(orgArrPtr + i); 
        // needs to equal the Ant or Doodlebug stored at that index in orgArr
        //copy the ant, not the pointer
    }
}

void printWorld (OrganismPtr*& worldArrPtr) {
    int worldArrRows = 20, worldArrCols = 20;

    for (int i = 0; i < worldArrRows; i++) {
        for (int j = 0; j < worldArrCols; j++) {
            (*(worldArrPtr + i * worldArrCols + j))->printOrganism();
            cout << "  ";
        }
        cout << endl;
    }
}

void organismActionsInWorld(OrganismPtr*& worldArrPtr){
 //iterate through worldArr 
//if species is "doodlebug" or "ant", find new current coordinates, store the coordinates and relocate the bug, swap fillerbug and ant 

// DOODLEBUGS - getting new coordinates
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if ((*(worldArrPtr + i * 20 + j))->getSpecies() == "doodlebug") {
                (*(worldArrPtr + i * 20 + j)) -> move(worldArrPtr, (*(worldArrPtr + i * 20 + j))->getAdjacentCellArr());
            }
        }
    }

// DOODLEBUGS - moving to new coordinates & starve timer
    int doodlebugNewRow, doodlebugNewCol;
    OrganismPtr tempHolder = NULL;

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if ((*(worldArrPtr + i * 20 + j))->getSpecies() == "doodlebug"){ // if it's a doodlebug, get the saved row and column 
                doodlebugNewRow = (*(worldArrPtr + i * 20 + j))->getCurrentRow();
                doodlebugNewCol = (*(worldArrPtr + i * 20 + j))->getCurrentCol();
                
                //to eat ants
                if ((*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol))->getSpecies() == "ant") {
                    tempHolder = (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol)); //captures ant's data
                    tempHolder = new FillerBug(); //fills temp holder with new fillerbug
                    (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol)) = (*(worldArrPtr + i * 20 + j)); // copies doodlebug to new position
                    (*(worldArrPtr + i * 20 + j)) = tempHolder; // puts a new fillerbug in at doodlebug's old position
                    tempHolder = NULL;
                }
                //to move
                else {
                    tempHolder = (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol)); //captures a fillerbug's data
                    (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol)) = (*(worldArrPtr + i * 20 + j)); // copies doodlebug to new position
                    (*(worldArrPtr + i * 20 + j)) = tempHolder; // puts the fillerbug in at doodlebug's old position
                    tempHolder = NULL;
                }
                
                //check starve timer after moving to new coordinate
                if((*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol))->getStarveTimer() == 3) {
                    tempHolder = (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol)); //capture's doodlebug's data
                    tempHolder = new FillerBug(); //fills temp holder with new fillerbug
                    (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol)) = tempHolder; //sets doodlebug's old position to new fillerbug
                    tempHolder = NULL;
                }

                //check breed timer after moving to new coordinate
                if((*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol))->getBreedTimer() >= 8){
                    (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol))->breed(worldArrPtr, (*(worldArrPtr + doodlebugNewRow * 20 + doodlebugNewCol))->getAdjacentCellArr());
                }
            }
            else {
                continue;
            }
        }
    }

//  ANTS - getting new coordinates
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if ((*(worldArrPtr + i * 20 + j))->getSpecies() == "ant") {
                (*(worldArrPtr + i * 20 + j)) -> move(worldArrPtr, (*(worldArrPtr + i * 20 + j))->getAdjacentCellArr());
            }
        }
    }

//  ANTS - moving to new coordinates & breed timer
    int antNewRow, antNewCol;

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if ((*(worldArrPtr + i * 20 + j))->getSpecies() == "ant"){
                antNewRow = (*(worldArrPtr + i * 20 + j))->getCurrentRow();
                antNewCol = (*(worldArrPtr + i * 20 + j))->getCurrentCol();

                tempHolder = (*(worldArrPtr + antNewRow * 20 + antNewCol));
                (*(worldArrPtr + antNewRow * 20 + antNewCol)) = (*(worldArrPtr + i * 20 + j)); // copies ant to new position
                (*(worldArrPtr + i * 20 + j)) = tempHolder; // puts a fillerbug in at ant's old position
                tempHolder = NULL;
                
                //check breed timer after moving to new coordinate
                if((*(worldArrPtr + antNewRow * 20 + antNewCol))->getBreedTimer() >= 3){
                    (*(worldArrPtr + antNewRow * 20 + antNewCol))->breed(worldArrPtr, (*(worldArrPtr + antNewRow * 20 + antNewCol))->getAdjacentCellArr());
                }
            }
            else {
                continue;
            }
        }
    }
}

Organism::Organism(int newBreedTimer, string newSpecies, int newStarveTimer){
    breedTimer = newBreedTimer;
    species = newSpecies;
    starveTimer = newStarveTimer;

    //sets current cell's coordinates to (0,0)
    current.setCoordinates(0,0);

    //sets all adjacent cells' coordinates to (0,0)
    for (int i = 0; i < 4; i++) {
        adjacentCellArr[i].setCoordinates(0, 0);
    }
}

ostream& operator<<(ostream& os, Organism& org) {
    os << org.current.getRow() << ", " << org.current.getCol();
    return os;
}

void Ant::move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr){
    int randNum;
    int row, col;
    Coordinate tempArr[4];
    int tempArrSize = 0;

    //check if adjacent cells to current ant have fillerbugs in them
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow();
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") {
            tempArr[tempArrSize].setCoordinates(row, col);
            tempArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) {
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug") {
            continue;
        }
    }

    //check to see all adjacent coordinates aren't all default values

    if (tempArrSize == 0) {
        setCurrent(getCurrentRow(), getCurrentCol());
        increaseBreedTimer();
    }
    else {
        randNum = getRandNum(tempArrSize);

        row = tempArr[randNum].getRow();
        col = tempArr[randNum].getCol();

        //set ant's new current cell
        setCurrent(row, col);
       
        //set ant's current cell's neighbors
        row = getCurrentRow();
        col = getCurrentCol();
        if ((row > 0) && (row < 19) && (col > 0) && (col < 19)){ // if coordinates aren't on edges
            setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, (col + 1));
        }
        else { // if coordinates are on edges 
            if (row <= 0 && col <= 0 && row < 19  && col < 19) { //top left corner 
                setAdjacentCells(row, col, (row + 1), col, row, col, row, (col + 1));
            }
            else if (row <= 0 && row < 19 && col > 0 && col < 19) { //top edge
                setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, (col + 1));
            }
            else if (row <= 0 && col >= 19 && row < 19 && col > 0 ) { // top right corner
                setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (col >= 19 && row > 0 && row < 19 && col > 0) { //right edge
                setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (row >= 19 && col >= 19 && row > 0 && col > 0) { //bottom right corner
                setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, col);
            }
            else if (row >= 19 && row > 0 && col > 0 && col < 19) { //bottom edge
                setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, (col + 1));
            }
            else if (row >= 19 && col <= 0 && row > 0 && col < 19) { // bottom left corner
                setAdjacentCells((row - 1), col, row, col, row, col, row, (col + 1));
            }
            else if (col <= 0 && col < 19 && row > 0 && row < 19) { //left edge 
                setAdjacentCells((row - 1), col, (row + 1), col, row, col, row, (col + 1));
            }
        }

        increaseBreedTimer();
    }
}

void Doodlebug::move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr) {
    int randNum;
    int row, col;
    Coordinate emptySpacesArr[4]; // for free spaces in case of no adjacent ants
    Coordinate foodPosArr[4]; // for ant spaces
    int emptySpacesArrSize = 0;
    int foodPosArrSize = 0;

    //check if adjacent cells to current doodlebug have ants in them
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow(); //get current row and column
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant") { //store adjacent cells with ants in them in the food possibility array
            foodPosArr[foodPosArrSize].setCoordinates(row, col);
            foodPosArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) { //if the adjacent cell is the same as the current cell, skip
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") {
            continue; //if the adjacent cell has another doodlebug or a fillerbug, skip
        }
    }

    //check if adjacent cells to current doodlebug have fillerbugs in them
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow(); 
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") { //store adjacent cells with fillerbugs in them in the case of no ants
            emptySpacesArr[emptySpacesArrSize].setCoordinates(row, col);    // in the empty cells array
            emptySpacesArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) { //ignore adjacent cells that are the same as the current cells
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug") {
            continue;   //ignore if the cell has ants or doodlebugs
        }
    }

    if (foodPosArrSize == 0) { //if there is nothing in the food possibility array, then do regular movement
        if (emptySpacesArrSize == 0) { // if there are no spaces to move to, stay in the same space and increase starve timer 
            setCurrent(getCurrentRow(), getCurrentCol());
            increaseStarveTimer();
            increaseBreedTimer();
        }
        else { // if there is an empty spot, move there and increase starve timer
            randNum = getRandNum(emptySpacesArrSize);

            row = emptySpacesArr[randNum].getRow();
            col = emptySpacesArr[randNum].getCol();

            //set ant's new current cell
            setCurrent(row, col);
          
            //set ant's current cell's neighbors
            row = getCurrentRow();
            col = getCurrentCol();
            if ((row > 0) && (row < 19) && (col > 0) && (col < 19)){ // if coordinates aren't on edges
                setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, (col + 1));
            }
            else { // if coordinates are on edges 
                if (row <= 0 && col <= 0 && row < 19  && col < 19) { //top left corner 
                    setAdjacentCells(row, col, (row + 1), col, row, col, row, (col + 1));
                }
                else if (row <= 0 && row < 19 && col > 0 && col < 19) { //top edge
                    setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, (col + 1));
                }
                else if (row <= 0 && col >= 19 && row < 19 && col > 0 ) { // top right corner
                    setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, col);
                }
                else if (col >= 19 && row > 0 && row < 19 && col > 0) { //right edge
                    setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, col);
                }
                else if (row >= 19 && col >= 19 && row > 0 && col > 0) { //bottom right corner
                    setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, col);
                }
                else if (row >= 19 && row > 0 && col > 0 && col < 19) { //bottom edge
                    setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, (col + 1));
                }
                else if (row >= 19 && col <= 0 && row > 0 && col < 19) { // bottom left corner
                    setAdjacentCells((row - 1), col, row, col, row, col, row, (col + 1));
                }
                else if (col <= 0 && col < 19 && row > 0 && row < 19) { //left edge 
                    setAdjacentCells((row - 1), col, (row + 1), col, row, col, row, (col + 1));
                }
            }
            
            //cout << "new current coords: (" << row << ", " << col << ")" << endl;
            increaseStarveTimer();
            increaseBreedTimer();
        }
    }
    else { // if there are ants adjacent, choose an ant to "eat" and move to that cell, reset starve timer
        randNum = getRandNum(foodPosArrSize);

        row = foodPosArr[randNum].getRow();
        col = foodPosArr[randNum].getCol();

        //set doodlebug's new current cell
        setCurrent(row, col);

        //set doodlebug's current cell's neighbors
        row = getCurrentRow();
        col = getCurrentCol();
        if ((row > 0) && (row < 19) && (col > 0) && (col < 19)){ // if coordinates aren't on edges
            setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, (col + 1));
        }
        else { // if coordinates are on edges 
            if (row <= 0 && col <= 0 && row < 19  && col < 19) { //top left corner 
                setAdjacentCells(row, col, (row + 1), col, row, col, row, (col + 1));
            }
            else if (row <= 0 && row < 19 && col > 0 && col < 19) { //top edge
                setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, (col + 1));
            }
            else if (row <= 0 && col >= 19 && row < 19 && col > 0 ) { // top right corner
                setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (col >= 19 && row > 0 && row < 19 && col > 0) { //right edge
                setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (row >= 19 && col >= 19 && row > 0 && col > 0) { //bottom right corner
                setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, col);
            }
            else if (row >= 19 && row > 0 && col > 0 && col < 19) { //bottom edge
                setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, (col + 1));
            }
            else if (row >= 19 && col <= 0 && row > 0 && col < 19) { // bottom left corner
                setAdjacentCells((row - 1), col, row, col, row, col, row, (col + 1));
            }
            else if (col <= 0 && col < 19 && row > 0 && row < 19) { //left edge 
                setAdjacentCells((row - 1), col, (row + 1), col, row, col, row, (col + 1));
            }
        }
        //cout << "new current coords: (" << row << ", " << col << ")" << endl;
        resetStarveTimer();
        increaseBreedTimer();
    }
}

void FillerBug::move(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr){
    int randNum;
    int row, col;
    Coordinate tempArr[4];
    int tempArrSize = 0;

    //check if adjacent cells to current ant have fillerbugs in them
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow();
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") {
            tempArr[tempArrSize].setCoordinates(row, col);
            tempArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) {
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug") {
            continue;
        }
    }

    //check to see all adjacent coordinates aren't all default values

    if (tempArrSize == 0) {
        setCurrent(getCurrentRow(), getCurrentCol());
    }
    else {
        randNum = getRandNum(tempArrSize);

        row = tempArr[randNum].getRow();
        col = tempArr[randNum].getCol();

        //set ant's new current cell
        setCurrent(row, col);
    
        //set ant's current cell's neighbors
        for (int i = 0; i < 4; i++) {
            row = getCurrentRow();
            col = getCurrentCol();
            if ((row > 0) && (row < 19) && (col > 0) && (col < 19)){ // if coordinates aren't on edges
                setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, (col + 1));
            }
            else { // if coordinates are on edges 
                if (row <= 0 && col <= 0 && row < 19  && col < 19) { //top left corner 
                    setAdjacentCells(row, col, (row + 1), col, row, col, row, (col + 1));
                }
                else if (row <= 0 && row < 19 && col > 0 && col < 19) { //top edge
                    setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, (col + 1));
                }
                else if (row <= 0 && col >= 19 && row < 19 && col > 0 ) { // top right corner
                    setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, col);
                }
                else if (col >= 19 && row > 0 && row < 19 && col > 0) { //right edge
                    setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, col);
                }
                else if (row >= 19 && col >= 19 && row > 0 && col > 0) { //bottom right corner
                    setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, col);
                }
                else if (row >= 19 && row > 0 && col > 0 && col < 19) { //bottom edge
                    setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, (col + 1));
                }
                else if (row >= 19 && col <= 0 && row > 0 && col < 19) { // bottom left corner
                    setAdjacentCells((row - 1), col, row, col, row, col, row, (col + 1));
                }
                else if (col <= 0 && col < 19 && row > 0 && row < 19) { //left edge 
                    setAdjacentCells((row - 1), col, (row + 1), col, row, col, row, (col + 1));
                }
            }
        }
    }
 }

void Ant::breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr) {
    int row, col; 
    int emptySpacesArrSize = 0;
    Coordinate emptySpacesArr[4];

    //if breed timer is 3, check for empty spaces
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow(); //get row and column from each adjacent coordinate in adjacent cells array
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") { // check if the coordinates have a fillerbug
            emptySpacesArr[emptySpacesArrSize].setCoordinates(row, col);
            emptySpacesArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) { //ignore if row and col are ant's row and col
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug") {
            continue; //ignore cell if there is an ant or doodlebug inside
        }
    }

    if (emptySpacesArrSize == 0) {
        increaseBreedTimer();
    }
    else {
        int babyRow, babyCol;
        babyRow = emptySpacesArr[0].getRow(); // gets the proper empty cell coordinates to put the new ant into
        babyCol = emptySpacesArr[0].getCol();

        OrganismPtr tempHolder = NULL;
        //tempHolder = (*(worldArrPtr + babyRow * 20 + babyCol)); // capture fillerbug
        tempHolder = new Ant(); // put in a new ant
        (*(worldArrPtr + babyRow * 20 + babyCol)) = tempHolder; //set coordinate with new ant
        (*(worldArrPtr + babyRow * 20 + babyCol))->setCurrent(babyRow, babyCol); // update the new ant's current coordinates
        tempHolder = NULL;

        // update the new ant's adjacent coordinates
        if ((babyRow > 0) && (babyRow < 19) && (babyCol > 0) && (babyCol < 19)){ // if coordinates aren't on edges
            setAdjacentCells((babyRow - 1), babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, (babyCol + 1));
        }
        else { // if coordinates are on edges 
            if (babyRow <= 0 && babyCol <= 0 && babyRow < 19  && babyCol < 19) { //top left corner 
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(babyRow, babyCol, (babyRow + 1), babyCol, babyRow, babyCol, babyRow, (babyCol + 1));
            }
            else if (babyRow <= 0 && babyRow < 19 && babyCol > 0 && babyCol < 19) { //top edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(babyRow, babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, (babyCol + 1));
            }
            else if (babyRow <= 0 && babyCol >= 19 && babyRow < 19 && babyCol > 0 ) { // top right corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(babyRow, babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, babyCol);
            }
            else if (babyCol >= 19 && babyRow > 0 && babyRow < 19 && babyCol > 0) { //right edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, babyCol);
            }
            else if (babyRow >= 19 && babyCol >= 19 && babyRow > 0 && babyCol > 0) { //bottom right corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, babyRow, babyCol, (babyRow - 1), babyCol, babyRow, babyCol);
            }
            else if (babyRow >= 19 && babyRow > 0 && babyCol > 0 && babyCol < 19) { //bottom edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, babyRow, babyCol, (babyRow - 1), babyCol, babyRow, (babyCol + 1));
            }
            else if (babyRow >= 19 && babyCol <= 0 && babyRow > 0 && babyCol < 19) { // bottom left corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, babyRow, babyCol, babyRow, babyCol, babyRow, (babyCol + 1));
            }
            else if (babyCol <= 0 && babyCol < 19 && babyRow > 0 && babyRow < 19) { //left edge 
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, (babyRow + 1), babyCol, babyRow, babyCol, babyRow, (babyCol + 1));
            }
        }
        
        resetBreedTimer(); // reset timer for parent ant
    }
}

void Doodlebug::breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr) {
    int row, col; 
    int emptySpacesArrSize = 0;
    Coordinate emptySpacesArr[4];

    //if breed timer is 8, check for empty spaces
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow();
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") {
            emptySpacesArr[emptySpacesArrSize].setCoordinates(row, col);
            emptySpacesArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) {
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug") {
            continue;
        }
    }

    if (emptySpacesArrSize == 0) { // if there are no open spaces, don't breed
        increaseBreedTimer();
    }
    else {
        //select the first entry in empty spaces array to hold the new doodlebug
        int babyRow, babyCol;
        babyRow = emptySpacesArr[0].getRow();
        babyCol = emptySpacesArr[0].getCol();

        OrganismPtr tempHolder = NULL;
        //tempHolder = (*(worldArrPtr + babyRow * 20 + babyCol)); // capture fillerbug
        tempHolder = new Doodlebug();
        (*(worldArrPtr + babyRow * 20 + babyCol)) = tempHolder; 
        (*(worldArrPtr + babyRow * 20 + babyCol))->setCurrent(babyRow, babyCol);
        tempHolder = NULL;

        if ((babyRow > 0) && (babyRow < 19) && (babyCol > 0) && (babyCol < 19)){ // if coordinates aren't on edges
            setAdjacentCells((babyRow - 1), babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, (babyCol + 1));
        }
        else { // if coordinates are on edges 
            if (babyRow <= 0 && babyCol <= 0 && babyRow < 19  && babyCol < 19) { //top left corner 
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(babyRow, babyCol, (babyRow + 1), babyCol, babyRow, babyCol, babyRow, (babyCol + 1));
            }
            else if (babyRow <= 0 && babyRow < 19 && babyCol > 0 && babyCol < 19) { //top edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(babyRow, babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, (babyCol + 1));
            }
            else if (babyRow <= 0 && babyCol >= 19 && babyRow < 19 && babyCol > 0 ) { // top right corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(babyRow, babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, babyCol);
            }
            else if (babyCol >= 19 && babyRow > 0 && babyRow < 19 && babyCol > 0) { //right edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, (babyRow + 1), babyCol, babyRow, (babyCol - 1), babyRow, babyCol);
            }
            else if (babyRow >= 19 && babyCol >= 19 && babyRow > 0 && babyCol > 0) { //bottom right corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, babyRow, babyCol, (babyRow - 1), babyCol, babyRow, babyCol);
            }
            else if (babyRow >= 19 && babyRow > 0 && babyCol > 0 && babyCol < 19) { //bottom edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, babyRow, babyCol, (babyRow - 1), babyCol, babyRow, (babyCol + 1));
            }
            else if (babyRow >= 19 && babyCol <= 0 && babyRow > 0 && babyCol < 19) { // bottom left corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, babyRow, babyCol, babyRow, babyCol, babyRow, (babyCol + 1));
            }
            else if (babyCol <= 0 && babyCol < 19 && babyRow > 0 && babyRow < 19) { //left edge 
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((babyRow - 1), babyCol, (babyRow + 1), babyCol, babyRow, babyCol, babyRow, (babyCol + 1));
            }
        }
        
        resetBreedTimer();
    }
}

void FillerBug::breed(Organism**& worldArrPtr, Coordinate* adjacentCellArrPtr) {
    int row, col; 
    int emptySpacesArrSize = 0;
    Coordinate emptySpacesArr[emptySpacesArrSize];

    //if breed timer is 3, check for empty spaces
    for (int i = 0; i < 4; i++) {
        row = adjacentCellArrPtr[i].getRow();
        col = adjacentCellArrPtr[i].getCol();

        if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "fillerbug") {
            emptySpacesArr[emptySpacesArrSize].setCoordinates(row, col);
            emptySpacesArrSize++;
        }
        else if ((row == getCurrentRow()) && (col == getCurrentCol())) {
            continue;
        }
        else if ((*(worldArrPtr + row * 20 + col))->getSpecies() == "ant" || (*(worldArrPtr + row * 20 + col))->getSpecies() == "doodlebug") {
            continue;
        }
    }

    int babyRow, babyCol;
    babyRow = emptySpacesArr[0].getRow();
    babyCol = emptySpacesArr[0].getCol();

    (*(worldArrPtr + babyRow * 20 + babyCol)) = new Ant();
    (*(worldArrPtr + babyRow * 20 + babyCol))->setCurrent(babyRow, babyCol);

    for (int i = 0; i < 4; i++) {
        row = babyRow;
        col = babyCol;
        if ((row > 0) && (row < 19) && (col > 0) && (col < 19)){ // if coordinates aren't on edges
            setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, (col + 1));
        }
        else { // if coordinates are on edges 
            if (row <= 0 && col <= 0 && row < 19  && col < 19) { //top left corner 
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(row, col, (row + 1), col, row, col, row, (col + 1));
            }
            else if (row <= 0 && row < 19 && col > 0 && col < 19) { //top edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, (col + 1));
            }
            else if (row <= 0 && col >= 19 && row < 19 && col > 0 ) { // top right corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells(row, col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (col >= 19 && row > 0 && row < 19 && col > 0) { //right edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((row - 1), col, (row + 1), col, row, (col - 1), row, col);
            }
            else if (row >= 19 && col >= 19 && row > 0 && col > 0) { //bottom right corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, col);
            }
            else if (row >= 19 && row > 0 && col > 0 && col < 19) { //bottom edge
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((row - 1), col, row, col, (row - 1), col, row, (col + 1));
            }
            else if (row >= 19 && col <= 0 && row > 0 && col < 19) { // bottom left corner
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((row - 1), col, row, col, row, col, row, (col + 1));
            }
            else if (col <= 0 && col < 19 && row > 0 && row < 19) { //left edge 
                (*(worldArrPtr + babyRow * 20 + babyCol))->setAdjacentCells((row - 1), col, (row + 1), col, row, col, row, (col + 1));
            }
        }
    }
    (*(worldArrPtr + babyRow * 20 + babyCol))->resetBreedTimer();
}