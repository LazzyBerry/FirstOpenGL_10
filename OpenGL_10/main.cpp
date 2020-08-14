#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl/glew.h>
#include <gl/glut.h>

//���_�f�[�^
//��6�ʑ�
//[6]��,[4]���_�A1���_��x,y,z��[3]�v�f
GLfloat vertexAry[6][4][3]
{
	//1�߂̖�[v0-v1-v2-v3)
	{
		{0.f,0.f,0.f},{1.f,0.f,0.f},
		{1.f,1.f,0.f},{0.f,1.f,0.f}
	},
	//2�߂̖�[v1-v5-v6-v2)
	{
		{1.f,0.f,0.f},{1.f,0.f,-1.f},
		{1.f,1.f,-1.f},{1.f,1.f,0.f}
	},
	//3�߂̖�[v4-v7-v6-v5)
	{
		{0.f,0.f,-1.f},{0.f,1.f,-1.f},
		{1.f,1.f,-1.f},{1.f,0.f,-1.f}
	},
	//4�߂̖�[v4-v0-v3-v7)
	{
		{0.f,0.f,-1.f},{0.f,0.f,0.f},
		{0.f,1.f,0.f},{0.f,1.f,-1.f}
	},
	//5�߂̖�[v3-v2-v6-v7)
	{
		{0.f,1.f,0.f},{1.f,1.f,0.f},
		{1.f,1.f,-1.f},{0.f,1.f,-1.f}
	},
	//6�߂̖�[v0-v4-v5-v1)
	{
		{0.f,0.f,0.f},{0.f,0.f,-1.f},
		{1.f,0.f,-1.f},{1.f,0.f,0.f}
	}
};

//�@���f�[�^
GLfloat normalAry[6][4][3]
{
	//1�߂̖�[v0-v1-v2-v3)
	{
		{0.f,0.f,1.f},{0.f,0.f,1.f},
		{0.f,0.f,1.f},{0.f,0.f,1.f}
	},
	//2�߂̖�[v1-v5-v6-v2)
	{
		{1.f,0.f,0.f},{1.f,0.f,0.f},
		{1.f,0.f,0.f},{1.f,0.f,0.f}
	},
	//3�߂̖�[v4-v7-v6-v5)
	{
		{0.f,0.f,-1.f},{0.f,0.f,-1.f},
		{0.f,0.f,-1.f},{0.f,0.f,-1.f}
	},
	//4�߂̖�[v4-v0-v3-v7)
	{
		{-1.f,0.f,0.f},{-1.f,0.f,0.f},
		{-1.f,0.f,0.f},{-1.f,0.f,0.f}
	},
	//5�߂̖�[v3-v2-v6-v7)
	{
		{0.f,1.f,0.f},{0.f,1.f,0.f},
		{0.f,1.f,0.f},{0.f,1.f,0.f}
	},
	//6�߂̖�[v0-v4-v5-v1)
	{
		{0.f,-1.f,0.f},{0.f,-1.f,0.f},
		{0.f,-1.f,0.f},{0.f,-1.f,0.f}
	}
};

//�F�f�[�^
GLfloat colorAry[6][4][3]
{
	//1�߂̖�[v0-v1-v2-v3)
	{
		{0.f,0.f,1.f},{0.f,0.f,1.f},
		{0.f,0.f,1.f},{0.f,0.f,1.f}
	},
	//2�߂̖�[v1-v5-v6-v2)
	{
		{1.f,0.f,0.f},{1.f,0.f,0.f},
		{1.f,0.f,0.f},{1.f,0.f,0.f}
	},
	//3�߂̖�[v4-v7-v6-v5)
	{
		{0.f,1.f,1.f},{0.f,1.f,1.f},
		{0.f,1.f,1.f},{0.f,1.f,1.f}
	},
	//4�߂̖�[v4-v0-v3-v7)
	{
		{1.f,1.f,0.f},{1.f,1.f,0.f},
		{1.f,1.f,0.f},{1.f,1.f,0.f}
	},
	//5�߂̖�[v3-v2-v6-v7)
	{
		{0.f,1.f,0.f},{0.f,1.f,0.f},
		{0.f,1.f,0.f},{0.f,1.f,0.f}
	},
	//6�߂̖�[v0-v4-v5-v1)
	{
		{1.f,0.f,1.f},{1.f,0.f,1.f},
		{1.f,0.f,1.f},{1.f,0.f,1.f}
	}
};

void drawAry()
{
	//�L����
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//�f�[�^�̊֘A�t��
	glVertexPointer(3, GL_FLOAT, 0, vertexAry);//���W
	glNormalPointer(GL_FLOAT, 0, normalAry);//�@��
	glColorPointer(3, GL_FLOAT, 0, colorAry);//�F

	glDrawArrays(GL_QUADS, 0, 4 * 6);//�`��(4���_*6��)

	//������
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

//�O�p��
//���_�f�[�^
//4��,3�p�`,3�v�f
GLfloat tryVertexAry[] =
{
	//v0-v1-v3
	0.f,0.f,0.f,//0�Ԗ�
	0.f,0.f,1.f,//1�Ԗ�
	0.f,1.f,0.f,//...
	//v0-v2-v1
	0.f,0.f,0.f,
	1.f,0.f,0.f,
	0.f,0.f,1.f,
	//v0-v3-v2
	0.f,0.f,0.f,
	0.f,1.f,0.f,
	1.f,0.f,0.f,
	//v3-v1-v2
	0.f,1.f,0.f,//...
	0.f,0.f,1.f,//10�Ԗ�
	1.f,0.f,0.f//11�Ԗ�
};

//�@��
GLfloat tryNormalAry[] =
{
	//v0-v1-v3
	-1.f,0.f,0.f,//0�Ԗ�
	-1.f,0.f,0.f,//1�Ԗ�
	-1.f,0.f,0.f,//...
	//v0-v2-v1
	0.f,-1.f,0.f,
	0.f,-1.f,0.f,
	0.f,-1.f,0.f,
	//v0-v3-v2
	0.f,0.f,-1.f,
	0.f,0.f,-1.f,
	0.f,0.f,-1.f,
	//v3-v1-v2
	1.f,1.f,1.f,//...
	1.f,1.f,1.f,//10�Ԗ�
	1.f,1.f,1.f//11�Ԗ�
};

//�F
GLfloat tryColorAry[] =
{
	//v0-v1-v3
	1.f,0.f,0.f,//0�Ԗ�
	1.f,0.f,0.f,//1�Ԗ�
	1.f,0.f,0.f,//...
	//v0-v2-v1
	0.f,1.f,0.f,
	0.f,1.f,0.f,
	0.f,1.f,0.f,
	//v0-v3-v2
	0.f,0.f,1.f,
	0.f,0.f,1.f,
	0.f,0.f,1.f,
	//v3-v1-v2
	1.f,0.f,1.f,//...
	1.f,0.f,1.f,//10�Ԗ�
	1.f,0.f,1.f//11�Ԗ�
};

//�C���f�b�N�X
GLubyte idxAry[] =
{
	0,1,2,
	3,4,5,
	6,7,8,
	9,10,11
};

//�`��
void trydraw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//�f�[�^�̊֘A�t��
	glVertexPointer(3, GL_FLOAT, 0, tryVertexAry);//���W
	glNormalPointer(GL_FLOAT, 0, tryNormalAry);//�@��
	glColorPointer(3, GL_FLOAT, 0, tryColorAry);//�F

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, idxAry);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

//�f�B�X�v���C���X�g���g�p����
//�O���ϐ��i�L���[�u�A�g�[���X�A�I�N�^�j
GLuint cubeId, torusId, octaId;
GLuint listId = 0;//����pID

void displayByDisplist()
{
	static int angle = 0;
	static GLfloat Light0Pos[] = { 1,1,1,0 };//�����̈ʒu
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, Light0Pos);//�ʒu�ݒ�

	glColor3f(0.f, 1.f, 0.f);

	glPushMatrix();
	glRotatef(float(angle), 1.f, 0.f, 0.f);
	glCallList(listId);//�f�B�X�v���C���X�g�̌Ăяo��
	glPopMatrix();
	glColor3f(1.f, 1.f, 1.f);

	glutSwapBuffers();

	if (++angle >= 360) {
		angle = 0;
	}
}

void keyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case '1':
		listId = cubeId;
		break;
	case '2':
		listId = torusId;
		break;
	case '3': 
		listId = octaId;
		break;
	case 'q':
	case '\033':
		//�s�v�ɂȂ�����폜
		glDeleteLists(listId, 3);//�擪ID����3��
		exit(0);
		break;
	default:
		break;
	}
}

void otherInitByDisplist()
{
	//�f�B�X�v���C���X�g���쐬
	//Id��ݒ�
	listId = glGenLists(3);//3�쐬�i�擪�ԍ����Ԃ�j
	cubeId = listId;
	torusId = listId + 1;
	octaId = listId + 2;
	//1��
	glNewList(cubeId, GL_COMPILE);
	glutSolidCube(1.0);
	glEndList();
	//2��
	glNewList(torusId, GL_COMPILE);
	glutSolidTorus(0.2, 0.4, 30, 30);
	glEndList();
	//3��
	glNewList(octaId, GL_COMPILE);
	glutSolidOctahedron();
	glEndList();
}

//VBO�g�p
//�C���f�b�N�X
GLubyte indexAry[] =
{
	0,1,2,3,
	4,5,6,7,
	8,9,10,11,
	12,13,14,15,
	16,17,18,19,
	20,21,22,23
};

// n/180�̒l
const float PI_OVER_180 = 0.0174532925f;

//VBO�pID
GLuint Vboid[3];//3��
GLuint VboIndex;//�C���f�b�N�X

//�`��֐�
void drawAryVbo()
{
	GLfloat* clientPtr;//�N���C�A���g���p
	GLfloat tmp[3];
	int idloop;
	int loop;
	static float angle = 2 * PI_OVER_180;

	//�f�[�^�̏ꏊ��m�点��
	//���W
	glBindBuffer(GL_ARRAY_BUFFER, Vboid[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	//�@��
	glBindBuffer(GL_ARRAY_BUFFER, Vboid[1]);
	glNormalPointer(GL_FLOAT, 0, 0);
	//�F
	glBindBuffer(GL_ARRAY_BUFFER, Vboid[2]);
	glColorPointer(3, GL_FLOAT, 0, 0);
	//�C���f�b�N�X�o�C���h
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboIndex);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	//�`��
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	//���W�Ɩ@������]������
	for (idloop = 0; idloop < 2; ++idloop)
	{
		//idloop�Ԗڂ̃o�b�t�@�I�u�W�F�N�g�ɒ���
		glBindBuffer(GL_ARRAY_BUFFER, Vboid[idloop]);

		//�Ή��t��
		clientPtr = (GLfloat *)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		if (clientPtr != NULL)
		{
			//24���_*3���_
			for (loop = 0; loop < 24 * 3; loop += 3)
			{
				//�ǂݏo��(READ)
				tmp[0] = clientPtr[loop];
				tmp[1] = clientPtr[loop + 1];
				tmp[2] = clientPtr[loop + 2];
				//��������(WRITE)
				clientPtr[loop] = float(cos(angle)) * tmp[0] + float(sin(angle)) * tmp[2];
				clientPtr[loop + 1] = tmp[1];
				clientPtr[loop + 2] = float(-sin(angle)) * tmp[0] + float(cos(angle)) * tmp[2];
			}
			glUnmapBuffer(GL_ARRAY_BUFFER);//�Ή��t���̊J��
		}
	}
	//�N���C�A���g���ɖ߂�
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void keybordVBO(unsigned char key, int x, int y)
{
	switch (key)
	{
	case'q':
	case'Q':
	case '\033':
		//�I������
		glDeleteBuffers(3, &Vboid[0]);
		glDeleteBuffers(1, &VboIndex);
		exit(0);
	default:
		break;
	}
}

//VBO�̍쐬
void buildVBO()
{
	glGenBuffers(3, &Vboid[0]);//���W�A�@���A�F��3��

	//���_
	glGenBuffers(GL_ARRAY_BUFFER, &Vboid[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexAry), vertexAry, GL_DYNAMIC_DRAW);//�f�[�^�ύX����

	//�@��
	glGenBuffers(GL_ARRAY_BUFFER, &Vboid[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalAry), normalAry, GL_DYNAMIC_DRAW);//�f�[�^�ύX����

	//�F
	glGenBuffers(GL_ARRAY_BUFFER, &Vboid[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorAry), colorAry, GL_STREAM_DRAW);//�f�[�^�ύX�Ȃ�

	//�C���f�b�N�X
	glGenBuffers(1, &VboIndex);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboIndex);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexAry), indexAry, GL_STATIC_DRAW);//�f�[�^�ύX�Ȃ�
}

//�e��R�[���o�b�N
void display()
{
	static int angle = 0;
	//�o�b�t�@�̏�����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(float(angle), 1.f, 0.f, 0.f);
	//glRotatef(float(angle), 0.f, 1.f, 0.f);
	//drawAry();
	//trydraw();
	drawAryVbo();
	glPopMatrix();

	glutSwapBuffers();

	if (++angle >= 360) {
		angle = 0;
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//�r���[�|�[�g�̐ݒ�

	glMatrixMode(GL_PROJECTION);//�ˉe�s��̐ݒ�
	glLoadIdentity();

	gluPerspective(30, (double)w / h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW); //���f���r���[�s��̐ݒ�
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}

//���̑��e��ݒ�
void otherInit()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);//�@���̐��K��
	//�J���[�}�e���A���ݒ�
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

//�g���@�\�̊m�F
void checkExtension()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(0);
	}
	//�g���@�\�̊m�F
	if (!glewIsSupported("GL_ARB_vertex_buffer_object"))
	{
		puts("you can`t use VBO");
		exit(0);
	}
}

//���C���֐�
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUT�̏�����
	//Window�̍쐬
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //�f�B�X�v���C���[�h
	glutCreateWindow("VBO Sample");

	checkExtension();
	//�R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keybordVBO);

	otherInit();
	//otherInitByDisplist();
	buildVBO();

	glutMainLoop(); //���C�����[�v��

	return 0;
}