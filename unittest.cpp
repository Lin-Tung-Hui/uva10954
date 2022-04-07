#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "main.cpp"

TEST(add_all, test_1)
{
    std::istringstream iss("3\n"
                           "6 5 4\n"
                           "10\n"
                           "9 5 48 2 4 5 6 3 5 4\n"
                           "10\n"
                           "3 4 5 4 7 2 3 8 4 5\n"
                           "0\n");

    std::ostringstream oss;

    add_all(iss, oss);

    EXPECT_EQ("24\n"
              "224\n"
              "147\n",
              oss.str());
}

TEST(add_all, test_2)
{
    std::istringstream iss("8\n"
                           "4 4 6 6 8 8 10 10\n"
                           "8\n"
                           "4 6 6 7 7 8 8 9\n"
                           "8\n"
                           "3 4 6 6 6 8 8 9\n"
                           "8\n"
                           "3 4 5 5 5 5 8 9\n"
                           "2\n"
                           "99999 0\n"
                           "4\n"
                           "99997 49999 49999 49999\n"
                           "4\n"
                           "49999 99998 49999 49999\n"
                           "0\n");
    std::ostringstream oss;

    add_all(iss, oss);

    EXPECT_EQ("166\n"
              "165\n"
              "148\n"
              "130\n"
              "99999\n"
              "499988\n"
              "499990\n",
              oss.str());
}

TEST(add_all, test_uDebug)
{
    std::ifstream input_file("test_uDebug.txt");

    std::ostringstream oss;

    add_all(input_file, oss);

    EXPECT_EQ("3034495442\n"
              "6180738192\n",
              oss.str());
}
