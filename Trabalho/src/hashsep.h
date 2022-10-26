typedef long ElementType;


#ifndef _HashSep_H
#define _HashSep_H

struct ListNode;
typedef struct ListNode *Position;

struct ListNode{
    wchar_t *Element;
    Position    Next;
};

typedef Position List;

struct HashTbl{
    int TableSize;
    List *TheLists;
};

unsigned long conv(wchar_t *str);

struct HashTbl;
typedef struct HashTbl *HashTable;

long Hash( unsigned long Key, int TableSize );

HashTable InitializeTable( int TableSize );
void DestroyTable( HashTable H );

Position Find( wchar_t *str, HashTable H );
void Insert( wchar_t *str, HashTable H );
wchar_t *Retrieve( Position P );
void PrintHashWordsTable(HashTable T);

/*
HashTable Delete( ElementType X, HashTable T );
HashTable MakeEmpty( HashTable T );
*/
#endif
