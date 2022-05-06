using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


internal class Сalculations
{
    internal int[] InsertionSort(int[] A)
    {
        int i;
        int j;
        int key;

        for (j = 1; j < A.Length; j++)
        {
            key = A[j];
            i = j - 1;
            while (i >= 0 && A[i] > key)
            {
                A[i + 1] = A[i];
                i--;
            }
            A[i + 1] = key;
        }

        return A;
    }
}

