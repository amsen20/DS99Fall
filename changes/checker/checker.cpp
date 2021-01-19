#include "testlib.h"
using namespace std;
int main(int argc, char * argv[])
{
	registerChecker("mls", argc, argv);
	compareRemainingLines(1);
}
