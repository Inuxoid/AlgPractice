using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



public class Calculations
{
    public int BinarySearch(List<int> array, int desiredValue, int l, int r)
    {
        int ind = 0;
        int m = l + (r - l) / 2;
        if (l < r)
        {
            if (array[m] < desiredValue)
            {
                ind = BinarySearch(array, desiredValue, m, r);
            }
            else if (array[m] > desiredValue)
            {
                ind = BinarySearch(array, desiredValue, l, m);
            }
            else
            {
                ind = m + 1;
            }
        }
        else
        {
            ind = -1;
        }
        return ind;
    }
}
