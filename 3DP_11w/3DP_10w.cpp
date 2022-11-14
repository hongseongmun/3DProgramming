#pragma once
#include "MuSoenMath.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace HSM;

void main()
{
	mat3 m3 = mat3(0,1,2,
				   3,4,5,
				   6,7,8);

	mat4 m4 = mat4(0,4,8,12,
				   1,5,9,13,
				   2,6,10,14,
				   3,7,11,15);

	mat3 mp3 = mat3(2, 0, 0,
				   0, 2, 0,
				   0, 0, 1);

	mat4 mp4 = mat4(2, 0, 0, 0,
				   0, 2, 0, 0,
				   0, 0, 2, 0,
				   0, 0, 0, 1);

	vec3 v3 = vec3(2,2);
	vec4 v4 = vec4(3,4,5);
	vec3 vv3 = vec3(1, 1, 1);
	vec4 vv4 = vec4(1, 1, 1, 1);

	mat3 mm3;
	mat4 mm4;
	vec3 mvmv3;
	vec4 mvmv4;
	vec3 mmv3;
	vec4 mmv4;
	vec3 mmvv3;
	vec4 mmvv4;

	cout << "-----------------��� ��ġ-----------------" << endl;
	transposeMatrix(m3);
	transposeMatrix(m4);
	cout << m3 << endl;
	cout << m4 << endl;
	cout << "--------------------------------------------" << endl;
	cout << "------------------���� ��ġ-----------------" << endl;
	transposeVector(v3);
	transposeVector(v4);
	cout << v3 << endl;
	cout << v4 << endl;
	cout << "---------------------------------------------" << endl;
	cout << "-----------------������� �ʱ�ȭ-----------------" << endl;
	identityMatrix(m3);
	identityMatrix(m4);
	cout << m3 << endl;
	cout << m4 << endl;
	cout << "--------------------------------------------------" << endl;

	//����� ������ķ� �ʱ�ȭ �����־��⿡ ���� ����� ��Ȯ�ϰ� �������� Ȯ���ϱ� ���� �Ʒ� ������ �ٽ� �ʱ�ȭ
	m3 = mat3(1, 0, 0,
			  0, 1, 0,
			  3, 5, 1);

	m4 = mat4(0, 4, 8, 12,
			  1, 5, 9, 13,
			  2, 6, 10, 14,
			  3, 7, 11, 15);


	cout << "-----------------�������� �ʱ�ȭ-----------------" << endl;
	identityVector(v3);
	identityVector(v4);
	cout << v3 << endl;
	cout << v4 << endl;
	cout << "--------------------------------------------------" << endl;
	//���͸� �������ͷ� �ʱ�ȭ ���ױ⿡ ���� ����� ��Ȯ�ϰ� �������� Ȯ���ϱ� ���� �Ʒ� ������ �ٽ� �ʱ�ȭ
	v3 = vec3(2, 2);
	v4 = vec4(3, 4, 5);

	cout << "-----------------��� ��, ��� ���� ��, ���� ��� ��-----------------" << endl;
	mm3 = multiplyMatrix(m3,mp3);
	mm4 = multiplyMatrix(m4, m4);
	mvmv3 = multiplyMatrix(m3, v3);
	mvmv4 = multiplyMatrix(m4, v4);
	mmv3 = multiplyVector(v3, m3);
	mmv4 = multiplyVector(v4, m4);
	cout << mm3 << endl;
	cout << mm4 << endl;
	cout << mvmv3 << endl;
	cout << mvmv4 << endl;
	cout << mmv3 << endl;
	cout << mmv4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------��ġ ��İ� ����, ���Ϳ� ��� ��-----------------" << endl;
	mm3 = multiplyTransposeMatrix(m3, mp3);
	mm4 = multiplyTransposeMatrix(m4, mp4);
	mvmv3 = multiplyTransposeMatrix(m3,v3);
	mvmv4 = multiplyTransposeMatrix(m4, v4);
    mmvv3 = multiplyTransposeVector(v3, m3);
	mmvv4 = multiplyTransposeVector(v4, m4);
	cout << mm3 << endl;
	cout << mm4 << endl;
	cout << mvmv3 << endl;
	cout << mvmv4 << endl;
	cout << mmv4 << endl;
	cout << mmvv3 << endl;
	cout << mmvv4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------��� ����-----------------" << endl;
	mm3 = plusMatrix(m3, m3);
	mm4 = plusMatrix(m4, m4);
	cout << mm3 << endl;
	cout << mm4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------���� ����-----------------" << endl;
	mmv3 = plusVector(v3, v3);
	mmv4 = plusVector(v4, v4);
	cout << mmv3 << endl;
	cout << mmv4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------��� ����-----------------" << endl;
	mm3 = minusMatrix(m3, mp3);
	mm4 = minusMatrix(m4, mp4);
	cout << mm3 << endl;
	cout << mm4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------���� ����-----------------" << endl;
	mmv3 = minusVector(v3, vv3);
	mmv4 = minusVector(v4, vv4);
	cout << mmv3 << endl;
	cout << mmv4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------��� ��� ��-----------------" << endl;
	mm3 = multiplyConstantMatrix(m3, 2);
	mm4 = multiplyConstantMatrix(m4, 2);
	cout << mm3 << endl;
	cout << mm4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------���� ��� ��-----------------" << endl;
	mmv3 = multiplyConstantVector(v3, 2);
	mmv4 = multiplyConstantVector(v4, 2);
	cout << mmv3 << endl;
	cout << mmv4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------��� ��� ������-----------------" << endl;
	mm3 = divideConstantMatrix(m3, 2);
	mm4 = divideConstantMatrix(m4, 2);
	cout << mm3 << endl;
	cout << mm4 << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "-----------------���� ��� ������-----------------" << endl;
	mmv3 = divideConstantVector(v3, 2);
	mmv4 = divideConstantVector(v4, 2);
	cout << mmv3 << endl;
	cout << mmv4 << endl;
	cout << "--------------------------------------------------" << endl;
}