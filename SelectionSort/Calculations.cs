using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Calculations
{
    public List<int> SelectionSort(List<int> array)
    {
        List<int> sortedArray = new List<int>();
        int count = array.Count;

        for (int i = 0; i < count; i++)
        {
            sortedArray.Add(array.Min());
            array.Remove(array.Min());
        }
        return sortedArray;
    }
}
