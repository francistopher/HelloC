// solved on 2/27/23
#include <stdio.h>

typedef enum bool {false, true} bool;

bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize){
    int matchingPiecesIndex;
    int pieceIndex;
    int* piece;
    int arrIndex;
    int piecesIndex;
    int pieceSize;
    while (arrIndex < arrSize)
    {
        piecesIndex = 0; 
        while (piecesIndex < piecesSize)
        {
            piece = pieces[piecesIndex];
            if (piece[0] == arr[arrIndex])
            {
                matchingPiecesIndex = piecesIndex;
                pieceSize = piecesColSize[piecesIndex];
                pieceIndex = 0; 
                while (pieceIndex < pieceSize)
                    if (piece[pieceIndex++] != arr[arrIndex++])
                        return false;
                break;
            }
            piecesIndex++;
        }
        if (matchingPiecesIndex == -1)
            return false;
        matchingPiecesIndex = -1;
    }
    return true;
}

int main(void)
{
	printf("i'll add later gotta dry clothes for tomorrow\n");
}
