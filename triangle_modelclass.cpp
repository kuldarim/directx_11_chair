////////////////////////////////////////////////////////////////////////////////
// Filename: triangle_modelclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "triangle_modelclass.h"


TriangleModelClass::TriangleModelClass():IndexModelClass()
{
}


TriangleModelClass::TriangleModelClass(const TriangleModelClass& other)
{
}


TriangleModelClass::~TriangleModelClass()
{
}


bool TriangleModelClass::InitializeBuffers(ID3D11Device* device)
{
	HRESULT result;
//
// Process the vertex buffer
//
	VertexType* vertices;
	D3D11_BUFFER_DESC vertexBufferDesc;
    D3D11_SUBRESOURCE_DATA vertexData;

	// Set the number of vertices in the vertex array.
	int vCount = 100;
	SetVertexCount(vCount);

	// Create the vertex array.
	vertices = new VertexType[vCount];
	if(!vertices)
	{
		return false;
	}

	// Load the vertex array with data.
	vertices[0].position = D3DXVECTOR3(-1.0f,-1.0f,-1.0f);
	vertices[1].position = D3DXVECTOR3(-1.0f, 1.0f,-1.0f);
	vertices[2].position = D3DXVECTOR3( 1.0f, 1.0f,-1.0f); 
	vertices[3].position = D3DXVECTOR3(1.0f,-1.0f,-1.0f);

	vertices[4].position = D3DXVECTOR3(-1.0f,-1.0f,-2.0f);
	vertices[5].position = D3DXVECTOR3(-1.0f, 1.0f,-2.0f);
	vertices[6].position = D3DXVECTOR3( 1.0f, 1.0f,-2.0f); 
	vertices[7].position = D3DXVECTOR3(1.0f,-1.0f,-2.0f);

	vertices[8].position = D3DXVECTOR3(-1.0f,-1.0f,-3.0f);
	vertices[9].position = D3DXVECTOR3(-1.0f, 1.0f,-3.0f);
	vertices[10].position = D3DXVECTOR3( 1.0f, 1.0f,-3.0f); 
	vertices[11].position = D3DXVECTOR3(1.0f,-1.0f,-3.0f);

	vertices[12].position = D3DXVECTOR3(-1.0f,-1.0f, 1.0f);
	vertices[13].position = D3DXVECTOR3(-1.0f, 1.0f, 1.0f);
	vertices[14].position = D3DXVECTOR3( 1.0f, 1.0f, 1.0f); 
	vertices[15].position = D3DXVECTOR3(1.0f,-1.0f, 1.0f);

	vertices[16].position = D3DXVECTOR3(-1.0f,-1.0f, 2.0f);
	vertices[17].position = D3DXVECTOR3(-1.0f, 1.0f, 2.0f);
	vertices[18].position = D3DXVECTOR3( 1.0f, 1.0f, 2.0f); 
	vertices[19].position = D3DXVECTOR3(1.0f,-1.0f, 2.0f);

	vertices[20].position = D3DXVECTOR3(-1.0f,-1.0f, 3.0f);
	vertices[21].position = D3DXVECTOR3(-1.0f, 1.0f, 3.0f);
	vertices[22].position = D3DXVECTOR3( 1.0f, 1.0f, 3.0f); 
	vertices[23].position = D3DXVECTOR3(1.0f,-1.0f, 3.0f);

	vertices[24].position = D3DXVECTOR3(0.0f, 3.0f, 0.0f);

	//roof colors
	vertices[24].color = D3DXVECTOR4(1.0f, 2.0f, 0.0f, 12.0f);
	vertices[10].color = D3DXVECTOR4(1.0f, 0.0f, 16.0f, 1.0f);
	vertices[22].color = D3DXVECTOR4(1.0f, 2.0f, 0.0f, 0.0f);
	vertices[21].color = D3DXVECTOR4(1.0f, 0.0f, 10.0f, 1.0f);
	vertices[9].color = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	vertices[10].color = D3DXVECTOR4(0.0f, 0.0f, 0.0f, 0.0f);
	//wall red
	vertices[0].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[1].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[2].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[3].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[4].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[5].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[6].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	vertices[7].color = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);

		// Set up the description of the static vertex buffer.
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    vertexBufferDesc.ByteWidth = sizeof(VertexType) * vCount;
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the vertex data.
	ZeroMemory( &vertexData, sizeof( vertexData ) );
    vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
    result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Release the array now that the vertex buffer has been created and loaded.
	delete [] vertices;
	vertices = 0;

//
// Process the index buffer	
//
	unsigned long* indices;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA indexData;

	// Set the number of indices in the index array.
	int iCount = 100;
	SetIndexCount(iCount);

	// Create the index array.
	indices = new unsigned long[iCount];
	if(!indices)
	{
		return false;
	}
	// Load the index array with data.
	indices[0] = 0;  
	indices[1] = 1;  
	indices[2] = 2;  
	indices[3] = 2;  
	indices[4] = 3;  
	indices[5] = 0;

	indices[6] = 4;  
	indices[7] = 5;  
	indices[8] = 6;  
	indices[9] = 6;  
	indices[10] = 7;  
	indices[11] = 4;

	indices[12] = 8;  
	indices[13] = 9;  
	indices[14] = 10;  
	indices[15] = 10;  
	indices[16] = 11;  
	indices[17] = 8;

	indices[18] = 12;  
	indices[19] = 13;  
	indices[20] = 14;  
	indices[21] = 14;  
	indices[22] = 15;  
	indices[23] = 12;

	indices[24] = 16;  
	indices[25] = 17;  
	indices[26] = 18;  
	indices[27] = 18;  
	indices[28] = 19;  
	indices[29] = 16;

	indices[30] = 20;  
	indices[31] = 21;  
	indices[32] = 22;  
	indices[33] = 22;  
	indices[34] = 23;  
	indices[35] = 20;

	//bottom
	indices[36] = 8;  
	indices[37] = 11;  
	indices[38] = 23;
	indices[39] = 23;  
	indices[40] = 20;  
	indices[41] = 8;
	
	//top
	indices[42] = 9;  
	indices[43] = 10;  
	indices[44] = 22;
	indices[45] = 22;  
	indices[46] = 21;  
	indices[47] = 9;

	//roof
	indices[48] = 24;  
	indices[49] = 10;  
	indices[50] = 22;
	indices[51] = 24;  
	indices[52] = 22;  
	indices[53] = 21;
	indices[54] = 24;  
	indices[55] = 9;  
	indices[56] = 10;
	indices[57] = 24;  
	indices[58] = 9;  
	indices[59] = 21;

	//wall
	indices[60] = 0;  
	indices[61] = 1;  
	indices[62] = 4;
	indices[63] = 4;  
	indices[64] = 1;  
	indices[65] = 5;
	indices[66] = 2;  
	indices[67] = 6;  
	indices[68] = 3;
	indices[69] = 3;  
	indices[70] = 6;  
	indices[71] = 7;

	// Set up the description of the static index buffer.
    indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(unsigned long) * iCount;
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
    indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Release the array now that the vertex buffer has been created and loaded.
	delete [] indices;
	indices = 0;

	return true;
}


void TriangleModelClass::Render(ID3D11DeviceContext* deviceContext)
{
	//Update the world transformations
	UINT  iTime  = timeGetTime() % 2000;
	float fAngle = iTime * 2 * D3DX_PI / 2000.0f;
	D3DXMATRIX rotMatrix;
	D3DXMatrixRotationY(&rotMatrix, fAngle );
	SetModelWorldMatrix(rotMatrix);
	//SetModelWorldMatrix(XMMatrixIdentity());

	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(deviceContext);

	return;
}


void TriangleModelClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	// Set vertex buffer stride and offset.
	stride = sizeof(VertexType); 
	offset = 0;
    
	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

    // Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

    // Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// render primitives
	deviceContext->DrawIndexed(GetIndexCount(), 0, 0);

	return;
}