#include <iostream>

using namespace std;
int main() {

	int height = 21;
	int width = 21;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			int dist = i;

			if (j < dist) {
				dist = j;
			}
			if ((height -1- i) < dist) {
				dist = height -1- i;
			}
			if ((width -1- j) < dist) {
				dist = width-1-j;
			}

			if (dist > 9) {
				cout << ".";
			}
			else{
				cout << dist;
			}	

		}
		cout << endl;
	}



	return 0;
}