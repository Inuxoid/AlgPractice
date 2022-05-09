using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class Launcher
{
    int[] arrayA = new int[9];
    int[] arrayB = new int[9];
    int[] arraySum = new int[10];
    IO IO = new IO();
    Calculations Calculations = new Calculations();
    internal void Launch()
    {
        arrayA = IO.GetRandomArray(arrayA);
        arrayB = IO.GetRandomArray(arrayB);
        IO.PtintIntArray(arrayA, "   ");
        IO.PtintIntArray(arrayB, "   ");
        arraySum = Calculations.BinarySum(arrayA, arrayB);
        IO.PtintIntArray(arraySum);
    }
}