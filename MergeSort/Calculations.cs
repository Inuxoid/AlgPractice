using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Calculations
{
    public List<int> MergeSort(List<int> array, int l, int r)
    {
        if (l < r)
        {
            int m = l + (r - l) / 2;
            
            MergeSort(array, 0, m);
            MergeSort(array, m+1, r);

            Merge(array, l, m, r);
        }
        return array;
    }

    void Merge(List<int> array, int l, int m, int r)
    {
        int sizeA = m - l + 1;
        int sizeB = r - m;

        int[] arrayA = new int[sizeA];
        int[] arrayB = new int[sizeB];
        int i, j;

        for (i = 0; i < sizeA; i++)
            arrayA[i] = array[l + i];
        for (j = 0; j < sizeB; j++)
            arrayB[j] = array[m + 1 + j];

        i = 0;
        j = 0;

        int k = l;
        while (i < sizeA && j < sizeB)
        {
            if (arrayA[i] <= arrayB[j])
            {
                array[k] = arrayA[i];
                i++;
            }
            else
            {
                array[k] = arrayB[j];
                j++;
            }
            k++;
        }

        while (i < sizeA)
        {
            array[k] = arrayA[i];
            i++;
            k++;
        }

        while (j < sizeB)
        {
            array[k] = arrayB[j];
            j++;
            k++;
        }
    }
}