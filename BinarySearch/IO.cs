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

    internal void PtintIntVar(int var, string description = "")
    {
        Console.WriteLine($"{description} {var}");
    }

    internal List<int> GetSortedArray(List<int> array)
    {
        Random rand = new Random();
        
        int add = rand.Next(1, 10);
        for (int i = 0; i < 10; i++)
            array.Add(i + add / 2);
        return array;
    }

    internal int GetRandomIntVar(int var)
    {
        Random rand = new Random();

        var = rand.Next(1, 10);
        return var;
    }
}
