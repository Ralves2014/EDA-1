#include "fatal.h"
#include "hashsep.h"
#include <stdlib.h>


#define MinTableSize (10)

typedef unsigned int Index;

struct ListNode{
    ElementType Element;
    Position    Next;
};
typedef Position List;


struct HashTbl{
    int TableSize;
    List *TheLists;
};


/* Return next prime; assume N >= 10 */
static int NextPrime( int N ){

    int n;

    if(N%2==0)
        N++;
    for (; ; N=N+2)
    {
        for (int i = 1; i <=N; i++)
        {
            n=0;
            if(N%i==0)
                n=n+1;
        }
        if(n==2)
            return N;
    }
}


/* Hash function for ints */
Index Hash( ElementType Key, int TableSize ){
	return Key%TableSize;
}


HashTable InitializeTable( int TableSize ){
    HashTable H;
    int i;

    /* Check TableSize */
    
    if(TableSize<MinTableSize){
    	Error("Table size too small");
    	return NULL;
    }


    /* Allocate table */

    H=malloc(sizeof(struct HashTbl));

    if(H==NULL)
    	FatalError("Out of space!");
    	
    H->TableSize=NextPrime(TableSize),


    /* Allocate array of lists */

    H->TableSize = NextPrime( TableSize );

    H->TheLists = malloc( sizeof(List) * H->TableSize );
    if( H->TheLists == NULL )
        FatalError( "Out of space!!!" );


    /* Allocate list headers */
    for(i=0;i<H->TableSize;i++){
    	
    	H->TheLists[ i ] = malloc( sizeof( struct ListNode ) );
    	
    	if(H->TheLists[i]==NULL)
    		FatalError("Out of space!");
    	else
    		H->TheLists[i]->Next=NULL;

    }

    return H;
}


void DestroyTable( HashTable H ){

    int i;
    
    for( i = 0; i < H->TableSize; i++ )
    {
        Position P = H->TheLists[ i ];
        Position Tmp;

        while( P != NULL )
        {
            Tmp = P->Next;
            free( P );
            P = Tmp;
        }
    }

    free( H->TheLists );
    free( H );

    /* Traverse the table */

    /* Free list nodes */

    /* Free array of lists */
    /* Free hash table */
}


Position Find( ElementType Key, HashTable H ){

	Position P;
    List L;
        
    L = H->TheLists[ Hash( Key, H->TableSize ) ];
    P = L->Next;
        
    while(P!=NULL && P->Element != Key)
    	P=P->Next;
        
    return P;
}


void Insert( ElementType Key, HashTable H ){

	Position Pos, NewCell;
    List L;
    Pos = Find( Key, H );
        
    if(Pos==NULL){
    	NewCell = malloc( sizeof( struct ListNode ) );
        if(NewCell==NULL)
    		FatalError("Out of space!");
    	else{

        	L = H->TheLists[ Hash( Key, H->TableSize ) ];	
        	NewCell->Next = L->Next;
    		NewCell->Element = Key;
    		L->Next = NewCell;
        }
    }
        		
}


ElementType Retrieve( Position P ){
	return P->Element;
}


HashTable Delete( ElementType X, HashTable T ){         //ver isto
}


HashTable MakeEmpty( HashTable T ){             //ver isto
}
