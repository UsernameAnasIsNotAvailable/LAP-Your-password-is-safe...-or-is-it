#include "bXX.hpp"
#define len(x) sizeof(x)/sizeof(x[0])
const std::string password = "xqmtvkrj";
//std::vector<char> guessed;
//N62 guessed;
char charsetL1[26];
char charsetL3[95];

int main() {
	for (int i = 97; i < 123; i++) charsetL1[i-97] = i;
	for (int i = 32; i < 126; i++) charsetL3[i-32] = i;
	b26 guessed = 0;


	//printf("%s\n", guessed.str());
	//guessed.testchars();
	while (true) {
		printf("%s\n", guessed.str());
		guessed=guessed+1;
	} //testing base systems

	/*while (guessed.str() != password) {
		guessed = guessed + 1;
		printf("%s\n", guessed.str());
	}*/

    return 0;
}