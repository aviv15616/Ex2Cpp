//anksilae@gmail.com

// ==============================
//  SquareMat - unified test file
//  Uses doctest (single‑header)
// ==============================

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <sstream>
#include <stdexcept>

using namespace matrix;

// =========================================================
//  Constructors & basic validation
// =========================================================
TEST_CASE("Constructor - valid & invalid inputs") {
    SUBCASE("scalar ctor - illegal size (0)") {
        CHECK_THROWS_AS(SquareMat(0, 1.0), std::invalid_argument);
    }
    SUBCASE("copy ctor & copy-assignment") {
        SquareMat m(2, 3.0);
        SquareMat c(m);          // copy‑ctor
        CHECK(c[0][0] == doctest::Approx(3));
        SquareMat other(2, 1.0);
        other = m;              // copy‑assignment
        CHECK(other[1][1] == doctest::Approx(3));
    }
}

// =========================================================
//  Access operators
// =========================================================
TEST_CASE("operator[] - boundaries") {
    SquareMat m(2, 1.0);
    const SquareMat cm(2, 1.0);

    CHECK_THROWS(m[-1]);
    CHECK_THROWS(m[2]);
    CHECK_THROWS(cm[-1]);
    CHECK_THROWS(cm[2]);
}

// =========================================================
//  Arithmetic (+,‑,*,scalar)
// =========================================================
TEST_CASE("Arithmetic operators & scalar multiplication") {
    SquareMat a(2, 1.0), b(2, 2.0);

    CHECK((a + b)[0][0] == doctest::Approx(3));
    CHECK((b - a)[0][0] == doctest::Approx(1));
    CHECK((-a)[0][0]      == doctest::Approx(-1));
    CHECK((a * b)[0][0]   == doctest::Approx(4));
    CHECK((2.0 * a)[0][0] == doctest::Approx(2));
    CHECK((a * 2.0)[0][0] == doctest::Approx(2));

    // size mismatch
    SquareMat big(3, 1.0);
    CHECK_THROWS_AS(a + big, std::invalid_argument);
}

// =========================================================
//  Modulo & division
// =========================================================
TEST_CASE("Modulo (matrix / int) and division by scalar") {
    SquareMat m(2, 5.0), other(2, 2.0);
    CHECK((m % other)[0][0] == doctest::Approx(10));
    CHECK((m % 3)[0][0]     == doctest::Approx(2));
    CHECK((m / 5.0)[0][0]   == doctest::Approx(1));

    CHECK_THROWS(m / 0.0);
    CHECK_THROWS(m / 1e-10);
}

// =========================================================
//  Power, increment / decrement
// =========================================================
TEST_CASE("Power & ++ / -- operators") {
    SquareMat m(2, 2.0);
    CHECK(((m ^ 0)[0][0]) == doctest::Approx(1));
    CHECK(((m ^ 2)[0][0]) == doctest::Approx(8));
    CHECK_THROWS(m ^ -1);

    // ++ / --
    SquareMat x(2, 1.0);
    ++x;      CHECK(x[0][0] == doctest::Approx(2));
    x++;      CHECK(x[0][0] == doctest::Approx(3));
    --x;      CHECK(x[0][0] == doctest::Approx(2));
    x--;      CHECK(x[0][0] == doctest::Approx(1));
}

// =========================================================
//  Comparison & self‑application (+=, *= …)
// =========================================================
TEST_CASE("Comparison & compound‑assignment operators") {
    SquareMat m1(2, 2.0), m2(2, 3.0);

    CHECK(m1 != m2);
    CHECK(m1 == m1);
    CHECK(m1 <  m2);
    CHECK(m2 >  m1);
    CHECK(m1 <= m2);
    CHECK(m2 >= m1);

    // compound ops
    SquareMat a(2, 1.0), b(2, 2.0);
    a += b;   CHECK(a[0][0] == doctest::Approx(3));
    a -= b;   CHECK(a[0][0] == doctest::Approx(1));
    a *= b;   CHECK(a[0][0] == doctest::Approx(4));
    a /= 2.0; CHECK(a[0][0] == doctest::Approx(2));
    a %= 2.0; CHECK(a[0][0] == doctest::Approx(0));
    a %= b;   CHECK(a[0][0] == doctest::Approx(0));
    a *= 3.0; CHECK(a[0][0] == doctest::Approx(0));
}

// =========================================================
//  Determinant & transpose
// =========================================================
TEST_CASE("Determinant & transpose") {
    SUBCASE("determinant ±1") {
        SquareMat m(2);
        m[0][0] = 0;
        m[0][1] = 1;
        m[1][0] = 1;
        m[1][1] = 0;
        CHECK((!m) == doctest::Approx(-1));
    }

    SUBCASE("determinant 0 (singular)") {
        SquareMat m(2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 0;
        m[1][1] = 0;
        CHECK((!m) == doctest::Approx(0));
   
    }

    SUBCASE("transpose operator ~") {
        SquareMat m(2, 1.0);
        auto t = ~m;
        CHECK(t[1][0] == doctest::Approx(1));
    }
}

// =========================================================
//  Output (operator<<) & scalar assignment
// =========================================================
TEST_CASE("operator<< & assign scalar") {
    SquareMat m(2, 5.0);
    m = 3.0;
    CHECK(m[0][0] == doctest::Approx(3));

    std::ostringstream oss;
    oss << m;
    CHECK(oss.str().find("3") != std::string::npos);
}

