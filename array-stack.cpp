#include <iostream>

using namespace std;

class arrastack
{
	private:
		int *element;
		int size;
		int last;
		
		void init(int start)
		{
			for (int i = start; i < size; i++)
			{
				element[i] = 0;
			}
		}
	public:
		arrastack(int s)
		{
			size = s;
			element = new int[size];
			last = 0;
			init(last);
		}
		void resize(int s)
		{
			if (s < last-1)
			{
				cout << "It looks like your array is larger than the size your trying to make it. \nRemove some elements or choose a different size and try again." << endl;
			}
			size = s;
			int  *temp = new int[size];
			for (int i = 0; i < last; i++)
			{
				temp[i] = element[i];
			}
			delete[] element;
			element = temp;
			init(last);
		}
		int get(int pos)
		{
			if (pos < 0 || pos >= size)
			{
				cout << "Invalid Index" << endl;
				return -999;
			}
			return element[pos];
		}
		void set(int el, int pos)
		{
			if (pos < size && pos>=0 && pos<last)
			{
				element[pos] = el;
			}
			else
			{
				cout << "Invalid index." << endl;
			}
			
		}
		int getSize()
		{
			return size;
		}
		int getNumOfEl()
		{
			return last;
		}
		void add(int el)
		{
			if (last >= size)
			{
				cout << "Array is full. Resizing array to double size..." << endl;
				resize(size*2);
			}
			element[last] = el;
			last++;
		}
		void remove(int pos)
		{
				element[pos] = 0;
				for (int i = pos; i < last; i++)
				{
					element[i] = element[i + 1];
				}
				element[last] = 0;
				last--;
		}
		void print()
		{
			for (int i = 0; i < last; i++)
			{
				cout << "element at index " << i << " contains " << element[i] << endl;
			}
		}
		~arrastack()
		{
			delete[] element;
		}
};

int main()
{
	int input=0;
	int index;
	int s;
	int e;
	cout << "Welcome to my array stack program! Insert a starting size below." << endl;
	cin >> s;
	while (s < 0)
	{
		cout << "Invalid size. Try again." << endl;
		cin >> s;
	}
	arrastack a(s);
	cout<<"You can perform any of the functions below. Just type the corresponding number!" << endl;
	while (input != 9)
	{
		cout << "1: Add an element to the stack. If the array is full, it's size will double." << endl;
		cout << "2: Remove an element from the an index in the stack." << endl;
		cout << "3: Get the data from an index in the array." << endl;
		cout << "4: Reset the data of a specific index to another value." << endl;
		cout << "5: Reset the size of your array. Elements will be kept intact." << endl;
		cout << "6: See the current size of your array." << endl;
		cout << "7: See the current number of elements in your array." << endl;
		cout << "8: Print your array." << endl;
		cout << "9: Exit the program." << endl;
		cin >> input;
		while (input > 9 || input < 1)
		{
			cout << "Invalid input. Try again." << endl;
			cin >> input;
		}
		switch (input)
		{
			case 1:
				cout << "What element would you like to add? ";
				cin >> e;
				a.add(e);
				break;
			case 2:
				cout << "At what index would you like to delete an element?" << endl;
				cin >> index;
				a.remove(index);
				break;
			case 3:
				cout << "What is the index you would like to read the data from?" << endl;
				cin >> index;
				int data;
				data=a.get(index);
				if(data!=-999)
				{
					cout << "The data in index " << index << " is " << data<< endl;
				}
				break;
			case 4:
				cout << "Input the element you want to input and the index you want it at, respectively." << endl;
				cin >> e >> index;
				a.set(e, index);
				break;
			case 5:
				cout << "What would you like the new size of your array to be?" << endl;
				cin >> s;
				a.resize(s);
				break;
			case 6:
				cout << "The current size of your array is " << a.getSize() << endl;
				break;
			case 7:
				cout << "The current number of elements in your array is " << a.getNumOfEl() << endl;
				break;
			case 8:
				a.print();
				break;
			case 9:
				return 0;
				break;
		}
		cout << endl;
	}
	return 0;
}