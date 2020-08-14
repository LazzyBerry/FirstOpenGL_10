#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <gl/glew.h>
#include <gl/glut.h>

//頂点データ
//正6面体
//[6]面,[4]頂点、1頂点はx,y,zの[3]要素
GLfloat vertexAry[6][4][3]
{
	//1つめの面[v0-v1-v2-v3)
	{
		{0.f,0.f,0.f},{1.f,0.f,0.f},
		{1.f,1.f,0.f},{0.f,1.f,0.f}
	},
	//2つめの面[v1-v5-v6-v2)
	{
		{1.f,0.f,0.f},{1.f,0.f,-1.f},
		{1.f,1.f,-1.f},{1.f,1.f,0.f}
	},
	//3つめの面[v4-v7-v6-v5)
	{
		{0.f,0.f,-1.f},{0.f,1.f,-1.f},
		{1.f,1.f,-1.f},{1.f,0.f,-1.f}
	},
	//4つめの面[v4-v0-v3-v7)
	{
		{0.f,0.f,-1.f},{0.f,0.f,0.f},
		{0.f,1.f,0.f},{0.f,1.f,-1.f}
	},
	//5つめの面[v3-v2-v6-v7)
	{
		{0.f,1.f,0.f},{1.f,1.f,0.f},
		{1.f,1.f,-1.f},{0.f,1.f,-1.f}
	},
	//6つめの面[v0-v4-v5-v1)
	{
		{0.f,0.f,0.f},{0.f,0.f,-1.f},
		{1.f,0.f,-1.f},{1.f,0.f,0.f}
	}
};

//法線データ
GLfloat normalAry[6][4][3]
{
	//1つめの面[v0-v1-v2-v3)
	{
		{0.f,0.f,1.f},{0.f,0.f,1.f},
		{0.f,0.f,1.f},{0.f,0.f,1.f}
	},
	//2つめの面[v1-v5-v6-v2)
	{
		{1.f,0.f,0.f},{1.f,0.f,0.f},
		{1.f,0.f,0.f},{1.f,0.f,0.f}
	},
	//3つめの面[v4-v7-v6-v5)
	{
		{0.f,0.f,-1.f},{0.f,0.f,-1.f},
		{0.f,0.f,-1.f},{0.f,0.f,-1.f}
	},
	//4つめの面[v4-v0-v3-v7)
	{
		{-1.f,0.f,0.f},{-1.f,0.f,0.f},
		{-1.f,0.f,0.f},{-1.f,0.f,0.f}
	},
	//5つめの面[v3-v2-v6-v7)
	{
		{0.f,1.f,0.f},{0.f,1.f,0.f},
		{0.f,1.f,0.f},{0.f,1.f,0.f}
	},
	//6つめの面[v0-v4-v5-v1)
	{
		{0.f,-1.f,0.f},{0.f,-1.f,0.f},
		{0.f,-1.f,0.f},{0.f,-1.f,0.f}
	}
};

//色データ
GLfloat colorAry[6][4][3]
{
	//1つめの面[v0-v1-v2-v3)
	{
		{0.f,0.f,1.f},{0.f,0.f,1.f},
		{0.f,0.f,1.f},{0.f,0.f,1.f}
	},
	//2つめの面[v1-v5-v6-v2)
	{
		{1.f,0.f,0.f},{1.f,0.f,0.f},
		{1.f,0.f,0.f},{1.f,0.f,0.f}
	},
	//3つめの面[v4-v7-v6-v5)
	{
		{0.f,1.f,1.f},{0.f,1.f,1.f},
		{0.f,1.f,1.f},{0.f,1.f,1.f}
	},
	//4つめの面[v4-v0-v3-v7)
	{
		{1.f,1.f,0.f},{1.f,1.f,0.f},
		{1.f,1.f,0.f},{1.f,1.f,0.f}
	},
	//5つめの面[v3-v2-v6-v7)
	{
		{0.f,1.f,0.f},{0.f,1.f,0.f},
		{0.f,1.f,0.f},{0.f,1.f,0.f}
	},
	//6つめの面[v0-v4-v5-v1)
	{
		{1.f,0.f,1.f},{1.f,0.f,1.f},
		{1.f,0.f,1.f},{1.f,0.f,1.f}
	}
};

void drawAry()
{
	//有効化
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//データの関連付け
	glVertexPointer(3, GL_FLOAT, 0, vertexAry);//座標
	glNormalPointer(GL_FLOAT, 0, normalAry);//法線
	glColorPointer(3, GL_FLOAT, 0, colorAry);//色

	glDrawArrays(GL_QUADS, 0, 4 * 6);//描画(4頂点*6面)

	//無効化
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

//三角錐
//頂点データ
//4面,3角形,3要素
GLfloat tryVertexAry[] =
{
	//v0-v1-v3
	0.f,0.f,0.f,//0番目
	0.f,0.f,1.f,//1番目
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
	0.f,0.f,1.f,//10番目
	1.f,0.f,0.f//11番目
};

//法線
GLfloat tryNormalAry[] =
{
	//v0-v1-v3
	-1.f,0.f,0.f,//0番目
	-1.f,0.f,0.f,//1番目
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
	1.f,1.f,1.f,//10番目
	1.f,1.f,1.f//11番目
};

//色
GLfloat tryColorAry[] =
{
	//v0-v1-v3
	1.f,0.f,0.f,//0番目
	1.f,0.f,0.f,//1番目
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
	1.f,0.f,1.f,//10番目
	1.f,0.f,1.f//11番目
};

//インデックス
GLubyte idxAry[] =
{
	0,1,2,
	3,4,5,
	6,7,8,
	9,10,11
};

//描画
void trydraw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//データの関連付け
	glVertexPointer(3, GL_FLOAT, 0, tryVertexAry);//座標
	glNormalPointer(GL_FLOAT, 0, tryNormalAry);//法線
	glColorPointer(3, GL_FLOAT, 0, tryColorAry);//色

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_BYTE, idxAry);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

//ディスプレイリストを使用する
//外部変数（キューブ、トーラス、オクタ）
GLuint cubeId, torusId, octaId;
GLuint listId = 0;//制御用ID

void displayByDisplist()
{
	static int angle = 0;
	static GLfloat Light0Pos[] = { 1,1,1,0 };//光源の位置
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 2.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, Light0Pos);//位置設定

	glColor3f(0.f, 1.f, 0.f);

	glPushMatrix();
	glRotatef(float(angle), 1.f, 0.f, 0.f);
	glCallList(listId);//ディスプレイリストの呼び出し
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
		//不要になったら削除
		glDeleteLists(listId, 3);//先頭IDから3つ分
		exit(0);
		break;
	default:
		break;
	}
}

void otherInitByDisplist()
{
	//ディスプレイリストを作成
	//Idを設定
	listId = glGenLists(3);//3つ作成（先頭番号が返る）
	cubeId = listId;
	torusId = listId + 1;
	octaId = listId + 2;
	//1つ目
	glNewList(cubeId, GL_COMPILE);
	glutSolidCube(1.0);
	glEndList();
	//2つ目
	glNewList(torusId, GL_COMPILE);
	glutSolidTorus(0.2, 0.4, 30, 30);
	glEndList();
	//3つ目
	glNewList(octaId, GL_COMPILE);
	glutSolidOctahedron();
	glEndList();
}

//VBO使用
//インデックス
GLubyte indexAry[] =
{
	0,1,2,3,
	4,5,6,7,
	8,9,10,11,
	12,13,14,15,
	16,17,18,19,
	20,21,22,23
};

// n/180の値
const float PI_OVER_180 = 0.0174532925f;

//VBO用ID
GLuint Vboid[3];//3つ分
GLuint VboIndex;//インデックス

//描画関数
void drawAryVbo()
{
	GLfloat* clientPtr;//クライアント側用
	GLfloat tmp[3];
	int idloop;
	int loop;
	static float angle = 2 * PI_OVER_180;

	//データの場所を知らせる
	//座標
	glBindBuffer(GL_ARRAY_BUFFER, Vboid[0]);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	//法線
	glBindBuffer(GL_ARRAY_BUFFER, Vboid[1]);
	glNormalPointer(GL_FLOAT, 0, 0);
	//色
	glBindBuffer(GL_ARRAY_BUFFER, Vboid[2]);
	glColorPointer(3, GL_FLOAT, 0, 0);
	//インデックスバインド
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboIndex);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	//描画
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	//座標と法線を回転させる
	for (idloop = 0; idloop < 2; ++idloop)
	{
		//idloop番目のバッファオブジェクトに注目
		glBindBuffer(GL_ARRAY_BUFFER, Vboid[idloop]);

		//対応付け
		clientPtr = (GLfloat *)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);
		if (clientPtr != NULL)
		{
			//24頂点*3頂点
			for (loop = 0; loop < 24 * 3; loop += 3)
			{
				//読み出し(READ)
				tmp[0] = clientPtr[loop];
				tmp[1] = clientPtr[loop + 1];
				tmp[2] = clientPtr[loop + 2];
				//書き込み(WRITE)
				clientPtr[loop] = float(cos(angle)) * tmp[0] + float(sin(angle)) * tmp[2];
				clientPtr[loop + 1] = tmp[1];
				clientPtr[loop + 2] = float(-sin(angle)) * tmp[0] + float(cos(angle)) * tmp[2];
			}
			glUnmapBuffer(GL_ARRAY_BUFFER);//対応付けの開放
		}
	}
	//クライアント側に戻す
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
		//終了処理
		glDeleteBuffers(3, &Vboid[0]);
		glDeleteBuffers(1, &VboIndex);
		exit(0);
	default:
		break;
	}
}

//VBOの作成
void buildVBO()
{
	glGenBuffers(3, &Vboid[0]);//座標、法線、色の3つ

	//頂点
	glGenBuffers(GL_ARRAY_BUFFER, &Vboid[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexAry), vertexAry, GL_DYNAMIC_DRAW);//データ変更あり

	//法線
	glGenBuffers(GL_ARRAY_BUFFER, &Vboid[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normalAry), normalAry, GL_DYNAMIC_DRAW);//データ変更あり

	//色
	glGenBuffers(GL_ARRAY_BUFFER, &Vboid[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colorAry), colorAry, GL_STREAM_DRAW);//データ変更なし

	//インデックス
	glGenBuffers(1, &VboIndex);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VboIndex);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexAry), indexAry, GL_STATIC_DRAW);//データ変更なし
}

//各種コールバック
void display()
{
	static int angle = 0;
	//バッファの初期化
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
	glViewport(0, 0, w, h);//ビューポートの設定

	glMatrixMode(GL_PROJECTION);//射影行列の設定
	glLoadIdentity();

	gluPerspective(30, (double)w / h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW); //モデルビュー行列の設定
	glLoadIdentity();
}

void idle()
{
	glutPostRedisplay();
}

//その他各種設定
void otherInit()
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);//法線の正規化
	//カラーマテリアル設定
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

//拡張機能の確認
void checkExtension()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(0);
	}
	//拡張機能の確認
	if (!glewIsSupported("GL_ARB_vertex_buffer_object"))
	{
		puts("you can`t use VBO");
		exit(0);
	}
}

//メイン関数
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUTの初期化
	//Windowの作成
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //ディスプレイモード
	glutCreateWindow("VBO Sample");

	checkExtension();
	//コールバック関数登録
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keybordVBO);

	otherInit();
	//otherInitByDisplist();
	buildVBO();

	glutMainLoop(); //メインループへ

	return 0;
}