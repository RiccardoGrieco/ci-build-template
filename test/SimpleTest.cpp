// Catch2 (conda based)
#include <catch2/catch_test_macros.hpp>

// manif (source based)
#include <manif/SO3.h>


/**
 * This test simply checks that the mock object works.
 */
TEST_CASE("Manif test")
{
  manif::SO3d rotation;
  rotation.setRandom();
  
  auto compose = rotation.inverse().compose(rotation);
  
  manif::SO3d identity;
  identity.setIdentity();

  REQUIRE(compose==identity);

}
