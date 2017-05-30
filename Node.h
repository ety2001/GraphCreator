// Node.h
class Node{
	private:
		Node* next;
		char val;
	public:
		Node(char);
		Node* getNext();
		char getVal();
		void setNext(Node*);
};
