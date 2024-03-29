#include<iostream>
#include<list>

using namespace std;

list<int> sample_list;


// display elements on the list 
void print_elements_from_list() {

	if (sample_list.empty()){
		cout << "Your list is currently empty." << endl;
	}
	else
	{
		cout << "Here's the updated list: ";
		for (auto it = sample_list.begin(); it != sample_list.end(); ++it)
		{
			cout << *it << " "; // separate with space 
		}
		cout << endl;
	}
}


// add element to the list
void add_element(int value) {
	sample_list.push_back(value);
}

// remove element from the list
void remove_element(int value) {
	if (sample_list.empty()){

		cout << "Your list is empty. Please enter an element first. " << endl;

	}
	else {

		int index = 0;
		bool found = false;
		for (auto it = sample_list.begin(); it != sample_list.end(); it++) {
			if (*it == value)
			{
				found = true;
				break;
			}
			
			index++;
		}

		if (found)
		{
			sample_list.erase(std::next(sample_list.begin(), index));
			cout << "The element " << value << " found at index " << index << " has been removed." << endl;
		}
		else
		{
			cout << "Unable to proceed.The element is not found in the list." << endl;
		}

	}
}


// check if the element is on the list
void check_element_position(int element_to_find) {
	if (sample_list.empty()) {

		cout << "Your list is empty. Please enter an element first. " << endl;

	}
	else {

		int index = 0;
		bool is_found = false;
		for (auto it = sample_list.begin(); it != sample_list.end(); ++it) {
			
			if (*it == element_to_find){
				is_found = true;
				break;
			}
			
			index++;
		}

		if (is_found) {
			cout << "Element " << element_to_find << " is at the index " << index << endl;

		}
		else {
			cout << "Element " << element_to_find << " is not found on the list" << endl;
		}

	}
}
int main() {
	int choice, number;
	char repeat_prog = 'y';
	cout << "List Operations. \n";
	cout << "Please choose which operation you'd like to perform. \n";
	cout << "---------------------------------------------------- \n";

	cout << "1. Add an element \n";
	cout << "2. Remove an element \n";
	cout << "3. Print the list \n";
	cout << "4. Check if an element exists \n";
	cout << "5. Exit \n\n";
	
	do{
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {

		case 1:
			cout << "Enter the element value to add: ";
			cin >> number;
			add_element(number);
			cout << endl;
			break;

		case 2:
			cout << "Enter the element value you want to remove: ";
			cin >> number;
			remove_element(number);
			cout << endl;
			break;

		case 3:
			print_elements_from_list();
			cout << endl;
			break;
		case 4:
			cout << "Enter the element value you want to check: ";
			cin >> number;
			check_element_position(number);
			break;
		case 5: 
			cout << "Exiting the program in a few... Thanks! ";
			repeat_prog = '\0'; 
			return 0;
			break;
		default:
			cout << "Invalid input." << endl;
			break;
		}
	} while (repeat_prog =='y');
	
}
