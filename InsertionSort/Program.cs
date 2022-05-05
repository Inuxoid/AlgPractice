int[] A = new int[10];
Random rand = new Random();

for (int i = 0; i < A.Length; i++)
    A[i] = rand.Next(1, 10);

Console.WriteLine("[{0}]", string.Join(", ", A));

InsertionSort(A);

Console.WriteLine("[{0}]", string.Join(", ", A));

int[] InsertionSort(int[] A)
{
    int i;
    int j;
    int key;

    for (j = 1; j < A.Length; j++)
    {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i+ 1] = key;
    }

    return A;
}