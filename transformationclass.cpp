////////////////////////////////////////////////////////////////////////////////
// Filename: TransformationClass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "transformationclass.h"


TransformationClass::TransformationClass()
{
	m_position = D3DXVECTOR3(0.0f, 0.0f, -10.0f);
	m_target = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_upv = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	m_screenWidth = 0;
	m_screenHeight = 0;

	m_screenNear = 0; 
	m_screenDepth = 0;
}


TransformationClass::TransformationClass(const TransformationClass& other)
{
}


TransformationClass::~TransformationClass()
{
}

void TransformationClass::Initialize(HWND hwnd)
{
	m_screenDepth = 1000.0f;
	m_screenNear = 4.0f;
	//m_screenNear = 10.5f;
	//m_screenNear = 0.5f;

	//Obtain window dimensions from the haddle
	RECT dimensions;
    GetClientRect( hwnd, &dimensions );
	m_screenWidth  = dimensions.right - dimensions.left;
    m_screenHeight = dimensions.bottom - dimensions.top;

	// Setup the projection matrix.
	float fieldOfView, screenAspect;
	//fieldOfView = D3DX_PI/4.0f+0.1;
	//fieldOfView = D3DX_PI/8.0f;
	fieldOfView = D3DX_PI/1.3f;	
	//screenAspect = (float)m_screenWidth / (float)m_screenHeight;
	screenAspect = 3 * (float)m_screenWidth / (float)m_screenHeight;
		
	// Create the projection matrix for 3D rendering.
	//D3DXMatrixPerspectiveFovLH(&m_projectionMatrix, fieldOfView, screenAspect, m_screenNear, m_screenDepth);

	// Create an orthographic projection matrix for 2D rendering.
	D3DXMatrixPerspectiveRH(&m_projectionMatrix, (float)m_screenWidth/60.0, (float)m_screenHeight/60.0, m_screenNear, m_screenDepth);
}

void TransformationClass::SetCameraPosition(D3DXVECTOR3 pos)
{
	m_position = pos;
	
	return;
}

void TransformationClass::SetCameraTarget(D3DXVECTOR3 target)
{
	m_target = target;

	return;
}

void TransformationClass::SetCameraUPV(D3DXVECTOR3 upv)
{
	m_upv = upv;

	return;
}

D3DXVECTOR3 TransformationClass::GetCameraUPV()
{
	return m_upv;
}

D3DXVECTOR3 TransformationClass::GetCameraPosition()
{
	return m_position;
}

D3DXVECTOR3 TransformationClass::GetCameraTarget()
{
	return m_target;
}

bool t=true;
float x=0;
float y=0;

void TransformationClass::Render()
{
	// view transformation
	//XMFLOAT3 position, target, upv;
	//position = m_position;
	//target = m_target;
	//upv = m_upv;

	// 0 1 0
	// -1 0 0

	D3DXVECTOR3 position, target, upv;
	position = m_position;
	target = m_target;
	upv = m_upv;

	// (90 * D3DX_PI / 180)

	if(t)
     {
        x+=0.001f;
        if(x > (90.0f * D3DX_PI / 180.0f))
            t=false;
    }
    else    
    {
        x-=0.001f;
        if(x < 0.0f)
            t=true;
    }
     
	m_upv=D3DXVECTOR3(sin(x), cos(-x), 0.0f);

	D3DXMatrixLookAtRH(&m_viewMatrix, &m_position, &m_target, &m_upv);

	return;
}

D3DXMATRIX TransformationClass::GetViewMatrix()
{
	return m_viewMatrix;
}

D3DXMATRIX TransformationClass::GetProjectionMatrix()
{
	return m_projectionMatrix;
}

D3DXMATRIX TransformationClass::GetOrthoMatrix()
{
	return m_orthoMatrix;
}