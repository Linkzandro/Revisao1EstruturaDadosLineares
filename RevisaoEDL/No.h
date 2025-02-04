#pragma once
template<class T>
class No
{
	private:
		T objeto;
		No* next;
	public:
		//construtor com templates
		template<class T> No(T obj) {
			next = nullptr;
			objeto = obj;
		}


		T getObject() {
			return objeto;
		}

		No* getNext() {
			if (this->next != nullptr) {
				return this->next;
			}
			return nullptr;
		}

		void setNext(No* p) {
			this->next = p;
		}

		void setObject(T obj) {
			this->objeto = obj;
		}



};

