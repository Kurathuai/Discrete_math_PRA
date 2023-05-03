
#include <algorithm> 
#include <iostream> 
#include <vector> 

int main()
{
	int first[] = { 5, 10, 15, 20, 25 };
	int second[] = { 50, 40, 30, 20, 10 };
	int n = sizeof(first) / sizeof(first[0]);

	std::cout << "First array contains :";
	for (int i = 0; i < n; i++)
		std::cout << " " << first[i];
	std::cout << "\n";

	std::cout << "Second array contains :";
	for (int i = 0; i < n; i++)
		std::cout << " " << second[i];
	std::cout << "\n\n";

	std::vector<int> v(10);
	std::vector<int>::iterator it, st;

	std::sort(first, first + 5);
	std::sort(second, second + 5);

	it = std::set_symmetric_difference(first, first + 5,
	second, second + 5, v.begin());

	std::cout << "The symmetric difference has "
			<< (it - v.begin()) << " elements:\n";
	for (st = v.begin(); st != it; ++st)
		std::cout << ' ' << *st;
	std::cout << '\n';

	return 0;
}
