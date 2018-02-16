#include "AppClass.h"
#include <math.h>
//Kyle Lekkas - E05 Transformations

//sry for global
/* this is what it should be. but the orientation never turned out right.
int locations[8][11] = {   so i flipped the values in a different array
	{ 0,0,1,0,0,0,0,0,1,0,0 },
	{ 0,0,0,1,0,0,0,1,0,0,0 },
	{ 0,0,1,1,1,1,1,1,1,0,0 },
	{ 0,1,1,0,1,1,1,0,1,1,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1 },
	{ 1,0,1,0,0,0,0,0,1,0,1 },
	{ 0,0,0,1,1,0,1,1,0,0,0 }
};
*/

int locations[8][11] = {
	{ 0,0,0,1,1,0,1,1,0,0,0 } ,
	{ 1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,1,1,1,1,1,1,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1 },
	{ 0,1,1,0,1,1,1,0,1,1,0 },
	{ 0,0,1,1,1,1,1,1,1,0,0 },
	{ 0,0,0,1,0,0,0,1,0,0,0 },
	{ 0,0,1,0,0,0,0,0,1,0,0 },
};


void Application::InitVariables(void)
{
	std::vector<MyMesh> allCubes;
	int locations[8][11] = {
		{ 0,0,1,0,0,0,0,0,1,0,0 },
		{ 0,0,0,1,0,0,0,1,0,0,0 },
		{ 0,0,1,1,1,1,1,1,1,0,0 },
		{ 0,1,1,0,1,1,1,0,1,1,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,1,1,1,1,1,1,0,1 },
		{ 1,0,1,0,0,0,0,0,1,0,1 },
		{ 0,0,0,1,1,0,1,1,0,0,0 }
	};

	//init the mesh
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(1.0f, C_BLACK);
	//m_pMesh->GenerateSphere(1.0f, 5, C_WHITE);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	matrix4 m4View = m_pCameraMngr->GetViewMatrix();
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	
	matrix4 m4Scale = glm::scale(IDENTITY_M4, vector3(2.0f,2.0f,2.0f));
	static float value = 0.0f;
	matrix4 m4Translate = glm::translate(IDENTITY_M4, vector3(value, 2.0f, 3.0f));

	//-----------------------------------------------------------------------------------------HERES THE ACTUAL CODE
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 11; c++) {
			if (locations[r][c] == 1) {
				//Loop through multi dimensional array and determine location based on the index.			-10 so it starts further left on the screen
				m_pMesh->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), glm::translate(vector3((1.0f * c + value) - 10.0f, 1.0f * r + sin(value), -10.0f)));
			}
		}
	}

	value += 0.01f;

	//matrix4 m4Model = m4Translate * m4Scale;
	//matrix4 m4Model = m4Scale * m4Translate;

	//m_pMesh->Render(m4Projection, m4View, m4Model);
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	SafeDelete(m_pMesh);

	//release GUI
	ShutdownGUI();
}