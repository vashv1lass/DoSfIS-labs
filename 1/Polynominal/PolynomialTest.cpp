#include "UnitTest++.h"
#include "polynomial.hpp"
#include <vector>

TEST(ConstructorTest1) {
	polynomial a;
	CHECK(a[0] == 0);
}

TEST(ConstructorTest2) {
	polynomial a(5);
	CHECK(a[0] == 0);
}

TEST(ConstructorTest3) {
	std::vector<double> b = { 14, 8, 5, 2 };
	polynomial a(3, b.data());
	CHECK(a[3] == 2 && a[2] == 5 && a[1] == 8 && a[0] == 14);
}

TEST(EqualOperatorTest) {
	std::vector<double> a_coeff = { 14, 8, 5, 2 };
	auto *b_coeff = new double[4];
	b_coeff[3] = 2;
	b_coeff[2] = 5;
	b_coeff[1] = 8;
	b_coeff[0] = 14;
	polynomial a(3, a_coeff.data());
	polynomial b(3, b_coeff);
	CHECK(a == b);
	delete[] b_coeff;
}

TEST(NotEqualOperatorTest) {
	std::vector<double> a_coeff = { 14, 8, 5, 2 };
	auto *b_coeff = new double[3];
	b_coeff[2] = 2;
	b_coeff[1] = 5;
	b_coeff[0] = 8;
	polynomial a(3, a_coeff.data());
	polynomial b(2, b_coeff);
	CHECK(a != b);
	delete[] b_coeff;
}

TEST(IndexBracesTest) {
	polynomial a;
	CHECK(a[1000] == 0);
}

TEST(RoundBracesTest) {
	auto *b_coeff = new double[4];
	b_coeff[3] = 2;
	b_coeff[2] = 5;
	b_coeff[1] = 8;
	b_coeff[0] = 14;
	polynomial b(3, b_coeff);
	CHECK(b(-2) == 2);
	delete[] b_coeff;
}

TEST(AdditionTest1) {
	polynomial p1(0, std::vector<double>(1, 0).data());
	polynomial p2(0, std::vector<double>(1, 0).data());
	CHECK((p1 + p2)[0] == 0);
}

TEST(AdditionTest2) {
	polynomial p1(0, std::vector<double>(1, 1).data());
	polynomial p2(0, std::vector<double>(1, 0).data());
	CHECK((p1 + p2)[0] == 1);
}

TEST(AdditionTest3) {
	polynomial p1(1, std::vector<double>({ 0, 1 }).data());
	polynomial p2(1, std::vector<double>({ 0, 2 }).data());
	polynomial result = p1 + p2;
	CHECK(result[0] == 0 && result[1] == 3);
}

TEST(AdditionTest4) {
	polynomial p1(2, std::vector<double>({ 1, 2, 1 }).data());
	polynomial p2(2, std::vector<double>({ 1, -2, 1 }).data());
	polynomial result = p1 + p2;
	CHECK(result[0] == 2 && result[1] == 0 && result[2] == 2);
}

TEST(AdditionTest5) {
	polynomial p1(3, std::vector<double>({ 0, 2, 0, 3 }).data());
	polynomial p2(3, std::vector<double>({ 4, 0, -1, 1 }).data());
	polynomial result = p1 + p2;
	CHECK(result[0] == 4 && result[1] == 2 && result[2] == -1 && result[3] == 4);
}

TEST(AdditionTest6) {
	polynomial p1(4, std::vector<double>({ 0, 0, 3, 0, 1 }).data());
	polynomial p2(3, std::vector<double>({ 0, 0, -1, 1 }).data());
	polynomial result = p1 + p2;
	CHECK(result[0] == 0 && result[1] == 0 && result[2] == 2 && result[3] == 1 && result[4] == 1);
}

TEST(SubtractionTest1) {
	polynomial p1(0, std::vector<double>(1, 0).data());
	polynomial p2(0, std::vector<double>(1, 0).data());
	CHECK((p1 - p2)[0] == 0);
}

TEST(SubtractionTest2) {
	polynomial p1(0, std::vector<double>(1, 1).data());
	polynomial p2(0, std::vector<double>(1, 0).data());
	CHECK((p1 - p2)[0] == 1);
}

TEST(SubtractionTest3) {
	polynomial p1(1, std::vector<double>({ 0, 1 }).data());
	polynomial p2(1, std::vector<double>({ 0, 2 }).data());
	polynomial result = p1 - p2;
	CHECK(result[0] == 0 && result[1] == -1);
}

TEST(SubtractionTest4) {
	polynomial p1(2, std::vector<double>({ 1, 2, 1 }).data());
	polynomial p2(2, std::vector<double>({ 1, -2, 1 }).data());
	polynomial result = p1 - p2;
	CHECK(result[0] == 0 && result[1] == 4 && result[2] == 0);
}

TEST(SubtractionTest5) {
	polynomial p1(3, std::vector<double>({ 0, 2, 0, 3 }).data());
	polynomial p2(3, std::vector<double>({ 4, 0, -1, 1 }).data());
	polynomial result = p1 - p2;
	CHECK(result[0] == -4 && result[1] == 2 && result[2] == 1 && result[3] == 2);
}

TEST(SubtractionTest6) {
	polynomial p1(4, std::vector<double>({ 0, 0, 3, 0, 1 }).data());
	polynomial p2(3, std::vector<double>({ 0, 0, -1, 1 }).data());
	polynomial result = p1 - p2;
	CHECK(result[0] == 0 && result[1] == 0 && result[2] == 4 && result[3] == -1 && result[4] == 1);
}

TEST(MultiplicationTest1) {
	polynomial p1(0, std::vector<double>({ 0 }).data());
	polynomial p2(0, std::vector<double>({ 0 }).data());
	polynomial result = p1 * p2;
	CHECK(result[0] == 0);
}

TEST(MultiplicationTest2) {
	polynomial p1(0, std::vector<double>({ 1 }).data());
	polynomial p2(0, std::vector<double>({ 0 }).data());
	polynomial result = p1 * p2;
	CHECK(result[0] == 0);
}

TEST(MultiplicationTest3) {
	polynomial p1(1, std::vector<double>({ 0, 1 }).data());
	polynomial p2(0, std::vector<double>({ 2 }).data());
	polynomial result = p1 * p2;
	CHECK(result[0] == 0 && result[1] == 2);
}

TEST(MultiplicationTest4) {
	polynomial p1(1, std::vector<double>({ 0, 1 }).data());
	polynomial p2(1, std::vector<double>({ 0, 1 }).data());
	polynomial result = p1 * p2;
	CHECK(result[0] == 0 && result[1] == 0 && result[2] == 1);
}

TEST(MultiplicationTest5) {
	polynomial p1(1, std::vector<double>({ 1, 1 }).data());
	polynomial p2(1, std::vector<double>({ -1, 1 }).data());
	polynomial result = p1 * p2;
	CHECK(result[0] == -1 && result[1] == 0 && result[2] == 1);
}

TEST(MultiplicationTest6) {
	polynomial p1(2, std::vector<double>({ 1, 2, 1 }).data());
	polynomial p2(1, std::vector<double>({ 1, 1 }).data());
	polynomial result = p1 * p2;
	CHECK(result[0] == 1 && result[1] == 3 && result[2] == 3 && result[3] == 1);
}

TEST(DivisionTest1) {
	polynomial p1(0, std::vector<double>({ 0 }).data());
	polynomial p2(0, std::vector<double>({ 1 }).data());
	polynomial result = p1 / p2;
	CHECK(result[0] == 0);
}

TEST(DivisionTest2) {
	polynomial p1(0, std::vector<double>({ 1 }).data());
	polynomial p2(0, std::vector<double>({ 1 }).data());
	polynomial result = p1 / p2;
	CHECK(result[0] == 1);
}

TEST(DivisionTest3) {
	polynomial p1(2, std::vector<double>({ 0, 0, 1 }).data());
	polynomial p2(1, std::vector<double>({ 0, 1 }).data());
	polynomial result = p1 / p2;
	CHECK(result[0] == 0 && result[1] == 1);
}

TEST(DivisionTest4) {
	polynomial p1(2, std::vector<double>({ -1, 0, 1 }).data());
	polynomial p2(1, std::vector<double>({ -1, 1 }).data());
	polynomial result = p1 / p2;
	CHECK(result[0] == 1 && result[1] == 1);
}

TEST(DivisionTest5) {
	polynomial p1(3, std::vector<double>({ 1, 3, 3, 1 }).data());
	polynomial p2(1, std::vector<double>({ 1, 1 }).data());
	polynomial result = p1 / p2;
	CHECK(result[0] == 1 && result[1] == 2 && result[2] == 1);
}

TEST(DivisionTest6) {
	polynomial p1(3, std::vector<double>({ 0, 2, 4, 2 }).data());
	polynomial p2(1, std::vector<double>({ 0, 2 }).data());
	polynomial result = p1 / p2;
	CHECK(result[0] == 1 && result[1] == 2 && result[2] == 1);
}