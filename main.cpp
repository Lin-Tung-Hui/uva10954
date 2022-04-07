#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

#ifdef GTEST
#include <gtest/gtest.h>
#endif

int get_unadded_value(std::multimap< int, bool > &mmap)
{
    auto it = mmap.begin();
    while (it != mmap.end()) {
        if (it->second == false) {
            it->second = true;
            return it->first;
        }
        ++it;
    }
    return -1;
}

int add_all(std::istream &is, std::ostream &os)
{
    std::string line;
    std::getline(is, line);
    int number = std::stoi(line);

    while ((number >= 2) && (number < 10000)) {

        std::getline(is, line);
        std::stringstream lineStream(line);
        std::string token;
        std::vector< int > sumvector;
        std::multimap< int, bool > mmap;
        int i = 0;
        while (lineStream >> token && i < number) {
            mmap.insert(std::pair< int, bool >(std::stoi(token), false));
            i++;
        }

        int first, second, sum;

        while (true) {
            first = get_unadded_value(mmap);
            if (first == -1)
                break;
            second = get_unadded_value(mmap);
            if (second == -1)
                break;
            sum = first + second;
            mmap.insert(std::pair< int, bool >(sum, false));
            sumvector.push_back(sum);
        }

        sum = 0;
        for (auto &v : sumvector) {
            sum = sum + v;
        }
        os << sum << "\n";
        std::getline(is, line);
        number = std::stoi(line);
    }
    return 0;
}

int main(int argc, char **argv)
{

#ifdef GTEST
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
#endif

    add_all(std::cin, std::cout);

    return 0;
}
