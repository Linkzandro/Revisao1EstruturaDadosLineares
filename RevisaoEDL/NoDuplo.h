#pragma once
template<class T>
class NoDuplo
{
private:
	T objeto;
	NoDuplo* next;
	NoDuplo* previous;
public:
	//construtor com templates
	NoDuplo(T obj) {
		next = nullptr;
		objeto = obj;
	}


	T getObject() {
		return objeto;
	}

	NoDuplo* getNext() {
		if (this->next != nullptr) {
			return this->next;
		}
		return nullptr;
	}

	NoDuplo* getPrevious() {
		if (this->previous != nullptr) {
			return this->previous;
		}
		return nullptr;
	}

	void setNext(NoDuplo* p) {
		this->next = p;
	}

	void setPrevious(NoDuplo* p) {
		this->previous = p;
	}

	void setObject(T obj) {
		this->objeto = obj;
	}



};
