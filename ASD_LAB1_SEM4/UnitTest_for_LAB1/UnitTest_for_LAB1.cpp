#include "pch.h"
#include "CppUnitTest.h"
#include "..\ASD_LAB1_SEM4\Red_Black_Tree_for_LAB1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforLAB1
{
	TEST_CLASS(UnitTestforLAB1)
	{
	public:
		
		Red_Black_Tree<int, int>* Tree; // Pointer to the red-black tree

		// Initializing a pointer to a red-black tree
		TEST_METHOD_INITIALIZE(INITIALIZE)
		{
			Tree = new Red_Black_Tree<int, int>();
		}

		// Clearing the pointer to a red-black tree
		TEST_METHOD_CLEANUP(CLEANUP)
		{
			delete Tree;
		}

		// Checking to get the root element of the tree if the tree is non-empty.
		TEST_METHOD(Get_Root_Node_Not_Empty_Tree) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_root_node()->key == 100);
			Assert::IsTrue(Tree->get_root_node()->value == 1);
		}

		// Checking to get the root element of the tree if the tree is empty (exception).
		TEST_METHOD(Get_Root_Node_Empty_Tree) 
		{
			try
			{
				stringstream output;
				output << Tree->get_keys();
				output << " " << Tree->get_values();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			try
			{
				int element = Tree->get_root_node()->key;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
		}

		// Checking to get the size of the tree.
		TEST_METHOD(Get_Size_Tree) 
		{
			Assert::IsTrue(Tree->get_size_tree() == 0);
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_size_tree() == 3);
		}

		// Checking the receipt of a leaf node of a red-black tree, if the tree is not empty.
		TEST_METHOD(Get_Nil_Node_Not_Empty_Tree) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_nil_node()->color == black);
			Assert::IsTrue(Tree->get_nil_node()->key == 0);
			Assert::IsTrue(Tree->get_nil_node()->value == 0);
			Assert::IsTrue(Tree->get_nil_node()->left_node == Tree->get_root_node());
			Assert::IsTrue(Tree->get_nil_node()->right_node == Tree->get_root_node());
		}

		// Checking for obtaining a leaf node of a red-black tree if the tree is empty (exception).
		TEST_METHOD(Get_Nil_Node_Empty_Tree) 
		{
			try
			{
				stringstream output;
				output << Tree->get_keys();
				output << " " << Tree->get_values();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			try
			{
				Assert::IsTrue(Tree->get_nil_node()->color == black);
				Assert::IsTrue(Tree->get_nil_node()->key == 0);
				Assert::IsTrue(Tree->get_nil_node()->value == 0);
				Assert::IsTrue(Tree->get_nil_node()->left_node == Tree->get_root_node());
				Assert::IsTrue(Tree->get_nil_node()->right_node == Tree->get_root_node());
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
		}

		// Checking the addition of an element to an empty tree by key.
		TEST_METHOD(Insert_Element_Tree_Empty_Tree) 
		{
			try
			{
				stringstream output;
				output << Tree->get_keys();
				output << Tree->get_values();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			Tree->insert(100, 1);
			Assert::IsTrue(Tree->get_size_tree() != 0);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 \n 1 \n");
			Assert::IsTrue(Tree->find(100) == true);
			Assert::IsTrue(Tree->get_root_node()->key == 100);
		}

		// Checking the addition of an element to a non-empty tree by key.
		TEST_METHOD(Insert_Element_Tree) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_size_tree() != 0);
			Assert::IsTrue(Tree->find(200) == false);
			Tree->insert(200, 4);
			stringstream output_after_insert;
			output_after_insert << Tree->get_keys();
			output_after_insert << " " << Tree->get_values();
			Assert::IsTrue(output_after_insert.str() == "100 50 150 200 \n 1 2 3 4 \n");
			Assert::IsTrue(Tree->find(200) == true);
		}

		// Checking for adding elements to the tree with the same keys (exception).
		TEST_METHOD(Insert_Element_Tree_Identical_Keys)
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_size_tree() != 0);
			Assert::IsTrue(Tree->find(50) == true);
			try
			{
				Tree->insert(50, 4);
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("An associative array cannot contain elements with the same keys", error.what());
			}
		}

		// Checking the operation of the left turn algorithm for the node of the red-black tree.
		TEST_METHOD(Left_Turn_Element_Tree) 
		{
			Tree->insert(10, 1);
			Tree->insert(5, 2);
			Tree->insert(20, 3);
			Tree->insert(15, 4);
			Tree->insert(25, 5);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "10 5 20 15 25 \n 1 2 3 4 5 \n");
			Assert::IsTrue(Tree->get_root_node()->key == 10);
			Tree->Left_turn(Tree->get_root_node());
			stringstream output_after_left_turn;
			output_after_left_turn << Tree->get_keys();
			output_after_left_turn << " " << Tree->get_values();
			Assert::IsTrue(output_after_left_turn.str() == "20 10 25 5 15 \n 3 1 5 2 4 \n");
			Assert::IsTrue(Tree->get_root_node()->key == 20);
		}

		// Checking the operation of the right turn algorithm for the node of the red-black tree.
		TEST_METHOD(Right_Turn_Element_Tree) 
		{
			Tree->insert(20, 3);
			Tree->insert(10, 1);
			Tree->insert(25, 5);
			Tree->insert(5, 2);
			Tree->insert(15, 4);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "20 10 25 5 15 \n 3 1 5 2 4 \n");
			Assert::IsTrue(Tree->get_root_node()->key == 20);
			Tree->Right_turn(Tree->get_root_node());
			stringstream output_after_right_turn;
			output_after_right_turn << Tree->get_keys();
			output_after_right_turn << " " << Tree->get_values();
			Assert::IsTrue(output_after_right_turn.str() == "10 5 20 15 25 \n 1 2 3 4 5 \n");
			Assert::IsTrue(Tree->get_root_node()->key == 10);
		}

		// Checking the algorithm for restoring the properties of the red-black tree when inserting, if the inserted element is the left child.
		TEST_METHOD(Restoring_Properties_Insert_Left_Child) 
		{
			Tree->insert(10, 1);
			Tree->insert(20, 2);
			stringstream output;
			output << Tree->get_keys() << " ";
			stringstream output_color;
			Red_Black_Tree<int, int>::Breadth_first_traverse_iterator* bft_iterator;
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output.str() == "10 20 \n 1 0 ");
			Assert::IsTrue(Tree->get_root_node()->key == 10);
			Tree->insert(30, 3);
			stringstream output_after_insert_and_restoring;
			output_after_insert_and_restoring << Tree->get_keys() << " ";
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output_after_insert_and_restoring << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output_after_insert_and_restoring.str() == "20 10 30 \n 1 0 0 ");
		}

		// Checking the algorithm for restoring the properties of the red-black tree when inserting, if the inserted element is the right child.
		TEST_METHOD(Restoring_Properties_Insert_Right_Child) 
		{
			Tree->insert(10, 1);
			Tree->insert(20, 2);
			stringstream output;
			output << Tree->get_keys() << " ";
			stringstream output_color;
			Red_Black_Tree<int, int>::Breadth_first_traverse_iterator* bft_iterator;
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output.str() == "10 20 \n 1 0 ");
			Assert::IsTrue(Tree->get_root_node()->key == 10);
			Tree->insert(15, 3);
			stringstream output_after_insert_and_restoring;
			output_after_insert_and_restoring << Tree->get_keys() << " ";
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output_after_insert_and_restoring << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output_after_insert_and_restoring.str() == "15 10 20 \n 1 0 0 ");
		}

		// Checking the search for an element present in the red-black tree by key.
		TEST_METHOD(Find_Element_Tree_Present)
		{
			Tree->insert(10, 1);
			Tree->insert(5, 2);
			Tree->insert(20, 3);
			Tree->insert(15, 4);
			Tree->insert(25, 5);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "10 5 20 15 25 \n 1 2 3 4 5 \n");
			Assert::IsTrue(Tree->find(20) == true);
		}

		// Checking the search for an element missing in the red-black tree by key.
		TEST_METHOD(Find_Element_Tree_Missing) 
		{
			Tree->insert(10, 1);
			Tree->insert(5, 2);
			Tree->insert(20, 3);
			Tree->insert(15, 4);
			Tree->insert(25, 5);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "10 5 20 15 25 \n 1 2 3 4 5 \n");
			Assert::IsTrue(Tree->find(100) == false);
		}

		// Checking the search for an element in an empty red-black tree by key (exception).
		TEST_METHOD(Find_Element_Tree_Empty_Tree) 
		{
			try
			{
				stringstream output;
				output << Tree->get_keys();
				output << Tree->get_values();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			try
			{
				bool element = Tree->find(100);
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("The element cannot be found because the associative array is empty", error.what());
			}
		}

		// Checking the deletion of the missing element in the red-black tree by key (exception).
		TEST_METHOD(Remove_Element_Tree_Missing) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_size_tree() != 0);
			try
			{
				Tree->remove(55);
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("An element with such a key is missing in the array", error.what());
			}
		}

		// Checking the deletion of an element without descendants of the red-black tree by key.
		TEST_METHOD(Remove_Element_Tree_Without_Descendants) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "100 50 150 \n 1 2 3 \n");
			Assert::IsTrue(Tree->get_size_tree() == 3);
			Tree->remove(50);
			stringstream output_after_remove;
			output_after_remove << Tree->get_keys();
			output_after_remove << " " << Tree->get_values();
			Assert::IsTrue(output_after_remove.str() == "100 150 \n 1 3 \n");
			Assert::IsTrue(Tree->get_size_tree() == 2);
			Assert::IsTrue(Tree->find(50) == false);
		}

		// Checking the deletion of an element with a missing right child in the red-black tree by key.
		TEST_METHOD(Remove_Element_Tree_Without_Right_Descendant) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Tree->insert(5, 4);
			Tree->insert(25, 5);
			Tree->insert(40, 6);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "20 10 30 5 25 40 \n 1 2 3 4 5 6 \n");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Tree->remove(10);
			stringstream output_after_remove;
			output_after_remove << Tree->get_keys();
			output_after_remove << " " << Tree->get_values();
			Assert::IsTrue(output_after_remove.str() == "20 5 30 25 40 \n 1 4 3 5 6 \n");
			Assert::IsTrue(Tree->get_size_tree() == 5);
			Assert::IsTrue(Tree->find(10) == false);
		}

		// Checking the deletion of a tree element with a missing left child in a red-black tree by key.
		TEST_METHOD(Remove_Element_Tree_Without_Left_Descendant) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Tree->insert(15, 4);
			Tree->insert(25, 5);
			Tree->insert(40, 6);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "20 10 30 15 25 40 \n 1 2 3 4 5 6 \n");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Tree->remove(10);
			stringstream output_after_remove;
			output_after_remove << Tree->get_keys();
			output_after_remove << " " << Tree->get_values();
			Assert::IsTrue(output_after_remove.str() == "20 15 30 25 40 \n 1 4 3 5 6 \n");
			Assert::IsTrue(Tree->get_size_tree() == 5);
			Assert::IsTrue(Tree->find(10) == false);
		}

		// Checking the deletion of an element without descendants in a red-black tree.
		TEST_METHOD(Remove_Element_Tree_All_Descendants_Have_Descendants) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Tree->insert(5, 4);
			Tree->insert(15, 5);
			Tree->insert(25, 6);
			Tree->insert(40, 7);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "20 10 30 5 15 25 40 \n 1 2 3 4 5 6 7 \n");
			Assert::IsTrue(Tree->get_size_tree() == 7);
			Tree->remove(10);
			stringstream output_after_remove;
			output_after_remove << Tree->get_keys();
			output_after_remove << " " << Tree->get_values();
			Assert::IsTrue(output_after_remove.str() == "20 15 30 5 25 40 \n 1 5 3 4 6 7 \n");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Assert::IsTrue(Tree->find(10) == false);
		}

		// Checking the algorithm for restoring the properties of the red-black tree when deleting, if the element being deleted is the left child.
		TEST_METHOD(Restoring_Properties_Remove_Left_Child)
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Tree->insert(5, 4);
			Tree->insert(15, 5);
			stringstream output;
			output << Tree->get_keys() << " ";
			stringstream output_color;
			Red_Black_Tree<int, int>::Breadth_first_traverse_iterator* bft_iterator;
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 5 15 \n 1 1 1 0 0 ");
			Assert::IsTrue(Tree->get_root_node()->left_node->key == 10);
			Tree->remove(10);
			stringstream output_after_remove_and_restoring;
			output_after_remove_and_restoring << Tree->get_keys() << " ";
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output_after_remove_and_restoring << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output_after_remove_and_restoring.str() == "20 15 30 5 \n 1 1 1 0 ");
			Assert::IsTrue(Tree->get_root_node()->left_node->key == 15);
			Assert::IsTrue(Tree->find(10) == false);
		}

		// Checking the algorithm for restoring the properties of the red-black tree when deleting, if the element being deleted is the right child.
		TEST_METHOD(Restoring_Properties_Remove_Right_Child)
		{
			Tree->insert(10, 1);
			Tree->insert(5, 2);
			Tree->insert(20, 3);
			Tree->insert(15, 4);
			Tree->insert(30, 5);
			stringstream output;
			output << Tree->get_keys() << " ";
			stringstream output_color;
			Red_Black_Tree<int, int>::Breadth_first_traverse_iterator* bft_iterator;
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output.str() == "10 5 20 15 30 \n 1 1 1 0 0 ");
			Assert::IsTrue(Tree->get_root_node()->right_node->key == 20);
			Tree->remove(20);
			stringstream output_after_remove_and_restoring;
			output_after_remove_and_restoring << Tree->get_keys() << " ";
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			while (bft_iterator->has_next())
			{
				output_after_remove_and_restoring << bft_iterator->next()->color << " ";
			}
			Assert::IsTrue(output_after_remove_and_restoring.str() == "10 5 30 15 \n 1 1 1 0 ");
			Assert::IsTrue(Tree->get_root_node()->right_node->key == 30);
			Assert::IsTrue(Tree->find(20) == false);
		}

		// Checking the clearing of the tree (associative array).
		TEST_METHOD(Clear_Red_Black_Tree)
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			stringstream output;
			output << Tree->get_keys();
			output << " " << Tree->get_values();
			Assert::IsTrue(output.str() == "20 10 30 \n 1 2 3 \n");
			Tree->clear();
			try
			{
				stringstream output_after_clear;
				output_after_clear << Tree->get_keys();
				output_after_clear << " " << Tree->get_values();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
			try
			{
				int element = Tree->get_root_node()->key;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
		}

		// Checking the queue for emptiness.
		TEST_METHOD(Is_Empty_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node()->left_node); 
			queue.enqueue(Tree->get_root_node()->right_node);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
		}

		// Checking to get the queue size.
		TEST_METHOD(Get_Size_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			Assert::IsTrue(queue.get_size_queue() == 1);
			queue.enqueue(Tree->get_root_node()->left_node);
			Assert::IsTrue(queue.get_size_queue() == 2);
			queue.enqueue(Tree->get_root_node()->right_node);
			Assert::IsTrue(queue.get_size_queue() == 3);
		}

		// Checking the receipt of the head element of the queue.
		TEST_METHOD(Get_Head_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.get_head() == nullptr);
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node()->left_node);
			queue.enqueue(Tree->get_root_node()->right_node);
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_size_queue() == 3);
			queue.dequeue();
			Assert::IsTrue(queue.get_head()->data->key == 10);
			Assert::IsTrue(queue.get_size_queue() == 2);
			queue.dequeue();
			Assert::IsTrue(queue.get_head()->data->key == 30);
			Assert::IsTrue(queue.get_size_queue() == 1);
			queue.dequeue();
			Assert::IsTrue(queue.get_head() == nullptr);
			Assert::IsTrue(queue.get_size_queue() == 0);
			Assert::IsTrue(queue.queue_is_empty() == true);
		}

		// Checking the receipt of the tail element of the queue.
		TEST_METHOD(Get_Tail_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.get_head() == nullptr);
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			Assert::IsTrue(queue.get_tail()->data->key == 20);
			queue.enqueue(Tree->get_root_node()->left_node);
			Assert::IsTrue(queue.get_tail()->data->key == 10);
			queue.enqueue(Tree->get_root_node()->right_node);
			Assert::IsTrue(queue.get_tail()->data->key == 30);
			Assert::IsTrue(queue.get_size_queue() == 3);
			queue.dequeue();
			Assert::IsTrue(queue.get_tail()->data->key == 30);
			Assert::IsTrue(queue.get_size_queue() == 2);
			queue.dequeue();
			Assert::IsTrue(queue.get_tail()->data->key == 30);
			Assert::IsTrue(queue.get_size_queue() == 1);
			queue.dequeue();
			Assert::IsTrue(queue.get_tail() == nullptr);
			Assert::IsTrue(queue.get_size_queue() == 0);
			Assert::IsTrue(queue.queue_is_empty() == true);
		}

		// Checking for adding an item to an empty queue.
		TEST_METHOD(Enqueue_Empty_Queue) 
		{
			Tree->insert(20, 1);
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_tail()->data->key == 20);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 1);
		}

		// Checking for adding an item to a non-empty queue.
		TEST_METHOD(Enqueue_Not_Empty_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_tail()->data->key == 20);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 1);
			queue.enqueue(Tree->get_root_node()->left_node);
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_tail()->data->key == 10);
			Assert::IsTrue(queue.get_size_queue() == 2);
		}

		// Checking the deletion of an item from an empty queue.
		TEST_METHOD(Dequeue_Empty_Queue) 
		{
			Red_Black_Tree<int, int>::Queue queue;
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
			Assert::IsTrue(queue.dequeue() == nullptr);
		}

		// Checking the deletion of an item from a queue containing a single item.
		TEST_METHOD(Dequeue_Single_Element) 
		{
			Tree->insert(20, 1);
			Red_Black_Tree<int, int>::Queue queue;
			queue.enqueue(Tree->get_root_node());
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_tail()->data->key == 20);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 1);
			Assert::IsTrue(queue.dequeue()->key == 20);
			Assert::IsTrue(queue.get_head() == nullptr);
			Assert::IsTrue(queue.get_tail() == nullptr);
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
		}

		// Checking the deletion of an item from a non-empty queue.
		TEST_METHOD(Dequeue_Not_Empty_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Red_Black_Tree<int, int>::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node()->left_node);
			queue.enqueue(Tree->get_root_node()->right_node);
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_tail()->data->key == 30);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
			Assert::IsTrue(queue.dequeue()->key == 20);
			Assert::IsTrue(queue.get_head()->data->key == 10);
			Assert::IsTrue(queue.get_tail()->data->key == 30);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 2);
		}

		// Checking for queue clearing.
		TEST_METHOD(Clear_Queue) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Red_Black_Tree<int, int>::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node()->left_node);
			queue.enqueue(Tree->get_root_node()->right_node);
			Assert::IsTrue(queue.get_head()->data->key == 20);
			Assert::IsTrue(queue.get_tail()->data->key == 30);
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
			queue.clear_queue();
			Assert::IsTrue(queue.get_head() == nullptr);
			Assert::IsTrue(queue.get_tail() == nullptr);
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
		}

		// Checking for the presence of non-traversed tree elements by a tree-wide traversal iterator.
		TEST_METHOD(BFT_Iterator_Has_Next) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Tree->insert(5, 4);
			Tree->insert(15, 5);
			Red_Black_Tree<int, int>::Breadth_first_traverse_iterator* bft_iterator;
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next()->key == 20);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next()->key == 10);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next()->key == 30);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next()->key == 5);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next()->key == 15);
			Assert::IsTrue(bft_iterator->has_next() == false);
			try
			{
				bft_iterator->next();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("There are no tree elements to process", error.what());
			}
		}

		// Checking the processing of the current node by a tree-wide traversal algorithm.
		TEST_METHOD(BFT_Iterator_Next) 
		{
			Tree->insert(20, 1);
			Tree->insert(10, 2);
			Tree->insert(30, 3);
			Tree->insert(5, 4);
			Tree->insert(15, 5);
			Red_Black_Tree<int, int>::Breadth_first_traverse_iterator* bft_iterator;
			bft_iterator = new Red_Black_Tree<int, int>::Breadth_first_traverse_iterator(Tree->get_root_node(), Tree->get_nil_node());
			Assert::IsTrue(bft_iterator->next()->key == 20);
			Assert::IsTrue(bft_iterator->next()->key == 10);
			Assert::IsTrue(bft_iterator->next()->key == 30);
			Assert::IsTrue(bft_iterator->next()->key == 5);
			Assert::IsTrue(bft_iterator->next()->key == 15);
			try
			{
				bft_iterator->next();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("There are no tree elements to process", error.what());
			}
		}

		// Checking the list for emptiness.
		TEST_METHOD(Is_Empty_List) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			List.push_back(1);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "1 \n");
			Assert::IsTrue(List.get_size_list() == 1);
			Assert::IsTrue(List.isEmpty() == false);
		}

		// Checking to get the size of the list.
		TEST_METHOD(Get_Size_List) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			List.push_back(1);
			Assert::IsTrue(List.get_size_list() == 1);
			List.push_back(2);
			Assert::IsTrue(List.get_size_list() == 2);
			List.push_back(3);
			Assert::IsTrue(List.get_size_list() == 3);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "1 2 3 \n");
			Assert::IsTrue(List.isEmpty() == false);
		}

		// Checking the addition of a list item.
		TEST_METHOD(Push_Back_List) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			List.push_back(1);
			List.push_back(2);
			List.push_back(3);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "1 2 3 \n");
			Assert::IsTrue(List.get_size_list() == 3);
			Assert::IsTrue(List.isEmpty() == false);
			List.push_back(4);
			Assert::IsTrue(List.get_size_list() == 4);
			stringstream output_after_push_back;
			output_after_push_back << List;
			Assert::IsTrue(output_after_push_back.str() == "1 2 3 4 \n");
		}

		// Checking to clear the list.
		TEST_METHOD(Clear_List) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			List.push_back(1);
			List.push_back(2);
			List.push_back(3);
			Assert::IsTrue(List.isEmpty() == false);
			Assert::IsTrue(List.get_size_list() == 3);
			List.clear_list();
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
		}

		// Checking the output statement for an empty stack.
		TEST_METHOD(Operator_Output_Empty_List) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "The list is empty\n\n");
		}

		// Checking the output statement for a non-empty stack.
		TEST_METHOD(Operator_Output_List) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			List.push_back(1);
			List.push_back(2);
			List.push_back(3);
			Assert::IsTrue(List.isEmpty() == false);
			Assert::IsTrue(List.get_size_list() == 3);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "1 2 3 \n");
		}

		// Checking to get a list of keys of an empty red-black tree (associative array) (exception).
		TEST_METHOD(Get_Keys_List_Empty_Tree) 
		{
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			stringstream output;
			try
			{
				List = Tree->get_keys();
				output << List;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
		}

		// Checking to get a list of keys of an empty red-black tree (associative array).
		TEST_METHOD(Get_Keys_List) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			Assert::IsTrue(Tree->get_size_tree() != 0);
			Red_Black_Tree<int, int>::List<int> List = Tree->get_keys();
			Assert::IsTrue(List.isEmpty() == false);
			Assert::IsTrue(List.get_size_list() == 3);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "100 50 150 \n");
		}

		// Checking to get a list of values of an empty red-black tree (associative array) (exception).
		TEST_METHOD(Get_Values_List_Empty_Tree) 
		{
			Assert::IsTrue(Tree->get_size_tree() == 0);
			Red_Black_Tree<int, int>::List<int> List;
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size_list() == 0);
			stringstream output;
			try
			{
				List = Tree->get_values();
				output << List;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Red-black tree (associative array) is empty", error.what());
			}
		}

		// Checking to get a list of values of an empty red-black tree (associative array).
		TEST_METHOD(Get_Values_List) 
		{
			Tree->insert(100, 1);
			Tree->insert(50, 2);
			Tree->insert(150, 3);
			Assert::IsTrue(Tree->get_size_tree() != 0);
			Red_Black_Tree<int, int>::List<int> List = Tree->get_values();
			Assert::IsTrue(List.isEmpty() == false);
			Assert::IsTrue(List.get_size_list() == 3);
			stringstream output;
			output << List;
			Assert::IsTrue(output.str() == "1 2 3 \n");
		}
	};
}
