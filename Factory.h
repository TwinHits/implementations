#ifndef FACTORY_H
#define FACTORY_H

template<typename T>
class Factory
{
	public:
		T* create() 
		{ 
			ptr = SceneObjectManager::Instance()->addSceneObject<T>();
			return ptr;
		}
	protected:
		Factory() {}
		Factory(const Factory& F) {}
		void operator=(const Factory& F) {}
		~Factory() {}

	private:
	
};

#endif
