using Xunit;


namespace InsertionSortTests
{
    public class InsertionSortTests
    {
        [Fact]
        public void Sort31_41_59_26_41_58_AscSorted()
        {
            // arrange
            int[] A = { 31, 41, 59, 26, 41, 58 };
            int[] expected = { 26, 31, 41, 41, 58, 59 };

            // act
            Calculations Calculations = new Calculations();
            int[] actual = Calculations.InsertionSortAsc(A);

            // assert
            Assert.Equal(expected, actual);
        }
    }
}