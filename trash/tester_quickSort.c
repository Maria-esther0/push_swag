/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_quickSort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariavillarroel <mariavillarroel@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:55:43 by mariavillar       #+#    #+#             */
/*   Updated: 2023/04/06 17:34:52 by mariavillar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// Función para intercambiar dos números
void swap(int* a, int* b) 
{
    int t;
    
    t = *a;
    *a = *b;
    *b = t;
}

// Función que devuelve el índice del pivote
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    //for (int j = low; j <= high - 1; j++) {
    int j; 
    
    j = low;
    while (j <= high -1)
    {    
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Función principal de QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir la matriz
void printArray(int arr[], int size)
{
    int i;
    //for (i = 0; i < size; i++)
    i = 0;
    while (i < size)
    {    
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

// Programa principal para probar la función QuickSort
int main()
{
    int arr[] = {10, 734245, 8, 29, 142, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("La matriz ordenada es: \n");
    printArray(arr, n);
    return 0;
}
