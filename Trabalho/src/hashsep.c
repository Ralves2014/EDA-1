#include<stdio.h>
#include "fatal.h"
#include "hashsep.h"
#include<wchar.h>
#include <stdlib.h>
#include <wctype.h>


#define MinTableSize (10)

//typedef unsigned int Index;
/*
struct ListNode{
    wchar_t *Element;
    Position    Next;
};
typedef Position List;


struct HashTbl{
    int TableSize;
    List *TheLists;
};
*/
unsigned long conv(wchar_t *str){
    int i=0;
    unsigned long num=0;
    for (; i < wcslen(str); i++)
    {
        str[i]=towlower(str[i]);
        if(str[i] == L'a' || str[i]==L'b' || str[i]==L'c'|| L'à'==str[i] || str[i]==L'á' || str[i]==L'ã' || str[i]==L'â' || str[i]==L'ç')
            num=num*10+2;
        else if(str[i] == L'd' || str[i] == L'e' || str[i] == L'f' || str[i] == L'é' || str[i] == L'ê')
            num=num*10+3;
        else if(str[i] == L'g' || str[i] == L'h' || str[i] == L'i' || str[i] == L'í')
            num=num*10+4;
        else if(str[i] == L'j' || str[i] == L'k' || str[i] == L'l')
            num=num*10+5;
        else if(str[i] == L'm' || str[i] == L'n' || str[i] == L'o' || str[i]==L'ó' || str[i]==L'õ' || str[i]==L'ô')
            num=num*10+6;
        else if(str[i] == L'p' || str[i] == L'q' || str[i] == L'r' || str[i] == L's')
            num=num*10+7;
        else if(str[i] == L't' || str[i] == L'u' || str[i] == L'v' || str[i] == L'ú')
            num=num*10+8;
        else if(str[i] == L'w' || str[i] == L'x' || str[i] == L'y' || str[i] == L'z')
            num=num*10+9;
    }
    //printf("%ld", num);
    return num;

}

/* Return next prime; assume N >= 10 */
static int NextPrime( int N ){
    int i;

    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 ){
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
        return N;
      ContOuter: ;
    }
}



/* Hash function for ints */
long Hash( unsigned long Key, int TableSize ){
    return Key%TableSize;
}


HashTable InitializeTable( int TableSize ){
    HashTable H;
    int i;

    /* Check TableSize */
    if (TableSize<MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }
    /* Allocate table */
    H=malloc(sizeof(struct HashTbl));
    if(H==NULL)
        FatalError("Out of space");

    /* Allocate array of lists */
    H->TableSize = NextPrime( TableSize );
    H->TheLists = malloc( sizeof(List) * H->TableSize );
    if( H->TheLists == NULL )
        FatalError( "Out of space!!!" );
    /* Allocate list headers */
    for (i = 0; i < H->TableSize; i++)
    {
        H->TheLists[i]= malloc(sizeof(struct ListNode));
        if(H->TheLists[i]==NULL)
            FatalError("Out of space");
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

}


Position Find( wchar_t *str, HashTable H ){
    Position P;
    List L;
    unsigned long aux=conv(str);
    L=H->TheLists[Hash(aux, H->TableSize)];
    P=L->Next;

    while((P!=NULL) && (P->Element != str))
        P=P->Next;
    
    return P;
}


void Insert( wchar_t *str, HashTable H ){
    Position pos, NewCell;
    List L;

    pos=Find(str, H);
    if (pos==NULL)
    {
        NewCell=malloc(sizeof(struct ListNode));
        NewCell->Element=(wchar_t *)malloc(sizeof(wchar_t *)*wcslen(str));
        if(NewCell==NULL)
            FatalError("Out of space");
        else
        {
            L=H->TheLists[Hash(conv(str), H->TableSize)];
            NewCell->Next=L->Next;
            NewCell->Element=str;
            L->Next=NewCell;
        }
    }
    else
    {
        NewCell=malloc(sizeof(struct ListNode));
        NewCell->Element=(wchar_t *)malloc(sizeof(wchar_t *) * wcslen(str));
        pos->Next=NewCell;
        NewCell->Element=str;
        NewCell->Next=NULL;
    }
    
}


wchar_t *Retrieve( Position P ){
    return P->Element;
}


//HashTable Delete( wchar_t *str, HashTable T ){
//}

/*
HashTable MakeEmpty( HashTable T ){
}
*/
void PrintHashWordsTable(HashTable T)
{
    printf("* Printing HashTable *\n");

    for(int i=0 ; i < T->TableSize ; i++)
    {   
        Position P = T->TheLists[i]->Next;

        if(P != NULL)
        {
            printf("%d\t[", i);
            while(P != NULL)
            {
                P->Element[wcslen(P->Element)+1] = 0;
                printf("%ls", P->Element);
                printf(" %ld", wcslen(P->Element));
                P = P->Next;

                //If is not the last element
                if(P != NULL)
                    printf(", ");
            }
            printf("]\n");
        }
        /*else
            printf("%d\t[%s]\n", i, "--");*/
    }
}
