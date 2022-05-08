using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


public class Calculations
{
    public int LinearSearch(int[] array, int obj)
    {
        int answ = -2;
        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] == obj)
            {
                answ = i;
                break;
            }
        }
        return answ + 1;
    }
}

