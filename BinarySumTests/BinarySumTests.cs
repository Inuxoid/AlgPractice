using Xunit;

namespace BinarySumTests
{
    public class BinarySumTests
    {
        [Fact]
        public void Sum1010_1010_10100result()
        {
            // arrange
            int[] arrayA = { 1, 0, 1, 0 };
            int[] arrayB = { 1, 0, 1, 0 };
            int[] expected = { 1, 0, 1, 0, 0 };

            // act
            Calculations calculations = new Calculations();
            int[] actual = calculations.BinarySum(arrayA, arrayB);

            // assert
            Assert.Equal(expected, actual);
        }
    }
}