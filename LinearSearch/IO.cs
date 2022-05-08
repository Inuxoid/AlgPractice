using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class IO
{
    internal void PtintIntArray(int[] array)
    {
        Console.WriteLine("[{0}]", string.Join(", ", array));
    }

    internal void PtintIntVar(int var, string description = "")
    {
        Console.WriteLine($"{description} {var}");
    }

    internal int[] GetRandomArray(int[] array)
    {
        Random rand = new Random();

        for (int i = 0; i < array.Length; i++)
            array[i] = rand.Next(1, 10);
        return array;
    }

    internal int GetRandomIntVar(int var)
    {
        Random rand = new Random();

        var = rand.Next(1, 10);
        return var;
    }
}

