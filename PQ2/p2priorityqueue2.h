#include<cstddef>

template <class V, class R>
	struct Node {
	    V value;
	    R priority;
	    Node<V,R>* next;
	    Node<V,R>* prev;	    
	};
	
template <class V, class R>
	struct PriorityQueue {
	    Node<V,R>* head;
	};	
		
	template<class V, class R>	
	void initialize(PriorityQueue<V,R>& PQ)
	{
		PQ.head = NULL;
	}

	template<class V,class R>
	void destroy(PriorityQueue<V,R>& PQ)
	{	
		while(PQ.head -> next != NULL)
		{
			Node<V,R>* p = PQ.head;
			PQ.head = PQ.head -> next;
			delete p;
		}
		initialize (PQ);
	}

	template<class V, class R>
	bool isEmpty(PriorityQueue<V,R> PQ)
	{
		return (PQ.head == NULL);
	}

	template<class V, class R>
	void push(PriorityQueue<V,R>& PQ,V v,R p)
	{
		Node<V,R>* Aldo = new Node<V,R>;
		Aldo -> value = v;
		Aldo -> priority = p;	
		Aldo -> next = Aldo;
		Aldo -> prev = Aldo;

		if (isEmpty(PQ))
		{
			PQ.head = Aldo;
		}

		else 
		{
			if (Aldo -> priority > PQ.head -> priority || PQ.head -> prev -> priority > Aldo-> priority)
			{
				Aldo -> next = PQ.head;
				Aldo -> prev = PQ.head->prev;
				PQ.head -> prev -> next = Aldo;
				PQ.head -> prev = Aldo;
				if(Aldo -> priority > PQ.head -> priority)
					PQ.head = Aldo;			
			}
			else 
			{
				Node<V,R>* x = PQ.head;
				while ( x -> next -> priority >= Aldo -> priority && x->next -> priority < x -> priority )
				{
					x = x -> next;
					//std::cout<<1;
				}
				Node<V,R>* y = x -> next;
				x -> next = Aldo;
				Aldo -> prev = x;
				Aldo -> next = y;
				y -> prev = Aldo;
				//delete x; delete y;
			}
		}

	}

	template<class V, class R>
	V    pop(PriorityQueue<V,R>& PQ)
	{
		V i = PQ.head -> value;
		if (PQ.head -> next == PQ.head && PQ.head -> prev == PQ.head)
		{
			initialize(PQ);
			return i;
		}
		PQ.head -> prev ->next = PQ.head -> next;
		PQ.head -> next -> prev = PQ.head -> prev;
		PQ.head = PQ.head -> next;
		return i;
	}