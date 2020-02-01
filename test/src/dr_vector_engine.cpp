/*
 * @author thomas
 * @date 1/27/20.
 */

#include <dr_vector_engine.hpp>

#include <catch2/catch.hpp>

TEST_CASE("dr_vector_engine Default Constructor", "[dr_vector_engine][default][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine;

		CHECK(engine.elements() == 0);
		CHECK(engine.capacity() == 3);
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine;

		CHECK(engine.elements() == 0);
		CHECK(engine.capacity() == 3);
	}

	SECTION("dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>>")
	{
		std::math::dr_vector_engine<std::vector<float>, std::allocator<std::vector<float>>> engine;

		CHECK(engine.elements() == 0);
		CHECK(engine.capacity() == 3);
	}
}

TEST_CASE("dr_vector_engine Move Constructor", "[dr_vector_engine][move][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3;
		engine1(1) = 2;
		engine1(2) = 1;

		CHECK(engine1(0) == 3);
		CHECK(engine1(1) == 2);
		CHECK(engine1(2) == 1);

		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine2 (std::move(engine1));

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == 3);
		CHECK(engine2(1) == 2);
		CHECK(engine2(2) == 1);

		CHECK(engine1.elements() == 0);
		CHECK(engine1.capacity() == 0);
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3.1;
		engine1(1) = 2.2;
		engine1(2) = 1.3;

		CHECK(engine1(0) == Approx(3.1));
		CHECK(engine1(1) == Approx(2.2));
		CHECK(engine1(2) == Approx(1.3));

		std::math::dr_vector_engine<float, std::allocator<float>> engine2 (std::move(engine1));

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == Approx(3.1));
		CHECK(engine2(1) == Approx(2.2));
		CHECK(engine2(2) == Approx(1.3));

		CHECK(engine1.elements() == 0);
		CHECK(engine1.capacity() == 0);
	}
}

TEST_CASE("dr_vector_engine Copy Constructor", "[dr_vector_engine][copy][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3;
		engine1(1) = 2;
		engine1(2) = 1;

		CHECK(engine1(0) == 3);
		CHECK(engine1(1) == 2);
		CHECK(engine1(2) == 1);

		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine2 (engine1);

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == 3);
		CHECK(engine2(1) == 2);
		CHECK(engine2(2) == 1);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		CHECK(engine1(0) == 3);
		CHECK(engine1(1) == 2);
		CHECK(engine1(2) == 1);
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine1 (3, 6);

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		engine1(0) = 3.1;
		engine1(1) = 2.2;
		engine1(2) = 1.3;

		CHECK(engine1(0) == Approx(3.1));
		CHECK(engine1(1) == Approx(2.2));
		CHECK(engine1(2) == Approx(1.3));

		std::math::dr_vector_engine<float, std::allocator<float>> engine2 (engine1);

		REQUIRE(engine2.elements() == 3);
		CHECK(engine2.capacity() == 6);

		CHECK(engine2(0) == Approx(3.1));
		CHECK(engine2(1) == Approx(2.2));
		CHECK(engine2(2) == Approx(1.3));

		REQUIRE(engine1.elements() == 3);
		CHECK(engine1.capacity() == 6);

		CHECK(engine1(0) == Approx(3.1));
		CHECK(engine1(1) == Approx(2.2));
		CHECK(engine1(2) == Approx(1.3));
	}
}

TEST_CASE("dr_vector_engine Initializer List Constructor", "[dr_vector_engine][initializer][list][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine {3, 6, 9, 12, 15};

		REQUIRE(engine.elements() == 5);
		CHECK(engine.capacity() >= 5);

		for (std::size_t i = 0; i < engine.elements(); ++i)
		{
			CHECK(engine(i) == ((i + 1) * 3));
		}
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine {4.0, 8.0, 12.0, 16.0, 20.0};

		REQUIRE(engine.elements() == 5);
		CHECK(engine.capacity() >= 5);

		for (std::size_t i = 0; i < engine.elements(); ++i)
		{
			CHECK(engine(i) == Approx(((i + 1) * 4.0)));
		}
	}
}

TEST_CASE("dr_vector_engine Single Argument Constructor", "[dr_vector_engine][single][argument][constructor]")
{
	SECTION("dr_vector_engine<unsigned short, std::allocator<unsigned short>>")
	{
		std::math::dr_vector_engine<unsigned short, std::allocator<unsigned short>> engine (3);

		REQUIRE(engine.elements() == 3);
		CHECK(engine.capacity() >= 3);

		for (std::size_t i = 0; i < engine.elements(); ++i)
		{
			CHECK(engine(i) == 0);
		}
	}

	SECTION("dr_vector_engine<float, std::allocator<float>>")
	{
		std::math::dr_vector_engine<float, std::allocator<float>> engine (3);

		REQUIRE(engine.elements() == 3);
		CHECK(engine.capacity() >= 3);

		for (std::size_t i = 0; i < engine.elements(); ++i)
		{
			CHECK(engine(i) == Approx(0.0));
		}
	}
}

TEST_CASE("dr_vector_engine Two Argument Constructor", "[dr_vector_engine][two][argument][constructor]")
{

}