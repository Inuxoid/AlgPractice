using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class IO
{
    internal void PtintIntArray(int[] array, string tab = "")
    {
        Console.Write(tab);
        Console.WriteLine("[{0}]", string.Join(", ", array));
    }

    internal int[] GetRandomArray(int[] array)
    {
        Random rand = new Random();

        for (int i = 0; i < array.Length; i++)
            array[i] = rand.Next(0, 2);
        return array;
    }
}
