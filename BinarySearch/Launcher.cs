using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class Launcher
{
    List<int> ArrayOfValues = new List<int>();
    int DesiredValue = new int();
    int DesiredValuePos = new int();
    IO IO = new IO();
    Calculations Calculations = new Calculations();
    internal void Launch()
    {
        ArrayOfValues = IO.GetSortedArray(ArrayOfValues);
        DesiredValue = IO.GetRandomIntVar(DesiredValue);
        IO.PtintIntArray(ArrayOfValues);
        IO.PtintIntVar(DesiredValue, "Desired value: ");
        DesiredValuePos = Calculations.BinarySearch(ArrayOfValues, DesiredValue, 0, ArrayOfValues.Count - 1);
        IO.PtintIntVar(DesiredValuePos, "Desired value position: ");
    }
}

