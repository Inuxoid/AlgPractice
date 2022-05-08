using Xunit;

namespace LinearSearchTests
{
    public class LinearSearchTests
    {
        [Fact]
        public void Searc59In31_41_59_26_41_58_3returned()
        {
            // arrange
            int[] valuesArray = { 31, 41, 59, 26, 41, 58 };
            int desiredValue = 59;
            int expected = 3;

            // act
            Calculations calculations = new Calculations();
            int actual = calculations.LinearSearch(valuesArray, desiredValue);

            // assert
            Assert.Equal(expected, actual);
        }

        [Fact]
        public void Searc99In31_41_59_26_41_58_minus1returned()
        {
            // arrange
            int[] valuesArray = { 31, 41, 59, 26, 41, 58 };
            int desiredValue = 99;
            int expected = -1;

            // act
            Calculations calculations = new Calculations();
            int actual = calculations.LinearSearch(valuesArray, desiredValue);

            // assert
            Assert.Equal(expected, actual);
        }
    }
}