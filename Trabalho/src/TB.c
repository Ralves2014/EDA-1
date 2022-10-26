#include <stdio.h>
#include <stdlib.h>
#include "hashsep.h"
#include <wchar.h>
#include <locale.h>
#include <wctype.h>
#include "fatal.h"
#include <time.h>
#include <string.h>

int main(int argv1, char*argv[]){

    clock_t begin = clock(); 
    
    setlocale(LC_ALL, "");

    HashTable H=InitializeTable(10000000);
    wchar_t str[400];
    wchar_t *tmpWord;
    FILE *f;
    f=fopen(argv[1],"rb");

    while (fwscanf(f,L"%ls", str) != EOF){
        //printf("%ls\n", str);
        tmpWord = (wchar_t*)malloc(sizeof(wchar_t*)*wcslen(str));
        tmpWord = wcscpy(tmpWord, str);
        //printf("%lu\n", conv(tmpWord));
        //printf(" %ld\n", wcslen(tmpWord));
        Insert(tmpWord, H);
        
    }
    fclose(f);
    //PrintHashWordsTable(H); //Imprime a hashtable
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("TIME: %f s\n", time_spent);
    
    //Inicio
    wchar_t array1[400]=L"\0";//guardar as palavras do utilizador

    long n=1; //variável que irá guardar o numero inserido
    char aceitacao; //Variável que vai guardar se a palavra é ou não aceita pelo utilizador
    char aceitacao1; //Varivel que vai guardar se se sai ou nao do programa com base na resposta do utilizador
    Position P1; // P1 é a posição que vai alterar a medida que percorre a lista
    wchar_t text[400];// Irá guardar a palavra inserida manualmente pelo utilizador
    
    char Nome[20];//Variavel para guardar o nome do dicionario
    char NewName[40]; //Variavel para quardar o nome do dicionario sem o .txt
    char final[40]="\0"; //Variavel para guardar o nome final do dicionario ja atualizado
    wchar_t str1[400]; //Variavel auxiliar para copiar as palavras para o dicionário atualizado

    strcpy(Nome, argv[1]);

    for (int d = 0; Nome[d]!='.'; d++)
    {
        NewName[d]=Nome[d];
    }
    strcat(final,NewName);
    strcat(final,"-update.txt");
    
    printf("2:  a b c  ́a à â ã  c\n");
    printf("3:  d e f  ́e ê\n");
    printf("4:  g h i  ́ı\n");
    printf("5:  j k l\n");
    printf("6:  m n o  ́o ô õ\n");
    printf("7:  p q r s\n");
    printf("8:  t u v  ́u\n");
    printf("9:  w x y z\n");
    printf("** Escreva a sua mensagem **\n");

    while(n!=0){

        scanf("%ld", &n);
        if(n==0){
            printf("Deseja sair da aplicação (s/n)? ");
            scanf(" %c", &aceitacao1);
            if(aceitacao1=='s')
                break;
            else
                scanf("%ld", &n);
        }
        if (n==1)
        {   
            printf("Mensagem: %ls\n", array1);
        }
        else
        {
            
            aceitacao='n';
            P1= H->TheLists[Hash(n, H->TableSize)]->Next;
            while (aceitacao!='s' && n!=0 && P1!=NULL){
                
                printf("Sugestão: %ls, aceita(s/n)? ", P1->Element);
                scanf(" %c", &aceitacao);
                if (aceitacao=='s'){
                    
                    wcscat(array1, P1->Element);
                    wcscat(array1, L" ");
                    
                    
                    break;
                }
                else
                {
                    if (P1->Next!=NULL)
                    {
                        P1=P1->Next;
                    }
                    else
                    {
                        printf("Não existem mais sugestões; introduza a palavra do teclado.\n");
                        scanf("%ls\n", text);
                        
                        FILE *NF=fopen(final, "a+");//ficheiro para receber a palavra escrita pelo utilizador
                        FILE *First=fopen(argv[1], "r");//First é o ficheiro que se abriu inicialmente para guardar o dicionario na hashtable
                        while (fwscanf(First,L"%ls", str1) != EOF){
                            fwprintf(NF, L"%ls\n", str1);
                        }
                        fclose(First);
                        fwprintf(NF, L"%ls\n", text);
                        fclose(NF);
                        wcscat(array1, text);
                        wcscat(array1, L" ");
                        
                        aceitacao='s';   
                    }
                }
                
            }
            if(P1==NULL){
                printf("Não existe!\n");
                printf("Não existem mais sugestões; introduza a palavra do teclado.\n");
                scanf("%ls\n", text);
                
                FILE *NF=fopen(final, "a+");//ficheiro para receber a palavra escrita pelo utilizador
                FILE *First=fopen(argv[1], "r");//First é o ficheiro que se abriu inicialmente para guardar o dicionario na hashtable
                while (fwscanf(First,L"%ls", str1) != EOF){
                    fwprintf(NF, L"%ls\n", str1);
                }
                fclose(First);
                fwprintf(NF, L"%ls\n", text);
                fclose(NF);
                wcscat(array1, text);
                wcscat(array1, L" ");
                
                aceitacao='s';  
            }
        }

    }
    
    
    return 0;
}