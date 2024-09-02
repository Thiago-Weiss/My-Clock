#include <stdio.h>

// Definição da struct com bit-fields
typedef struct
{
    unsigned var1 : 1; // 1 bit
    unsigned var2 : 2; // 2 bits
    unsigned var3 : 5; // 5 bits
    unsigned var4 : 3; // 3 bits
} BitFields;

// Tipo de função que aponta para um membro da struct
typedef void (*FieldUpdater)(BitFields *);

// Funções que incrementam campos específicos
void incrementVar1(BitFields *bf)
{
    if (bf->var1 < 1)
    {
        bf->var1++;
    }
}

void incrementVar2(BitFields *bf)
{
    if (bf->var2 < 3)
    {
        bf->var2++;
    }
}

void incrementVar3(BitFields *bf)
{
    if (bf->var2 < 3)
    {
        bf->var2++;
    }
}

void incrementVar4(BitFields *bf)
{
    if (bf->var4 < 7)
    {
        bf->var4++;
    }
}

// Função que usa um ponteiro para a função que incrementa o campo
void incrementField(BitFields *bf, FieldUpdater updater)
{
    updater(bf);
}

int main()
{
    BitFields bf = {0, 0, 0, 0}; // Inicialize a struct com zeros

    // Exemplo de uso
    incrementField(&bf, incrementVar1);
    incrementField(&bf, incrementVar2);
    incrementField(&bf, incrementVar3);
    incrementField(&bf, incrementVar4);

    // Exibindo os resultados
    printf("var1: %u\n", bf.var1);
    printf("var2: %u\n", bf.var2);
    printf("var3: %u\n", bf.var3);
    printf("var4: %u\n", bf.var4);

    return 0;
}
