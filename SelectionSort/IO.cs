using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class IO
{
    internal void PtintIntArray(List<int> array)
    {
        Console.WriteLine("[{0}]", string.Join(", ", array));
    }

    internal List<int> GetRandomArray(List<int> array)
    {
        Random rand = new Random();

        for (int i = 0; i < 10; i++)
            array.Add(rand.Next(1, 10));
        return array;
    }
}
