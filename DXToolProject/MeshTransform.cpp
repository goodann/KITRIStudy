#include"GameCommon.h"



void MeshTransform::PathDivision(const char * _total, char * _path, char * _name)
{
	char* p = strrchr((char*)_total, '/');
	UINT n = (UINT)(p - _total);
	strncpy(_path, _total, n);
	strcpy(_name, p + 1);
}

void MeshTransform::SetAddIndexedMatrix(int index,D3DXVECTOR3 _pivot , D3DXMATRIX * _pMat)
{
	m_index = index;
	m_pivot = _pivot;
	m_mpMat = _pMat;
}

void MeshTransform::Init(OBJECTINFO _info)
{
	Transform::Init(_info);
	switch (_info.Pollygon) {
	case PG_SPHERE:
		m_fRadius = _info.fRadius;
		D3DXCreateSphere(DEVICE, m_fRadius, 36, 36, &m_pMesh, NULL);
		
		break;
	case PG_CYLINDER:
		m_fRadius = _info.fRadius;
		D3DXCreateCylinder(DEVICE, m_fRadius, m_fRadius, m_fRadius,36, 36, &m_pMesh, NULL);
		
		break;
	case PG_BOX:
		D3DXCreateBox(DEVICE, 2, 2, 2, &m_pMesh, nullptr);
		break;
	case PG_FROMXFILE:
	{
		char szOriginPath[255] = { 0, };
		char szPath[255] = { 0, };
		char szName[32] = { 0, };
		PathDivision(_info.FileName.c_str(), szPath, szName);
		int i = _info.FileName.rfind('/');
		GetCurrentDirectory(255, szOriginPath);
		SetCurrentDirectory(szPath);

		LPD3DXBUFFER _pBuffer = nullptr;
		D3DXLoadMeshFromX(szName, D3DXMESH_MANAGED, DEVICE, nullptr, &_pBuffer, nullptr, &m_MaterialCount, &m_pMesh);
		if (m_pMesh == nullptr)
		{
			char tmp[50] = { 0, };
			sprintf(tmp, "Mesh load File : %s", _info.FileName.c_str());
			MessageBox(nullptr, tmp, "Fail", MB_OK);
			return;
		}
		m_pMaterials = new D3DMATERIAL9[m_MaterialCount];
		ZeroMemory(m_pMaterials, sizeof(D3DMATERIAL9)*m_MaterialCount);
		m_ppTextures = new MyTexture*[m_MaterialCount];
		ZeroMemory(m_ppTextures, sizeof(MyTexture*)*m_MaterialCount);
		D3DXMATERIAL* pMaterial = (D3DXMATERIAL*)_pBuffer->GetBufferPointer();

		for (int i = 0; i < (int)m_MaterialCount; ++i) {
			m_pMaterials[i] = pMaterial[i].MatD3D;
			m_pMaterials[i].Ambient = m_pMaterials[i].Diffuse;
			if (pMaterial[i].pTextureFilename != NULL && strlen(pMaterial[i].pTextureFilename)>4) {
				m_ppTextures[i] = TEXMGR->GetTexture(pMaterial[i].pTextureFilename);
			}
		}
		SetCurrentDirectory(szOriginPath);
	}
	break;
	}
	
	
}

void MeshTransform::Render(void)
{
	if (m_MaterialCount == 0) {
		DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
		m_pMesh->DrawSubset(0);
	}
	else {

		DEVICE->SetRenderState(D3DRS_LIGHTING, true);
		for (int i = 0; i < (int)m_MaterialCount; ++i) {
			if (i == m_index && m_mpMat != nullptr) {
				//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
				//D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
				//D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);

				D3DXMATRIX a;
				D3DXMatrixTranslation(&a, m_pivot.x, m_pivot.y, m_pivot.z);
				D3DXMATRIX c;
				D3DXMatrixTranslation(&c, -m_pivot.x, -m_pivot.y, -m_pivot.z);
				c = m_mScale*a* *m_mpMat*c*m_mRot*m_mTrans;

				DEVICE->SetTransform(D3DTS_WORLD, &c);
			}else{
				DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
			}
			DEVICE->SetMaterial(&m_pMaterials[i]);
			DEVICE->SetTexture(0, m_ppTextures[i] ? m_ppTextures[i]->GetTexture() : nullptr);
			m_pMesh->DrawSubset(i);
		}
		DEVICE->SetTexture(0, nullptr);
	}
}

void MeshTransform::Release(void)
{
	SAFE_RELEASE(m_pMesh);
}

MeshTransform::MeshTransform()
{
	m_index = 0;
	m_MaterialCount = 0;
	m_pMesh = nullptr;
	m_mpMat = nullptr;
	m_pivot = VEC3ZERO;
}


MeshTransform::~MeshTransform()
{
	Release();
}
