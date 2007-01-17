#include "LivingDead.h"

int main(){
	
	LivingDead b;
	std::cout << "B                 =" << b << std::endl;
	LivingDead ind1("Y");
	std::cout << "ind1 Y            =" << ind1 << std::endl;
	LivingDead ind2("n");
	std::cout << "ind2 n            =" << ind2 << std::endl;
	b.set("y");
	std::cout << "B after set y     =" << b << std::endl;
	LivingDead::addLookupTableEntry("YES",true);
	std::cout << "Added YES to the LivingDead map " << std::endl;
	LivingDead ind3("YES");
	std::cout << "ind3 YES          =" << ind3 << std::endl;
	LivingDead ind4,ind5;
	std::cout << "ind3==ind4         " << (ind3==ind4) << std::endl;
	std::cout << "ind3==ind1         " << (ind3==ind1) << std::endl;
	std::cout << "ind3==ind2         " << (ind3==ind2) << std::endl;
	std::cout << "ind4==ind5         " << (ind4==ind5) << std::endl;
	std::cout << "ind3 < ind4        " << (ind3 < ind4) << std::endl;
	std::cout << "ind3 < ind1        " << (ind3 < ind1) << std::endl;
	std::cout << "ind3 < ind2        " << (ind3 < ind2) << std::endl;
	std::cout << "ind4 < ind5        " << (ind4 < ind5) << std::endl;
	std::cout << "ind4 < ind3        " << (ind4 < ind3) << std::endl;
	std::cout << "ind2 < ind3        " << (ind2 < ind3) << std::endl;
	LivingDead ind6(".");
	std::cout << "ind6               " << ind6 << std::endl;	
	std::cout << "ind6.isMissing()   " << ind6.isMissing() << std::endl;
	ind6.set(false);
	std::cout << "ind6.set(false)    " << ind6 << std::endl;
	std::cout << "ind6.getDataType() " << ind6.getDataType() << std::endl;
	std::cout << "ind6.getBoolean()  " << ind6.getBoolean() << std::endl;
	std::cout << "ind3.getBoolean()  " << ind3.getBoolean() << std::endl;
	std::cout << "ind1.getBoolean()  " << ind1.getBoolean() << std::endl;
	std::cout << "ind3               " << ind3 << std::endl;
	ind3.setMissing();
	std::cout << "ind3.setMissing()  " << ind3 << std::endl;
	std::cout << "ind3.getEnum       " << ind3.getEnum() << std::endl;
	std::cout << "ind6.getEnum       " << ind6.getEnum() << std::endl;
	std::cout << "ind1.getEnum       " << ind1.getEnum() << std::endl;
	ind1.set(LivingDead::MISSING);
	std::cout << "ind1.set(MISSING)  " << ind1 << std::endl;
	ind1.set(LivingDead::ALIVE);
	std::cout << "ind1.set(ALIVE)    " << ind1 << std::endl;

	return 0;
}

