#include <iostream>
#include <vector>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> pending;
    bool openable[1000] = {};
    for (size_t i = 0; i < n; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        for (size_t j = 0; j < pending.size(); ) {
            if (pending[j] != b) {
                ++j;
            } else {
                std::swap(pending[j], pending.back());
                pending.pop_back();
            }
        }

        if (!openable[a-1])
            pending.push_back(a);

        openable[b-1] = true;
    }

    answer(pending.size());

    return 0;
}

