#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
TEST_CASE("Good snowman code") {
    //hat
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(21114411) == string("  ___  \n ..... \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(31114411) == string("   _   \n  /_\\  \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(41114411) == string("  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) "));
    //nose
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(12114411) == string("       \n _===_ \n (...) \n ( : ) \n ( : ) "));
            CHECK(snowman(13114411) == string("       \n _===_ \n (._.) \n ( : ) \n ( : ) "));
            CHECK(snowman(14114411) == string("       \n _===_ \n (. .) \n ( : ) \n ( : ) "));
    //left eye
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11214411) == string("       \n _===_ \n (o,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11314411) == string("       \n _===_ \n (O,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11414411) == string("       \n _===_ \n (-,.) \n ( : ) \n ( : ) "));
    //right eye
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11124411) == string("       \n _===_ \n (.,o) \n ( : ) \n ( : ) "));
            CHECK(snowman(11134411) == string("       \n _===_ \n (.,O) \n ( : ) \n ( : ) "));
            CHECK(snowman(11144411) == string("       \n _===_ \n (.,-) \n ( : ) \n ( : ) "));
    //left arm
            CHECK(snowman(11111411) == string("       \n _===_ \n (.,.) \n<( : ) \n ( : ) "));
            CHECK(snowman(11112411) == string("       \n _===_ \n\\(.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11113411) == string("       \n _===_ \n (.,.) \n/( : ) \n ( : ) "));
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
    //right arm
            CHECK(snowman(11114111) == string("       \n _===_ \n (.,.) \n ( : )>\n ( : ) "));
            CHECK(snowman(11114211) == string("       \n _===_ \n (.,.)/\n ( : ) \n ( : ) "));
            CHECK(snowman(11114311) == string("       \n _===_ \n (.,.) \n ( : )\\\n ( : ) "));
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
    //tosom
            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11114421) == string("       \n _===_ \n (.,.) \n (] [) \n ( : ) "));
            CHECK(snowman(11114431) == string("       \n _===_ \n (.,.) \n (> <) \n ( : ) "));
            CHECK(snowman(11114441) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
    //base

            CHECK(snowman(11114411) == string("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
            CHECK(snowman(11114412) == string("       \n _===_ \n (.,.) \n ( : ) \n (\" \") "));
            CHECK(snowman(11114413) == string("       \n _===_ \n (.,.) \n ( : ) \n (___) "));
            CHECK(snowman(11114414) == string("       \n _===_ \n (.,.) \n ( : ) \n (   ) "));

}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(555));//illegal input
    CHECK_THROWS(snowman(123456));//illegal input
    CHECK_THROWS(snowman(12341235));//illegal input
    CHECK_THROWS(snowman(6666));//illegal input
    CHECK_THROWS(snowman(0));//illegal input
    CHECK_THROWS(snowman(1234));//to short input less then 8
    CHECK_THROWS(snowman(1234123));//to short input less then 8
    CHECK_THROWS(snowman(432143));//to short input less then 8
    CHECK_THROWS(snowman(444444));//to short input less then 8
    CHECK_THROWS(snowman(121212));//to short input less then 8
    CHECK_THROWS(snowman(343434));//to short input less then 8
    CHECK_THROWS(snowman(123412341));//to long input more then 8
    CHECK_THROWS(snowman(111111111));//to long input more then 8
    CHECK_THROWS(snowman(222222222));//to long input more then 8
    CHECK_THROWS(snowman(123123123));//to long input more then 8
    CHECK_THROWS(snowman(434343434));//to long input more then 8
    CHECK_THROWS(snowman(-1));//negative input
    CHECK_THROWS(snowman(-12331234));//negative input
    CHECK_THROWS(snowman(-11111111));//negative input
    CHECK_THROWS(snowman(-555));//negative input
    CHECK_THROWS(snowman(-44444444));//negative input
}