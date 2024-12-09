/*
    Rearranjar um conjunto de objetos em ordem ascendente ou descendente.
    BUBBLESORT:
        -um dos piores
        -mais simples
    SELECTIONSORT:
        -encontra o menor elemento no arranjo nao ordenado e troca se necessario(o elemento nao esta na posicao correta)
        -posicoes ja vistas nao sao revisadas
        -se os dados ja estiverem ordenados nao afeta o desempenho do algoritmo
    INSERTIONSORT
        -baseado na insercao de itens
        -pega uma objeto e confere se ele e menor que o elemento anterior, e assim vai ate achar a posicao adequada
    SHELLSORT
        -considera incrementos decrescentes para definir a sublista de itens a serem comparados
    QUICKSORT
        -E um dos algoritmos mais rapidos que existe
        -metodo recursivo 
        -utiliza-se de um elemento pivo x
            -vai particionar o arranjo em:
                -elementos menores ou iguais que x a esquerda
                -elementeos maiores que x a direita
        -faz a chamada recursiva para ordenar cada particao
    MERGSORT
        - muito eficiente
        -divide um conjunto recursivamente ao meio
        -realiza a fusao ordenada entra duas particoes ordenadas
*/
typedef struct registro{
    int chave;
}registro;
//BUBBLESORT
void bubblesort(registro *v, int n)
{
    int i, j;
    registro temp;
    for(i=0; i<n-1; i++)
    {
        for(j=1; j<n; j++)
        {
            if(v[j].chave<v[j-1].chave)
            {
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }
}
//SELCTIONSORT
void selectionsort(registro *v, int n)
{
    int i, j, menor;
    registro temp;
    for(i=0; i<n; i++)
    {
        menor = i;
        for(j=i+1; j<n; j++)
        {
            if(v[j].chave<v[menor].chave)
            {
                menor =j;
            }
        }
        temp=v[menor];
        v[menor]=v[i];
        v[i]=temp;
    }
}
//INSERTIONSORT
void insertionsort(registro *v, int n)
{
    int i, j;
    registro temp;
    for(i=1;i<n; i++)
    {
        temp = v[i];
        j = i - 1;
        while((j >= 0) && (temp.chave < v[i].chave))
        {
            v[j+1]=v[j];
            j--;
        }
        v[j+1] = temp;
    }
}
//SHELLSORT
void shellsort(registro *v, int n)
{
    int i, j;
    int h=1;
    registro temp;

    do{
        h=h*3+1;
    }while(h<n);
    
    do{
        h /= 3;
        for(i=h; i<n; i++)
        {
            temp =v[i];
            j=i;
            while(v[j - h].chave > temp.chave)
            {
                v[j] = v[j - h];
                j -= h;
                if(i<h)
                {
                    break;
                }
            }
        }
    }while(h != 1);
}
//QUICKSORT
void partition(int Esq, int Dir, int *i, int *j, registro *v)
{
    registro x, w;
    *i = Esq; 
    *j = Dir;
    x = v[(*i + *j)/2];

    do{
        while(x.chave > v[*i].chave)
        {
            (*i)++;
        }
        while(x.chave < v[*j].chave)
        {
            (*j)--;
        }
        if(*j <= *j)
        {
            w = v[*i];
            v[*i] = v[*j];
            v[*j] = v[*j];
            (*i)++;
            (*j)--;
        }
    }while(*i <= *j);
}
void sort(int Esq, int Dir, registro *v)
{
    int i,j;
    partition(Esq, Dir, &i, &j, v);
    if(Esq < j)
    {
        sort(Esq, j, v);
    }
    if(i<Dir)
    {
        sort(i, Dir, v);
    }
}
void quicksort(registro *v, int n)
{
    sort(0, n-1, v);
}
//MERGESORT
void merge(registro *v, int p, int q, int r)
{
    int i, j, k;
    registro *w;
    w = (registro *) malloc ((r-p+1) * sizeof(registro));
    i = p;
    j= q+1;
    k=0;

    while(i <= q && j <= q)
    {
        if(v[i].chave <= v[i].chave)
        {
            w[k++] = v[i++];
        }
        else{
            w[k++] = v[j++];
        }
            
    }
    while(i<=q)
    {
        w[k++]=v[i++];
    }
    while(j<=r)
    {
        w[k++]=v[j++];
    }
    for(i=p; i<=r; i++)
    {
        v[i]=w[i-p];
    }
    free(w);
}
void mergesort(registro *v, int ini, int fim)
{
    int meio;
    if(ini < fim)
    {
        meio=(ini + fim)/2;
        mergesort(v, ini,meio);
        mergesort(v, meio+1, fim);
        merge(v, ini,meio, fim);
    }
}