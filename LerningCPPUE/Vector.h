#pragma once
#include <cmath>
#include <iostream>
#include <vector>
#include <cassert>
#define NDEBUG
//ѕерегрузить дл€ класса Vector оператор умножени€ (умножение вектора на число)
//ѕерегрузить оператор разности
//ѕерегрузить оператор ввода дл€ вектора(по примеру оператора вывода)
//ѕротестировать.
constexpr float EPS = 1e-4;

class Vector
{
public:
	Vector() = default;
	Vector(const float x_,const float y_, const float z_) :x(x_), y(y_), z(z_) {};

	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}

	Vector& operator+=(const Vector& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector& rhs);
	
	bool operator>(const Vector& rhs) const
	{
		return (x * x + y * y + z * z) > (rhs.x * rhs.x + rhs.y * rhs.y + rhs.z * rhs.z);
	}

	Vector& operator*(float m) const
	{
		Vector out(x * m, y * m, z * m);
		return out;
	}
	Vector& operator-(const Vector& rhs) const
	{
		Vector out(x - rhs.x, y - rhs.y, z - rhs.z);
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Vector& vec);
	

	bool operator==(const Vector& rhs)const
	{
		
		return (x - rhs.x <= EPS) && (y - rhs.y <= EPS) && (z - rhs.z <= EPS);
	}
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

 std::istream& operator>>(std::istream& in, Vector& vec)
{
	in >> vec.x;
	in >> vec.y;
	in >> vec.z;
	return in;

}


 std::ostream& operator<<(std::ostream& out, const Vector& rhs)
 {
	 out << rhs.x << " " << rhs.y << " " << rhs.z << std::endl;
	 return out;
 }

struct TestStruct
{
	float x;
	float y;
	float z;
	float m;
};

bool RunTestMinus()
{
	std::cout << "Testing minus" << std::endl;

	const std::vector<TestStruct> Tests = {
		{0.0,0.0,0.0, 5.0},
		{-1.0,0.0,3.0,-5.0},
		{5.0,5.0,5.0, 5.0},
		{-1.0,-5.0,-6.0, 5.0}
	};
	assert(Vector(Tests[0].x, Tests[0].y, Tests[0].z) - Vector(Tests[0].x, Tests[0].y, Tests[0].z) == Vector());
	assert(Vector(Tests[1].x, Tests[1].y, Tests[1].z) - Vector(Tests[0].x, Tests[0].y, Tests[0].z) == Vector(-1, 0, 3));
	assert(Vector(Tests[2].x, Tests[2].y, Tests[2].z) - Vector(Tests[3].x, Tests[3].y, Tests[3].z) == Vector(6, 10, 11));
	std::cout << "Test minus Expect" << std::endl;
	return true;
}

bool RunTestMultiply()
{
	std::cout << "Testing multiply" << std::endl;

	const std::vector<TestStruct> Tests = {
		{0.0,0.0,0.0, 5.0},
		{-1.0,0.0,3.0,-5.0},
		{5.0,5.0,5.0, 5.0},
		{-1.0,-5.0,-6.0, 5.0}
	};
	assert(Vector(Tests[0].x, Tests[0].y, Tests[0].z) * Tests[0].m == Vector(0,0,0));
	assert(Vector(Tests[1].x, Tests[1].y, Tests[1].z) * Tests[1].m == Vector(5, 0, -15));
	assert(Vector(Tests[2].x, Tests[2].y, Tests[2].z) * Tests[2].m == Vector(25, 25, 25));
	assert(Vector(Tests[3].x, Tests[3].y, Tests[3].z) * Tests[3].m == Vector(-5, -25, -30));
	std::cout << "Test multiply Expect" << std::endl;
	return true;
}

