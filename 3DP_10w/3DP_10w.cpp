#include "MuSoenMath.h"
#include <math.h>
#include <iostream>

using namespace std;
using namespace HSM;

void main()
{
	//백터 선언 및 초기값 설정
	vec3 v = vec3(1,1);

	//각도
	float r = 30 * 3.14/ 180;

	//(3,5) 만큼 이동할 이동 행렬
	mat3 Translate = mat3(1, 0, 0,
						  0, 1, 0,
						  3, 5, 1);
	//30도 회전행렬
	mat3 Rotate = mat3(cos(r), -sin(r), 0,
					   sin(r), cos(r), 0,
					   0,0,1);

	//2배 만큼 커지는 스케일 행렬
	mat3 Scale = mat3(2, 0, 0,
					  0, 2, 0,
					  0, 0, 1);

	// *연산
	vec3 k = v * Translate * Rotate * Scale;
	//결과 출력
	cout << k << endl;


}