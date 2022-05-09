using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class Calculations
{
    public int[] BinarySum(int[] arrayA, int[] arrayB)
    {
        int[] arraySum = new int[arrayA.Length+1];
        int add = 0;
        for (int i = arraySum.Length - 1; i >= 1 ; i--)
        {
            if (arrayA[i-1] + arrayB[i-1] == 2)
            {
                arraySum[i] = add;
                add = 1;
            }
            else if (arrayA[i-1] + arrayB[i-1] + add == 2)
            {
                arraySum[i] = 0;
                add = 1;
            }
            else
            {
                arraySum[i] = arrayA[i-1] + arrayB[i-1] + add;
                add = 0;
            }
        }
        arraySum[0] = add;
        return arraySum;
    }
}