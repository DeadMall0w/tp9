#include "file.h" 


// Utilisait pour déboguer 
void debug(char *c){
    // printf("[DEBUG] %s \n", c);
}


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Queue = -1;
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
    if (ptrF->Tete == ptrF->Queue){ // On enlève le dernier element, dcp on peut réinitialiser l'élément 
        initFile(ptrF);
    }else{   
        ptrF->Tete += 1;
        ptrF->Tete = ptrF->Tete % MAX;
    }
        

    return 0;
};

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    // printf("queue : %d \n", ptrF->Queue);
    if (filePleine(ptrF)){
        // printf("File pleine !");
        return 1;
    }

    ptrF->Queue += 1;
    ptrF->Queue = ptrF->Queue % MAX;
    // printf("POSTION QUEUE : %d \n", ptrF->Queue);

    affecterElt(&ptrF->Elts[ptrF->Queue], ptrE);
    debug("Ajout d'un élément dans la pile !");
    return 0;
} 

int fileVide(const  T_File *prtF) // qd Tete == 0 
{
    // return (prtF->Tete == prtF->Queue)?1:0;
    if (prtF->Queue == -1){
        return 1;
    }

    return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if (ptrF->Tete == 0 && ptrF->Queue == MAX-1){ // file pleine cas 1
        return 1;
    }

    if (ptrF->Queue+1 == ptrF->Tete && ptrF->Queue != -1){
        debug("TETE ET QUEUE TROP PROCHE, DONC FILE PLEINE ! \n");
        return 1;
    }

    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    if (fileVide(ptrF)){
        // return 0;
        printf("Pile vide ! \n");
    }

    return ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    T_Elt e;

    T_File emp;
    initFile(&emp);
    // Dans un premier temps nous allons copier tous les éléments dans une autre file
    while (fileVide(ptrF) == 0){ // Tant que la file n'est pas vide
        retirer(ptrF, &e);
        // debugFile(ptrF);
        afficherElt(&e);
        // printf("\n");
        ajouter(&emp, &e);
    
    }

    while (fileVide(&emp) == 0){ // Tant que la file n'est pas vide
        retirer(&emp, &e);
        // afficherElt(&e);
        // printf("\n");
        ajouter(ptrF, &e);
    }
}

// Affiche la pile comme un tableau surtout utiliser pour le débogage 
void debugFile(T_File *ptrF){
    // debug("debug FILE !");
    printf("tete %d & queue %d \n", ptrF->Tete, ptrF->Queue);
    int i;
    for (i = ptrF->Tete; i < ptrF->Queue+1; i++)
    {
        printf("index %d : ", i);

        // afficherElt(ptrF->Elts[i]);
        printf("%d \n", ptrF->Elts[i]);
    }
}






