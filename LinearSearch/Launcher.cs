using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class Launcher
{
    int[] ArrayOfValues = new int[10];
    int DesiredValue = new int();
    int DesiredValuePos = new int();
    IO IO = new IO();
    Calculations Calculations = new Calculations();
    internal void Launch()
    {
        ArrayOfValues = IO.GetRandomArray(ArrayOfValues);
        DesiredValue = IO.GetRandomIntVar(DesiredValue);
        IO.PtintIntArray(ArrayOfValues);
        IO.PtintIntVar(DesiredValue, "Desired value: ");
        DesiredValuePos = Calculations.LinearSearch(ArrayOfValues, DesiredValue);
        IO.PtintIntVar(DesiredValuePos, "Desired value position: ");
    }
}

