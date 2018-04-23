#include "MyOctantExample.h"

using namespace Simplex;

Simplex::MyOctant::MyOctant(uint a_nMaxLevel, uint a_nIdealEntityCount)
{
	/*
	USAGE: Constructor, will create an octant containing all MagnaEntities Instances in the Mesh
	manager	currently contains
	ARGUMENTS:
	- uint a_nMaxLevel = 2 -> Sets the maximum level of subdivision
	- uint nIdealEntityCount = 5 -> Sets the ideal level of objects per octant
	OUTPUT: class object
	*/
	m_pEntityMngr = m_pEntityMngr->GetInstance();
	m_pMeshMngr = m_pMeshMngr->GetInstance();

	static uint m_uMaxLevel = a_nMaxLevel;
	static uint m_uIdealEntityCount = a_nIdealEntityCount;


	//find min, max, and center
	for (int i = 0; i < m_pEntityMngr->GetEntityCount(); i++) {

		if (m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMinGlobal().x < m_v3Min.x) {
			m_v3Min.x = m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMinGlobal().x;
		}
		if (m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMaxGlobal().x > m_v3Max.x) {
			m_v3Max.x = m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMaxGlobal().x;
		}
		if (m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMinGlobal().y < m_v3Min.y) {
			m_v3Min.y = m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMinGlobal().y;
		}
		if (m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMaxGlobal().y > m_v3Max.y) {
			m_v3Max.y = m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMaxGlobal().y;
		}
		if (m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMinGlobal().z < m_v3Min.z) {
			m_v3Min.z = m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMinGlobal().z;
		}
		if (m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMaxGlobal().z > m_v3Max.z) {
			m_v3Max.z = m_pEntityMngr->GetEntity(i)->GetRigidBody()->GetMaxGlobal().z;
		}
	}

	//mid point
	m_v3Center = vector3(((m_v3Min.x + m_v3Max.x) / 2), ((m_v3Min.y + m_v3Max.y) / 2), ((m_v3Min.z + m_v3Max.z) / 2));

	//Size = 
	m_fSize = glm::abs(m_v3Max.x) + glm::abs(m_v3Min.x);

	m_pRoot = this;
}

Simplex::MyOctant::MyOctant(vector3 a_v3Center, float a_fSize)
{
	/*
	USAGE: Constructor
	ARGUMENTS:
	- vector3 a_v3Center -> Center of the octant in global space
	- float a_fSize -> size of each side of the octant volume
	OUTPUT: class object
	*/

	m_fSize = a_fSize;
	m_v3Center = a_v3Center;

}

Simplex::MyOctant::MyOctant(MyOctant const & other)
{
	/*
	USAGE: Copy Constructor
	ARGUMENTS: class object to copy
	OUTPUT: class object instance
	*/
}

/*
MyOctant & Simplex::MyOctant::operator=(MyOctant const & other)
{
	// TODO: insert return statement here
	
	USAGE: Copy Assignment Operator
	ARGUMENTS: class object to copy
	OUTPUT: ---
	
	return other;
}
*/

Simplex::MyOctant::~MyOctant(void)
{
	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	delete(this);
}

void Simplex::MyOctant::Swap(MyOctant & other)
{
	/*
	USAGE: Changes object contents for other object's
	ARGUMENTS:
	- MyOctant& other -> object to swap content from
	OUTPUT: ---
	*/
}

float Simplex::MyOctant::GetSize(void)
{
	/*
	USAGE: Gets this octant's size
	ARGUMENTS: ---
	OUTPUT: size of octant
	*/
	return m_fSize;
	//determined by level?
}

vector3 Simplex::MyOctant::GetCenterGlobal(void)
{
	return m_v3Center;
}

vector3 Simplex::MyOctant::GetMinGlobal(void)
{
	return m_v3Min;
}

vector3 Simplex::MyOctant::GetMaxGlobal(void)
{
	return m_v3Max;
}

bool Simplex::MyOctant::IsColliding(uint a_uRBIndex)
{
	return false;
}

void Simplex::MyOctant::Display(uint a_nIndex, vector3 a_v3Color)
{

}

void Simplex::MyOctant::Display(vector3 a_v3Color)
{
	//float xVal = glm::abs(m_v3Max.x) + glm::abs(m_v3Min.x);
	//float yVal = glm::abs(m_v3Max.y) + glm::abs(m_v3Min.y);
	//float zVal = glm::abs(m_v3Max.z) + glm::abs(m_v3Min.z);
	//draw our root
	matrix4 m4center = glm::scale(vector3(this->m_fSize, this->m_fSize, this->m_fSize));
	m_pMeshMngr->AddWireCubeToRenderList(m4center, a_v3Color, RENDER_WIRE);
}

void Simplex::MyOctant::DisplayLeafs(vector3 a_v3Color)
{
	/*
	USAGE: Displays the non empty leafs in the octree
	ARGUMENTS:
	- vector3 a_v3Color = REYELLOW -> Color of the volume to display.
	OUTPUT: ---
	*/
}

void Simplex::MyOctant::ClearEntityList(void)
{
	/*
	USAGE: Clears the Entity list for each node
	ARGUMENTS: ---
	OUTPUT: ---
	*/
}

void Simplex::MyOctant::Subdivide(void)
{
	/*
	USAGE: allocates 8 smaller octants in the child pointers
	ARGUMENTS: ---
	OUTPUT: ---
	*/
}

MyOctant * Simplex::MyOctant::GetChild(uint a_nChild)
{
	/*
	USAGE: returns the child specified in the index
	ARGUMENTS: uint a_nChild -> index of the child (from 0 to 7)
	OUTPUT: MyOctant object (child in index)
	*/
	return nullptr;
}

MyOctant * Simplex::MyOctant::GetParent(void)
{
	/*
	USAGE: Asks the MyOctant if it does not contain any children (its a leaf)
	ARGUMENTS: ---
	OUTPUT: It contains no children
	*/
	return nullptr;
}



bool Simplex::MyOctant::IsLeaf(void)
{
	/*
	USAGE: Asks the MyOctant if it does not contain any children (its a leaf)
	ARGUMENTS: ---
	OUTPUT: It contains no children
	*/
	return false;
}

bool Simplex::MyOctant::ContainsMoreThan(uint a_nEntities)
{
	//check how many entities are colliding with this section
	//if > than a_nEntities, subdivide
	return false;
}

void Simplex::MyOctant::KillBranches(void)
{
	/*
	USAGE: Deletes all children and the children of their children (almost sounds apocalyptic)
	ARGUMENTS: ---
	OUTPUT: ---
	*/
}

void Simplex::MyOctant::ConstructTree(uint a_nMaxLevel)
{
	/*
	USAGE: Creates a tree using subdivisions, the max number of objects and levels
	ARGUMENTS:
	- uint a_nMaxLevel = 3 -> Sets the maximum level of the tree while constructing it
	OUTPUT: ---
	*/
}

void Simplex::MyOctant::AssignIDtoEntity(void)
{
	/*
	USAGE: Traverse the tree up to the leafs and sets the objects in them to the index
	ARGUMENTS: ---
	OUTPUT: ---
	*/
}

uint Simplex::MyOctant::GetOctantCount(void)
{
	return uint();
}

void Simplex::MyOctant::Release(void)
{
}

void Simplex::MyOctant::Init(void)
{
	/*
	USAGE: Allocates member fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
}

void Simplex::MyOctant::ConstructList(void)
{
	/*
	USAGE: creates the list of all leafs that contains objects.
	ARGUMENTS: ---
	OUTPUT: ---
	*/
}
//what a disaster