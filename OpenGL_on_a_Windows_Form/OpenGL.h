#pragma once
#include <afxwin.h>
#include "GL/glew.h"
#include <GL/glu.h>

//extern HWND hwndChild1;

int m_uImageCount;
int m_uImageWidth;
int m_uImageHeight;
int m_nTexId = 0;
float dOrthoSize = 1.0f;
float alp = 0.1;
int ReadFile(int , int , int );
void Renderer(float *, float);
void Display(void);
void setupMenus();
int getrot(int, int);
int SetPane(int);



int   wireframe = 0;
int   segments = 16;
int   main_window;



// Shapes scale
float g_Zoom = 1.2f;
float g_axis[3] = { 0, 1, 0 };
float g_alpha;
float g_thick = 1.0;
float g_depth = 0.0;
int slider[4] = { 0,0,0,0 };

float G_zoom[4] = { 1.2, 1.2, 1.2, 1.2 };
float G_alpha[4] = { 0.15, 0.15, 0.15, 0.15 };
float G_thick[4] = { 0.1, 0.1, 0.1, 0.1 };
float G_depth[4] = { 0.15, 0.25, 0.25, 0.25 };
int oldcontext = 3;



// Shape orientation (stored as a quaternion)
float g_rotation[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
//array<array<float>^>^ G_rotation = gcnew array<array<float>^>(4);

float G_rotation[16] = { 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };
// Auto rotate
int g_AutoRotate = 0;
int g_RotateTime = 0;
float g_RotateStart[] = { 0.0f, 0.0f, 0.0f, 1.0f };
// Shapes material
float g_MatAmbient[] = { 0.5f, 0.0f, 0.0f, 1.0f };
float g_MatDiffuse[] = { 1.0f, 1.0f, 0.0f, 1.0f };
// Light parameter
float g_LightMultiplier = 1.0f;
float g_LightDirection[] = { -0.57735f, -0.57735f, -0.57735f };

HDC m_hDC;
		HDC my_hDC1, my_hDC2, my_hDC3, my_hDC4;
		HGLRC m_hglrc;


using namespace System::Windows::Forms;



namespace OpenGLForm 
{
	public ref class COpenGL: public System::Windows::Forms::NativeWindow
	{
	public:
		COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight, HWND hwndChild1, HWND hwndChild2, HWND hwndChild3, HWND hwndChild4)
		{
			HWND hwndMain;

			HINSTANCE hinst, hinstance;
			DWORD dw;

			hwndMain = (HWND)parentForm->Handle.ToPointer();
			m_hDC  = GetDC(hwndMain);
			my_hDC1 = GetDC(hwndChild1);
			my_hDC2 = GetDC(hwndChild2);
			my_hDC3 = GetDC(hwndChild3);
			my_hDC4 = GetDC(hwndChild4);
			if(m_hDC)
			{
				MySetPixelFormat(my_hDC1);
				MySetPixelFormat(my_hDC2);
				MySetPixelFormat(my_hDC3);
				MySetPixelFormat(my_hDC4);
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}
		}




		System::Void Render(System::Void)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear screen and depth buffer
			glLoadIdentity();									// Reset the current modelview matrix
			glTranslatef(0.f,0.0f,-6.0f);						// Move left 1.5 units and into the screen 6.0
			Display();
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(my_hDC1) ;
			SwapBuffers(my_hDC2);
			SwapBuffers(my_hDC3);
			SwapBuffers(my_hDC4);
		}

/*	private:
		HDC m_hDC;
		HDC my_hDC1, my_hDC2, my_hDC3, my_hDC4;
		HGLRC m_hglrc;
*/
	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc) //DHC is of parent
		{
			static	PIXELFORMATDESCRIPTOR pfd;

			memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
			pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
			pfd.iPixelType = PFD_TYPE_RGBA;
			//add alpha buffer here
			pfd.cColorBits = 24;
			pfd.cDepthBits = 32;
			pfd.cStencilBits = 8;
			pfd.iLayerType = PFD_MAIN_PLANE;
			
			GLint  iPixelFormat; 

		 
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
			 
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}





			
				if ((m_hglrc = wglCreateContext(hdc)) == NULL)
				{
					MessageBox::Show("wglCreateContext Failed");
					return 0;
				}

				if ((wglMakeCurrent(hdc, m_hglrc)) == NULL)
				{
					MessageBox::Show("wglMakeCurrent Failed");
					return 0;
				}
				glewInit();
				glEnable(GL_DEPTH_TEST);

				glClearColor(0.9f, 0.0f, 0.0f, 0.0f);

				if (GL_TRUE != glewGetExtension("GL_EXT_texture3D"))
				{
					::MessageBox(0, _T("3D texture is not supported !"), _T("Error"), MB_ICONEXCLAMATION | MB_OK);
					return 0;
				}

				ReadFile(256, 256, 109);
		
			return 1;
		}



		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			PIXELFORMATDESCRIPTOR stPixelFormatDescriptor;
			HDC hContext_i;
			
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			return TRUE;										// Initialisation went ok
		}

		GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
		{
			if (height==0)										// Prevent A Divide By Zero By
			{
				height=1;										// Making Height Equal One
			}

			glViewport(0,0,width,height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix

			// Calculate The Aspect Ratio Of The Window
			gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix
		}
	};
}



int SetPane(int g_context)
{
	if (g_context == 1)
	{
		if ((wglMakeCurrent(my_hDC1, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}
		G_zoom[oldcontext] = g_Zoom;
		G_alpha[oldcontext] = g_alpha;
		G_thick[oldcontext] = g_thick;
		G_depth[oldcontext] = g_depth;
		//(for (int i = ((oldcontext+1) * 4) - 1; (i > (oldcontext+1) * 4 - 4); i--)
		slider[oldcontext] = getrot(0, 0);
		/*for (int i = ((oldcontext * 4) + 3); (i >= oldcontext * 4); i--)
			G_rotation[i] = g_rotation[i % 4];*/
			

		oldcontext = 0;
		getrot(1, slider[oldcontext]);
		g_Zoom = G_zoom[0];
		g_alpha = G_alpha[0];
		g_thick = G_thick[0];
		g_depth= G_depth[0];
		/*for (int i = ((oldcontext * 4) + 3); (i >= oldcontext * 4); i--)
			g_rotation[i%4] = G_rotation[i];*/
			
		


	}
	if (g_context == 2)
	{
		if ((wglMakeCurrent(my_hDC2, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}
		G_zoom[oldcontext] = g_Zoom;
		G_alpha[oldcontext] = g_alpha;
		G_thick[oldcontext] = g_thick;
		G_depth[oldcontext] = g_depth;
		slider[oldcontext] = getrot(0, 0);
		


		oldcontext = 1;
		getrot(1, slider[oldcontext]);
		g_Zoom = G_zoom[1];
		g_alpha = G_alpha[1];
		g_thick = G_thick[1];
		g_depth = G_depth[1];

	



	}
	if (g_context == 3)
	{
		if ((wglMakeCurrent(my_hDC3, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}
		G_zoom[oldcontext] = g_Zoom;
		G_alpha[oldcontext] = g_alpha;
		G_thick[oldcontext] = g_thick;
		G_depth[oldcontext] = g_depth;
		slider[oldcontext] = getrot(0, 0);
		

		oldcontext = 2;
		getrot(1, slider[oldcontext]);
		g_Zoom = G_zoom[2];
		g_alpha = G_alpha[2];
		g_thick = G_thick[2];
		g_depth = G_depth[2];
		
	
		


	}
	if (g_context == 4)
	{
		if ((wglMakeCurrent(my_hDC4, m_hglrc)) == NULL)
		{
			MessageBox::Show("wglMakeCurrent Failed");
			return 0;
		}
		G_zoom[oldcontext] = g_Zoom;
		G_alpha[oldcontext] = g_alpha;
		G_thick[oldcontext] = g_thick;
		G_depth[oldcontext] = g_depth;
		slider[oldcontext] = getrot(0, 0);
		
			

		oldcontext = 3;
		getrot(1, slider[oldcontext]);
		g_Zoom = G_zoom[3];
		g_alpha = G_alpha[3];
		g_thick = G_thick[3];
		g_depth = G_depth[3];
		
			
		



	}

	return 0;
}







// Routine to set a quaternion from a rotation axis and angle
// ( input axis = float[3] angle = float  output: quat = float[4] )
void SetQuaternionFromAxisAngle(const float *axis, float angle, float *quat)
{
	float sina2, norm;
	sina2 = (float)sin(0.5f * angle);
	norm = (float)sqrt(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
	quat[0] = sina2 * axis[0] / norm;
	quat[1] = sina2 * axis[1] / norm;
	quat[2] = sina2 * axis[2] / norm;
	quat[3] = (float)cos(0.5f * angle);
}





// Routine to convert a quaternion to a 4x4 matrix
// ( input: quat = float[4]  output: mat = float[4*4] )
void ConvertQuaternionToMatrix(const float *quat, float *mat)
{
	float yy2 = 2.0f * quat[1] * quat[1];
	float xy2 = 2.0f * quat[0] * quat[1];
	float xz2 = 2.0f * quat[0] * quat[2];
	float yz2 = 2.0f * quat[1] * quat[2];
	float zz2 = 2.0f * quat[2] * quat[2];
	float wz2 = 2.0f * quat[3] * quat[2];
	float wy2 = 2.0f * quat[3] * quat[1];
	float wx2 = 2.0f * quat[3] * quat[0];
	float xx2 = 2.0f * quat[0] * quat[0];
	mat[0 * 4 + 0] = -yy2 - zz2 + 1.0f;
	mat[0 * 4 + 1] = xy2 + wz2;
	mat[0 * 4 + 2] = xz2 - wy2;
	mat[0 * 4 + 3] = 0;
	mat[1 * 4 + 0] = xy2 - wz2;
	mat[1 * 4 + 1] = -xx2 - zz2 + 1.0f;
	mat[1 * 4 + 2] = yz2 + wx2;
	mat[1 * 4 + 3] = 0;
	mat[2 * 4 + 0] = xz2 + wy2;
	mat[2 * 4 + 1] = yz2 - wx2;
	mat[2 * 4 + 2] = -xx2 - yy2 + 1.0f;
	mat[2 * 4 + 3] = 0;
	mat[3 * 4 + 0] = mat[3 * 4 + 1] = mat[3 * 4 + 2] = 0;
	mat[3 * 4 + 3] = 1;
}


// Routine to multiply 2 quaternions (ie, compose rotations)
// ( input q1 = float[4] q2 = float[4]  output: qout = float[4] )
void MultiplyQuaternions(const float *q1, const float *q2, float *qout)
{
	float qr[4];
	qr[0] = q1[3] * q2[0] + q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1];
	qr[1] = q1[3] * q2[1] + q1[1] * q2[3] + q1[2] * q2[0] - q1[0] * q2[2];
	qr[2] = q1[3] * q2[2] + q1[2] * q2[3] + q1[0] * q2[1] - q1[1] * q2[0];
	qr[3] = q1[3] * q2[3] - (q1[0] * q2[0] + q1[1] * q2[1] + q1[2] * q2[2]);
	qout[0] = qr[0]; qout[1] = qr[1]; qout[2] = qr[2]; qout[3] = qr[3];
}





// Callback function called by ?? to render screen
void Display(void)
{
	float v[4]; // will be used to set light parameters
	float mat[4 * 4]; // rotation matrix

    // Clear frame buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glEnable(GL_NORMALIZE);

	// Set light
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	v[0] = v[1] = v[2] = g_LightMultiplier*0.4f; v[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_AMBIENT, v);
	v[0] = v[1] = v[2] = g_LightMultiplier*0.8f; v[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, v);
	v[0] = -g_LightDirection[0]; v[1] = -g_LightDirection[1]; v[2] = -g_LightDirection[2]; v[3] = 0.0f;
	glLightfv(GL_LIGHT0, GL_POSITION, v);

	// Set material
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, g_MatAmbient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, g_MatDiffuse);

	// Rotate and draw shape
	glPushMatrix();
	//glTranslatef(0.25f, -0.3f, 0.0f);
	glTranslatef(-1.3f, -1.1f, 0.0f);
	{
//		float axis[3] = { 0, 1, 0 };
		float angle = (float)getrot(0, 0)/50.;
		float quat[4];
		SetQuaternionFromAxisAngle(g_axis, angle, quat);
		MultiplyQuaternions(g_RotateStart, quat, g_rotation);
	}
	ConvertQuaternionToMatrix(g_rotation, mat);
	glMultMatrixf(mat);
	glScalef(g_Zoom, g_Zoom, g_Zoom);
	//glCallList(g_CurrentShape);

	Renderer(mat, g_Zoom);
	glPopMatrix();
}










// Macro to draw the quad.
// Performance can be achieved by making a call list.
// To make it simple i am not using that now :-)
#define MAP_3DTEXT( TexIndex ) \
        glTexCoord3f(0.0f, 0.0f, ((float)TexIndex+1.0f)/2.0f);  \
        glVertex3f(-dOrthoSize,-dOrthoSize,TexIndex);\
        glTexCoord3f(1.0f, 0.0f, ((float)TexIndex+1.0f)/2.0f);  \
        glVertex3f(dOrthoSize,-dOrthoSize,TexIndex);\
        glTexCoord3f(1.0f, 1.0f, ((float)TexIndex+1.0f)/2.0f);  \
        glVertex3f(dOrthoSize,dOrthoSize,TexIndex);\
        glTexCoord3f(0.0f, 1.0f, ((float)TexIndex+1.0f)/2.0f);  \
        glVertex3f(-dOrthoSize,dOrthoSize,TexIndex);

void Renderer(float *d, float zoom)
{
	float fFrameCount = (float)m_uImageCount;
	GLdouble eqn[4] = { 0.,  0., 1., -.30 }; // z=-1 is the direction and -.3 is the depth 
	GLdouble eqn1[4] = { 0.,  0., -1., .5 };
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_ALPHA_TEST);
	glEnable(GL_DEPTH_TEST);
	glAlphaFunc(GL_GREATER, g_alpha);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();

	eqn[3] = -g_thick;
	glClipPlane(GL_CLIP_PLANE0, eqn);
	glEnable(GL_CLIP_PLANE0);

	eqn1[3] = g_depth;
	glClipPlane(GL_CLIP_PLANE1, eqn1);
	glEnable(GL_CLIP_PLANE1);

	if (glGetError() == GL_NO_ERROR)
		printf("no error\n");
	glLoadIdentity();

	// Translate and make 0.5f as the center 
	// (texture co ordinate is from 0 to 1. so center of rotation has to be 0.5f)
	//glTranslatef(0.5f, 0.5f, 0.5f);
	glTranslatef(0.5f, 0.5f, 0.5f);

	// A scaling applied to normalize the axis 
	// (Usually the number of slices will be less so if this is not - 
	// normalized then the z axis will look bulky)
	// Flipping of the y axis is done by giving a negative value in y axis.
	// This can be achieved either by changing the y co ordinates in -
	// texture mapping or by negative scaling of y axis
	glScaled((float)m_uImageWidth / (float)m_uImageWidth,
		-1.0f*(float)m_uImageWidth / (float)(float)m_uImageHeight,
		(float)m_uImageWidth / (float)m_uImageCount);

	// Apply the user provided transformations
	glScalef(1.0 / zoom, 1.0 / zoom, 1.0 / zoom);
	{
		double aaa[16] = { 1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1.,0.,0.,0.,0.,1. };
		for (int i = 0; i < 16; i++)
			aaa[i] = (double)d[i];
		glMultMatrixd(aaa);
	}
	//glTranslatef(0.0f, 0.0f, -0.5f);
	glTranslatef(-0.5f, -0.5f, -0.5f);

	glEnable(GL_TEXTURE_3D);
	glBindTexture(GL_TEXTURE_3D, m_nTexId);
	for (float fIndx = -1.0f; fIndx <= 1.0f; fIndx += 0.01f)
	{
		glBegin(GL_QUADS);
		MAP_3DTEXT(fIndx);
		glEnd();
	}
}



int ReadFile(int nWidth_i, int nHeight_i, int nSlices_i)
{
	CFile Medfile;
	if (!Medfile.Open(_T("head256x256x109"), CFile::modeRead))
		return 0; // error

				  // Holds the luminance buffer
	char* chBuffer = new char[nWidth_i*nHeight_i*nSlices_i];
	if (!chBuffer)
	{
		return false;
	}
	// Holds the RGBA buffer
	char* pRGBABuffer = new char[nWidth_i*nHeight_i*nSlices_i * 4];
	if (!pRGBABuffer)
	{
		return false;
	}

	Medfile.Read(chBuffer, nWidth_i*nHeight_i*nSlices_i);


	// Convert the data to RGBA data.
	// Here we are simply putting the same value to R, G, B and A channels.
	// Usually for raw data, the alpha value will be constructed by a threshold value given by the user 

	for (int nIndx = 0; nIndx < nWidth_i*nHeight_i*nSlices_i; ++nIndx)
	{
		pRGBABuffer[nIndx * 4] = chBuffer[nIndx];
		pRGBABuffer[nIndx * 4 + 1] = chBuffer[nIndx];
		pRGBABuffer[nIndx * 4 + 2] = chBuffer[nIndx];
		pRGBABuffer[nIndx * 4 + 3] = chBuffer[nIndx];
	}

	// If this function is getting called again for another data file.
	// Deleting and creating texture is not a good idea, 
	// we can use the glTexSubImage3D for better performance for such scenario.
	// I am not using that now :-)
	if (0 != m_nTexId)
	{
		glDeleteTextures(1, (GLuint*)&m_nTexId);
	}
	glGenTextures(1, (GLuint*)&m_nTexId);

	glBindTexture(GL_TEXTURE_3D, m_nTexId);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, nWidth_i, nHeight_i, nSlices_i, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, pRGBABuffer);
	glBindTexture(GL_TEXTURE_3D, 0);

	delete[] chBuffer;
	delete[] pRGBABuffer;
	m_uImageCount = nSlices_i;
	m_uImageWidth = nWidth_i;
	m_uImageHeight = nHeight_i;

}
