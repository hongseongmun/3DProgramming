#pragma once
#include<iostream>

namespace HSM
{
	//��� ����ü
struct mat3
{
	//����� ���� �׸� num
	float num[3][3];

public:
	//����ü �����Ҷ� �ʱⰪ ���� ������ �ִ� ����
	mat3() { ; };

	//����ü�� �ʱⰪ �����Ҷ� ���� �Ű������� ��� num�� �־���
	mat3(float a, float b, float c,
		float d, float e, float f,
		float g, float h, float i) {
		num[0][0] = a; num[0][1] = b; num[0][2] = c;
		num[1][0] = d; num[1][1] = e; num[1][2] = f;
		num[2][0] = g; num[2][1] = h; num[2][2] = i;
	};
};
//��Ÿ ����ü
struct vec3
{
	//����Ҷ� ����� �׸�vm�� ������� ���� ����� �׸� vec
	float vec[3][1];
	float vm[3][1];

public:
	//����ü �����Ҷ� �ʱⰪ���� ����
	vec3() { ; };
	//����ü �����Ҷ� �ʱⰪ�� �Ű������� ��� vec�� �־���
	vec3(float x, float y){
		vec[0][0] = x; vec[1][0] = y; vec[2][0] = 1;
	}
	//�ش� ����ü�� mat����ü�� * ������ ���� �����ε� operator*(const mat3) 
	vec3 operator*(const mat3 m) const;

	//��� *�������ϰ� vm�� ���� �־��ֱ� vec�� ������ ����� ���� �� ������� �ٸ��� �����
	vec3& operator*(const mat3& m)
	{
		this->vm[0][0] = vec[0][0] * m.num[0][0] + vec[1][0] * m.num[1][0] + vec[2][0] * m.num[2][0];
		this->vm[1][0] = vec[0][0] * m.num[0][1] + vec[1][0] * m.num[1][1] + vec[2][0] * m.num[2][1];
		this->vm[2][0] = vec[0][0] * m.num[0][2] + vec[1][0] * m.num[1][2] + vec[2][0] * m.num[2][2];

		//������ ������ ���� ��� ���� �ٽ� vec�� �־������ν� ���� *������ �Ҷ� ������� �ٸ��� ��µ�
		this->vec[0][0] = vm[0][0];
		this->vec[1][0] = vm[1][0];
		this->vec[2][0] = vm[2][0];

		//���ϰ�
		return (*this);
	}
	//��� ������
	friend std::ostream& operator << (std::ostream& out, vec3& v)
	{
		out << "(" << v.vm[0][0] << "," << v.vm[1][0] << "," << v.vm[2][0] << ")\n";
		return out;
	}
};
}