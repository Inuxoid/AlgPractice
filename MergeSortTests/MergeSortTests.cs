using Xunit;
using System;
using System.Collections.Generic;

namespace MergeSortTests
{
    public class MergeSortTests
    {
        [Fact]
        public void Sort31_41_59_26_41_58_AscSorted()
        {
            // arrange
            List<int> A = new List<int> { 31, 41, 59, 26, 41, 58 };
            List<int> expected = new List<int> { 26, 31, 41, 41, 58, 59 };

            // act
            Calculations Calculations = new Calculations();
            List<int> actual = Calculations.MergeSort(A, 0, A.Count - 1);

            // assert
            Assert.Equal(expected, actual);
        }
    }
}