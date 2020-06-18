#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t untreated_crime_count = 0;
    for (size_t i = 0, man_power = 0; i < n; ++i) {
        int event;
        std::cin >> event;

        if (event > 0)
            man_power += event;
        else if (man_power > 0)
            --man_power;
        else
            ++untreated_crime_count;
    }

    answer(untreated_crime_count);

    return 0;
}

