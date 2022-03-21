#include <iostream>
#include "Red_Black_Tree_for_LAB1.h"

using namespace std;

int main()
{
    cout << "Creating an associative array (map)\n\n";
    Red_Black_Tree<int, int> Tree;
    cout << "Let's add elements with a key and a value to it\n\n";
    try
    {
        Tree.insert(55, 1);
        Tree.insert(40, 2);
        Tree.insert(65, 3);
        Tree.insert(60, 4);
        Tree.insert(70, 5);
        Tree.insert(57, 6);
    }
    catch (const domain_error error)
    {
        cout << error.what();
        return 1;
    }
    cout << "Output an associative array to the screen\n\n";
    try
    {
        Tree.print();
    }
    catch (const domain_error error)
    {
        cout << error.what();
    }
    cout << "\n";
    cout << "Clearing the associative array";
    try
    {
        Tree.clear();
    }
    catch (const domain_error error)
    {
        cout << error.what();
    }
    cout << "Let's try to display an empty associative array on the screen \n\n";
    try
    {
        Tree.print();
    }
    catch (const domain_error error)
    {
        cout << error.what();
    }
    cout << "\n\nFill in the associative array again \n\n";
    try
    {
        Tree.insert(100, 1);
        Tree.insert(150, 2);
        Tree.insert(120, 3);
        Tree.insert(200, 4);
        Tree.insert(70, 5);
        Tree.insert(80, 6);
        Tree.insert(60, 7);
    }
    catch (const domain_error error)
    {
        cout << error.what();
        return 1;
    }
    try
    {
        Tree.print();
    }
    catch (const domain_error error)
    {
        cout << error.what();
    }
    cout << "\nLet's check if there is an element with the key 150 in this array: ";
    if (Tree.find(150)) 
    {
        cout << "true";
    }
    else cout << "false";
    cout << "\nLet's check if there is an element with the key 125 in this array: ";
    if (Tree.find(125))
    {
        cout << "true";
    }
    else cout << "false";
    cout << "\n\nRemove the element with the key 150 from the associative array\n";
    Tree.remove(150);
    cout << "Let's check if there is an element with the key 150 in this array: ";
    if (Tree.find(150))
    {
        cout << "true";
    }
    else cout << "false";
    cout << "\n\nWe will display only the list of keys of the associative array:\n\n";
    Red_Black_Tree<int, int>::List<int> List_keys = Tree.get_keys();
    cout << List_keys << '\n';
    cout << "We will display only the list of values of the associative array:\n\n";
    Red_Black_Tree<int, int>::List<int> List_values = Tree.get_values();
    cout << List_values << '\n';

    return 0;
}