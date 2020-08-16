#include <testthat.h>

#include <string>
#include <stdexcept>
#include <exception>

namespace {

void ouch() {
  std::string message = "logic";
  throw std::logic_error(message);
}

} // anonymous namespace

context("Catch: Example Unit Test") {

  test_that("4 + 4 == 8") {
    expect_true((4 + 4) == 8);
  }
}

context("Catch: A second context") {

  test_that("2 - 2 == 0") {
    expect_true((2 - 2) == 0);
  }

  test_that("-1 is negative") {
    expect_true((-1 < 0));
  }

}

context("Catch: Respect 'src/Makevars'") {

  bool compiling_testthat;

#ifdef COMPILING_TESTTHAT
  compiling_testthat = true;
#else
  compiling_testthat = false;
#endif

  test_that("COMPILING_TESTTHAT is inherited from 'src/Makevars'") {
    expect_true(compiling_testthat);
  }

}

context("Catch: Exception handling") {

  test_that("we can use Catch to test for exceptions") {

    expect_error(ouch());
    expect_error_as(ouch(), std::exception);
    expect_error_as(ouch(), std::logic_error);

  }
}
