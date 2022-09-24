#include <iostream>

//por simplificacion esta funcion toma el ultimo elemento como pivote
//se colocan los elementos menores a la izquerda del pivote y
//los mayores a la derecha.
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivote o particion
    int i = (low- 1); // Index of smaller element and indicates
                      // the right position of pivot found so far

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* Implementa QuickSort
arr[] --> Arreglo a ordernar,
low --> indice inicial,
high --> indice final */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Recursivamente ordena los elementos antes del pivote y despues del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    std::cout << "Arreglo ordenado: \n";
    printArray(arr, n);
    return 0;
}
