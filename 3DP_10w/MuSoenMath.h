#pragma once
#include<iostream>

namespace HSM
{
	//행렬 구조체
struct mat3
{
	//행렬을 담을 그릇 num
	float num[3][3];

public:
	//구조체 선언할때 초기값 없이 변수명만 있는 형태
	mat3() { ; };

	//구조체에 초기값 선언할때 값을 매개변수로 담아 num에 넣어줌
	mat3(float a, float b, float c,
		float d, float e, float f,
		float g, float h, float i) {
		num[0][0] = a; num[0][1] = b; num[0][2] = c;
		num[1][0] = d; num[1][1] = e; num[1][2] = f;
		num[2][0] = g; num[2][1] = h; num[2][2] = i;
	};
};
//백타 구조체
struct vec3
{
	//계산할때 사용할 그릇vm과 계산이후 값을 담아줄 그릇 vec
	float vec[3][1];
	float vm[3][1];

public:
	//구조체 선언할때 초기값없는 형태
	vec3() { ; };
	//구조체 선언할때 초기값을 매개변수로 담아 vec에 넣어줌
	vec3(float x, float y){
		vec[0][0] = x; vec[1][0] = y; vec[2][0] = 1;
	}
	//해당 구조체와 mat구조체의 * 연산을 위해 오버로딩 operator*(const mat3) 
	vec3 operator*(const mat3 m) const;

	//행렬 *연산을하고 vm에 값을 넣어주기 vec에 넣으면 연산된 값이 들어가 결과값이 다르게 출려됨
	vec3& operator*(const mat3& m)
	{
		this->vm[0][0] = vec[0][0] * m.num[0][0] + vec[1][0] * m.num[1][0] + vec[2][0] * m.num[2][0];
		this->vm[1][0] = vec[0][0] * m.num[0][1] + vec[1][0] * m.num[1][1] + vec[2][0] * m.num[2][1];
		this->vm[2][0] = vec[0][0] * m.num[0][2] + vec[1][0] * m.num[1][2] + vec[2][0] * m.num[2][2];

		//연산이 끝나고 나온 결과 값을 다시 vec에 넣어줌으로써 다음 *연산을 할때 결과값이 바르게 출력됨
		this->vec[0][0] = vm[0][0];
		this->vec[1][0] = vm[1][0];
		this->vec[2][0] = vm[2][0];

		//리턴값
		return (*this);
	}
	//출력 연산자
	friend std::ostream& operator << (std::ostream& out, vec3& v)
	{
		out << "(" << v.vm[0][0] << "," << v.vm[1][0] << "," << v.vm[2][0] << ")\n";
		return out;
	}
};
}