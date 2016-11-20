/*
 S * CQueue.h
 *
 *  Created on: 3 de oct. de 2016
 *      Author: christian
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_

#include "IDataStructure.h"

template<class T>
class CQueue: public IDataStructure<T> {
	CNode<T>* one;
public:
	CQueue() {
		this->one=0;
	}
	~CQueue() {

	}
	void insert(T _dato) {
		CSimpleNode<T>* NewNodo=new CSimpleNode<T>(_dato);
		if(this->one==NULL){
			this->one=NewNodo;
		}
		else{
			CSimpleNode<T>* NewNodo=new CSimpleNode<T>(_dato);
			CNode<T>* temp=this->one;
			while(temp->getLink(LINKS::back)){
				temp=temp->getLink(LINKS::back);
			}
			temp->setLink(LINKS::back,NewNodo);
		}

	}
	void erase(T _dato) {
		CNode<T>* temp1, *temp2;
		temp1 = this->one;
		temp2 = this->one;
		while (temp1 != 0) {
		    if (temp1->getData() == _dato) {
			    if (temp1 == this->one) {
				    temp2 = temp1->getLink(LINKS::back);
				    this->one = temp2;
				    delete temp1;
				    temp1 = this->one;
			    }
			    else {
				    if (temp1->getLink(LINKS::back) != 0) {
					    temp2->setLink(LINKS::back,   temp1->getLink(LINKS::back));
					    delete temp1;
					    temp1 = temp2->getLink(LINKS::back);
				    } else {
					    temp2->setLink(LINKS::back, 0);
					    delete temp1;
					    temp1=0;
				    }
			    }
		    }
		    else {
			temp2 = temp1;
			temp1 = temp1->getLink(LINKS::back);
		    }
	    }

	}
	bool search(T _dato) {
		CNode<T>* temp=this->one;
				while(temp){
					if(temp->getData()==_dato)
						return true;
					temp=temp->getLink(LINKS::back);

				}
				return false;

	}
	void clear() {
		CNode<T>* temp=this->one;

		while(temp){
			temp=temp->getLink(LINKS::back);
			std::cout<<"Eliminado"<<this->one<<std::endl;
			delete this->one;
			this->one=temp;
		}

	}
	void show(std::ostream& out) {
		CNode<T> * temp = this->one;

		while (temp->getLink(LINKS::back)) {
			out << temp->getData() << " -- "; // devuelve un object, int, float o cualquier tipo
			temp = temp->getLink(LINKS::back);
		}
		out << temp->getData() << std::endl;
	}
};

#endif /* CQUEUE_H_ */
