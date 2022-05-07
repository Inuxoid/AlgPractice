using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


internal class Launcher
{
    int[] A = new int[10];
    IO IO = new IO();
    Сalculations Calculations = new Сalculations();
    internal void Launch()
    {
        A = IO.GetRandomArray(A);
        IO.PtintIntArray(A);
        Calculations.InsertionSortAsc(A);
        IO.PtintIntArray(A);
        Calculations.InsertionSortDesc(A);
        IO.PtintIntArray(A);
    }
}