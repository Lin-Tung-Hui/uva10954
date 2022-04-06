#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#ifdef GTEST
#include <gtest/gtest.h>
#endif

int add_all(std::istream &is, std::ostream &os)
{
    std::string line;
    std::getline(is, line);
	std::stringstream output;
    int number = std::stoi(line);

    while ((number >= 2)&&(number <= 5000)) {

		std::getline(is, line);
	    std::stringstream lineStream(line);
    	std::string token;
    	std::vector< int > myvector;

		int i = 0;
    	while(lineStream >> token && i < number) {
			myvector.push_back( std::stoi(token) );
			i++;
    	}

        std::sort(myvector.begin(), myvector.end());

		int cost = myvector[0] + myvector[1];
		int sum = cost;
		for(int i=2; i < myvector.size(); i++){
			cost = cost + myvector[i];
			sum = sum + cost;
		}
        output << sum << "\n";

		std::getline(is, line);
		number = std::stoi(line);
	}
	std::cout << output.str();
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
