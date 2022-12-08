#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int main() {

    int i, j, sizeOfPosArrContainer=0, sizeOfNegArrContainer=0, itr=0, numOfElement;
    int posStartNode=numeric_limits<int>::max(), posEndNode=0, negStartNode=numeric_limits<int>::max(), negEndNode=0;
    bool hasPosNode=false, hasNegNode=false;

    // Get array size
    cout << "Enter array size: ";
    cin >> numOfElement;

    // Array  creation
    int *arr = new int[numOfElement];

    cout << "Enter elements:\n";
    for (i=0; i<numOfElement; i++) {
        cin >> arr[i];
        if (arr[i]>=0) {
            hasPosNode = true;
            if(arr[i]>posEndNode) {
                posEndNode = arr[i];
            }
            if(arr[i]<posStartNode) {
                posStartNode = arr[i];
            }
        } else {
            hasNegNode = true;
            if(abs(arr[i])>negEndNode) {
                negEndNode = abs(arr[i]);
            }
            if(abs(arr[i])<negStartNode) {
                negStartNode = abs(arr[i]);
            }
        }
    }

    // Size for array container
    if(hasPosNode) {
        sizeOfPosArrContainer = posEndNode - posStartNode + 1;
    }
    if(hasNegNode) {
        sizeOfNegArrContainer = negEndNode - negStartNode + 1;
    }

    // Array container creation
    int *posArrContainer = new int[sizeOfPosArrContainer];
    int *negArrContainer = new int[sizeOfNegArrContainer];

    // Initialization of array
    if(sizeOfPosArrContainer >= sizeOfNegArrContainer) {
        for(i=0; i<sizeOfPosArrContainer; i++) {
            posArrContainer[i] = 0;
            if(i < sizeOfNegArrContainer) {
                negArrContainer[i] = 0;
            }
        }
    } else {
        for(i=0; i<sizeOfNegArrContainer; i++) {
            negArrContainer[i] = 0;
            if(i < sizeOfPosArrContainer) {
                posArrContainer[i] = 0;
            }
        }
    }

    // Assigning index to elements according to their value
    for(i=0; i<numOfElement; i++) {
        if(arr[i]>=0) {
            posArrContainer[arr[i]-posStartNode]++;
        } else {
            negArrContainer[abs(arr[i])-negStartNode]++;
        }
    }

    // New array to store sorted element
    int *sortedArr = new int[numOfElement];

    // Collecting negative sorted element
    for(i=sizeOfNegArrContainer-1; i>=0; i--) {
        if(negArrContainer[i]>0) {
            for(j=0; j<negArrContainer[i]; j++) {
                sortedArr[itr] = (-1) * (i+negStartNode);
                itr++;
            }
        }
    }

    // Collecting positive sorted element
    for(i=0; i<sizeOfPosArrContainer; i++) {
        if(posArrContainer[i]>0) {
            for(j=0; j<posArrContainer[i]; j++) {
                sortedArr[itr] = i + posStartNode;
                itr++;
            }
        }
    }

    // Free memory
    delete  [] posArrContainer;
    delete  [] negArrContainer;

    // Display sorted array
    cout << "\n\nSorted arr:\n";
    for(i=0; i<numOfElement; i++) {
        cout << sortedArr[i] << endl;
    }

    return 0;
}
