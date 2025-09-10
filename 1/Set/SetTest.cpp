#include "UnitTest++.h"
#include "set.hpp"
#include <stdexcept>

TEST(DefaultConstructorTest) {
	set defaultSet;
	CHECK(defaultSet.cardinality() == 0);
}

TEST(EmptySetConstructorTest) {
	set emptySet("{}");
	CHECK(emptySet.cardinality() == 0);
}

TEST(UnbalancedBracketsConstructorTest1) {
	CHECK_THROW(set badBrackets("{1, 2, 3}{}"), std::invalid_argument);
}

TEST(UnbalancedBracketsConstructorTest2) {
	CHECK_THROW(set badBrackets("{1, 2, 3}}"), std::invalid_argument);
}

TEST(UnbalancedBracketsConstructorTest3) {
	CHECK_THROW(set badBrackets("{1, {2, {3, {4}, 5}, 6}"), std::invalid_argument);
}

TEST(EmptySetStringConstructorTest) {
	CHECK_THROW(set emptyStringSet(""), std::invalid_argument);
}

TEST(InvalidSetStringConstructorTest1) {
	CHECK_THROW(set badSetString("{a, v, , }"), std::invalid_argument);
}

TEST(InvalidSetStringConstructorTest2) {
	CHECK_THROW(set badSetString("{\"hello\", wdwed weded}"), std::invalid_argument);
}

TEST(InvalidSetStringConstructorBadQuotesTest) {
	CHECK_THROW(set badSetString("{\"hello\", \"wdwed weded}"), std::invalid_argument);
}

TEST(BraceElementConstructorTest) {
	set braceSet("{\"{}{{}}{}}}}\", \"{\", \"}\" }");
	
	set sample;
	sample.insert("}");
	sample.insert("{}{{}}{}}}}");
	sample.insert("{");
	
	CHECK(braceSet == sample);
}

TEST(NestedSetConstructorTest) {
	set braceSet("{{{1}, {2}, 3}, 4}");
	
	set sample;
	sample.insert("4");
	set innerSample;
	innerSample.insert("3");
	innerSample.insert(set("{2}"));
	innerSample.insert(set("{1}"));
	sample.insert(innerSample);
	
	CHECK(braceSet == sample);
}

TEST(STDStringConstructorTest) {
	set setSTDString(std::string("      {     1,    32 , 4 }     "));
	set sample;
	sample.insert("32");
	sample.insert("1");
	sample.insert("4");
	
	CHECK(sample == setSTDString);
}

TEST(CopyConstructorTest) {
	set s("{1, 2, 3, 4, 5}");
	set s2(s);
	CHECK(s == s2);
}

TEST(CopyConstructorAddressTest) {
	set s("{1, 2, 3, 4, 5}");
	set s2(s);
	CHECK(&s != &s2);
}

TEST(AssignmentTest) {
	set s("{1, 2, 3, 4, 5}");
	set s2("{1, 2, 3}");
	s2 = s;
	CHECK(s == s2);
}

TEST(AssignmentAddressTest) {
	set s("{1, 2, 3, 4, 5}");
	set s2("{1, 2, 3}");
	s2 = s;
	CHECK(&s != &s2);
}

TEST(MoveConstructorTest) {
	set s("{1, 2, 3}");
	set prevS = s;
	set s2(std::move(s));
	CHECK(s2 == prevS && s.cardinality() == 0);
}

TEST(MoveAssignmentTest) {
	set s("{1, 2, 3}");
	set s2("{1}");
	set prevS = s;
	s2 = std::move(s);
	CHECK(s2 == prevS && s.cardinality() == 0);
}

TEST(EqualOperatorTestEqual) {
	set lhs("{3, 2, \"1\"}");
	set rhs("{1, \"2\", \"3\"}");
	CHECK(lhs == rhs);
}

TEST(FoundOperatorTest) {
	set s("{1, 2, 3, 4, 5}");
	CHECK(s["1"]);
}

TEST(FoundOperatorSetTest) {
	set s("{1, {2, 3}, 4, 5}");
	CHECK(s[set("{2, 3}")]);
}

TEST(FoundOperatorNotFoundTest) {
	set s("{1, 2, 3, 4, 5}");
	CHECK(!s["123"]);
}

TEST(FoundOperatorNotFoundSetTest) {
	set s("{1, {2, 3}, 4, 5}");
	CHECK(!s["{2, 3, 4}"]);
}

TEST(RemoveTest) {
	set s("{1, 2, {3, 4}, 5, \"ee ee\"}");
	
	set sampleNoInner("{1, 2, 5, \"ee ee\"}");
	s.remove(set("{3, 4}"));
	bool innerRemoved = (s == sampleNoInner && s.cardinality() == 4);
	
	set sampleNoInnerAndString("{1, 2, 5}");
	s.remove("ee ee");
	bool stringRemoved = (s == sampleNoInnerAndString && s.cardinality() == 3);
	
	s.remove("123");
	bool notRemovedNotExisted = (s == sampleNoInnerAndString && s.cardinality() == 3);
	
	s.remove("1");
	s.remove("2");
	s.remove("5");
	
	bool isEmpty = s.empty();
	
	s.remove("2");
	
	bool nothingHappenedInEmptySet = s.empty();
	
	CHECK(innerRemoved && stringRemoved && notRemovedNotExisted && isEmpty && nothingHappenedInEmptySet);
}

TEST(IntersectionTest1) {
	set a("{a, b, c}");
	set b("{b, c, d}");
	set result(a * b);
	CHECK(result == set("{b, c}"));
}

TEST(IntersectionTest2) {
	set a("{\"a, b\", \"c d\"}");
	set b("{\"a, b\", \"e f\"}");
	set result(a * b);
	CHECK(result == set("{\"a, b\"}"));
}

TEST(IntersectionTest3) {
	set a("{{\"a\", \"b\"}, \"c\"}");
	set b("{\"c\", {\"a\", \"b\"}}");
	set result(a * b);
	CHECK(result == set("{\"c\", {\"a\", \"b\"}}"));
}

TEST(IntersectionTest4) {
	set a("{a}");
	set b("{\"\"}");
	set result(a * b);
	CHECK(result == set("{}"));
}

TEST(IntersectionTest5) {
	set a("{}");
	set b("{a}");
	set result(a * b);
	CHECK(result == set("{}"));
}

TEST(UnionTest1) {
	set a("{a, b}");
	set b("{b, c}");
	set result = a + b;
	CHECK(result == set("{a, b, c}"));
}

TEST(UnionTest2) {
	set a("{a, \"a\"}");
	set b("{b}");
	CHECK(a + b == set("{a, b}"));
}

TEST(UnionTest3) {
	set a("{\"a\", {\"b\"}}");
	set b("{\"c\", {\"b\"}}");
	CHECK(a + b == set("{\"a\", \"c\", {\"b\"}}"));
}

TEST(UnionTest4) {
	set a("{}");
	set b("{a, b}");
	CHECK(a + b == set("{\"a\", \"b\"}"));
}

TEST(DifferenceTest1) {
	set a("{\"a\", \"b\", \"c\"}");
	set b("{\"b\", \"d\"}");
	CHECK(a - b == set("{\"a\", \"c\"}"));
}

TEST(DifferenceTest2) {
	set a("{a, \"a\", \"b\"}");
	set b("{\"a\"}");
	CHECK(a - b == set("{\"b\"}"));
}

TEST(DifferenceTest3) {
	set a("{{\"a\", \"b\"}}");
	set b("{{\"a\", \"c\"}}");
	CHECK(a - b == set("{{\"a\", \"b\"}}"));
}

TEST(DifferenceTest4) {
	set a("{\"a\", \"b\"}");
	set b("{} ");
	CHECK(a - b == set("{\"a\", \"b\"}"));
}

TEST(DifferenceTest5) {
	set a("{}");
	set b("{\"a\", \"b\"}");
	CHECK(a - b == set("{}"));
}

TEST(DifferenceTest6) {
	set a("{\"a\", \"b\"}");
	set b("{\"b\", \"c\", \"d\"}");
	CHECK(a - b == set("{\"a\"}"));
}

TEST(PowersetTest1) {
	CHECK(set("{}").powerset() == set("{{}}"));
}

TEST(PowersetTest2) {
	CHECK(set("{a}").powerset() == set("{{}, {a}}"));
}

TEST(PowersetTest3) {
	CHECK(set("{a, b}").powerset() == set("{{}, {a}, {b}, {a, b}}"));
}

TEST(PowersetTest4) {
	CHECK(set("{a, b, c}").powerset() == set("{{}, {a},{b}, {c} , {a, b}, {a, c}, {b, c}, {a, c, b}}"));
}

//int main() {
//	return UnitTest::RunAllTests();
//}