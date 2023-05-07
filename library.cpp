using namespace std;
#include <iostream>
void correctly()
{
	cout << "Input correctly\n";			 //функція для виводу на екран запису про неправильний ввід
}
void Fill_r(int arr[], int size)             // функція рандомного заповнення масиву та забезпечення неповторювальності значень
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % size + 1;
		if (i > 0) {
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] == arr[i]) {
					i--;
				}
			}
		}
	}
}
void Fill_arr(int arr[], int size)			 //функція для запису даних в масив
{											// та забезпечення неповторювальності значень
	cout << "Input the books\n";
	for (int i = 0; i < size; i++) {
		int a;
		do {
			cout << "book " << i + 1 << ": ";
			cin >> a;
			if (a < 1) {									// захист від вводу значень менших від 0 та 0
				cout << "You can not input this number\n";
				correctly();
			}
		} while (a < 1);
		arr[i] = a;
		if (i > 0) {
			for (int j = i - 1; j >= 0; j--) {
				if (arr[j] == arr[i]) {
					cout << "You have already entered this number\n";
					i--;
				}
			}
		}
	}
}
void Output(int arr[], int size)			 //вивід масиву на екран
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void add_book(int*& arr, int& size)				//функція для добавляння елементу в масив
{

	int question = 1;
	while (question != 0) {
		cout << "Want to  add one more book? (1 - yes, 0 - no) \n";
		cin >> question;
		if (question < 0 || question > 1) {
			correctly();
			continue;
		}
		if (question == 1) {
			int value;
			int number;
			do {
				cout << "Enter the book\n";
				cin >> number;
				if (number < 1) {
					correctly();
				}
				for (int i = 0; i < size; i++) {
					if (number == arr[i]) {
						cout << "This number already exist\n";
						number = 0;
					}
				}
			} while (number < 1);
			do {
				cout << "Enter the position of number (1 - " << size + 1 << ")\n";

				cin >> value;
				if (value < 1 || value > size + 1) {
					correctly();
				}
			} while (value < 1 || value > size + 1);

			int* new_arr = new int[size + 1];			//створення нового масиву
			int k = 0;

			for (int i = 0; i < size + 1; i++) {			// вставка нового елемента в новий масив
				if (i == value - 1) {
					new_arr[i] = number;
					k = 1;
					continue;
				}
				if (k == 0) {
					new_arr[i] = arr[i];
				}
				else {
					new_arr[i] = arr[i - 1];
				}
			}
			size++;
			delete[] arr;							// видалення старого масиву
			arr = new_arr;							// новий масив стає на місце старого
			Output(arr, size);						// вивід на еркан масиву
		}
	}
}
void bubble_sort(int* arr, int size, int k)
{
	int m = size;
	if (k == 1) {
		do {									//сортування зростанням
			int a;
			for (int i = 1; i < m; i++) {
				if (arr[i - 1] > arr[i]) {
					a = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = a;
				}
			}
			m--;
		} while (m > 1);
	}
	if (k == 2) {
		do {									// cортування спаданням
			int a;
			for (int i = size - 2; i >= 0; i--) {
				if (arr[i + 1] > arr[i]) {
					a = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = a;
				}
			}
			m--;
		} while (m > 1);
	}
	cout << "Sorted by bubble:\n";
	Output(arr, size);
}
void insertion_sort(int* arr, int size, int k)
{
	if (k == 1) {
		for (int i = 1; i < size; i++) {
			int j = i;
			while (j > 0 && arr[j - 1] > arr[j]) {
				int a = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = a;
				j--;
			}
		}
	}
	if (k == 2) {
		for (int i = 1; i < size; i++) {
			int j = i;
			while (j > 0 && arr[j - 1] < arr[j]) {
				int a = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = a;
				j--;
			}
		}
	}
	cout << "Sorted by insertion:\n";
	Output(arr, size);
}
void selection_sort(int* arr, int size, int k)
{
	if (k == 1) {
		int m = 0;
		int n = 0;
		do {
			int min = INT_MAX;
			for (int i = m; i < size; i++) {
				if (min > arr[i]) {
					min = arr[i];
					n = i;
				}
			}
			arr[n] = arr[m];
			arr[m] = min;
			m++;
		} while (m < size);
	}
	if (k == 2) {
		int m = size;
		int n = 0;
		do {
			int min = INT_MAX;
			for (int i = m - 1; i >= 0; i--) {
				if (min > arr[i]) {
					min = arr[i];
					n = i;
				}
			}
			arr[n] = arr[m - 1];
			arr[m - 1] = min;
			m--;
		} while (m > 0);
	}
	cout << "Sorted by selection:\n";
	Output(arr, size);
}
void random_sort(int* arr, int size)		//рандомне перемішування масиву
{
	int a = 0;
	int r = 0;
	for (int i = 0; i < size; i++) {
		r = rand() % size;
		a = arr[i];
		arr[i] = arr[r];
		arr[r] = a;
	}
	cout << "Date are shuffled\n";
	Output(arr, size);
}
void line_search(int* arr, int size, int value)		//лінійний пошук
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			cout << "Found  by line search " << value << " as " << i + 1 << " element\n";
			return;
		}
	}
	cout << "Not found\n";
}
int bin_search(int* arr, int size, int value, int sort)		//бінарний пошук
{
	int left = 0;
	int right = size - 1;
	int middle;
	if (sort == 1) {
		while (left <= right) {
			middle = (left + right) / 2;
			if (arr[middle] == value) {
				cout << "Found by binary search " << value << " as " << middle + 1 << " element\n";
				return 0;
			}
			if (arr[middle] > value) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
	}
	if (sort == 2) {
		while (left <= right) {
			middle = (left + right) / 2;
			if (arr[middle] == value) {
				cout << "Found by binary search " << value << " as " << middle + 1 << " element\n";
				return 0;
			}
			if (arr[middle] < value) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
	}
	cout << "Not found\n";
	return 0;
}

int main()
{
	srand(time(NULL));
	short type_sort = 0;
	int question;
	int size = 0;									//створення початкового масиву
	do {
		cout << "Input the number of books \n";
		cin >> size;
		if (size < 1) {
			cout << "Input more then 0 book\n";
		}
	} while (size < 1);
	int* arr = new int[size];
	do {
		cout << "Random filling		- input 1\n";
		cout << "Yourself filling	- input 2\n";
		cin >> question;
		if (question < 1 || question > 2) {
			correctly();
		}
	} while (question < 1 || question > 2);

	if (question == 1) {
		Fill_r(arr, size);
	}
	if (question == 2) {
		Fill_arr(arr, size);
	}
	Output(arr, size);

	int general_question = 1;
	while (general_question == 1) {
		add_book(arr, size);

		int i_ofSort = 0;
		short sorted_or_not = 0;

		do {
			do {
				if (i_ofSort == 0) {
					cout << "Want to sort books?(1 - yes, 0 - no)\n";
				}
				else {
					cout << "Want to sort books again?(1 - yes, 0 - no)\n";
				}
				cin >> question;
				if (question < 0 || question > 1) {
					correctly();
				}
			} while (question < 0 || question > 1);

			if (question == 1) {
				i_ofSort++;
				do {
					cout << "Bubble sort	- input 1;\n";
					cout << "Insertion sort	- input 2;\n";
					cout << "Selection sort	- input 3;\n";
					cout << "Random sort	- input 4;\n";
					cin >> question;
					if (question < 1 || question > 5) {
						correctly();
					}
				} while (question < 1 || question > 5);
			}

			if (question != 4 && question != 0) {
				sorted_or_not = 1;
				int question2;
				do {
					cout << "Incrementing sort - input 1\n";
					cout << "Decrementing sort - input 2\n";
					cin >> question2;
					if (question2 < 1 || question2 > 2) {
						correctly();
					}
				} while (question2 < 1 || question2 > 2);
				if (question2 == 2) {
					type_sort = 1;
				}
				if (question2 == 1) {
					type_sort = 2;
				}
				if (question == 1 && question2 == 1) {
					bubble_sort(arr, size, question2);
				}
				else if (question == 1 && question2 == 2) {
					bubble_sort(arr, size, question2);
				}
				else if (question == 2 && question2 == 1) {
					insertion_sort(arr, size, question2);
				}
				else if (question == 2 && question2 == 2) {
					insertion_sort(arr, size, question2);
				}
				else if (question == 3 && question2 == 1) {
					selection_sort(arr, size, question2);
				}
				else if (question == 3 && question2 == 2) {
					selection_sort(arr, size, question2);
				}
			}
			else if (question == 4) {
				random_sort(arr, size);
				sorted_or_not = 0;
			}
		} while (question != 0);

		short search = 0;
		do {
			if (search == 0) {
				cout << "Want search a book ? (1 - yes, 0 - no)\n";
				search++;
			}
			else {
				cout << "Want search again? (1 - yes, 0 - no)\n";
			}
			do {
				cin >> question;
				if (question < 0 || question > 1) {
					correctly();
				}
			} while (question < 0 || question > 1);
			if (question == 1) {
				do {
					cout << "What number do you want find?\n";
					cin >> question;
					if (question < 1) {
						correctly();
					}
				} while (question < 1);
				if (sorted_or_not == 0) {
					line_search(arr, size, question);
				}
				else {
					bin_search(arr, size, question, type_sort);
				}
			}
		} while (question != 0);
		cout << "Exit program	  - press 0\n";
		cout << "Continue program - press 1\n";
		do {
			cin >> general_question;
			if (general_question < 0 || general_question > 1) {
				correctly();
			}
		} while (general_question < 0 || general_question > 1);
	}
}