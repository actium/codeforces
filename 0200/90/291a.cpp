#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<size_t>& id)
{
    int z = 0;

    std::unordered_map<size_t, size_t> x;
    for (const size_t a : id) {
        if (a == 0)
            continue;

        const size_t c = ++x[a];
        if (c > 2)
            return answer(-1);

        z += (c == 2);
    }

    answer(z);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> id(n);
    std::cin >> id;

    solve(id);

    return 0;
}

