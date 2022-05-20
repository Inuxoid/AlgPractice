using Xunit;
using System.Collections.Generic;

namespace BinarySearchTests
{
    public class BinarySearchTests
    {
        [Fact]
        public void Searc59In31_41_59_76_661_548_3returned()
        {
            // arrange
            List<int> valuesArray = new List<int> { 31, 41, 59, 76, 661, 548 };
            int desiredValue = 59;
            int expected = 3;

            // act
            Calculations calculations = new Calculations();
            int actual = calculations.BinarySearch(valuesArray, desiredValue, 0, valuesArray.Count - 1);

            // assert
            Assert.Equal(expected, actual);
        }
    }
}