#include <iostream>
#include <cstdlib>
#include <ctime>

/*
Sejam os seguintes algoritmos de ordenação:
 Inserção direta
 Inserção binária
 Seleção
 Bubblesort
 Heapsort
 Fusão
 QuickSort
Pede-se:
a) Implemente os algoritmos relacionados para vetores de
inteiros com tamanho n (digitado pelo usuário).
b) Obtenha os gráficos dos números de comparações entre
chaves e de movimentações realizadas nos algoritmos
considerando-se pelo menos 5 diferentes valores de n para:
(1) vetores de entrada em ordem crescente
(2) vetores de entrada em ordem decrescente
(3) vetores de entrada com valores aleatórios
c) Analise os algoritmos através dos gráficos obtidos,
comentando se os resultados são condizentes com a análise
assintótica de cada algoritmo.
d) Baseado nos resultados obtidos, comente qual (ou quais)
algoritmo(s) de ordenação é(são) mais apropriado(s) para
cada tipo de vetor.

*/

using namespace std;
void clearScreen();
void menuOrdenacao(int *vetor, int n, int *count);
void ordInsercaoDireta(int *vetor, int n, int *count);
void ordSelecao(int *vetor, int n, int *count);
void ordBubllesort(int *vetor, int n, int *count);
void ordHeapsort(int *vetor, int n, int *count);
void ordFusao(int *vetor, int n, int *count);
void ordQuickSort(int *vetor, int esquerda, int direita, int *count);
void ordInsercaoBinaria(int *vetor, int n, int *count);
void merge(int *vetor, int esquerda, int meio, int direita, int *count);
void mergesort(int *vetor, int esquerda, int direita, int *count);

int main()
{

    int n, m, x;
inicio:
    cout << " Escreva o tamanho do vetor que voce quer ordenar: ";
    cin >> n;
    clearScreen();

    int *vetor = (int *)calloc(n, sizeof(int));
    int *count = (int *)calloc(2, sizeof(int));


    clearScreen();
    cout << " Escolha como vai ser a entrada para o vetor: \n\n";
    cout << "Digite (1) caso queira que a entrada seja um vetor em ordem crescente.\n";
    cout << "Digite (2) caso queira que a entrada seja um vetor em ordem decrescente.\n";
    cout << "Digite (3) caso queira que a entrada seja um vetor em ordem aleatoria.\n";
    cin >> m;
    clearScreen();

    switch (m)
    {
    case 1:
        for (int i = 1; i < n; i++)
        {
            vetor[i] = vetor[i - 1] + 2;
        }

        menuOrdenacao(vetor, n, count);

        break;

    case 2:
        for (int i = n - 2; i >= 0; i--)
        {
            vetor[i] = vetor[i + 1] + 2;
        }

        menuOrdenacao(vetor, n, count);

        break;

    case 3:
        for (int i = 0; i < n; i++)
        {
            vetor[i] = rand();
        }

        menuOrdenacao(vetor, n, count);

        break;

    default:
        break;
    }

    cin >> x;
    clearScreen();

    goto inicio;
    return 0;
}

void menuOrdenacao(int *vetor, int n, int *count)
{
    int m;
    cout << " Escolha o algoritmo que voce quer usar para ordenar o vetor.\n\n";
    cout << " Digite (1) para escolher o algoritmo de insercao direta. \n";
    cout << " Digite (2) para escolher o algoritmo de insercao binaria. \n";
    cout << " Digite (3) para escolher o algoritmo de selecao. \n";
    cout << " Digite (4) para escolher o algoritmo de blubblesort. \n";
    cout << " Digite (5) para escolher o algoritmo de heapsort. \n";
    cout << " Digite (6) para escolher o algoritmo de fusao. \n";
    cout << " Digite (7) para escolher o algoritmo de quicksort. \n";
    cin >> m;
    // cout << "\n\n";
    clearScreen();

    switch (m)
    {
    case 1:
        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        ordInsercaoDireta(vetor, n, count);

        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ",";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por insercao direta.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    case 2:

        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        ordInsercaoBinaria(vetor, n, count);
        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por insercao binaria.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    case 3:

        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        ordSelecao(vetor, n, count);

        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por selecao.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    case 4:

        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        ordBubllesort(vetor, n, count);

        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por bubllesort.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    case 5:

        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        ordHeapsort(vetor, n, count);

        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por heapsort.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    case 6:

        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        mergesort(vetor, 0, n - 1, count);

        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por fusao.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    case 7:

        cout << "Vetor desordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        ordQuickSort(vetor, 0, n, count);

        cout << "Vetor ordenado: {";
        for (int i = 0; i < n; i++)
        {
            cout << vetor[i] << ", ";
        }
        cout << "}\n\n";

        cout << "Ordenacao do vetor de tamanho " << n << " por quicksort.\n\n";
        cout << "Numero de atribuicoes: " << count[0] << "\n";
        cout << "Numero de comparacoes: " << count[1] << "\n";
        cout << "Total de operacoes primitivas: " << count[0] + count[1];

        count[0] = 0;
        count[1] = 0;

        break;

    default:

        break;
    }
}

void clearScreen()
{
#ifdef _WIN64
    system("cls");
#elif __linux
    system("clear");
#elif _WIN32
    system("cls");
#else
#endif
}

void ordInsercaoDireta(int *vetor, int n, int *count)
{
    int i, j, aux;

    for (i = 0; i < n - 1; i++) // 1
    {
        count[0] += 1;
        count[1] += 1;

        if (vetor[i] > vetor[i + 1]) // 1
        {
            aux = vetor[i + 1];
            vetor[i + 1] = vetor[i];
            vetor[i] = aux;
            j = i - 1;

            count[0] += 4;

            while (j >= 0) // 1
            {
                count[1] += 1;

                if (aux < vetor[j]) // 1
                {
                    vetor[j + 1] = vetor[j];
                    vetor[j] = aux;

                    count[0] += 2;
                }
                else
                {
                    break;
                }
                j = j - 1;

                count[0] += 1;
                count[1] += 1;
            }

            count[1] += 1;
        }

        count[1] += 1;
    }
}

void ordInsercaoBinaria(int *vetor, int n, int *count)
{

    int i, j, aux, esquerda, direita, meio;

    for (i = 1; i < n; i++) // 1
    {
        aux = vetor[i];
        esquerda = 0;
        direita = i;

        count[1] += 1;
        count[0] += 4;

        while (esquerda < direita) // 1
        {
            meio = (esquerda + direita) / 2;
            count[0] += 1;
            count[1] += 1;

            if (vetor[meio] <= aux)
            {
                esquerda = meio + 1;
            }
            else
            {
                direita = meio;
            }

            count[0] += 1;
            count[1] += 1;
        }

        count[1] += 1;

        for (j = i; j > esquerda; j--)
        {
            vetor[j] = vetor[j - 1];

            count[1] += 1;
            count[0] += 2;
        }

        vetor[direita] = aux;
    }
}

void ordSelecao(int *vetor, int n, int *count)
{

    int menor, aux;

    for (int i = 0; i < n - 1; i++) // 1
    {
        menor = i;

        count[0] += 2;
        count[1] += 1;

        for (int j = i + 1; j < n; j++)
        {
            count[0] += 1;
            count[1] += 1;

            if (vetor[menor] > vetor[j])
            {
                menor = j;

                count[0] += 1;
            }

            count[1] += 1;
        }
        if (i != menor)
        {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;

            count[0] += 3;
        }

        count[1] += 1;
    }
}

void ordBubllesort(int *vetor, int n, int *count)
{

    for (int j = n - 1; j >= 1; j--)
    {
        count[0] += 1;
        count[1] += 1;

        for (int i = 0; i < j; i++)
        {
            count[0] += 1;
            count[1] += 1;

            if (vetor[i] > vetor[i + 1])
            {
                int aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;

                count[0] += 3;
            }

            count[1] += 1;
        }
    }
}

void ordHeapsort(int *vetor, int n, int *count)
{
    int i = n / 2, pai, filho, aux;

    count[0] += 1;

    while (true)
    {
        count[1] += 1;

        if (i > 0)
        {
            i--;
            aux = vetor[i];

            count[0] += 2;
        }
        else
        {
            n--;
            if (n <= 0)
                return;
            aux = vetor[n];
            vetor[n] = vetor[0];

            count[0] += 3;
            count[1] += 1;
        }

        pai = i;
        filho = i * 2 + 1;

        count[0] += 1;

        while (filho < n)
        {
            count[1] += 1;

            if ((filho + 1 < n) && (vetor[filho + 1] > vetor[filho]))
            {
                filho++;

                count[0] += 1;
            }
            count[1] += 1;
            if (vetor[filho] > aux)
            {
                vetor[pai] = vetor[filho];
                pai = filho;
                filho = pai * 2 + 1;

                count[0] += 3;
            }
            else
            {
                break;
            }
            count[1] += 1;
        }
        vetor[pai] = aux;

        count[0] += 1;
    }
}

void ordQuickSort(int *vetor, int esquerda, int direita, int *count)
{

    // int *count = (int *)calloc(2, sizeof(int)); //count[0] é atribuicoes ou mudancas e count[1] sao as comparacoes.

    int i, j, pivo, aux;

    i = esquerda;
    j = direita - 1;

    pivo = vetor[(esquerda + direita) / 2];

    count[0] += 3;

    while (i <= j)
    {
        count[1] += 1;

        while (vetor[i] < pivo && i < direita)
        {
            count[1] += 1;
            count[0] += 1;

            i++;
        }

        count[1] += 1;

        while (vetor[j] > pivo && j > esquerda)
        {
            j--;

            count[1] += 1;
            count[0] += 1;
        }

        count[1] += 1;

        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;

            count[0] += 1;
        }

        count[1] += 1;
    }

    count[1] += 1;

    if (j > esquerda)
    {
        count[1] += 1;
        ordQuickSort(vetor, esquerda, j + 1, count);
    }
    count[1] += 1;
    if (i < direita)
    {
        count[1] += 1;
        ordQuickSort(vetor, i, direita, count);
    }
    count[1] += 1;
}

void mergesort(int *vetor, int esquerda, int direita, int *count)
{

    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        count[0] += 1;

        mergesort(vetor, esquerda, meio, count);
        mergesort(vetor, meio + 1, direita, count);

        merge(vetor, esquerda, meio, direita, count);
    }
    count[1] += 1;
}

void merge(int *vetor, int esquerda, int meio, int direita, int *count)
{

    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    count[0] += 2;

    int vEsquerda[n1], vDireita[n2];

    for (i = 0; i < n1; i++)
    {
        vEsquerda[i] = vetor[esquerda + i];

        count[1] += 1;
        count[0] += 2;
    }

    for (j = 0; j < n2; j++)
    {
        vDireita[j] = vetor[meio + 1 + j];

        count[1] += 1;
        count[0] += 2;
    }

    i = 0;
    j = 0;
    k = esquerda;

    count[0] += 3;

    while (i < n1 && j < n2)
    {
        count[1] += 1;

        if (vEsquerda[i] <= vDireita[j])
        {

            vetor[k] = vEsquerda[i];
            i++;

            count[0] += 2;
        }
        else
        {
            vetor[k] = vDireita[j];
            j++;

            count[0] += 2;
        }

        k++;
        count[0] += 1;
        count[1] += 1;
    }

    count[1] += 1;

    while (i < n1)
    {

        vetor[k] = vEsquerda[i];
        i++;
        k++;

        count[0] += 3;
        count[1] += 1;
    }

    count[1] += 1;

    while (j < n2)
    {
        vetor[k] = vDireita[j];
        j++;
        k++;

        count[0] += 3;
        count[1] += 1;
    }

    count[1] += 1;
}
