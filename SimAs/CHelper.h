#pragma once

#include <GL/glut.h>

#include <btBulletDynamicsCommon.h>
#include "LinearMath/btQuaternion.h"
#include "LinearMath/btTransform.h"

class CHelper
{
public:
	CHelper() {};
	~CHelper() {};
	//オイラー角での軸回り回転行列セット関数
	void setMatrix_roteV3(GLfloat *pMatrix, btVector3 jiku, GLfloat rad);
	//4元数での軸回り回転行列セット関数
	void setMatrix_roteV3_q(GLfloat *pMatrix, btVector3 jiku, GLfloat rad);

};

