#include <iostream>

using namespace std;

void rhombus(int x) {
	for (int i = 0; i <= x; i++) {
		for (int j = x - i; j > 0; j--) {
			cout << " ";
		}
		for (int k = 1; k <= x; k++) {
			cout << "* ";
		}
		cout << endl;
	}
}

void diamond(int x) {
	for (int i = 1; i <= x; i++) {
		for (int j = x - i; j > 0; j--) {
			cout << " ";
		}
		for (int k = x-i; k <x; k++) {
			cout << "* ";
		}
		cout << endl;
	}

	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (int k = x-i; k > 0; k--) {
			cout << "* ";
		}
		cout << endl;
	}
}

void diamond2(int x) {
	int z = (x*2)-3;
	int y = (x*2)-3;
	int p = 1;

	for (int i = 1; i <= x; i++) {
		if (i == 1) {
			while (z >= 1) {
				cout << " ";
				z--;
			}
			cout << " * ";
		}
		if (i == x) {
			while (y >= 1) {
				cout << " ";
				y--;
			}
			cout << " * ";
		}

		if (i != 1 && x != i) {

			if ((x / 2) + 1 >= i) {
				for (int j = 1; j <= 2*(x - i) ; j++) {
					cout << " ";
				}

				for (int k = 1; k <= i + z; k++) {
					cout << "* ";
				}
			}
			else {
				for (int k = 1; k <= (p-i) * 2; k++) {
					cout << " ";
				}
				for (int k = 1; k <= ((x-i) * 2) + 1; k++) {
					cout << "* ";
				}
			}
			
		}
		cout << endl << endl;
		z++;
		p = p+ 2;
	}
}



int selectionOfSize(int x) {
	cout << "How big u want your shape to be" << endl;
	cout << "Keep in mind, that if u want to do diamond, u have to select an odd number" << endl;
	cin >> x;
	return x;
}

int main() {

	int selection;
	int sizeOfShapes = 0;
	

	string shapes[] = { "rhombus", "Diamond with triangles" , "Diamond the right way" };

	START:

	cout << "Welcome to drawing in console dumb shapes: " << endl << "Please, Select what type of shape u want to select\n" << endl;

	for (int i = 0; i < 3; i++) {
		cout << i << ") " << shapes[i];
		cout << endl;
	}
	cin >> selection;
	system("cls");

	if (selection != 0 && selection != 1 && selection != 2) {
		cout << "U Selected the wrong number for picking shape";
		cin.ignore(2);
		system("cls");
		goto START;
	}

	sizeOfShapes = selectionOfSize(sizeOfShapes);
	if (selection == 1 && sizeOfShapes % 2 == 0 || selection ==2 && sizeOfShapes % 2 == 0) {
		cout << "Please, select an odd number if u are picking diamond" << endl;
		cin.ignore(2);
		system("cls");
		goto START;
		selection = 0;
	}
	system("cls");

	switch(selection) {
	case 0:{
		rhombus(sizeOfShapes);
		break;
	}
	case 1: {
		diamond(sizeOfShapes);
		break;
	}
	case 2: {
		diamond2(sizeOfShapes);
		break;
	}
	default: {
		goto START;
	}
	}


}