﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class Launcher
{
    List<int> A = new List<int>();
    List<int> B = new List<int>();
    List<int> C = new List<int>();
    IO IO = new IO();
    Calculations Calculations = new Calculations();
    internal void Launch()
    {
        A = IO.GetRandomArray(A);
        IO.PtintIntArray(A);
        A = Calculations.MergeSort(A, 0, A.Count - 1);
        IO.PtintIntArray(A);
    }
}