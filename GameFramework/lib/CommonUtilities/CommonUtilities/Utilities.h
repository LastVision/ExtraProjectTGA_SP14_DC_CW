#pragma once
namespace CommonUtilities
{
#define MIN(A,B) (A) < (B)? A:B
#define MAX(A,B) (A) > (B)? A:B
#define SAFE_DELETE(POINTER) delete POINTER; POINTER = nullptr;
#define FOR_EACH(INDEX, SIZE) for((INDEX) = 0; (INDEX) < (SIZE); (++INDEX))
#define FOR_EACH_OBJECT(VECTOR) for(unsigned int i = 0; i < (VECTOR).size(); ++i)
#define CYCLE_ERASE(INDEX, VECTOR) (VECTOR).at(INDEX) = (VECTOR).back(); (VECTOR).pop_back();
#define SRAND srand(static_cast<unsigned int>(time(nullptr)));
#define PRINT(TEXT) std::cout << (TEXT);
#define ERROR_MESSAGE(TEXT) std::cout << "Error: " << (TEXT) << std::endl;
#define RANDOM_BETWEEN(MINVALUE, MAXVALUE) rand() % (MAXVALUE) + (MINVALUE);
#define TOGGLE(BOOLVARIABLE) (BOOLVARIABLE == true) ? (BOOLVARIABLE = false):(BOOLVARIABLE = true);

	class Utilities
	{
	public:
		Utilities();
		~Utilities();
	};


};
namespace CU = CommonUtilities;

