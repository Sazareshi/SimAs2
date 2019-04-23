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
	//�I�C���[�p�ł̎�����]�s��Z�b�g�֐�
	void setMatrix_roteV3(GLfloat *pMatrix, btVector3 jiku, GLfloat rad);
	//4�����ł̎�����]�s��Z�b�g�֐�
	void setMatrix_roteV3_q(GLfloat *pMatrix, btVector3 jiku, GLfloat rad);

};

