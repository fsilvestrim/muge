/*
 *  AbstractManager.cpp
 *  MuGE
 *
 *  Created by Filipe Silvestrim on 11/19/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */


#include "AbstractManager.h"

using namespace muge::utils::manager;

template<typename T>
AbstractManager<T>::AbstractManager()
{
	this->numChildren		= 0;
}

template<typename T>
AbstractManager<T>::~AbstractManager()
{
	childrens.clear();
}

template<typename T>
int	AbstractManager<T>::getChildIndex(T *node)
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

template<typename T>
bool AbstractManager<T>::contains(T *node)
{
	return getChildByName(node->name) != NULL ? true : false;
}

template<typename T>
T *AbstractManager<T>::getChildByName(const char *name)
{
	T *searchNode;
	T *returnNode = NULL;
	
	for ( it_childrens = childrens.begin() ; it_childrens != childrens.end(); it_childrens++ )
	{
		searchNode = (*it_childrens).second;
		
		if (searchNode->getName() == name)
			returnNode = searchNode; break;
	}
	
	return returnNode;	
}

template<typename T>
T *AbstractManager<T>::getChildAt(int index)
{
	return childrens[index];
}

template<typename T>
T *AbstractManager<T>::addChild(T* node)
{
	childrens[numChildren++] = node;
}

template<typename T>
T *AbstractManager<T>::addChildAt(T* node, int index)
{
	if (getChildAt(index) == NULL)
		throw "This index is already full";
	
	childrens[index] = node;
}

template<typename T>
void AbstractManager<T>::removeChild(T *node)
{
	childrens.erase(childrens.find(getChildIndex(node)));
}

template<typename T>
void AbstractManager<T>::removeChildAt(int index)
{
	childrens.erase(childrens.find(index));
}
