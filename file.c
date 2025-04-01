#include "file.h" 



void debug(char *c){
    printf("[DEBUG] %s \n", c);
}


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = 0;
    ptrF->Tete = 0;

    debug("Initialiser de la file réussie !");
    
}

int  retirer(T_File *ptrF, T_Elt *ptrE) //si pas vide, en tete de file
{
    if (fileVide(ptrF)){
        debug("File vide !");
        return 1;
    }

    *ptrE = ptrF->Elts[ptrF->Tete];
    ptrF->Tete += 1;
    return 0;
};

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    // printf("queue : %d \n", ptrF->Queue);
    if (filePleine(ptrF)){
        debug("File pleine !");
        return 1;
    }
    affecterElt(&ptrF->Elts[ptrF->Queue], ptrE);
    ptrF->Queue += 1;
    debug("Ajout d'un élément dans la pile !");
    return 0;
} 

int fileVide(const  T_File *prtF) // qd Tete == 0 
{
    return (prtF->Tete == prtF->Queue)?1:0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if (ptrF->Tete == 0 && ptrF->Queue == MAX){ // file pleine cas 1
        return 1;
    }

    // if (ptrF->Queue == ptrF->Tete +1){
    //     return 1;
    // }

    return 0;
    // return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
return 0;
}

void afficherFile(T_File *ptrF)
{

}

// Affiche la pile comme un tableau surtout utiliser pour le débogage 
void debugFile(T_File *ptrF){
    // debug("debug FILE !");
    printf("tete %d & queue %d \n", ptrF->Tete, ptrF->Queue);
    int i;
    for (i = ptrF->Tete; i < ptrF->Queue; i++)
    {
        printf("index %d : ", i);

        // afficherElt(ptrF->Elts[i]);
        printf("%d \n", ptrF->Elts[i]);
    }
}






