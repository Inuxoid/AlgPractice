#include <iostream>

void CollectNumbers(int& count, int& posCount, int& summ, int& posSumm, int& max, int& posMin, int& maxNumb, int& minPosNumb) {
	int x = 1;
	bool first = true;
	while (x != 0)
	{
		std::cout << "Enter: ";
		std::cin >> x;
		std::cout << "\n";
		if (x != 0)
		{
			count++;
			summ += x;
			if (x > 0)
			{
				posCount++;
				posSumm += x;
				if (first || x < posMin)
				{
					posMin = x;
					minPosNumb = count;
				}
			}
			if (first || x > max)
			{
				max = x;
				maxNumb = count;
			}
		}
		first = false;
	}
}

void CalculateAvg(int& count, int& posCount, int& summ, int& posSumm, float& avg, float& posAvg) {
	avg = static_cast<float>(summ) / static_cast<float>(count);
	posAvg = static_cast<float>(posSumm) / static_cast<float>(posCount);
}

void PrintNumbers(int& summ, float& avg, float& posAvg, int& max, int& posMin, int& maxNumb, int& minPosNumb) {
	std::cout << "Summ: " << summ << "\n";
	std::cout << "Avg: " << avg << "\n";
	std::cout << "Positive avg: " << posAvg << "\n";
	std::cout << "Max: " << max << " Numb: " << maxNumb << "\n";
	std::cout << "Min positive: " << posMin << " Numb: " << minPosNumb << "\n";
}

int main()
{
	int count = 0;
	int posCount = 0;
	int summ = 0;
	int posSumm = 0;
	float avg = 0;
	float posAvg = 0;
	int max = 0;
	int posMin = 0;
	int maxNumb = 0;
	int minPosNumb = 0;

	CollectNumbers(count, posCount, summ, posSumm, max, posMin, maxNumb, minPosNumb);
	CalculateAvg(count, posCount, summ, posSumm, avg, posAvg);
	PrintNumbers(summ, avg, posAvg, max, posMin, maxNumb, minPosNumb);
}