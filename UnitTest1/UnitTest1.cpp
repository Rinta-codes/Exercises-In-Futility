#include "pch.h"
#include "CppUnitTest.h"
#include "..\GameMonsters\monsters.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MonsterOGRE)
		{
			Monster Ogre_test{MonsterType::OGRE, Balrog, 584};
		}
	};
}
