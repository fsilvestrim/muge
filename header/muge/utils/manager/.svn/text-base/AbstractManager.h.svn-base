/*
 *  AbstractManager.h
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muge__utils__manager__AbstractManager_h__
#define __muge__utils__manager__AbstractManager_h__

#include <map>
using namespace std;

#pragma GCC visibility push(default)
namespace muge
{
	namespace utils
	{
		namespace manager
		{
			template<class T>
			class AbstractManager
			{
			protected:
				int										numChildren;
				map<const char*, T*>					childrens;
				typename map<const char*, T*>::iterator	it_childrens;
				
			public:
				
				AbstractManager()
				{
					this->numChildren		= 0;
				}
				
				~AbstractManager()
				{
					childrens.clear();
				}
				
				int getNumChildrens()
				{
					return numChildren;
				}
				
				int	getChildIndex(T *node)
				{
					T *searchNode;
					T *returnNode = NULL;
					
					for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
					{
						searchNode = (*it_childrens).second;
						
						if (searchNode == node)
							returnNode = node; break;
					}
					
					return (*it_childrens).first;
				}
				
				bool contains(T *node)
				{
					return getChildByName(node->name) != NULL ? true : false;
				}
				
				T *getChildAt(int index)
				{
					return childrens[(const char*)index];
				}
				
				T *getChildById(const char *id)
				{
					return childrens[id];
				}
				
				virtual T *addChild(T* node)
				{
					childrens[(const char*)numChildren++] = node;
					
					return node;
				}
				
				T *addChild(const char *id, T* node)
				{
					childrens[(const char*)id] = node;
					numChildren++;
					return node;
				}
				
				T *addChildAt(T* node, int index)
				{
					if (getChildAt(index) == NULL)
						throw "This index is already full";
					
					childrens[index] = node;
					
					return node;
				}
				
				void removeChild(T *node)
				{
					childrens.erase(childrens.find(getChildIndex(node)));
				}
				
				void removeChildAt(int index)
				{
					childrens.erase(childrens.find(index));
				}
				
				virtual void explode() {};
				
			};
		}
	}
}
#pragma GCC visibility pop
#endif