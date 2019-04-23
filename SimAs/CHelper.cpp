#include "stdafx.h"
#include "CHelper.h"


void CHelper::setMatrix_roteV3(GLfloat *pMatrix, btVector3 v3, GLfloat rad)
{
	//回転座標なので4行と4列は固定値セット
	*(pMatrix + 3) = *(pMatrix + 7) = *(pMatrix + 11) = *(pMatrix + 12) = *(pMatrix + 13) = *(pMatrix + 14) = 0.0;
	*(pMatrix + 15) = 1.0;

	//回転軸を単位ベクトルに
	GLfloat temp_d = v3[0] * v3[0] + v3[1] * v3[1] + v3[2] * v3[2];
			temp_d = sqrt(temp_d);
			if (temp_d < 0.000001) temp_d = 1.0;
			btVector3 ev3 = v3 / temp_d;
	//sin cos 
	GLfloat s = sin(rad);
	GLfloat c = cos(rad);

	//ロドリゲスの回転公式で残りの配列セット
	*(pMatrix + 0) = c + ev3[0] * ev3[0] * (1 - c);
	*(pMatrix + 1) = ev3[0] * ev3[1] * (1 - c) - ev3[2] * s;
	*(pMatrix + 2) = ev3[0] * ev3[2] * (1 - c) + ev3[1] * s;

	*(pMatrix + 4) = ev3[1] * ev3[0] * (1 - c) + ev3[2] * s;
	*(pMatrix + 5) = c + ev3[1] * ev3[1] * (1 - c);
	*(pMatrix + 6) = ev3[1] * ev3[2] * (1 - c) - ev3[0] * s;

	*(pMatrix + 8) = ev3[2] * ev3[0] * (1 - c) - ev3[1] * s;
	*(pMatrix + 9) = ev3[2] * ev3[1] * (1 - c) + ev3[0] * s;
	*(pMatrix + 10) = c + ev3[2] * ev3[2] * (1 - c);

	return;
}

void CHelper::setMatrix_roteV3_q(GLfloat *pMatrix, btVector3 v3, GLfloat rad)
{
	//回転座標なので4行と4列は固定値セット
	*(pMatrix + 3) = *(pMatrix + 7) = *(pMatrix + 11) = *(pMatrix + 12) = *(pMatrix + 13) = *(pMatrix + 14) = 0.0;
	*(pMatrix + 15) = 1.0;

	//回転軸を単位ベクトルに
	GLfloat temp_d = v3[0] * v3[0] + v3[1] * v3[1] + v3[2] * v3[2];
	temp_d = sqrt(temp_d);
	if (temp_d < 0.000001) temp_d = 1.0;
	btVector3 ev3 = v3 / temp_d;
	
	//sin cos 
	GLfloat s = sin(rad/2.0);
	GLfloat c = cos(rad/2.0);

	//Quaternion
	GLfloat vx = ev3[0] * s;
	GLfloat vy = ev3[1] * s;
	GLfloat vz = ev3[2] * s;


	//四元数から回転行列への変換
	*(pMatrix + 0) = 1 - 2*vy*vy- 2*vz*vz;
	*(pMatrix + 1) = 2 * vx*vy + 2*c*vz;
	*(pMatrix + 2) = 2 * vx*vz - 2 * c*vy;

	*(pMatrix + 4) = 2 * vx*vy - 2 * c*vz;
	*(pMatrix + 5) = 1 - 2 * vx*vx - 2 * vz*vz;
	*(pMatrix + 6) = 2 * vy*vz + 2 * c*vx;

	*(pMatrix + 8) = 2 * vx*vz + 2 * c*vy;
	*(pMatrix + 9) = 2 * vy*vz - 2 * c*vx;
	*(pMatrix + 10) = 1 - 2 * vx*vx - 2 * vy*vy;

	return;
}

