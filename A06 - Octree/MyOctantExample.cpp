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
}

vector3 Simplex::MyOctant::GetCenterGlobal(void)
{
	return vector3();
}

vector3 Simplex::MyOctant::GetMinGlobal(void)
{
	return vector3();
}

vector3 Simplex::MyOctant::GetMaxGlobal(void)
{
	return vector3();
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
}

void Simplex::MyOctant::DisplayLeafs(vector3 a_v3Color)
{
}

void Simplex::MyOctant::ClearEntityList(void)
{
}

void Simplex::MyOctant::Subdivide(void)
{
}

MyOctant * Simplex::MyOctant::GetChild(uint a_nChild)
{
	return nullptr;
}

MyOctant * Simplex::MyOctant::GetParent(void)
{
	return nullptr;
}

bool Simplex::MyOctant::IsLeaf(void)
{
	return false;
}

bool Simplex::MyOctant::ContainsMoreThan(uint a_nEntities)
{
	return false;
}

void Simplex::MyOctant::KillBranches(void)
{
}

void Simplex::MyOctant::ConstructTree(uint a_nMaxLevel)
{
}

void Simplex::MyOctant::AssignIDtoEntity(void)
{
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
}

void Simplex::MyOctant::ConstructList(void)
{
}
