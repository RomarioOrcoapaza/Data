/*
 * CStack.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CSTACK_H_
#define CSTACK_H_

#include "IDataStructure.h"
//#include "CNode.h"

template<class T>
class CStack: public IDataStructure<T> {
protected:
	CNode<T>* cabeza;
public:
	CStack() {
		this->cabeza=0;
	}
	~CStack() {

	}
	void insert(T _dato) {
		CStackNode<T>* NewNodo=new CStackNode<T>(_dato);
		if(this->cabeza==NULL){
			this->cabeza=NewNodo;
		}
		else{
			CStackNode<T>* NewNodo=new CStackNode<T>(_dato);
			CNode<T>* temp=this->cabeza;
			this->cabeza=NewNodo;
			NewNodo->setLink(LINKS::down,temp);
		}
	}

	void erase(T _data) {
		CNode<T>* temp1, *temp2;
		temp1 = this->cabeza;
		temp2 = this->cabeza;
		while (temp1 != 0) {
		    if (temp1->getData() == _data) {
			    if (temp1 == this->cabeza) {
				    temp2 = temp1->getLink(LINKS::down);
				    this->cabeza = temp2;
				    delete temp1;
				    temp1 = this->cabeza;
			    }
			    else {
				    if (temp1->getLink(LINKS::down) != 0) {
					    temp2->setLink(LINKS::down,   temp1->getLink(LINKS::down));
					    delete temp1;
					    temp1 = temp2->getLink(LINKS::down);
				    } else {
					    temp2->setLink(LINKS::down, 0);
					    delete temp1;
					    temp1=0;
				    }
			    }
		    }
		    else {
			temp2 = temp1;
			temp1 = temp1->getLink(LINKS::down);
		    }
	    }
	}

	bool search(T _dato) {
		CNode<T>* temp=this->cabeza;
				while(temp){
					if(temp->getData()==_dato)
						return true;
					temp=temp->getLink(LINKS::down);

				}
				return false;

	}
	void clear() {
		CNode<T>* temp=this->cabeza;
		while(temp){
			temp=temp->getLink(LINKS::down);
			std::cout<<"Eliminado"<<this->cabeza<<std::endl;
			delete this->cabeza;
			this->cabeza=temp;
		}

	}
	void show(std::ostream& out) {
		CNode<T> * temp = this->cabeza;

		while (temp->getLink(LINKS::down)) {
			out << temp->getData() << " -- "; // devuelve un object, int, float o cualquier tipo
			temp = temp->getLink(LINKS::down);
		}
		out << temp->getData() << std::endl;
	}
};

#endif /* CSTACK_H_ */
