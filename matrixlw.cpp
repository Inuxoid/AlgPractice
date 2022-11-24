#include <fstream>
#include <iostream>

int** read_array(std::istream &in, int& matrix_size)
{
    if (in >> matrix_size)
    {
        std::cout << matrix_size << std::endl;

        const auto matrix = new int*[matrix_size];
        for (int i = 0; i < matrix_size; i++)
            matrix[i] = new int[matrix_size];

        for (int i = 0; i < matrix_size; i++)
        {
            for (int j = 0; j < matrix_size; j++)
            {
                in >> matrix[i][j];
            }
        }
        return matrix;
    }
    std::cerr << "Input file could not be opened or end of file reached\n"; // NOLINT(clang-diagnostic-invalid-pp-token)
    return nullptr;
}

void print_matrix(std::ofstream &out, int** matrix, const int matrix_size)
{
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            std::cout.width(6);
            std::cout.precision(2);
            std::cout << matrix[i][j];
            out << matrix[i][j] << " ";
        }
        std::cout << std::endl;
        out << std::endl;
    }
}

void print_numb(std::ofstream &out, const int sum)
{
    std::cout << sum << std::endl;
    out << sum << std::endl;
}

int find_sum(int** matrix, const int matrix_size)
{
    int sum = 0;
    for (int i = 1; i < matrix_size; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int** smooth_matrix(const int matrix_size, int** matrix)
{
    const auto smoothed_matrix = new int*[matrix_size];
    for (int i = 0; i < matrix_size; i++)
        smoothed_matrix[i] = new int[matrix_size];

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            int tmp = 0;
            int for_numb = 0;
            if (i > 0)
            {
                tmp += matrix[i - 1][j];
                for_numb++;
                if (j > 0)
                {
                    tmp += matrix[i - 1][j - 1];
                    for_numb++;
                }
                if (j < matrix_size - 1)
                {
                    tmp += matrix[i - 1][j + 1];
                    for_numb++;
                }
            }
            if (i < matrix_size - 1)
            {
                tmp += matrix[i + 1][j];
                for_numb++;
                if (j > 0)
                {
                    tmp += matrix[i + 1][j - 1];
                    for_numb++;
                }
                if (j < matrix_size - 1)
                {
                    tmp += matrix[i + 1][j + 1];
                    for_numb++;
                }
            }

            if (j > 0)
            {
                tmp += matrix[i][j - 1];
                for_numb++;
            }
            if (j < matrix_size - 1)
            {
                tmp += matrix[i][j + 1];
                for_numb++;
            }
            smoothed_matrix[i][j] = tmp / for_numb;
        }
    }
    return smoothed_matrix;
}

void clean_memory(const int matrix_size, int** matrix)
{
    for (int i = 0; i < matrix_size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main(int argc, char* argv[])
{
    const std::string infile = "infile.txt";
    const std::string outfile = "outfile.txt";
    std::ifstream in(infile);
    std::ofstream out(infile);
    int matrix_size;

    while (true)
        {
        int** matrix = read_array(in, matrix_size);
        if (matrix != nullptr)
        {
            print_matrix(out, matrix, matrix_size);

            int** smoothed_matrix = smooth_matrix(matrix_size, matrix);
            print_matrix(out, smoothed_matrix, matrix_size);

            const int sum = find_sum(smoothed_matrix, matrix_size);
            print_numb(out, sum);
            clean_memory(matrix_size, matrix);
            clean_memory(matrix_size, smoothed_matrix);
            continue;
        }
        break;
    }

    in.close();
    return 0;
}
