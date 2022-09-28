#include <iostream>

template<typename T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template<typename T, int n>
void bubble_sort(T arr[n])
{
    int i, j;
    for(i=0; i< n; i++)
        for(j=0; j < n-i-1; j++)
            if(arr[j] > arr[j+1])
                Swap<T>(arr[j], arr[j+1]);
}

int main()
{
    const int N = 10;
    float a[N] = {2, 1, 5.9, 99, 22, 2.1, 4, 38, 1000, 0};

    # podemos ordenar numeros, en esta caso floats o ints
    bubble_sort<float, N>(a);
    std::cout << "Sorted floats:" << std::endl;
    for(int i=0; i<N; i++)
        std::cout << a[i] << std::endl;

    # tambien podemos ordenar characteres con el mismo template:
    char c[N] = {'b','z','a','A','C','c','f','w','h','b'};
    bubble_sort<char, N>(c);
    std::cout << "Sorted chars:" << std::endl;
    for(int i=0; i<N; i++)
        std::cout << c[i] << std::endl;

    return 0;
}

